#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    softPwmCreate(28, 0, 100);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_horizontalSlider_valueChanged(int value)
{
    softPwmWrite(28, value);
}

