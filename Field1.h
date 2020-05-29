#pragma once
#ifndef FIELD1_H
#define FIELD1_H
#include <QWidget>
#include <QRect>
#include <QPainter>
#include <QKeyEvent>
#include "Frame1.h"

class Field1 : public QWidget
{
    public:
        Field1(int sh, int sw);
    private:
        Frame1 *f1;
        void paintEvent(QPaintEvent *event);
    protected:
        void keyPressEvent(QKeyEvent *event);
};

#endif // FIELD1_H
