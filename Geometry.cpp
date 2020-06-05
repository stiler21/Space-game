#include "Geometry.h"

Geometry::Geometry()
{

}

QPolygonF Geometry::get_asteroid(int x, int y, int d, int type) {
    QPolygonF astr;
    qreal cx, cy;
    cx = x;
    cy = y;
    astr << QPointF(cx, cy);
    cx += d*sin(M_PI/180*(135/2));
    cy += d*cos(M_PI/180*(135/2));
    astr << QPointF(cx, cy);
    cx += d*cos(M_PI/180*(135/2));
    cy += d*sin(M_PI/180*(135/2));
    astr << QPointF(cx, cy);
    cx -= d*cos(M_PI/180*(135/2));
    cy += d*sin(M_PI/180*(135/2));
    astr << QPointF(cx, cy);
    cx -= d*sin(M_PI/180*(135/2));
    cy += d*cos(M_PI/180*(135/2));
    astr << QPointF(cx, cy);
    cx -= d*sin(M_PI/180*(135/2));
    cy -= d*cos(M_PI/180*(135/2));
    astr << QPointF(cx, cy);
    cx -= d*cos(M_PI/180*(135/2));
    cy -= d*sin(M_PI/180*(135/2));
    astr << QPointF(cx, cy);
    cx += d*cos(M_PI/180*(135/2));
    cy -= d*sin(M_PI/180*(135/2));
    astr << QPointF(cx, cy);
    astr << QPointF(x, y);
    return astr;
}

qreal Geometry::get_rightX_for8Polygon(int x, int d) {
    qreal cx = x;
    cx += d*sin(M_PI/180*(135/2));
    cx += d*cos(M_PI/180*(135/2));
    return cx;
}

qreal Geometry::get_leftX_for8Polygon(int x, int d) {
    qreal cx = x;
    cx += d*sin(M_PI/180*(135/2));
    cx += d*cos(M_PI/180*(135/2));
    cx -= d*sin(M_PI/180*(135/2));
    cx -= d*cos(M_PI/180*(135/2));
    cx -= d*sin(M_PI/180*(135/2));
    cx -= d*cos(M_PI/180*(135/2));
    return cx;
}

QRegion Geometry::get_asteroid_region(QPolygon astr) {
    QRegion reg(astr);
    return reg;
}

QPolygon Geometry::get_right_basis(Rocket rocket) {
    QPolygon f;
    qreal xc, yc, r, xc1, yc1, xr1, yr1;
    r = (pow(rocket.wr,2) + pow(rocket.hr,2)) / (2 * rocket.wr);
    xr1 = rocket.xr - (r - rocket.wr) - r;
    yr1 = rocket.yr - r;
    xc1 = xr1 + r;
    yc1 = yr1 + r;

    yc = rocket.yr + 4*rocket.hr/5;
    xc = xc1 + sqrt(pow(r,2) - pow(yc - yc1,2));
    f << QPoint(xc, yc);
    yc -= rocket.hr/2;
    f << QPoint(xc, yc);
    xc += sin(M_PI*60/180) * (rocket.hr/3);
    yc += cos(M_PI*60/180) * (rocket.hr/3);
    f << QPoint(xc, yc);
    yc += rocket.hr/2;
    f << QPoint(xc, yc);
    yc = rocket.yr + 4*rocket.hr/5;
    xc = xc1 + sqrt(pow(r,2) - pow(yc - yc1,2));
    f << QPoint(xc, yc);
    return f;
}

QPointF Geometry::get_right_down(Rocket rocket) {
    qreal xc, yc, r, xc1, yc1, xr1, yr1;
    r = (pow(rocket.wr,2) + pow(rocket.hr,2)) / (2 * rocket.wr);
    xr1 = rocket.xr - (r - rocket.wr) - r;
    yr1 = rocket.yr - r;
    xc1 = xr1 + r;
    yc1 = yr1 + r;
    yc = rocket.yr + 4*rocket.hr/5;
    xc = xc1 + sqrt(pow(r,2) - pow(yc - yc1,2));
    yc -= rocket.hr/2;
    xc += sin(M_PI*60/180) * (rocket.hr/3);
    yc += cos(M_PI*60/180) * (rocket.hr/3);
    yc += rocket.hr/2;
    return QPointF(xc, yc);
}

