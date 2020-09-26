//
// Created by alexvim on 9/12/20.
//

#include <iostream>
#include <fstream>

#ifndef CONTROLS_COMMANDLINE_H
#define CONTROLS_COMMANDLINE_H


class CommandLine {
public:
    CommandLine(int c, char *v[]);
    CommandLine();
    std::string getInfo(std::string name);
    std::string getCommand() const;
    std::string getArgument() const;
    int getCount() const;

private:
    int itsCount;
    std::string itsCommand;
    std::string itsArgument;
};


#endif //CONTROLS_COMMANDLINE_H
