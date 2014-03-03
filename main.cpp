#include "qdxwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDXWidget w;
    w.init();
    w.show();

    return a.exec();
}
