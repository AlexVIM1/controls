#include "Actions/Actions.h"

int main(int argc, char *argv[]) {
    CommandLine *cmd = new CommandLine(argc, argv);
    Actions *act = new Actions();

    if (cmd->getCount() == 0) {
        std::cout << act->error();
    }

    else {
        if (cmd->getCommand() == "help") {
            std::cout << act->help();
        }

        if (cmd->getCommand() == "write") {
            if (cmd->getArgument() == "cat") {
                act->createCat();
            }
        }

        else {
            std::cout << act->error();
        }
    }

	return 0;
}
