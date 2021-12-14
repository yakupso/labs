#include "inputdata.h"
#include "ui_inputdata.h"

InputData::InputData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputData)
{
    ui->setupUi(this);
}

InputData::~InputData()
{
    delete ui;
}

void InputData::on_pushButtonCancel_clicked()
{
    ui->lineNumStars->clear();
    ui->lineSystemRadius->clear();
    ui->lineDistConnect->clear();

    QDialog::reject();
    QWidget::close();
}

void InputData::on_pushButtonAccept_clicked()
{
    QDialog::accept();
    QWidget::close();
}

int InputData::getNumStars()
{
    int numStars;
    if (ui->lineNumStars->text().isEmpty())
        numStars = 0;
    else
        numStars = ui->lineNumStars->text().toInt();
    return numStars;
}

double InputData::getSystemRadius()
{
    double systemRadius;
    if (ui->lineSystemRadius->text().isEmpty())
        systemRadius = 0;
    else
        systemRadius = ui->lineSystemRadius->text().toDouble();
    return systemRadius;

}

double InputData::getDistConnect()
{
    double distConnect;
    if (ui->lineDistConnect->text().isEmpty())
        distConnect = 0;
    else
        distConnect = ui->lineDistConnect->text().toDouble();
    return distConnect;
}

