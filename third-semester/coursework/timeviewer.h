#ifndef TIMEVIEWER_H
#define TIMEVIEWER_H

//#include "mainwindow.h"

#include <QDialog>
#include <QTimer>
#include <QTime>

namespace Ui {
class TimeViewer;
}

class TimeViewer : public QDialog
{
    Q_OBJECT

public:
    static int count_tv;
    explicit TimeViewer(QWidget *parent = nullptr);
    QTimer *timer = new QTimer(this);
    QTime ViewCurrentTime;

    QTime getCurrentTime();
    void getMainCurrentTime(QTime time);

    void update_time();
    void paintEvent(QPaintEvent *event);
    ~TimeViewer();

private:
    Ui::TimeViewer *ui;
};

#endif // TIMEVIEWER_H
