#include "Engine.h"

Engine::Engine()
{
    this->game = true;
    this->score = 0;
    this->k = 1;
    gameTime = 0;
    ktime = 0;
    time = 0;
    vplus = 0;
    sizeplus = 0;
    stepplus = 0;
    level = 1;
    asteroidplus = 2;
}

void Engine::init() {
    score = 0;
    vplus = 0;
    sizeplus = 0;
    stepplus = 0;
    k = 1;
    level = 1;
    asteroidplus = 2;
    gameTime = 0;
    ktime = 0;
    time = 0;
}

bool Engine::checkCollisions(Rocket rocket, Geometry ggeometry, QVector<Asteroid*> astrs, int d, QString direction,  int x, int y, int screenWidth, int screenHeight) {
    microStep = -1;
    if ((ggeometry.get_left_down(rocket).x() - d <= x) && (direction == "left")) {
         if ((ggeometry.get_left_down(rocket).x() - x) < parameters.distance_between_rocket_and_wall) {
             return true;
         } else {
             microStep = ggeometry.get_left_down(rocket).x() - x - parameters.distance_between_rocket_and_wall;
         }
    }
    if ((ggeometry.get_right_down(rocket).x() + d >= x + screenWidth) && (direction == "right")) {
        if ((x + screenWidth - ggeometry.get_right_down(rocket).x()) < parameters.distance_between_rocket_and_wall) {
            return true;
        } else {
            microStep = x + screenWidth - ggeometry.get_right_down(rocket).x() - parameters.distance_between_rocket_and_wall;
        }
    }
    if ((ggeometry.get_left_down(rocket).y() + d >= y + screenHeight) && (direction == "down")) {
        if ((y + screenHeight - ggeometry.get_left_down(rocket).y()) < parameters.distance_between_rocket_and_wall) {
            return true;
        } else {
            microStep = y + screenHeight - ggeometry.get_left_down(rocket).y() - parameters.distance_between_rocket_and_wall;
        }
    }
    if ((ggeometry.get_up(rocket).y() - d <= y) && (direction == "up")) {
        if ((ggeometry.get_up(rocket).y() - y) < parameters.distance_between_rocket_and_wall) {
            return true;
        } else {
            microStep = ggeometry.get_up(rocket).y() - y - parameters.distance_between_rocket_and_wall;
        }
    }

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
    if (gameTime > 500) {
        this->score += 1*this->k;
        gameTime = 0;
    } else {
        gameTime++;
    }
    if (ktime > 3000) {
        level++;
        this->k += 5;
        if (vplus < parameters.max_dv) {
            vplus += parameters.dv;
        } else {
            if (asteroidplus < parameters.max_asteroid_dquantity) {
                asteroidplus++;
            } else {
                if (parameters.asteroid_period > parameters.min_asteroid_period) {
                    parameters.asteroid_period -= parameters.dasteroid_period;
                }
            }
        }
        if (sizeplus < parameters.max_dsize) {
            sizeplus += parameters.dsize;
        }
        if (stepplus < parameters.max_dstep) {
            stepplus += parameters.dstep;
        }
        ktime = 0;
    } else {
        ktime++;
    }
    if (time > parameters.asteroid_period) {
        time = 0;
        int q = parameters.getRandomAsteroidsQuantity(800, asteroidplus);
        int x, y, d, v;
        int l;
        for(int i = 0; i < q; i++) {
            d = parameters.getRandomD(width, sizeplus);
            x = parameters.getRandomX_for8Polygon(d, width);
            y = parameters.getInitialY_for8Polygon(d);
            v = parameters.getRandomV(height, vplus);
            l = parameters.get_angle(x, y, width, height);
            astrs.push_back(new Asteroid(ggeometry.get_asteroid(x, y, d, 1), x, y, d, v, ggeometry.get_leftX_for8Polygon(x, d), ggeometry.get_rightX_for8Polygon(x, d), l, parameters.generateColor()));
        }
    } else {
        time++;
    }
    for(int i = 0; i < astrs.count(); i++) {
        if ((astrs.at(i)->y < height)&&(astrs.at(i)->LeftX > leftX)&&(astrs.at(i)->RightX < rightX)) {
            astrs.at(i)->y += astrs.at(i)->v;
            if (astrs.at(i)->angle < 0) {
                astrs.at(i)->x -= (astrs.at(i)->v)*qTan(-M_PI/180*astrs.at(i)->angle);
            } else {
                astrs.at(i)->x += (astrs.at(i)->v)*qTan(M_PI/180*astrs.at(i)->angle);
            }
            astrs.at(i)->LeftX = ggeometry.get_leftX_for8Polygon(astrs.at(i)->x, astrs.at(i)->d);
            astrs.at(i)->RightX = ggeometry.get_rightX_for8Polygon(astrs.at(i)->x, astrs.at(i)->d);
            astrs.at(i)->astr = ggeometry.get_asteroid(astrs.at(i)->x, astrs.at(i)->y, astrs.at(i)->d, 1);
        } else {
            astrs.remove(i);
        }
    }
}
