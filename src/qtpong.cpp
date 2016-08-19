#include "qtpong.h"
#include "ui_qtpong.h"

QTPong::QTPong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTPong)
{
    ui->setupUi(this);
    myScene = new QGraphicsScene;
    myScene->setSceneRect(0,0,1024,512); // This size is an example one for now
}

QTPong::~QTPong()
{
    delete ui;
    delete myScene;
}

void QTPong::setupGame(){
    p1Paddle = new QGraphicsRectItem;
    p2Paddle = new QGraphicsRectItem;


}
