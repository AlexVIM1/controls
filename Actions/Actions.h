//
// Created by alexvim on 9/12/20.
//

#include "../CommandLine/CommandLine.h"

#ifndef CONTROLS_ACTIONS_H
#define CONTROLS_ACTIONS_H
#define CATEGORY
#define FILE


class Actions {
public:
    Actions();
    ~Actions();
    std::string help();

public CATEGORY:
    std::string createCat();
    std::string listCat();
    std::string listCat(bool files);
    std::string rmCat();

public FILE:
    std::string writeFile();
    std::string listFile();
    std::string rmFile();

private:
    std::ifstream *itsFile;
    CommandLine *itsCmd;
};


#endif //CONTROLS_ACTIONS_H
