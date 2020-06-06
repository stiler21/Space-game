#pragma once
#ifndef FRAME1_H
#define FRAME1_H
#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <QPainterPath>
#include <QFont>
#include <QVBoxLayout>
#include <QColor>
#include <QTimer>
#include <QVector>
#include <QMessageBox>
#include "Asteroid.h"
#include "Geometry.h"
#include "Rocket.h"
#include "Parameters.h"
#include "Engine.h"

class Frame1 : public QWidget
{
    public:
        Frame1(int w, int h);
        void keyPressed();
        void moveRocket(int key);

    protected:
        void timerEvent(QTimerEvent *e);
    private:
        QFrame *f1;
        void paintEvent(QPaintEvent *e);
        void resizeEvent(QResizeEvent *event);
        void paintRocket(qreal x, qreal y, qreal a, qreal b);
        void paintBackGround();
        void draw_asteroid();
        void showStatus(int score = 0);
        void initialize(int w, int h);
        QVBoxLayout *box;
        Asteroid *asteroid;
        int timer_id;
        QVector<Asteroid*> astrs;
        Geometry ggeometry;
        Rocket rocket;
        Parameters parameters;
        Engine engine;
};

#endif // FRAME1_H
