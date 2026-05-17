
#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include <QListWidgetItem>

// ------------------------------------------------------------------
// CONSTRUCTOR — MainWindow::MainWindow()
// This function runs automatically when "MainWindow window;" is written in main.cpp.
// Its job is to build everything the user will see: labels, input boxes,
// buttons, and the task list — and then arrange and connect them all.
// ------------------------------------------------------------------
MainWindow::MainWindow()
{
    setWindowTitle("Daily Planner Simulator");
    resize(540, 520);

    // "new" creates a QLabel OBJECT on the HEAP (a region of memory that
    // persists until we're done with it). The result is a POINTER — an arrow
    // that tells us WHERE in memory the label lives.
    // We store that arrow in titleLabel so we can reach the object later.
    titleLabel = new QLabel("Daily Planner Simulator");
    QFont titleFont("Segoe UI", 20, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);

    // Same idea: "new" makes a QLabel on the heap and we keep its pointer.
    // The -> arrow lets us call methods on an object through a pointer.
    // (If it weren't a pointer, we'd use a dot "." instead.)
    taskCountLabel = new QLabel("No tasks yet");
    taskCountLabel->setAlignment(Qt::AlignCenter);
    taskCountLabel->setStyleSheet("color: #5b6d8f;");

    // QLineEdit is the text box. "new" allocates it on the heap.
    // setPlaceholderText shows faint grey hint text when the box is empty.
    taskInput = new QLineEdit();
    taskInput->setPlaceholderText("Add a new task...");
    taskInput->setMinimumHeight(42);

    // Create the three button objects on the heap.
    // Each QPushButton gets a label string shown on the button face.
    addButton = new QPushButton("Add Task");
    completeButton = new QPushButton("Mark Completed");
    deleteButton = new QPushButton("Delete Task");

    // QListWidget is the scrollable box that shows all our tasks.
    // setSpacing adds a little breathing room between each task row.
    taskList = new QListWidget();
    taskList->setSpacing(6);
    taskList->setStyleSheet(
        "QListWidget { background: white; border: 1px solid #d8dee9; border-radius: 16px; padding: 10px; }"
        "QListWidget::item { padding: 10px; border-radius: 10px; }"
        "QListWidget::item:selected { background: #d7e2ff; color: #1b2f6a; }"
    );

    // Give all three buttons the same font style so they look consistent.
    QFont buttonFont("Segoe UI", 11, QFont::DemiBold);
    addButton->setFont(buttonFont);
    completeButton->setFont(buttonFont);
    deleteButton->setFont(buttonFont);
    // PointingHandCursor changes the mouse cursor to a hand when hovering a button,
    // which is a common visual hint that something is clickable.
    addButton->setCursor(Qt::PointingHandCursor);
    completeButton->setCursor(Qt::PointingHandCursor);
    deleteButton->setCursor(Qt::PointingHandCursor);

    // setStyleSheet applies CSS-like rules to control colors, borders, and shapes.
    // This one rule applies to the whole window and every widget inside it.
    setStyleSheet(
        "QWidget { background-color: #eff3fb; }"
        "QLineEdit { background-color: white; border: 1px solid #d8dee9; border-radius: 14px; padding: 12px; }"
        "QPushButton { background-color: #4b7bff; color: white; border: none; border-radius: 14px; min-height: 42px; }"
        "QPushButton:hover { background-color: #3567e6; }"
        "QPushButton:pressed { background-color: #274fb2; }"
    );

    // ------------------------------------------------------------------
    // LAYOUT — How widgets are arranged on screen.
    // Instead of placing every widget at an exact pixel position,
    // Qt uses LAYOUT objects that arrange widgets automatically.
    // QVBoxLayout stacks widgets vertically (top to bottom), like a list.
    // "new" creates it on the heap; setSpacing and setContentsMargins
    // control the gaps between widgets and the padding around the edges.
    // ------------------------------------------------------------------
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setSpacing(18);
    layout->setContentsMargins(22, 22, 22, 22);
    layout->addWidget(titleLabel);
    layout->addWidget(taskCountLabel);
    layout->addWidget(taskInput);
    layout->addWidget(addButton);
    layout->addWidget(taskList);

    // QHBoxLayout arranges widgets horizontally (side by side).
    // We use it to place the "Mark Completed" and "Delete Task" buttons
    // next to each other in one row at the bottom of the window.
    QHBoxLayout *buttons = new QHBoxLayout();
    buttons->setSpacing(14);
    buttons->addWidget(completeButton);
    buttons->addWidget(deleteButton);

    // Nest the horizontal button row inside the main vertical layout,
    // then hand the finished layout to the window with setLayout().
    layout->addLayout(buttons);
    setLayout(layout);

    // ------------------------------------------------------------------
    // SIGNALS & SLOTS — How buttons talk to functions.
    // connect() is Qt's way of saying "when THIS signal fires, call THAT slot."
    //
    // Format:  connect( sender,  &SenderClass::signalName,
    //                   receiver, &ReceiverClass::slotName );
    //
    // QPushButton::clicked is a SIGNAL — it fires automatically the moment
    // the button is pressed. addTask / completeTask / deleteTask are SLOTS —
    // plain member functions that get called in response.
    // "this" refers to the current MainWindow object (the receiver).
    // ------------------------------------------------------------------

    // Wire addButton: clicking it calls our addTask() function.
    connect(addButton, &QPushButton::clicked,
            this, &MainWindow::addTask);

    // Wire completeButton: clicking it calls our completeTask() function.
    connect(completeButton, &QPushButton::clicked,
            this, &MainWindow::completeTask);

    // Wire deleteButton: clicking it calls our deleteTask() function.
    connect(deleteButton, &QPushButton::clicked,
            this, &MainWindow::deleteTask);

    // Show the task list right away (it will be empty at first).
    refreshTasks();
}

