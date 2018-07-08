#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "storytext.h"
#include "gamemessages.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // Make variables to make ui elements easier to work with
    QLineEdit *input;
    QTextEdit *console;
    QLabel *enemiesPic;
    QLabel *gamePic;
    // Make an object for game messages
    gameMessages game;
    // Make an object for the story text
    storyText story;
};

#endif // MAINWINDOW_H
