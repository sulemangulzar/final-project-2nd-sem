#include "Planner.h"
#include <iostream>

Planner::Planner() {
    count = 0;
}

void Planner::addTask(const std::string &title) {
    if (count < 20) {
        tasks[count] = Task(title);
        count++;
    } else {
        std::cout << "Task limit reached!\n";
    }
}

void Planner::viewAll() {
    if (count == 0) {
        std::cout << "No tasks found.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << ". ";
        tasks[i].showTask();
    }
}

void Planner::editTask(int index, const std::string &newTitle) {
    if (index >= 0 && index < count) {
        tasks[index].title = newTitle;
    }
}

void Planner::deleteTask(int index) {
    if (index < 0 || index >= count) return;

    for (int i = index; i < count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    count--;
}

void Planner::markTaskDone(int index) {
    if (index >= 0 && index < count) {
        tasks[index].markDone();
    }
}

void Planner::viewPending() {
    for (int i = 0; i < count; i++) {
        if (!tasks[i].completed) {
            std::cout << i + 1 << ". ";
            tasks[i].showTask();
        }
    }
}

void Planner::viewCompleted() {
    for (int i = 0; i < count; i++) {
        if (tasks[i].completed) {
            std::cout << i + 1 << ". ";
            tasks[i].showTask();
        }
    }
}

int Planner::getCount() const {
    return count;
}

std::string Planner::getTaskText(int index) const {
    if (index >= 0 && index < count) {
        return tasks[index].title;
    }
    return std::string();
}

bool Planner::isTaskCompleted(int index) const {
    if (index >= 0 && index < count) {
        return tasks[index].completed;
    }
    return false;
}