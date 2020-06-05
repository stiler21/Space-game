#ifndef ASTEROID_H
#define ASTEROID_H
#include <QTimer>
#include <QPolygonF>
#include <QColor>

class Asteroid : public QObject
{
    protected:
    //void timerEvent(QTimerEvent *e);
    public:
        int x, y, d, v;
        int angle;
        Asteroid(QPolygonF astr, int x, int y, int d, int v, qreal leftX, qreal rightX, int angle, QColor color);
        QPolygonF astr;
        QColor color;
        qreal LeftX, RightX;
};

#endif // ASTEROID_H
