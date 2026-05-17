#ifndef PLANNER_H
#define PLANNER_H

#include <string>
#include "Task.h"

// ---------------------------------------------------------------
// This is a CLASS called Planner.
// Think of a class like a blueprint — just like a blueprint for
// a house describes what rooms it has and what you can do in it,
// this class describes what data a Planner holds and what actions
// it can perform.
//
// The Planner's job is to keep track of a list of tasks for you.
// It can add tasks, show them, edit them, delete them, and more.
// ---------------------------------------------------------------
class Planner {

// ---------------------------------------------------------------
// PRIVATE means "hidden from the outside world."
// Only the code INSIDE this class can read or change these.
// This is called ENCAPSULATION — we protect the data so that
// nobody accidentally breaks it from outside the class.
// Think of it like the engine of a car: you don't need to touch
// it directly, you just use the steering wheel and pedals (the
// public functions below).
// ---------------------------------------------------------------
private:
    // An ARRAY is a fixed-size list of items stored in a row.
    // Here we are storing up to 20 Task objects.
    // Think of it like 20 labeled slots in a drawer — each slot
    // can hold one task, and each slot has a number (0 to 19).
    Task tasks[20];

    // This variable keeps track of HOW MANY tasks have actually
    // been added so far. It starts at 0 and goes up every time
    // a new task is added. We need this because the array always
    // has 20 slots, but we may only be using 3 of them right now.
    int count;

// ---------------------------------------------------------------
// PUBLIC means "anyone can use these."
// These are the actions (functions) that other parts of your
// program are allowed to call. They are the "interface" — the
// buttons and switches on the outside of the machine.
// ---------------------------------------------------------------
public:
    // This is the CONSTRUCTOR. It runs automatically the moment
    // you create a Planner object. Its job is to set up the
    // planner in a clean starting state (empty, with 0 tasks).
    Planner();

    // ---- ADDING TASKS ----

    // Adds a brand new task to the list.
    // You pass in a title (the name/description of the task),
    // and the planner stores it for you.
    void addTask(const std::string &title);

    // ---- VIEWING TASKS ----

    // Prints every single task in the list to the screen,
    // whether it is done or not.
    void viewAll();

    // Prints only the tasks that have NOT been completed yet.
    // Useful when you want to see what you still need to do.
    void viewPending();

    // Prints only the tasks that HAVE been completed.
    // Useful when you want to see what you have already finished.
    void viewCompleted();

    // ---- MODIFYING TASKS ----

    // Changes the title (text) of an existing task.
    // "index" is the POSITION of the task in the array.
    // For example, index 0 means the first task,
    // index 1 means the second task, and so on.
    // "newTitle" is the replacement text you want to give it.
    void editTask(int index, const std::string &newTitle);

    // Removes a task from the list completely.
    // "index" is the position of the task you want to delete.
    // After deleting, the tasks after it slide forward to
    // fill the empty spot — like removing a book from a shelf.
    void deleteTask(int index);

    // Marks a specific task as "done" / completed.
    // "index" is the position of the task you want to mark.
    void markTaskDone(int index);

    // ---- READING INFORMATION (no changes allowed) ----
    // Notice the word "const" at the end of these functions.
    // CONST means "I PROMISE not to change anything."
    // These functions only READ data — they never modify it.
    // This is a safety guarantee for anyone calling them.

    // Returns how many tasks are currently stored in the planner.
    int getCount() const;

    // Returns the title (text) of the task at a given position.
    // "index" is the position in the array (0 = first task).
    // If the index is invalid, it returns an empty string.
    std::string getTaskText(int index) const;

    // Returns true if the task at the given position is completed,
    // or false if it is still pending.
    // "index" is the position of the task you want to check.
    bool isTaskCompleted(int index) const;
};

#endif
