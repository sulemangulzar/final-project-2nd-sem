#ifndef PLANNER_H
#define PLANNER_H

#include <string>
#include "Task.h"

class Planner {
private:
    Task tasks[20];
    int count;

public:
    Planner();

    void addTask(const std::string &title);
    void viewAll();
    void editTask(int index, const std::string &newTitle);
    void deleteTask(int index);
    void markTaskDone(int index);
    void viewPending();
    void viewCompleted();

    int getCount() const;
    std::string getTaskText(int index) const;
    bool isTaskCompleted(int index) const;
};

#endif