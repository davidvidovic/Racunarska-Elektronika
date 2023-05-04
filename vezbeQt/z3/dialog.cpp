#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    unsigned char led1, led2, led3, led4 = 0;
    digitalWrite(25, led1);
    digitalWrite(26, led2);
    digitalWrite(27, led3);
    digitalWrite(28, led4);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    led1 = ~led1;
    digitalWrite(25, led1);
}


void Dialog::on_pushButton_2_clicked()
{
    led2 = ~led2;
    digitalWrite(26, led2);
}


void Dialog::on_pushButton_3_clicked()
{
    led3 = ~led3;
    digitalWrite(27, led3);
}


void Dialog::on_pushButton_4_clicked()
{
    led4 = ~led4;
    digitalWrite(28, led4);
}

