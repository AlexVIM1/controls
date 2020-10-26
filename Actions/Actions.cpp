//
// Created by alexvim on 9/12/20.
//

#include "Actions.h"

Actions::Actions() :
    itsFile(new std::ifstream()),
    itsCmd(new CommandLine())
{

}

Actions::~Actions() {
    delete itsFile;
}

std::string Actions::help() const {
    return "Insert data:\n"
           "\twrite:\n"
           "\t\t* category - create group of data files\n"
           "\t\t\tExample: controls write cat\n"
           "\t\t* file in category - create file with data which you will use to certain targets in the "
           "certain category\n"
           "\t\t\tExample: controls write file\n"
           "Out data:\n"
           "\tlist:\n"
	   "\t\t* categories - list all your categories\n"
	   "\t\t\tExample: controls list cats\n"
           "\t\t* category - list data files in category\n"
           "\t\t\tExample: controls list cat\n"
           "\t\t* file - out file data in the category\n"
           "\t\t\tExample: controls list file\n"
           "Delete data:\n"
           "\trm:\n"
           "\t\t* category - remove the category\n"
           "\t\t\tExample: controls rm cat\n"
           "\t\t* file - remove file in the category\n"
           "\t\t\tExample: controls rm file\n"
           "Help:\n"
           "\t* help - display this message\n"
           "\t* Get docs and info in https://github.com/AlexVIM1/controls or https://gitlab.com/alexvim/controls\n";
}

std::string Actions::error() const {
    return "'help' to list manual\n";
}

std::string Actions::createCat() {
    std::string name = itsCmd->getInfo("Category name: ");
    std::string pwd = itsCmd->getInfo("Category password: ");
    system(("cd ~/.controls/data/ && touch init && mv '" + name + ".zip' ../backup/ 2>&1 2> ../controls/tmp ; zip -e -P '" + pwd +
        "' '" + name + ".zip' init >> ../controls/tmp && rm init").c_str());

    return name;
}

std::string Actions::writeFile() {
    std::string cat = itsCmd->getInfo("Category name: ");
    std::string pwd = itsCmd->getInfo("Category password: ");
    std::string name = itsCmd->getInfo("File name: ");
    std::string data = itsCmd->getInfo("File data: ");
    system(("cd ~/.controls/data/ && rm -rf ../build/* 2> ../controls/tmp ; unzip -P '" + pwd + "' '" + cat + ".zip' -d ../build/ "
        ">> ../controls/tmp && rm ../build/init 2> ../controls/tmp && mv '" + name + "' ../backup/ > ../controls/tmp 2>&1 ; echo '" + data + "' > ../build/'" + name +
            "' && cd ../build/ && zip -e -P '" + pwd + "' ../data/'" + cat + ".zip' * >> ../controls/tmp && rm -rf *").c_str());

    return name;
}

std::string Actions::listCat() {
    system("cd ~/.controls/data/ && ls -F | grep -v / | sed -r 's/^(.+)\\.[^.]+$/\\1/'");
}

std::string Actions::listCat(bool files) {
    std::string name = itsCmd->getInfo("Category name: ");
    std::string pwd = itsCmd->getInfo("Category password: ");
    system(("cd ~/.controls/data/ && rm -rf build/*  >> ../controls/tmp && unzip -P '"
        + pwd + "' '" + name + ".zip' -d ../build/ >> ../controls/tmp && "
            "cd ~/.controls/build/ && ls && cd .. && rm -rf build/* 2> controls/tmp").c_str());
}

std::string Actions::listFile() {
    std::string cat = itsCmd->getInfo("Category name: ");
    std::string pwd = itsCmd->getInfo("Category password: ");
    std::string name = itsCmd->getInfo("File name: ");
    system(("cd ~/.controls/data/ && rm -rf ../build/* && unzip -P '" + pwd + "' '" + cat + ".zip' -d ../build/ "
        ">> ../controls/tmp && cd ~/.controls/build/ && cat '" + name + "' && cd .. && rm -rf build/* 2> controls/tmp").c_str());

    return name;
}

std::string Actions::rmCat() {
    std::string name = itsCmd->getInfo("Category name: ");
    system(("cd ~/.controls/data/ && rm '" + name + ".zip'").c_str());

    return name;
}

std::string Actions::rmFile() {
    std::string cat = itsCmd->getInfo("Category name: ");
    std::string pwd = itsCmd->getInfo("Category password: ");
    std::string name = itsCmd->getInfo("File name: ");
    system(("cd ~/.controls/data/ && unzip -P '" + pwd + "' '" + cat + ".zip' -d ../build/ "
        ">> ../controls/tmp && rm ../build/'" + name + "' ; zip -e -P '" + pwd + "' '" + cat +
            ".zip' ../build/* >> ../controls/tmp && rm -rf ../build/* 2> ../controls/tmp").c_str());

    return name;
}
