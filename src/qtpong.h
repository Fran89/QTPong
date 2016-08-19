#ifndef QTPONG_H
#define QTPONG_H

#include <QMainWindow>
#include <QGraphicsScene>

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

    void setupGame();
};

#endif // QTPONG_H
