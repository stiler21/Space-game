#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <QVector>
#include <QPolygon>
#include <QElapsedTimer>
#include "Asteroid.h"
#include "Geometry.h"
#include "Rocket.h"
#include "Parameters.h"

class Engine
{
    public:
        Engine();
        bool checkCollisions(Rocket rocket, Geometry ggeometry, QVector<Asteroid*> astrs, int d, QString direction, int x, int y, int screenWidth, int screenHeight);
        bool game;
        void move_asteroid(QVector<Asteroid*> &astrs, int height, int width, qreal leftX, qreal rightX);
        void init();
        int score;
        int k;
        int vplus;
        int sizeplus;
        int level;
        int microStep;
        int stepplus;
        int asteroidplus;
    private:
        Geometry ggeometry;
        Parameters parameters;
        int time;
        int gameTime;
        int ktime;
};

#endif // ENGINE_H
