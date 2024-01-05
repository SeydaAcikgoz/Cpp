#include "mermi.h"
#include <QTimer>
#include "mainwindow.h"
#include <QMessageBox>

mermi::mermi(MainWindow *frm, QWidget *parent) : QPushButton(parent)
{
    anafrm = frm;
    QTimer *zamanlayici = new QTimer(this);
    connect(zamanlayici, SIGNAL(timeout()), this, SLOT(hareketlendir()));
    zamanlayici->start(20);
}

void mermi::hareketlendir()
{
    setGeometry(x(), y() - 5, width(), height());
    anafrm->kontrol(this);
}
