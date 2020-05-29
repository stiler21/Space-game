#pragma once
#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QtMath>
#include <QColor>
#include <QRandomGenerator>
#include "Rocket.h"

class Parameters
{
public:
    Parameters();
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
    qreal rocketStep, rocketRatioX, rocketRatioY;
    QRandomGenerator random;
};

#endif // PARAMETERS_H
