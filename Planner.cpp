#include "Planner.h"
#include <iostream>

// ---------------------------------------------------------------
// CONSTRUCTOR — this runs automatically when you write:
//     Planner myPlanner;
// It sets count to 0, meaning the planner starts completely
// empty with no tasks stored yet.
// ---------------------------------------------------------------
Planner::Planner() {
    count = 0;
}

// ---------------------------------------------------------------
// addTask — adds a new task to the planner.
//
// "title" is the text description of the task you want to add,
// for example "Buy groceries" or "Finish homework".
//
// We first check if there is still room. Remember, our array
// only has 20 slots (positions 0 through 19). If count is less
// than 20, there is still an empty slot we can use.
//
// tasks[count] means "go to the slot at position 'count'".
// Since count starts at 0, the first task goes into slot 0,
// the second into slot 1, and so on.
// After storing the task we increase count by 1 so next time
// the new task goes into the next empty slot.
// ---------------------------------------------------------------
void Planner::addTask(const std::string &title) {
    if (count < 20) {              // Check if we have space
        tasks[count] = Task(title); // Create new task
        count++;                    // Increase task count
    } else {
        std::cout << "Task limit reached!\n";
    }
}

// ---------------------------------------------------------------
// viewAll — prints every task in the list to the screen.
//
// First we check if there are 0 tasks and tell the user if so.
// Otherwise we loop through ALL slots from 0 up to count-1
// and call showTask() on each one to print it.
//
// "i + 1" is used so the numbering shown to the user starts
// at 1 (more natural) even though the array starts at 0.
// ---------------------------------------------------------------
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

// ---------------------------------------------------------------
// editTask — changes the title of an existing task.
//
// "index" is the POSITION (slot number) of the task you want
// to change. Think of it as which drawer to open.
// index 0 = first task, index 1 = second task, etc.
//
// "newTitle" is the new text you want to replace the old one with.
//
// We first make sure the index is valid — it must be 0 or more,
// and it must be less than count (we can't edit a slot that
// doesn't have a task in it yet).
// ---------------------------------------------------------------
void Planner::editTask(int index, const std::string &newTitle) {
    if (index >= 0 && index < count) {
        tasks[index].title = newTitle;
    }
}

// ---------------------------------------------------------------
// deleteTask — completely removes a task from the list.
//
// "index" is the position of the task you want to delete.
//
// You can't just leave an empty hole in the middle of the array,
// so after removing the task we SHIFT every task that came after
// it one position to the left to fill the gap.
// Imagine pulling a book off a shelf and sliding all the other
// books along to close the gap.
//
// Finally we decrease count by 1 because we now have one
// fewer task stored.
// ---------------------------------------------------------------
void Planner::deleteTask(int index) {
    if (index < 0 || index >= count) return; // Invalid index
    
    // Shift all tasks after this one to fill the gap
    for (int i = index; i < count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    count--;
}

// ---------------------------------------------------------------
// markTaskDone — marks a task as completed.
//
// "index" is the position of the task you want to mark as done.
//
// We check that the index is valid, then call markDone() on that
// task. markDone() is a function defined inside the Task class
// that flips the task's status to "completed".
// ---------------------------------------------------------------
void Planner::markTaskDone(int index) {
    if (index >= 0 && index < count) {
        tasks[index].markDone();
    }
}

// ---------------------------------------------------------------
// viewPending — prints only tasks that are NOT yet completed.
//
// We loop through every task. For each one, we check
// tasks[i].completed — if it is FALSE (not done), we print it.
// The "!" symbol means NOT, so "!tasks[i].completed" means
// "this task is NOT completed".
// ---------------------------------------------------------------
void Planner::viewPending() {
    for (int i = 0; i < count; i++) {
        if (!tasks[i].completed) {
            std::cout << i + 1 << ". ";
            tasks[i].showTask();
        }
    }
}

// ---------------------------------------------------------------
// viewCompleted — prints only tasks that ARE completed.
//
// Same idea as viewPending, but this time we only print a task
// if tasks[i].completed is TRUE (meaning it is done).
// ---------------------------------------------------------------
void Planner::viewCompleted() {
    for (int i = 0; i < count; i++) {
        if (tasks[i].completed) {
            std::cout << i + 1 << ". ";
            tasks[i].showTask();
        }
    }
}

// ---------------------------------------------------------------
// getCount — returns how many tasks are currently in the planner.
//
// The "const" at the end is a promise: this function will NOT
// change any data inside the Planner. It only reads and returns
// the value of count. Marking it const makes the code safer and
// clearer about its intentions.
// ---------------------------------------------------------------
int Planner::getCount() const {
    return count;
}

// ---------------------------------------------------------------
// getTaskText — returns the title (text) of a specific task.
//
// "index" is the position of the task you want to look up.
// For example, index 0 gives you the first task's title.
//
// We first make sure the index is valid. If it is out of range
// (too small or too large), we return an empty string instead
// of crashing the program.
//
// "const" at the end means this function only reads — it does
// not change anything inside the Planner.
// ---------------------------------------------------------------
std::string Planner::getTaskText(int index) const {
    if (index >= 0 && index < count) {
        return tasks[index].title;
    }
    return std::string(); // Return empty string if invalid
}

// ---------------------------------------------------------------
// isTaskCompleted — checks whether a specific task is done.
//
// "index" is the position of the task you want to check.
//
// Returns TRUE if that task has been marked as completed,
// or FALSE if it is still pending (or if the index is invalid).
//
// "const" at the end means this function only reads — it does
// not change anything inside the Planner.
// ---------------------------------------------------------------
bool Planner::isTaskCompleted(int index) const {
    if (index >= 0 && index < count) {
        return tasks[index].completed;
    }
    return false;
}
