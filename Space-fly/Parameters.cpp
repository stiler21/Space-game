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

int Parameters::getRandomAsteroidsQuantity(int time) {
    if (time == 900) return this->getRandomX(0, 2);
    if (time == 1000) return this->getRandomX(0, 2);
    if (time == 2000) return this->getRandomX(0, 2);
    return 0;
}

int Parameters::getRandomD(int width, int dsize) {
    return getRandomX(width/120 + dsize, width/40 + dsize);
}

int Parameters::getRandomX_for8Polygon(int d, int width) {
    return this->getRandomX(2*d,width - 2*d);
}

int Parameters::getRandomV(int height, int dv) {
    return getRandomX(height/500 + dv, height/300 + dv);
}

int Parameters::getInitialY_for8Polygon(int d) {
    return -2*d;
}

int Parameters::get_angle(int x, int y, int width, int height) {
    int l, b, c;
    l = ggeometry.getLeftAngle(x, y, width, height);
    b = ggeometry.getRightAngle(x, y, width, height);
    c = this->getRandomX(0, l+b);
    if (c <= l) {
        return -l;
    } else {
        return l;
    }
}
