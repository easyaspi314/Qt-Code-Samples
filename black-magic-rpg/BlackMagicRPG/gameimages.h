#ifndef GAMEIMAGES_H
#define GAMEIMAGES_H
#include <QPixmap>

class gameImages {
public:
    gameImages();
    const QPixmap &getMainMenuLogo() const;
    const QPixmap &getNewGameImage() const;
private:
    QPixmap mainMenuLogo;
    QPixmap newGameImage;
};

#endif // GAMEIMAGES_H
