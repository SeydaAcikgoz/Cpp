#include "etiket.h"
#include "mainwindow.h"

etiket::etiket(QWidget *parent) :
    QLabel(parent)
{
    setScaledContents(true);//resmi label a göe yeniden konumlandır
    bulundu = false;
}

void etiket::mousePressEvent(QMouseEvent *event)
{
    if (bulundu) {
        return;
    }
    QImage saklanan(":resim/" + sakliResim + ".png");
    setPixmap(QPixmap::fromImage(saklanan));
    anafrm->kontrol(this);
}

void etiket::setBulundu()
{
    bulundu = true;
}

QString etiket::getSakliResim()
{
    return sakliResim;
}

void etiket::resimYukle(int gelenResim)
{
    QImage kapak(":/resim/kapak.png");
    setPixmap(QPixmap::fromImage(kapak));
    sakliResim = QString::number(gelenResim);
}

void etiket::kapat()
{
    QImage kapak(":/resim/kapak.png");
    setPixmap(QPixmap::fromImage(kapak));
}
