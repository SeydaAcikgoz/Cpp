#include "ordek.h"
#include <QRandomGenerator>
#include "mainwindow.h"
#include <QThread>
#include <QMessageBox>


ordek::ordek(MainWindow *frm, QWidget *parent) : QLabel(parent)
{
    hareketZamanlayici = new QTimer(this);
    yoketZamanlayici = new QTimer(this);
    connect(hareketZamanlayici, SIGNAL(timeout()), this, SLOT(hareketlendir()));
    connect(yoketZamanlayici, SIGNAL(timeout()), this, SLOT(yoket()));
    anafrm = frm;
    prnt = parent;
    setGeometry(QRandomGenerator::global()->bounded(parent->size().width()), 5, 30, 30);
    setScaledContents(true);
    QImage ordekresmi(":/res/ordek.png");
    setPixmap(QPixmap::fromImage(ordekresmi));
    show();
    hareketZamanlayici->start(100);
}

ordek::~ordek()
{
    delete yoketZamanlayici;
    delete hareketZamanlayici;
}

void ordek::hareketlendir()
{
    setGeometry(x(), y() + 5, width(), height());
    kacanKontrol();
}

void ordek::yoket()
{
    delete this;
}

void ordek::mousePressEvent(QMouseEvent *event)
{
    hareketZamanlayici->stop();
    QImage vurulma(":/res/vurulma.png");
    setPixmap(QPixmap::fromImage(vurulma));
    anafrm->vurulaniEkranaBas();
    yoketZamanlayici->start(200);

}

void ordek::kacanKontrol()
{    
    if (y() > prnt->size().height()) {
        anafrm->kacaniEkranaBas();
        delete this;
    }
}
