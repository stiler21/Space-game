
#include <QApplication>
#include "Field1.h"
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize size = qApp->screens()[0]->size();
    int h = size.height();
    int w = size.width();

    Field1 *f1 = new Field1(h, w);
    f1->show();


    return a.exec();
}
