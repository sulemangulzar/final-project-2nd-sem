// -------------------------------------------------------------------
// Task.cpp — The "implementation" file for the Task class
//
// While Task.h describes WHAT the class looks like,
// this file explains HOW each method actually works.
// Think of Task.h as a menu and Task.cpp as the kitchen.
// -------------------------------------------------------------------

// We include our own header so the compiler knows about the Task class.
#include "Task.h"

// We include <iostream> so we can print text to the screen
// using std::cout.
#include <iostream>

// -------------------------------------------------------------------
// CONSTRUCTOR 1 — Default constructor
//
// This runs when you create a Task with NO arguments, like:
//     Task myTask;
//
// "Task::" tells the compiler this function belongs to the Task class.
// We set the title to an empty string and completed to false,
// so every new Task starts as "not done" with no name.
// -------------------------------------------------------------------
Task::Task() {
    title = "";        // Start with an empty title (no name yet)
    completed = false; // The task is not done yet
}

// -------------------------------------------------------------------
// CONSTRUCTOR 2 — Parameterized constructor
//
// This runs when you create a Task WITH a title, like:
//     Task myTask("Buy milk");
//
// The parameter "t" is the title string that was passed in.
// We copy it into the member variable "title" so the object
// remembers the name we gave it.
// -------------------------------------------------------------------
Task::Task(const std::string &t) {
    title = t;         // Save the title that was passed in
    completed = false; // The task always starts as not done
}

// -------------------------------------------------------------------
// METHOD: markDone()
//
// This method is an ACTION the Task object can perform.
// Calling it simply flips the "completed" flag to true.
// After this runs, the task is considered finished.
//
// Example:
//     myTask.markDone();
// -------------------------------------------------------------------
void Task::markDone() {
    completed = true;
}

// -------------------------------------------------------------------
// METHOD: showTask()
//
// This method prints the task's title and current status
// to the screen (the terminal/console).
//
// std::cout is the standard way to print in C++.
// The "<<" operator sends text to the output.
// std::endl ends the line (like pressing Enter).
//
// Example output:
//     Buy milk [Pending]
//     Do homework [Completed]
// -------------------------------------------------------------------
void Task::showTask() {
    std::cout << title;          // Print the task title first
    if (completed)
        std::cout << " [Completed]";  // Task is done
    else
        std::cout << " [Pending]";    // Task is still to-do
    std::cout << std::endl;      // Move to the next line
}
