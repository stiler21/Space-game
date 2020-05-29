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
        Asteroid(QPolygonF astr, int x, int y, int d, int v, QColor color);
        QPolygonF astr;
        QColor color;
};

#endif // ASTEROID_H
