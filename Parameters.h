#pragma once
#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QtMath>
#include <QColor>
#include <QRandomGenerator>
#include "Rocket.h"
#include "Geometry.h"

class Parameters
{
public:
    Parameters();
    const int dv = 1;
    const int dsize = 3;
    const int dstep = 4;
    const int distance_between_rocket_and_wall = 2;
    const int max_dv = 2;
    const int max_dsize = 10;
    const int max_dstep = 30;
    const int max_asteroid_dquantity = 4;
    const int min_asteroid_period = 50;
    const int dasteroid_period = 10;
    int asteroid_period = 80;
    qreal getRocketHeight(int screenHeight);
    qreal getRocketWidth(int screenWidth);
    qreal getStartX(int screenWidth);
    qreal getStartY(int screenHeight);
    qreal recalculateX(int screenWidth);
    qreal recalculateY(int screenHeight);
    QColor generateColor();
    int getRandomX(int x1, int x2);
    void getRocketStep(int screenWidth);
    void getRocketRatioX(Rocket rocket, int screenWidth);
    void getRocketRatioY(Rocket rocket, int screenHeight);
    int getRandomAsteroidsQuantity(int time, int max);
    int getRandomD(int width, int dsize);
    int getRandomX_for8Polygon(int d, int width);
    int getRandomV(int height, int dv);
    int getInitialY_for8Polygon(int d);
    int get_angle(int x, int y, int width, int height);
    qreal rocketStep, rocketRatioX, rocketRatioY;
    Geometry ggeometry;
    QRandomGenerator random;
};

#endif // PARAMETERS_H
