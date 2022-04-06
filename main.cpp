#include "samplerwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SamplerWindow w;
    w.show();
    return a.exec();
}
