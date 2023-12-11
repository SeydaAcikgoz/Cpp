#include "dugme.h"
#include "mainwindow.h"

dugme::dugme(MainWindow *frm, QWidget *parent) : QPushButton(parent)
{
    anafrm = frm;
}

void dugme::mouseMoveEvent(QMouseEvent *event)
{
    setGeometry(event->x() - ilkNokta.x() + x(), event->y() - ilkNokta.y() + y(),width(), height());
    anafrm->butonBagla();
}

void dugme::mousePressEvent(QMouseEvent *event)
{
    ilkNokta = event->pos();
}
