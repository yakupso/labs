#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

#include "timeviewer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool ellipse = false;
    static bool flag_;
    const QString textB[2] = {"Start", "Stop"};
    QTimer *timer = new QTimer(this);
    QTime currentTime;
    QTime getCurrentTime();

private:
    Ui::MainWindow *ui;
    TimeViewer *tv;
    bool eventFilter();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void buttonText();
    void on_pushButtonSeeTime_clicked();
    void on_pushButtonOutput_clicked();
    void on_pushButtonStart_clicked();
    void on_pushButtonInput_clicked();
    void on_pushButtonInputManually_clicked();
};

#endif // MAINWINDOW_H
