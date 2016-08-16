#ifndef QTPONG_H
#define QTPONG_H

#include <QMainWindow>

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
};

#endif // QTPONG_H
