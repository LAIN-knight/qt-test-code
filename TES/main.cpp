
#include "mainwindow.h"
#include "my_window.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MY_window w;
    w.show();
    return a.exec();
}
