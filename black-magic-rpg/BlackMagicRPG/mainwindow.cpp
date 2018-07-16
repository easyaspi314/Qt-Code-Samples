#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    // Remove resizability
    this->setFixedSize(QSize(640,480));
    ui->setupUi(this);

    // Focus the input on launch
    QTimer::singleShot(0, ui->input, QOverload<>::of(&QWidget::setFocus));

    game *gameLogic = new game(this);
    // Handle connecting the input and console to the game logic class
    connect(this, &MainWindow::sendInput, gameLogic, &game::acceptInput);
    connect(gameLogic, &game::sendParsedInput, this, &MainWindow::appendToConsole);
    connect(gameLogic, &game::sendImage, this, &MainWindow::changeImage);
    gameLogic->initializeGame();
}

// Destructor
MainWindow::~MainWindow() {
    delete ui;
}

// This slot handles enter being pressed
void MainWindow::on_input_returnPressed() {
    // Make the lowercase text
    emit sendInput(ui->input->text());
    ui->input->clear();
}

// This slot handles appending text to the screen based on what's typed
void MainWindow::appendToConsole(const QString &text) {
    if(text.compare(QLatin1String("clear"), Qt::CaseInsensitive) == 0)
        ui->consoleScreen->clear();
    else
        ui->consoleScreen->append(text);
}

void MainWindow::changeImage(const QPixmap &image) {
    ui->gameStatePic->setPixmap(image);
}
