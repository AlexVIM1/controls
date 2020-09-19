//
// Created by alexvim on 9/12/20.
//

#ifndef CONTROLS_ACTIONS_H
#define CONTROLS_ACTIONS_H
#define CATEGORY
#define FILE


#include "../CommandLine/CommandLine.h"

class Actions {
public:
    Actions();
    ~Actions();
    std::string help();

public CATEGORY:
    std::string createCat();
    std::string listCat();
    std::string rmCat();

public FILE:
    std::string createFile();
    std::string listFile();
    std::string rmFile();

private:
    std::ifstream *itsFile;
};


#endif //CONTROLS_ACTIONS_H
