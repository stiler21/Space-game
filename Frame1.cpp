#include "Frame1.h"
#include <QPaintEvent>

Frame1::Frame1(int w, int h)
{
    box = new QVBoxLayout();
    Frame1::f1 = new QFrame();
    Frame1::f1->setLineWidth(0);
    Frame1::f1->setFrameShape(QFrame::Shape::NoFrame);
    box->setSpacing(0);
    box->setMargin(0);
    box->addWidget(f1);
    setLayout(box);
    initialize(w, h);
}

void Frame1::initialize(int w, int h) {
    rocket.hr = parameters.getRocketHeight(h);
    rocket.wr = parameters.getRocketWidth(w);
    rocket.xr = parameters.getStartX(w);
    rocket.yr = parameters.getStartY(h);
    parameters.getRocketStep(w);
    parameters.getRocketRatioX(rocket, w);
    parameters.getRocketRatioY(rocket, h);
    engine.init();
    startTimer(10);
    astrs.clear();
}

void Frame1::timerEvent(QTimerEvent *e) {
    if (!engine.game) {
        killTimer(e->timerId());
    }
    timer_id = e->timerId();
    engine.move_asteroid(astrs, f1->geometry().size().height(), f1->width(), f1->geometry().x(), f1->geometry().x() + f1->geometry().width());
    repaint();
}

void Frame1::draw_asteroid() {
    QPainter p;
    p.begin(this);
    for(int i = 0; i < astrs.count(); i++) {
        p.setBrush(astrs.at(i)->color);
        p.drawPolygon(astrs.at(i)->astr);
    }
    p.end();
    for(int i = 0; i < astrs.count(); i++) {
        QPolygon qp = astrs.at(i)->astr.toPolygon();
        if (ggeometry.get_rocket_region(rocket).intersects(ggeometry.get_asteroid_region(qp))) {
            killTimer(timer_id);
            engine.game = false;
        }
    }
}

void Frame1::showStatus(int score) {
    QPainter p;
    QFont font;
    QString str = "Your score is: " + QString::number(score);
    font.setPointSize(14);
    p.begin(this);
    p.setPen(Qt::red);
    p.setFont(font);
    p.drawText(f1->geometry().x() + 5, f1->geometry().y() + f1->geometry().height() - 5, str);
    p.drawText(f1->geometry().x() + 5, f1->geometry().y() + f1->geometry().height() - 25, "Level: " + QString::number(engine.level));
    if (!engine.game) {
        p.drawText(f1->geometry().x() + 5, f1->geometry().y() + f1->geometry().height() - 45, "Press F5 to continue");
    }
    p.end();
}

void Frame1::paintEvent(QPaintEvent *e) {
    paintBackGround();
    paintRocket(rocket.xr, rocket.yr, rocket.wr, rocket.hr);
    draw_asteroid();
    showStatus(engine.score);
}

void Frame1::paintBackGround() {
    QPainter pntr;
    pntr.begin(this);
    pntr.setBrush(Qt::black);
    pntr.drawRect(f1->geometry().left(), f1->geometry().top(), f1->geometry().width(), f1->geometry().height());
    pntr.end();
}

void Frame1::paintRocket(qreal x, qreal y, qreal a, qreal b) {
    QPainter pntr;
    QPolygonF f1,f2;
    QPainterPath p;
    pntr.begin(this);
    pntr.setRenderHint(QPainter::Antialiasing, true);
    //basis

    //right basis
    f1 = ggeometry.get_right_basis(rocket);
    pntr.setBrush(QColor(0, 40, 150));//QColor(140, 20, 20)
    pntr.drawPolygon(f1);
    //left basis
    f2 = ggeometry.get_left_basis(rocket);
    pntr.drawPolygon(f2);
    //rocket
    p.addRegion(ggeometry.get_rocket(rocket));
    pntr.setBrush(QColor(0, 20, 90));//QColor(0, 200, 50)
    pntr.setPen(Qt::NoPen);
    pntr.drawPath(p);
    //rocket window
    pntr.setBrush(QColor(0, 120, 250));//QColor(0, 50, 180)
    pntr.drawEllipse(ggeometry.get_rocket_window(rocket));

    pntr.end();
    parameters.getRocketRatioX(rocket, this->geometry().size().width());
    parameters.getRocketRatioY(rocket, this->geometry().size().height());
}

void Frame1::resizeEvent(QResizeEvent *event) {
    qreal h, w;
    h = f1->geometry().size().height();
    w = f1->geometry().size().width();
    rocket.hr = parameters.getRocketHeight(h);
    rocket.wr = parameters.getRocketWidth(w);
    rocket.xr = parameters.recalculateX(this->geometry().size().width());
    rocket.yr = parameters.recalculateY(this->geometry().size().height());
    parameters.getRocketStep(this->geometry().size().width());
    update();
}

void Frame1::moveRocket(int key) {
    if (engine.game) {
        switch(key) {
            case Qt::Key_Right:
                if (!engine.checkCollisions(rocket,ggeometry,astrs, parameters.rocketStep + engine.stepplus, "right",this->geometry().x(),this->geometry().y(),this->geometry().width(),this->geometry().height())) {
                    if (engine.microStep == -1) {
                        rocket.xr += parameters.rocketStep + engine.stepplus;
                    } else {
                        rocket.xr += engine.microStep;
                    }
                    update();
                }
            break;
            case Qt::Key_Left:
                if (!engine.checkCollisions(rocket,ggeometry,astrs, parameters.rocketStep + engine.stepplus, "left",this->geometry().x(),this->geometry().y(),this->geometry().width(),this->geometry().height())) {
                    if (engine.microStep == -1) {
                        rocket.xr -= parameters.rocketStep + engine.stepplus;
                    } else {
                        rocket.xr -= engine.microStep;
                    }
                    update();
                }
            break;
            case Qt::Key_Up:
                if (!engine.checkCollisions(rocket,ggeometry,astrs, parameters.rocketStep + engine.stepplus, "up",this->geometry().x(),this->geometry().y(),this->geometry().width(),this->geometry().height())) {
                    if (engine.microStep == -1) {
                        rocket.yr -= parameters.rocketStep + engine.stepplus;
                    } else {
                        rocket.yr -= engine.microStep;
                    }
                    update();
                }
            break;
            case Qt::Key_Down:
                if (!engine.checkCollisions(rocket,ggeometry,astrs, parameters.rocketStep + engine.stepplus, "down",this->geometry().x(),this->geometry().y(),this->geometry().width(),this->geometry().height())) {
                    if (engine.microStep == -1) {
                        rocket.yr += parameters.rocketStep + engine.stepplus;
                    } else {
                        rocket.yr += engine.microStep;
                    }
                    update();
                }
            break;
        }
        repaint();
    } else {
        if (key == Qt::Key_F5) {
            engine.game = true;
            initialize(this->width(), this->height());
        }
    }
}
