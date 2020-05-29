#include "Parameters.h"

Parameters::Parameters()
{

}

qreal Parameters::getRocketHeight(int screenHeight) {
    return screenHeight/8;
}

qreal Parameters::getRocketWidth(int screenWidth) {
    return screenWidth/55;
}

qreal Parameters::getStartX(int screenWidth) {
    return screenWidth/2;
}

qreal Parameters::getStartY(int screenHeight) {
    return screenHeight - getRocketHeight(screenHeight)*2;
}

void Parameters::getRocketStep(int screenWidth) {
    this->rocketStep = screenWidth/45;
}

void Parameters::getRocketRatioX(Rocket rocket, int screenWidth) {
    this->rocketRatioX = rocket.xr / (screenWidth - rocket.xr);
}

void Parameters::getRocketRatioY(Rocket rocket, int screenHeight) {
    this->rocketRatioY = rocket.yr / (screenHeight - rocket.yr);
}

qreal Parameters::recalculateX(int screenWidth) {
    return this->rocketRatioX*screenWidth/(this->rocketRatioX + 1);
}

qreal Parameters::recalculateY(int screenHeight) {
    return this->rocketRatioY*screenHeight/(this->rocketRatioY + 1);
}

QColor Parameters::generateColor() {
    int r, g, b;
    r = random.global()->bounded(0, 255);
    g = random.global()->bounded(0, 255);
    b = random.global()->bounded(0, 255);
    return QColor(r, g, b);
}

int Parameters::getRandomX(int x1, int x2) {
    return random.global()->bounded(x1, x2);
}