// ------------------------------------------------------------------
// SLOT: addTask()
// Qt calls this function automatically when the user clicks "Add Task".
// It reads whatever text the user typed, passes it to the Planner object,
// clears the input box, and refreshes the on-screen list.
// ------------------------------------------------------------------
void MainWindow::addTask()
{
    // taskInput->text() reads the string currently in the text box.
    // trimmed() removes any leading or trailing spaces the user may have typed.
    QString text = taskInput->text().trimmed();

    // Only add the task if the user actually typed something.
    if (!text.isEmpty()) {
        planner.addTask(text.toStdString()); // toStdString() converts Qt's QString
                                             // to a plain C++ std::string for the Planner.
        taskInput->clear();                  // Wipe the text box so it's ready for the next task.
        refreshTasks();                      // Redraw the list so the new task appears instantly.
    }
}

// ------------------------------------------------------------------
// SLOT: completeTask()
// Qt calls this function automatically when the user clicks "Mark Completed".
// It finds out which task is highlighted, then tells the Planner to mark it done.
// ------------------------------------------------------------------
void MainWindow::completeTask()
{
    // currentRow() returns the index (position number) of the highlighted task.
    // Row 0 is the first task, row 1 is the second, and so on.
    // If nothing is selected, currentRow() returns -1.
    int row = taskList->currentRow();

    // Only proceed if a task is actually selected (row must be 0 or higher).
    if (row >= 0) {
        planner.markTaskDone(row);  // Tell the Planner object to mark that task as done.
        refreshTasks();             // Redraw the list so the checkmark / "Completed" text appears.
    }
}

// ------------------------------------------------------------------
// SLOT: deleteTask()
// Qt calls this function automatically when the user clicks "Delete Task".
// It finds out which task is highlighted, then tells the Planner to remove it.
// ------------------------------------------------------------------
void MainWindow::deleteTask()
{
    // currentRow() returns the index of the highlighted task, or -1 if none selected.
    int row = taskList->currentRow();

    // Only proceed if a task is actually selected.
    if (row >= 0) {
        planner.deleteTask(row);    // Tell the Planner object to erase that task.
        refreshTasks();             // Redraw the list so the deleted task disappears.
    }
}

// ------------------------------------------------------------------
// refreshTasks()
// This function syncs the on-screen list with whatever is stored in the Planner.
// It is called after every change (add, complete, delete) to keep the display current.
// ------------------------------------------------------------------
void MainWindow::refreshTasks()
{
    taskList->clear();  // Wipe everything currently shown in the list widget.

    // Ask the Planner how many tasks it currently holds.
    int total = planner.getCount();
    
    // Update the small count label near the top.
    // If there are no tasks we show a friendly message; otherwise show the count.
    if (total == 0) {
        taskCountLabel->setText("No tasks yet");
    } else {
        taskCountLabel->setText(QString("%1 task(s) in your planner").arg(total));
    }

    // Loop through every task the Planner knows about and add it to the list widget.
    // "i" is the index — it starts at 0 (the first task) and counts up.
    for (int i = 0; i < total; i++) {
        // Fetch the task's text from the Planner using its index.
        std::string text = planner.getTaskText(i);

        // "new" creates a QListWidgetItem on the heap — one visual row in the list.
        // fromStdString() converts the C++ std::string back into a Qt QString for display.
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(text));

        // Check whether this task has been marked done and style it differently.
        // Completed tasks get muted colours; pending tasks get bold blue colours.
        if (planner.isTaskCompleted(i)) {
            item->setText(item->text() + "  • Completed");
            item->setForeground(QColor("#6c7488"));
            item->setBackground(QColor("#eef1ff"));
        } else {
            item->setText(item->text() + "  • Pending");
            item->setForeground(QColor("#1c2f61"));
            item->setBackground(QColor("#f7f8ff"));
        }

        // Apply a consistent font to every row, then insert it into the list widget.
        item->setFont(QFont("Segoe UI", 11));
        taskList->addItem(item);  // addItem() hands ownership of the item to taskList.
    }
}
