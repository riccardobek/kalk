#include "View/kalk.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Kalk w;
    w.show();

    return a.exec();
}

