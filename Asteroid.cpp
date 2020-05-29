#include "Asteroid.h"

Asteroid::Asteroid(QPolygonF astr, int x, int y, int d, int v, QColor color)
{
   this->x = x;
   this->y = y;
   this->d = d;
   this->astr = astr;
   this->v = v;
   this->color = color;
}

/*
void Asteroid::timerEvent(QTimerEvent *e) {
    this->x = x;
    if (this->y < 700) {
        this->y += 10;
    } else {
        this->y = 20;
    }
}
*/