QPolygon Geometry::get_left_basis(Rocket rocket) {
    QPolygon f;
    qreal xc, yc, r, xc2, yc2, xr2, yr2;
    r = (pow(rocket.wr,2) + pow(rocket.hr,2)) / (2 * rocket.wr);
    xr2 = rocket.xr - rocket.wr;
    yr2 = rocket.yr - r;
    xc2 = xr2 + r;
    yc2 = yr2 + r;

    yc = rocket.yr + 4*rocket.hr/5;
    xc = xc2 - sqrt(pow(r,2) - pow(yc - yc2,2));
    f << QPoint(xc, yc);
    yc -= rocket.hr/2;
    f << QPoint(xc, yc);
    xc -= sin(M_PI*60/180) * (rocket.hr/3);
    yc += cos(M_PI*60/180) * (rocket.hr/3);
    f << QPoint(xc, yc);
    yc += rocket.hr/2;
    f << QPoint(xc, yc);
    yc = rocket.yr + 4*rocket.hr/5;
    xc = xc2 - sqrt(pow(r,2) - pow(yc - yc2,2));
    f << QPoint(xc, yc);
    return f;
}

QPointF Geometry::get_left_down(Rocket rocket) {
    qreal xc, yc, r, xc2, yc2, xr2, yr2;
    r = (pow(rocket.wr,2) + pow(rocket.hr,2)) / (2 * rocket.wr);
    xr2 = rocket.xr - rocket.wr;
    yr2 = rocket.yr - r;
    xc2 = xr2 + r;
    yc2 = yr2 + r;

    yc = rocket.yr + 4*rocket.hr/5;
    xc = xc2 - sqrt(pow(r,2) - pow(yc - yc2,2));
    yc -= rocket.hr/2;
    xc -= sin(M_PI*60/180) * (rocket.hr/3);
    yc += cos(M_PI*60/180) * (rocket.hr/3);
    yc += rocket.hr/2;
    return QPointF(xc, yc);
}

QRegion Geometry::get_rocket(Rocket rocket) {
    qreal r, xr1, yr1, xr2, yr2;
    QRect *r1, *r2;
    QRegion *reg1, *reg2, reg3;
    r = (pow(rocket.wr,2) + pow(rocket.hr,2)) / (2 * rocket.wr);
    xr1 = rocket.xr - (r - rocket.wr) - r;
    yr1 = rocket.yr - r;
    xr2 = rocket.xr - rocket.wr;
    yr2 = rocket.yr - r;

    r1 = new QRect(xr1, yr1, 2*r, 2*r);
    r2 = new QRect(xr2, yr2, 2*r, 2*r);
    reg1 = new QRegion(*r1, QRegion::Ellipse);
    reg2 = new QRegion(*r2, QRegion::Ellipse);
    reg3 = reg1->intersected(*reg2);
    return reg3;
}

QRect Geometry::get_rocket_window(Rocket rocket) {
    QRect r(rocket.xr - 3*rocket.wr/7, rocket.yr - rocket.hr/2, 6*rocket.wr/7, 6*rocket.wr/7);
    return r;
}

QRegion Geometry::get_rocket_region(Rocket rocketa) {
    QRegion reg, rocket(get_rocket(rocketa)), right_basis(get_right_basis(rocketa)), left_basis(get_left_basis(rocketa));
    reg = rocket.united(right_basis).united(left_basis);
    return reg;
}

QPointF Geometry::get_up(Rocket rocket) {
    return QPointF(rocket.xr, rocket.yr - rocket.hr);
}

qreal Geometry::getLeftAngle(int x, int y, int width, int height) {
    if (y < 0) {
        return qAtan(x/(qFabs(y) + 1*height/3));
    } else {
        return qAtan(x/(1*height/3 - y));
    }
}

qreal Geometry::getRightAngle(int x, int y, int width, int height) {
    if (y < 0) {
        return qAtan((width - x)/(qFabs(y) + 1*height/3));
    } else {
        return qAtan((width - x)/(1*height/3 - y));
    }
}
