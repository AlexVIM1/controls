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

        else if (cmd->getCommand() == "write") {
            if (cmd->getArgument() == "cat") {
                act->createCat();
            }

            else if (cmd->getArgument() == "file") {
                act->writeFile();
            }

            else {
                std::cout << act->error();
            }
        }

        else if (cmd->getCommand() == "list") {
            if (cmd->getArgument() == "cats") {
                act->listCat();
            }

            else if (cmd->getArgument() == "cat") {
                act->listCat(true);
            }

            else if (cmd->getArgument() == "file") {
                act->listFile();
            }

            else {
                std::cout << act->error();
            }
        }

        else if (cmd->getCommand() == "rm") {
            if (cmd->getArgument() == "cat") {
                act->rmCat();
            }

            else if (cmd->getArgument() == "file") {
                act->rmFile();
            }
            else {
                std::cout << act->error();
            }
        }
    }

	return 0;
}
