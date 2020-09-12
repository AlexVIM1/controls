//
// Created by alexvim on 9/12/20.
//

#ifndef CONTROLS_COMMANDLINE_H
#define CONTROLS_COMMANDLINE_H


#include <iostream>

class CommandLine {
public:
    CommandLine(int c, char *v[]);
    inline std::string getCommand() const;
    inline std::string getArgument() const;
    inline int getCount() const;

private:
    int itsCount;
    std::string itsCommand;
    std::string itsArgument;
};


#endif //CONTROLS_COMMANDLINE_H