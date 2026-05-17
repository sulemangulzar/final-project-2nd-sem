
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// These #include lines bring in Qt's ready-made classes so we can use them.
// Think of them like importing tools from a toolbox — Qt already built these
// widgets for us, so we don't have to write them from scratch.
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include "Planner.h"

// ------------------------------------------------------------------
// INHERITANCE: MainWindow "inherits" from QWidget.
// This means MainWindow IS a QWidget, plus anything extra we add to it.
// Inheritance in OOP means: "take everything the parent class (QWidget) can do,
// and build on top of it." QWidget gives us a blank window for free —
// we just need to fill it with our own buttons, labels, and logic.
// ------------------------------------------------------------------
class MainWindow : public QWidget
{
    // Q_OBJECT is a special Qt macro (a behind-the-scenes code generator).
    // You MUST include this whenever your class uses signals and slots.
    // Without it, Qt won't be able to wire buttons to functions automatically.
    Q_OBJECT

private:
    // This is a Planner OBJECT stored directly inside MainWindow.
    // It lives here as a "member variable" — the window owns one Planner
    // that keeps track of all the tasks. This is called COMPOSITION:
    // one object containing another object to use its features.
    Planner planner;

    // Below are POINTERS (*) to all the visual pieces (widgets) in our window.
    // A pointer holds the MEMORY ADDRESS of an object rather than the object itself.
    // We use pointers here because these widgets are created with "new" (see .cpp),
    // which places them on the HEAP — a separate area of memory that stays alive
    // as long as we need it and is managed by Qt's parent-child system.

    QLabel *titleLabel;      // The big heading text at the top of the window
    QLabel *taskCountLabel;  // A smaller line that shows how many tasks exist
    QLineEdit *taskInput;    // The text box where the user types a new task
    QPushButton *addButton;       // The "Add Task" button
    QPushButton *completeButton;  // The "Mark Completed" button
    QPushButton *deleteButton;    // The "Delete Task" button
    QListWidget *taskList;        // The scrollable list that displays all tasks

public:
    // CONSTRUCTOR: This special function runs automatically the moment you create
    // a MainWindow object. It's responsible for building and arranging everything
    // you see — setting up labels, buttons, the task list, and connecting them together.
    MainWindow();

    // This function redraws the task list on screen.
    // It asks the Planner for the latest tasks and shows them in taskList.
    // We call it every time a task is added, completed, or deleted.
    void refreshTasks();

// SLOTS: In Qt, a "slot" is just a regular function that is allowed to be
// connected to a "signal". Think of it like this:
//   - A SIGNAL is the button shouting "I was clicked!"
//   - A SLOT is the function that hears that shout and responds.
// The connect() calls in MainWindow.cpp wire each button's signal to a slot below.
private slots:
    void addTask();      // Runs when the user clicks the "Add Task" button
    void completeTask(); // Runs when the user clicks the "Mark Completed" button
    void deleteTask();   // Runs when the user clicks the "Delete Task" button
};

#endif
