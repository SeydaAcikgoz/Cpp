#include "hedef.h"
#include "mainwindow.h"

hedef::hedef(QWidget *parent) : QPushButton(parent)
{

}

void hedef::mousePressEvent(QMouseEvent *event)
{
    ilkKonum = event->pos();
}

void hedef::mouseMoveEvent(QMouseEvent *event)
{
    setGeometry(event->x() - ilkKonum.x() + x(),
                event->y() - ilkKonum.y() + y(), width(), height());
}
