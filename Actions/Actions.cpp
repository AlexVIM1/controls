//
// Created by alexvim on 9/12/20.
//

#include "Actions.h"

Actions::Actions(CommandLine *cmd) :
    itsCmd(cmd)
{

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
    std::string name;
    std::string pwd;
    std::cout << "Category name: ";
    std::cin >> name;
    std::cout << "Category password: ";
    std::cin >> pwd;
    system(("cd ~/.controls/ && touch init && mv '" + name + ".zip' backup/ && zip -e -P '" + pwd +
        "' '" + name + ".zip' init && rm init").c_str());

    return name;
}

std::string Actions::createFile() {
    std::string name;
    std::string cat;
    std::string data;
    std::string pwd;
    std::cout << "File name: ";
    std::cin >> name;
    std::cout << "File category: ";
    std::cin >> cat;
    std::cout << "Category password: ";
    std::cin >> pwd;
    std::cout << "File data: ";
    std::cin >> data;
    system(("cd ~/.controls/ && unzip -P '" + pwd + "' '" + name + ".zip' -d build/ " +
        "rm build/init && echo '" + data + "' >> build/'" + name + "' && zip -e -P '" + pwd + "' '" + cat +
            ".zip' build/*").c_str());

    return name;
}
