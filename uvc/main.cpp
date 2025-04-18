#include "mainwindow.h"
#include "test.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //test_main(0, 0);
    test_iad_main(0,0);
    MainWindow w;
    w.show();
    return a.exec();
}
