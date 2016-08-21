#ifndef QTPONG_H
#define QTPONG_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QLabel>
#include "game.h"

namespace Ui {
class QTPong;
}

class QTPong : public QMainWindow
{
    Q_OBJECT

public:
    explicit QTPong(QWidget *parent = 0);
    ~QTPong();

private:
    Ui::QTPong *ui;
    QGraphicsScene *myScene;
    QGraphicsRectItem *p1Paddle, *p2Paddle;
    QGraphicsEllipseItem *ball;
    QLabel *status;
    Game *game;

    bool inGame;
    bool switchSide;

    void keyPressEvent(QKeyEvent *key);

    void setupGame();

public slots:
    void setStatus(QString);

private slots:

    void startRound();
    void pointP1();
    void pointP2();

};

#endif // QTPONG_H
