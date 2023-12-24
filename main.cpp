#include "setpath.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SetPath w;
    w.show();
    return a.exec();
}
