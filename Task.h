#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    std::string title;
    bool completed;

    Task();
    Task(const std::string &t);

    void markDone();
    void showTask();
};

#endif