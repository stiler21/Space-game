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
    int dv = 1;
    int dsize = 3;
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
    int getRandomAsteroidsQuantity(int time);
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
