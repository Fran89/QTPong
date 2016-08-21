#ifndef GAME_H
#define GAME_H
#include <QThread>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QPointF>


class Game : public QThread
{
    Q_OBJECT
public:
    Game(QGraphicsRectItem * PP1, QGraphicsRectItem * PP2, QGraphicsEllipseItem * B);

private:
    QGraphicsRectItem * P1;
    QGraphicsRectItem * P2;
    QGraphicsEllipseItem * ball;

    bool point;
    bool UD;
    bool LR;

    void run();
    void swSide();   // switch the ball direction X axis
    void swUpDown(); // switch the ball direction Y axis

signals:

};

#endif // GAME_H
