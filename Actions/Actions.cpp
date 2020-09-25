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

std::string Actions::help() {
    return "Insert data:\n"
           "\tcreate:\n"
           "\t\t* category - create group of data files\n"
           "\t\t\tExample: controls create example_category\n"
           "\t\t* file - create file with tabs of data which you will use to certain targets in the "
           "certain category\n"
           "\t\t\tExample: controls create example_category my_data\n"
           "\twrite:\n"
           "\t\t* file in category - change existing file in certain directory\n"
           "\t\t\tExample: controls write example_category my_data\n"
           "Out data:\n"
           "\tlist:\n"
           "\t\t* category - list data files in category\n"
           "\t\t\tExample: controls list example_category\n"
           "\t\t* file - out file data in the category\n"
           "\t\t\tExample: controls list example_category my_data\n"
           "Delete data:\n"
           "\trm:\n"
           "\t\t* category - remove the category\n"
           "\t\t\tExample: controls rm example_category\n"
           "\t\t* file - remove file in the category\n"
           "\t\t\tExample: controls rm example_category my_data\n"
           "Help:\n"
           "\t* help - display this message\n"
           "\t* Get docs in https://github.com/AlexVIM1/controls or https://gitlab.com/alexvim/controls\n";
}

std::string Actions::createCat() {
    std::string name = itsCmd->getInfo("Category name: ");
    std::string pwd = itsCmd->getInfo("Category password: ");
    system(("cd ~/.controls/data/ && touch init && mv '" + name + ".zip' ../backup/ && zip -e -P '" + pwd +
        "' '" + name + ".zip' init && rm init").c_str());

    return name;
}

std::string Actions::writeFile() {
    std::string name, cat, data, pwd;
    std::cout << "Category name: ";
    std::cin >> cat;
    std::cout << "Category password: ";
    std::cin >> pwd;
    std::cout << "File name: ";
    std::cin >> name;
    std::cout << "File data: ";
    std::cin >> data;
    system(("cd ~/.controls/data/ && unzip -P '" + pwd + "' '" + cat + ".zip' -d ../build/ && " +
        "rm ../build/init && mv '" + name + "' ../backup/ && echo '" + data + "' >> ../build/'" + name +
            "' && zip -e -P '" + pwd + "' '" + cat +
                ".zip' ../build/* && rm -rf ../build/*").c_str());

    return name;
}

std::string Actions::listCat() {
    system("cd ~/.controls/data/ && rm ../controls/count && ls >> ../controls/count");
    itsFile->open("~/.controls/controls/count");
    std::string out, el;
    char ex[255];
    while (getline(itsFile, el)) {
        for (int i = 0; i < el.size(); i++) {
            if (i == el.size()-3) {
                break;
            }
            ex[i] = el.at(i);
        }
        out.append(ex);
    }
    itsFile->close();
    std::cout << out;

    return out;
}

std::string Actions::listCat(bool files) {
    std::string name = itsCmd->getInfo("Category name: ");
    std::string pwd = itsCmd->getInfo("Category password: ");
    system(("cd ~/.controls/data/ && unzip -P '" + pwd + "' '" + name + ".zip' -d ../build/ && "
        "cd ~/.controls/build/ && rm ../controls/count && ls >> ../controls/count && cd .. && rm -rf build/*").c_str());
    itsFile->open("~/.controls/controls/count");
    std::string out, el;
    while (getline(itsFile, el)) {
        out.append(el);
    }
    itsFile->close();
    std::cout << out;

    return name;
}

std::string Actions::listFile() {
    std::string cat = itsCmd->getInfo("Category name: ");
    std::string pwd = itsCmd->getInfo("Category password: ");
    std::string name = itsCmd->getInfo("File name: ");
    system(("cd ~/.controls/data/ && unzip -P '" + pwd + "' '" + cat + ".zip' -d ../build/ && "
        "cd ~/.controls/build/ && rm ../controls/file && cat '" + name +
            "' >> ../controls/file && cd .. && rm -rf build/*").c_str());
    itsFile->open("~/.controls/controls/file");
    std::string out, el;
    while (getline(itsFile, el)) {
        out.append(el);
    }
    itsFile->close();
    std::cout << out;

    return name;
}

std::string Actions::rmCat() {
    std::string name = itsCmd->getInfo("Category name: ");
    system(("cd ~/.controls/data/ && rm ../.controls/controls/rm && rm '" + name +
        ".zip' 2> ../controls/rm").c_str());
    itsFile->open("~/.controls/controls/rm");
    std::string out, el;
    while (getline(itsFile, el)) {
        out.append(el);
    }
    itsFile->close();
    std::cout << out;

    return name;
}

std::string Actions::rmFile() {
    std::string cat = itsCmd->getInfo("Category name: ");
    std::string pwd = itsCmd->getInfo("Category password: ");
    std::string name = itsCmd->getInfo("File name: ");
    system(("cd ~/.controls/data/ && unzip -P '" + pwd + "' '" + cat + ".zip' -d ../build/ && rm ../controls/rm"
        " && rm ../build/'" + name + "' 2> ../controls/rm  && zip -e -P '" + pwd + "' '" + cat +
            ".zip' ../build/* && rm -rf ../build/*").c_str());
    itsFile->open("~/.controls/controls/rm");
    std::string out, el;
    while (getline(itsFile, el)) {
        out.append(el);
    }
    itsFile->close();
    std::cout << out;

    return name;
}
