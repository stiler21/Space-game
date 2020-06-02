#include "Asteroid.h"

Asteroid::Asteroid(QPolygonF astr, int x, int y, int d, int v, qreal leftX, qreal rightX, int angle, QColor color)
{
   this->x = x;
   this->y = y;
   this->d = d;
   this->astr = astr;
   this->v = v;
   this->LeftX = leftX;
   this->RightX = rightX;
   this->angle = angle;
   this->color = color;
}
