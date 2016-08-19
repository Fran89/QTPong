#include "qtpong.h"
#include "ui_qtpong.h"

QTPong::QTPong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTPong)
{
    ui->setupUi(this);
    myScene = new QGraphicsScene;
    myScene->setSceneRect(0,0,1024,512); // This size is an example one for now
    setupGame();
    ui->graphicsView->setScene(myScene);
}

QTPong::~QTPong()
{
    delete ui;
    delete myScene;
}

void QTPong::setupGame(){
    p1Paddle = new QGraphicsRectItem;
    p1Paddle->setRect(50,150,20,100);
    p2Paddle = new QGraphicsRectItem;
    p2Paddle->setRect(974,150,20,100);

    myScene->addItem(p1Paddle);
    myScene->addItem(p2Paddle);

}
