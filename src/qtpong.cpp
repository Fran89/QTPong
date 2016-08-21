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

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(startRound()));

}

QTPong::~QTPong()
{
    delete ui;
    delete myScene;
}

void QTPong::setupGame(){
    p1Paddle = new QGraphicsRectItem; // Create new Rectangle
    p1Paddle->setRect(50,206,20,100); // Placen into pos
    p2Paddle = new QGraphicsRectItem; // Create another Rectangle
    p2Paddle->setRect(974,206,20,100); // Place into pos

    myScene->addRect(0,0,1024,512); // Playing field

    myScene->addItem(p1Paddle); // add rect1 (it's pos is now 0,0 within the scene)
    myScene->addItem(p2Paddle); // add rect2 (likewise)

    ui->graphicsView->setScene(myScene); // Start Scene
}

void QTPong::keyPressEvent(QKeyEvent *key){ // Let's overwrite this protected function
    int currentpos = p1Paddle->y();
    if (key->key() == Qt::Key_2 && currentpos < 204){
            p1Paddle->setY(currentpos+5);
    } else
    if(key->key() == Qt::Key_8 && currentpos > -204){
            p1Paddle->setY(currentpos-5);
    }

}

void QTPong::startRound(){
    ball = new QGraphicsEllipseItem;
    ball->setRect(487,231,50,50);
    myScene->addItem(ball);
}

void QTPong::pointP1(){

}

void QTPong::pointP2(){

}
