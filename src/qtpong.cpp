#include "qtpong.h"
#include "ui_qtpong.h"

QTPong::QTPong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTPong)
{
    ui->setupUi(this);
    myScene = new QGraphicsScene;
}

QTPong::~QTPong()
{
    delete ui;
}
