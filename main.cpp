#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    /*if(Amotnet_init())  return 0;
    if(ring_init())     return 0;
    _mnet_m4_set_pls_iptmode(0, 2, 0, 1, 0);*/

    //check AMOnet card First & pass init error

    w.show();

    return a.exec();
}
