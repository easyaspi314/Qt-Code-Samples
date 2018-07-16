#include "gameimages.h"

gameImages::gameImages() {
    mainMenuLogo.load(QStringLiteral(":/images/logoConverted.png")); // Main screen logo
    newGameImage.load(QStringLiteral(":/images/city.png")); // Set the path for the city image in resources
}

const QPixmap &gameImages::getMainMenuLogo() const {
    return mainMenuLogo;
}

const QPixmap &gameImages::getNewGameImage() const {
    return newGameImage;
}
