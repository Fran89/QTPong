#include "qtpong.h"
#include "ui_qtpong.h"

QTPong::QTPong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTPong)
{
    ui->setupUi(this);
}

QTPong::~QTPong()
{
    delete ui;
}
