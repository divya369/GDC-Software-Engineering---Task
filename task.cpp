#include <iostream>
#include "functions/help.hpp"
#include "functions/add.hpp"
#include "functions/ls.hpp"
#include "functions/done.hpp"
#include "functions/delete.hpp"
#include "functions/report.hpp"

int main(int argc, char* argv[]) {
    std::string argvNewRequest, task;

    if (argc > 1) {
        argvNewRequest = argv[1];
    } else if (argc == 1) {
        help();
    }

    // find which command is requested and invoke that function
    if (argvNewRequest == "help") {
        help();
    }
    else if (argvNewRequest == "add") {
        if (argc == 4) {
            int priorityNumber = atoi(argv[2]);
            task = argv[3];
            add(priorityNumber, task);
        }
        else {
            std::cout<<"Error: Missing tasks string. Nothing added!";
        }
    } else if (argvNewRequest == "ls") {
        ls();
    } else if (argvNewRequest == "done") {
        if (argc == 3) {
            int taskToBeDone = atoi(argv[2]);
            done(taskToBeDone);
        } else {
            std::cout<<"Error: Missing NUMBER for marking tasks as done.";
        }
    } else if (argvNewRequest == "del") {
        if (argc == 3) {
            int taskToBeDeleted = atoi(argv[2]);
            deleteTask(taskToBeDeleted);
        } else {
            std::cout<<"Error: Missing NUMBER for deleting tasks.";
        }
    } else if (argvNewRequest == "report") {
        report();
    }
    return 0;
}
