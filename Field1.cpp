#include "Field1.h"
#include <QVBoxLayout>

Field1::Field1(int sh, int sw)
{
    this->resize(sw, sh);
    QVBoxLayout *box = new QVBoxLayout();
    f1 = new Frame1(this->width(), this->height());
    f1->resize(this->width(), this->height());
    box->setSpacing(0);
    box->setMargin(0);
    box->addWidget(f1);
    setLayout(box);
}

void Field1::paintEvent(QPaintEvent *event) {

}

void Field1::keyPressEvent(QKeyEvent *event) {
    this->f1->moveRocket(event->key());
}
