#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <QVector>
#include <QPolygon>
#include "Asteroid.h"
#include "Geometry.h"
#include "Rocket.h"

class Engine
{
public:
    Engine();
    bool checkCollisions(Rocket rocket, Geometry ggeometry, QVector<Asteroid*> astrs, int d, QString direction, int x, int y, int screenWidth, int screenHeight);
    bool game;
    bool msg;
};

#endif // ENGINE_H
