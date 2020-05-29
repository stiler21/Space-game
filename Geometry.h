#pragma once

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QtMath>
#include <QPolygonF>
#include <QPolygon>
#include <QPointF>
#include <QRegion>
#include <QRect>
#include "Rocket.h"

class Geometry
{
public:
    Geometry();
    QPolygonF get_asteroid(int x, int y, int d, int type);
    QRegion get_asteroid_region(QPolygon astr);
    QPolygon get_right_basis(Rocket rocket);
    QPolygon get_left_basis(Rocket rocket);
    QRegion get_rocket(Rocket rocket);
    QRect get_rocket_window(Rocket rocket);
    QRegion get_rocket_region(Rocket rocket);
    QPointF get_left_down(Rocket rocket);
    QPointF get_up(Rocket rocket);
    QPointF get_right_down(Rocket rocket);
};

#endif // GEOMETRY_H
