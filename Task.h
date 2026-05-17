// -------------------------------------------------------------------
// Task.h — The "blueprint" (header file) for a Task object
//
// In C++, a CLASS is like a blueprint or a recipe.
// It describes what data an object holds and what it can do.
// We define the class here in the header (.h) file so that
// any other file in the project can use it.
// -------------------------------------------------------------------

// These two lines are a "header guard".
// They make sure this file is only read once by the compiler,
// even if it is included in multiple places.
#ifndef TASK_H
#define TASK_H

// We include <string> so we can use the std::string type
// to store text (like a task's title).
#include <string>

// -------------------------------------------------------------------
// CLASS: Task
//
// Think of a class as a custom data type that you design yourself.
// A Task object represents a single to-do item.
// Every Task will have:
//   - a title  (the name of the task, e.g. "Buy milk")
//   - a completed flag (whether it is done or not)
// -------------------------------------------------------------------
class Task {

// "public" means everything listed below this keyword can be
// accessed from OUTSIDE the class — for example, from main().
// If something were "private", only the class itself could use it.
public:

    // ---------------------------------------------------------------
    // MEMBER VARIABLES (also called "fields" or "attributes")
    //
    // These are the pieces of data that every Task object stores.
    // Think of them like the columns in a row of a table.
    // ---------------------------------------------------------------

    std::string title;  // The name/description of the task
                        // e.g. "Do homework" or "Buy groceries"

    bool completed;     // A true/false flag that tracks whether the
                        // task is finished.
                        //   true  = task is done
                        //   false = task is still pending

    // ---------------------------------------------------------------
    // CONSTRUCTORS
    //
    // A constructor is a special function that runs automatically
    // when you CREATE a new object from this class.
    // Its job is to set the object up with starting values.
    // It always has the SAME NAME as the class (Task).
    // ---------------------------------------------------------------

    // Constructor 1 — Default constructor (no arguments)
    // Use this when you want to create an empty Task with no title.
    // Example:  Task t;
    Task();

    // Constructor 2 — Parameterized constructor (takes a title)
    // Use this when you already know the task's name at creation time.
    // The "&" means we pass the string by reference (efficient, no copy).
    // The "const" means we promise not to change the string we receive.
    // Example:  Task t("Buy milk");
    Task(const std::string &t);

    // ---------------------------------------------------------------
    // METHODS (also called "member functions")
    //
    // Methods are ACTIONS that a Task object can perform.
    // They are functions that belong to this class.
    // ---------------------------------------------------------------

    // markDone() — marks the task as completed.
    // After calling this, the task's "completed" flag becomes true.
    // Example:  myTask.markDone();
    void markDone();

    // showTask() — prints the task's title and status to the screen.
    // "void" means this function does not return any value.
    // Example:  myTask.showTask();
    void showTask();

};  // <-- Don't forget the semicolon that closes a class definition!

#endif  // End of the header guard
