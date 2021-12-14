#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <QDialog>

namespace Ui {
class InputData;
}

class InputData : public QDialog
{
    Q_OBJECT

public:
    explicit InputData(QWidget *parent = nullptr);
    ~InputData();
    int getNumStars();
    double getSystemRadius();
    double getDistConnect();

private slots:
    void on_pushButtonCancel_clicked();
    void on_pushButtonAccept_clicked();

private:
    Ui::InputData *ui;
};

#endif // INPUTDATA_H
