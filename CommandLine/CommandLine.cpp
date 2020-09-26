//
// Created by alexvim on 9/12/20.
//

#include "CommandLine.h"

CommandLine::CommandLine(int c, char *v[]) {
    if (c <= 1) {
        itsCommand = "help";
        itsCount = 0;
    } else {
        for (int i = 0; i < c; i++) {
            if (i == 1) {
                itsCommand = v[i];
                itsCount = 1;
            }
            if (i == 2) {
                itsArgument = v[i];
                itsCount = 2;
            }
        }
    }
}

CommandLine::CommandLine() {

}

std::string CommandLine::getCommand() const {
    return itsCommand;
}

std::string CommandLine::getArgument() const {
    return itsArgument;
}

int CommandLine::getCount() const {
    return itsCount;
}

std::string CommandLine::getInfo(std::string name) {
    std::string out;
    std::cout << name;
    std::cin >> out;

    return out;
}
