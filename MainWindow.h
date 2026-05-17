#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include "Planner.h"

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    Planner planner;

    QLabel *titleLabel;
    QLabel *taskCountLabel;
    QLineEdit *taskInput;
    QPushButton *addButton;
    QPushButton *completeButton;
    QPushButton *deleteButton;
    QListWidget *taskList;

public:
    MainWindow();

    void refreshTasks();

private slots:
    void addTask();
    void completeTask();
    void deleteTask();
};

#endif