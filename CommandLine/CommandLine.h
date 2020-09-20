//
// Created by alexvim on 9/12/20.
//

#ifndef CONTROLS_COMMANDLINE_H
#define CONTROLS_COMMANDLINE_H
#define DATA


#include <iostream>
#include <fstream>

class CommandLine {
public:
    CommandLine(int c, char *v[]);
    CommandLine();
    std::string getInfo(std::string name);
    inline std::string getCommand() const;
    inline std::string getArgument() const;
    inline int getCount() const;

private:
    int itsCount;
    std::string itsCommand;
    std::string itsArgument;
};


#endif //CONTROLS_COMMANDLINE_H
