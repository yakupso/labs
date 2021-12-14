#include "mainwindow.h"
#include "inputdata.h"
#include "timeviewer.h"
#include "math.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <sstream>

#include <QPainter>
#include <QTime>
#include <QString>
#include <star.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->pushButtonStart,  SIGNAL(clicked()), this, SLOT(buttonText()));
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
    //connect(timer, &QTimer::timeout, this, QOverload<>::of(&TimeViewer::update));
    //connect(timer, &QTimer::timeout, this, SLOT(myTimer()));
    timer->start(1);
    currentTime.setHMS(0,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter()
{
    if (ui->pushButtonStart->text() == textB[1])
        return true;
    return false;
}

void MainWindow::buttonText()
{
    if (ui->pushButtonStart->text()==textB[0]) {
        ui->pushButtonStart->setText(textB[1]);
        connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
        connect(timer, &QTimer::timeout, this, QOverload<>::of(&TimeViewer::update));
    }
    else {
        ui->pushButtonStart->setText(textB[0]);
        disconnect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
        disconnect(timer, &QTimer::timeout, this, QOverload<>::of(&TimeViewer::update));
    }
    return;
}

const int topX0 = 100, topY0 = 100, height_ = 800, length = 800;
galaxy* galactika = new galaxy(numStars, systemRadius, distConnect);

QString qStringFromLongDouble(const long double myLongDouble)
{
  std::stringstream ss;
  ss << myLongDouble;

  return QString::fromStdString(ss.str());
}

QTime MainWindow::getCurrentTime() {

    return currentTime;
}

void MainWindow::paintEvent(QPaintEvent *e) {
  Q_UNUSED(e);
  QPainter painter(this);
  QPen pen(Qt::black, 1, Qt::SolidLine);
  painter.setPen(pen);

  QTime time = QTime::currentTime();
  int mSec = time.msec();
  int Sec = time.second();

  QBrush brush; //(Qt::yellow);
  brush.setStyle(Qt::SolidPattern);

  double coefX = length / 2 / 1e12; // system lenght
  int centerX = length / 2;
  double coefY = height_ / 2 / 1e12; // system height
  int centerY = height_ / 2;
  for (int i = 0; i < galactika->num; ++i) {
    if (galactika->stars[i]) {
        brush.setColor(galactika->stars[i]->col);
        if (!i) brush.setColor(Qt::yellow);
        painter.setBrush(brush);
        for (int k = 0; k < 2; ++k) {
        // условие не рисовать вне квадрата
        /*if(galactika->stars[i]->x[0] * coefX + centerX + topX0 > 0 &&
            galactika->stars[i]->x[0] * coefX + centerX  < length &&
            galactika->stars[i]->x[1] * coefY + centerY + topY0 > 0 &&
            galactika->stars[i]->x[1] * coefY + centerY  < height_)*/
            painter.drawEllipse(galactika->stars[i]->x[0] * coefX + centerX + topX0,
                                galactika->stars[i]->x[1] * coefY + centerY + topY0,
                                galactika->stars[i]->size, galactika->stars[i]->size);
                                // 6 + 4 * !i, 6 + 4 * !i);
        }
     }
  }
  if (eventFilter()) {
      galactika->move();
      if (TimeViewer::count_tv) {
          //tv->getCurrentTime();
          tv->ViewCurrentTime = time;
      }
  }

      ui->lineEdit->setText(QString::number(star::starCounter));
      ui->lineEdit_2->setText(qStringFromLongDouble(galactika->stars[0]->m));
      ui->lineEdit_3->setText(QString::number(galactika->stars[0]->x[0]));

}

int TimeViewer::count_tv = 0;
void MainWindow::on_pushButtonSeeTime_clicked()
{
    if (TimeViewer::count_tv) {
        tv->show();
    }
    else {
        tv = new TimeViewer(this);
        tv->show();
    }
}

void MainWindow::on_pushButtonOutput_clicked()
{
    std::fstream fout("/Users/yakupso/Desktop/yakupso/qt_proj/starsCreation/output.txt", std::ios::out);
    fout << *galactika;
    fout.close();
}

void MainWindow::on_pushButtonStart_clicked()
{
    if (ui->pushButtonStart->text()==textB[0]) {
        ui->pushButtonStart->setText(textB[1]);
        connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
        connect(timer, &QTimer::timeout, this, QOverload<>::of(&TimeViewer::update));
    }
    else {
        ui->pushButtonStart->setText(textB[0]);
        disconnect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
        disconnect(timer, &QTimer::timeout, this, QOverload<>::of(&TimeViewer::update));
    }
    return;
}

void MainWindow::on_pushButtonInput_clicked()
{
    double systemSet[3];

    std::fstream fin("/Users/yakupso/Desktop/yakupso/qt_proj/starsCreation/input.txt", std::ios::in);
    fin >> systemSet;
    fin.close();

    numStars = systemSet[0];
    systemRadius = systemSet[1];
    distConnect = systemSet[2];
    delete galactika;
    galactika = new galaxy(numStars, systemRadius, distConnect);
}

void MainWindow::on_pushButtonInputManually_clicked()
{
    InputData in;
    in.setModal(true);

    if (in.exec() == QDialog::Accepted) {
        numStars = in.getNumStars();
        systemRadius = in.getSystemRadius();
        distConnect = in.getDistConnect();

        delete galactika;
        galactika = new galaxy(numStars, systemRadius, distConnect);
    }
}
