#include "timeviewer.h"
#include "ui_timeviewer.h"
#include "mainwindow.h"

#include <QTime>
#include <QPainter>

TimeViewer::TimeViewer(QWidget *parent): QDialog(parent), ui(new Ui::TimeViewer)
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&TimeViewer::update));
    timer->start(1);
    ViewCurrentTime.setHMS(0,0,0);
    //ViewCurrentTime = MainWindow::getCurrentTime();
    count_tv++;
}

void TimeViewer::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    //QTime currentTime = QTime::currentTime();
    int mSec = ViewCurrentTime.msec();
    int Sec = ViewCurrentTime.second();
    int Min = ViewCurrentTime.minute();

    ui->minutesLineEdit->setText(QString::number((Min)));
    ui->msecLineEdit->setText(QString::number((mSec)));
    ui->secLineEdit->setText(QString::number(Sec));
}

QTime TimeViewer::getCurrentTime()
{
    ViewCurrentTime = ViewCurrentTime.addMSecs(1);
    return ViewCurrentTime;
}

void TimeViewer::getMainCurrentTime(QTime time) {
    ViewCurrentTime = time;
}

TimeViewer::~TimeViewer()
{

}
