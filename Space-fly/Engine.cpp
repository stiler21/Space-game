#include "Engine.h"

Engine::Engine()
{
    this->game = true;
    this->score = 0;
    this->k = 1;
    this->gameTime.start();
    this->ktime.start();
    this->time.start();
    vplus = 0;
    sizeplus = 0;
}

void Engine::init() {
    score = 0;
    vplus = 0;
    sizeplus = 0;
    k = 1;
    gameTime.restart();
    ktime.restart();
}

bool Engine::checkCollisions(Rocket rocket, Geometry ggeometry, QVector<Asteroid*> astrs, int d, QString direction,  int x, int y, int screenWidth, int screenHeight) {
    if ((ggeometry.get_left_down(rocket).x() - d <= x) && (direction == "left")) return true;
    if ((ggeometry.get_right_down(rocket).x() + d >= x + screenWidth) && (direction == "right")) return true;
    if ((ggeometry.get_left_down(rocket).y() + d >= y + screenHeight) && (direction == "down")) return true;
    if ((ggeometry.get_up(rocket).y() - d <= y) && (direction == "up")) return true;

    for(int i = 0; i < astrs.count(); i++) {
        if (astrs.at(i)->y >= 0) {
            QPolygon qp = astrs.at(i)->astr.toPolygon();
            if (ggeometry.get_rocket_region(rocket).intersects(ggeometry.get_asteroid_region(qp))) {
                this->game = false;
                return true;
            }
        }
    }
    return false;
}

void Engine::move_asteroid(QVector<Asteroid *> &astrs, int height, int width, qreal leftX, qreal rightX) {
    if (!this->game)  {
        return;
    }
    if (this->gameTime.elapsed() > 5000) {
        this->score += 1*this->k;
        this->gameTime.restart();
    }
    if (this->ktime.elapsed() > 30000) {
        this->k += 5;
        vplus += parameters.dv;
        sizeplus += parameters.dsize;
        this->ktime.restart();
    }
    if (this->time.elapsed() > 900) {
        this->time.restart();
        int q = parameters.getRandomAsteroidsQuantity(900);
        int x, y, d, v, l;
        for(int i = 0; i < q; i++) {
            d = parameters.getRandomD(width, sizeplus);
            x = parameters.getRandomX_for8Polygon(d, width);
            y = parameters.getInitialY_for8Polygon(d);
            v = parameters.getRandomV(height, vplus);
            l = parameters.get_angle(x, y, width, height);
            astrs.push_back(new Asteroid(ggeometry.get_asteroid(x, y, d, 1), x, y, d, v, ggeometry.get_leftX_for8Polygon(x, d), ggeometry.get_rightX_for8Polygon(x, d), l, parameters.generateColor()));
        }
    }
    for(int i = 0; i < astrs.count(); i++) {
        if ((astrs.at(i)->y < height)&&(astrs.at(i)->LeftX > leftX)&&(astrs.at(i)->RightX < rightX)) {
            astrs.at(i)->y += astrs.at(i)->v;
            if (astrs.at(i)->angle < 0) {
                astrs.at(i)->x -= (astrs.at(i)->v)*tan(-M_PI/180*astrs.at(i)->angle);
            } else {
                astrs.at(i)->x += (astrs.at(i)->v)*tan(M_PI/180*astrs.at(i)->angle);
            }
            astrs.at(i)->LeftX = ggeometry.get_leftX_for8Polygon(astrs.at(i)->x, astrs.at(i)->d);
            astrs.at(i)->RightX = ggeometry.get_rightX_for8Polygon(astrs.at(i)->x, astrs.at(i)->d);
            astrs.at(i)->astr = ggeometry.get_asteroid(astrs.at(i)->x, astrs.at(i)->y, astrs.at(i)->d, 1);
        } else {
            astrs.remove(i);
            int q = parameters.getRandomAsteroidsQuantity(1000);
            int x, y, d, v, l;
            for(int i = 0; i < q; i++) {
                d = parameters.getRandomD(width, sizeplus);
                x = parameters.getRandomX_for8Polygon(d, width);
                y = parameters.getInitialY_for8Polygon(d);
                v = parameters.getRandomV(height, vplus);
                l = parameters.get_angle(x, y, width, height);
                astrs.push_back(new Asteroid(ggeometry.get_asteroid(x, y, d, 1), x, y, d, v, ggeometry.get_leftX_for8Polygon(x, d), ggeometry.get_rightX_for8Polygon(x, d), l, parameters.generateColor()));
            }
        }
    }
}
