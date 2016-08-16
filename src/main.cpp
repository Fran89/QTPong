#include "qtpong.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTPong w;
    w.show();

    return a.exec();
}
