#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include <QListWidgetItem>

MainWindow::MainWindow()
{
    setWindowTitle("Daily Planner Simulator");
    resize(540, 520);

    titleLabel = new QLabel("Daily Planner Simulator");
    QFont titleFont("Segoe UI", 20, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);

    taskCountLabel = new QLabel("No tasks yet");
    taskCountLabel->setAlignment(Qt::AlignCenter);
    taskCountLabel->setStyleSheet("color: #5b6d8f;");

    taskInput = new QLineEdit();
    taskInput->setPlaceholderText("Add a new task...");
    taskInput->setMinimumHeight(42);

    addButton = new QPushButton("Add Task");
    completeButton = new QPushButton("Mark Completed");
    deleteButton = new QPushButton("Delete Task");

    taskList = new QListWidget();
    taskList->setSpacing(6);
    taskList->setStyleSheet(
        "QListWidget { background: white; border: 1px solid #d8dee9; border-radius: 16px; padding: 10px; }"
        "QListWidget::item { padding: 10px; border-radius: 10px; }"
        "QListWidget::item:selected { background: #d7e2ff; color: #1b2f6a; }"
    );

    QFont buttonFont("Segoe UI", 11, QFont::DemiBold);
    addButton->setFont(buttonFont);
    completeButton->setFont(buttonFont);
    deleteButton->setFont(buttonFont);
    addButton->setCursor(Qt::PointingHandCursor);
    completeButton->setCursor(Qt::PointingHandCursor);
    deleteButton->setCursor(Qt::PointingHandCursor);

    setStyleSheet(
        "QWidget { background-color: #eff3fb; }"
        "QLineEdit { background-color: white; border: 1px solid #d8dee9; border-radius: 14px; padding: 12px; }"
        "QPushButton { background-color: #4b7bff; color: white; border: none; border-radius: 14px; min-height: 42px; }"
        "QPushButton:hover { background-color: #3567e6; }"
        "QPushButton:pressed { background-color: #274fb2; }"
    );

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setSpacing(18);
    layout->setContentsMargins(22, 22, 22, 22);
    layout->addWidget(titleLabel);
    layout->addWidget(taskCountLabel);
    layout->addWidget(taskInput);
    layout->addWidget(addButton);
    layout->addWidget(taskList);

    QHBoxLayout *buttons = new QHBoxLayout();
    buttons->setSpacing(14);
    buttons->addWidget(completeButton);
    buttons->addWidget(deleteButton);

    layout->addLayout(buttons);
    setLayout(layout);

    connect(addButton, &QPushButton::clicked,
            this, &MainWindow::addTask);

    connect(completeButton, &QPushButton::clicked,
            this, &MainWindow::completeTask);

    connect(deleteButton, &QPushButton::clicked,
            this, &MainWindow::deleteTask);

    refreshTasks();
}

void MainWindow::addTask()
{
    QString text = taskInput->text().trimmed();

    if (!text.isEmpty()) {
        planner.addTask(text.toStdString());
        taskInput->clear();
        refreshTasks();
    }
}

void MainWindow::completeTask()
{
    int row = taskList->currentRow();

    if (row >= 0) {
        planner.markTaskDone(row);
        refreshTasks();
    }
}

void MainWindow::deleteTask()
{
    int row = taskList->currentRow();

    if (row >= 0) {
        planner.deleteTask(row);
        refreshTasks();
    }
}

void MainWindow::refreshTasks()
{
    taskList->clear();

    int total = planner.getCount();
    taskCountLabel->setText(total == 0 ? "No tasks yet" : QString("%1 task(s) in your planner").arg(total));

    for (int i = 0; i < total; i++) {
        std::string text = planner.getTaskText(i);
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(text));

        if (planner.isTaskCompleted(i)) {
            item->setText(item->text() + "  • Completed");
            item->setForeground(QColor("#6c7488"));
            item->setBackground(QColor("#eef1ff"));
        } else {
            item->setText(item->text() + "  • Pending");
            item->setForeground(QColor("#1c2f61"));
            item->setBackground(QColor("#f7f8ff"));
        }

        item->setFont(QFont("Segoe UI", 11));
        taskList->addItem(item);
    }
}
