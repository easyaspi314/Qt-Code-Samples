#ifndef GAME_H
#define GAME_H
#include "gameimages.h"
#include <QApplication>
#include <QString>
#include <QTimer>
#include <QWidget>
#include <QQueue>
#include <QThread>

class game : public QObject
{
    Q_OBJECT
public:
    explicit game(QObject *parent = nullptr);
    virtual ~game();
    void initializeGame();
    bool getRunning() const; // Getter for the game state
signals:
    void sendParsedInput(const QString &); // Signal to send input
    void sendImage(const QPixmap &); // Signal to send image
public slots:
    void advance(); // Advance the timer
    void acceptInput(const QString &); // Get the input from the gui
    void returnInput(const QString &); // Send the input to the gui
private slots:
    void returnImage(const QPixmap &); // Send an image to be displayed
private:
    int state;
    void handleMainMenu(const QString &);
    QQueue<QString> userInput;
    gameImages images;
    bool running; // Bool for the game loop to run on
};

#endif // GAME_H
