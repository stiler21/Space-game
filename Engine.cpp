#include "Engine.h"

Engine::Engine()
{
    this->game = true;
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
