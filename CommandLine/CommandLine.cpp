//
// Created by alexvim on 9/12/20.
//

#include "CommandLine.h"

CommandLine::CommandLine(int c, char *v[]) {
    if (c <= 1) {
        itsCommand = "help";
    } else {
        for (int i = 0; i < c; i++) {
            if (i == 2) {
                itsCommand = v[i];
                itsCount = 1;
            }
            if (i == 3) {
                itsArgument = v[i];
                itsCount = 2;
            }
        }
    }
}

inline std::string CommandLine::getCommand() const {
    return itsCommand;
}

inline std::string CommandLine::getArgument() const {
    return itsArgument;
}

inline int CommandLine::getCount() const {
    return itsCount;
}
