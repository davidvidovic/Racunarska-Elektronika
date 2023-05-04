#include "dialog.h"

#include <QApplication>
//#include <wiringPi.h>

int main(int argc, char *argv[])
{
    wiringPiSetup();
    // Prebaciti setup u konstuktor dialoga?
//  softPwmCreate(28, 0, 100);

    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
