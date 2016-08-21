#include "qtpong.h"
#include "ui_qtpong.h"

QTPong::QTPong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTPong)
{
    // Setup UI & Hide ToolBar
    ui->setupUi(this);
    ui->mainToolBar->hide();

    // New Staus Bar
    status = new QLabel;
    ui->statusBar->addWidget(status);

    // Create a new Scene (1024X512)
    myScene = new QGraphicsScene;
    myScene->setSceneRect(0,0,1024,512); // This size is an example one for now

    // Setup the Game
    setupGame();

    // Connect Button Start Round
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(startRound()));
}

QTPong::~QTPong()
{
    delete ui;
    delete myScene;
}

// This function sets a string on the status bar
void QTPong::setStatus(QString text){
    status->setText(text);
}

// This function creates the paddles and adds them to the scene
void QTPong::setupGame(){
    p1Paddle = new QGraphicsRectItem; // Create new Rectangle
    p2Paddle = new QGraphicsRectItem; // Create another Rectangle

    p1Paddle->setRect(0,0,20,100); // Placen into pos
    p2Paddle->setRect(0,0,20,100); // Place into pos

    myScene->addItem(p1Paddle); // add rect1
    myScene->addItem(p2Paddle); // add rect2

    p1Paddle->setPos(50,206); // this is the proper way to get scene coordinates
    p2Paddle->setPos(974,206); // ditto

    myScene->addRect(0,0,1024,512); // Playing field

    ui->graphicsView->setScene(myScene); // Start Scene

    inGame = false; // we havent started a round yet

    setStatus("Welcome to Pong"); // welcome message
}

// Handle 8 and 2 on the numberpad, moves the paddles.
void QTPong::keyPressEvent(QKeyEvent *key){
    int currentpos = p1Paddle->y();
    if (key->key() == Qt::Key_2 && p1Paddle->sceneBoundingRect().bottom() < 511.5){
            p1Paddle->setY(currentpos+5);
    } else
    if(key->key() == Qt::Key_8 && p1Paddle->sceneBoundingRect().top() > 0.5){
            p1Paddle->setY(currentpos-5);
    }
}

// Starts a thread that handles the game logic (Game.cpp)
void QTPong::startRound(){
    if(inGame) // don't continue if we are already in a game;
        return;

    // Create a ball
    ball = new QGraphicsEllipseItem;
    ball->setRect(0,0,25,25); // 25 in size
    ball->setPos(487,231);    // place in the middle
    myScene->addItem(ball);   // add it

    // New game round
    game = new Game(p1Paddle,p2Paddle,ball);
    game->start(); // GAME STARTO!

    // We are in game;
    inGame = true;
}

void QTPong::pointP1(){

}

void QTPong::pointP2(){

}
