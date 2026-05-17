#include "Task.h"
#include <iostream>

Task::Task() {
    title = "";
    completed = false;
}

Task::Task(const std::string &t) {
    title = t;
    completed = false;
}

void Task::markDone() {
    completed = true;
}

void Task::showTask() {
    std::cout << title;
    if (completed)
        std::cout << " [Completed]";
    else
        std::cout << " [Pending]";
    std::cout << std::endl;
}