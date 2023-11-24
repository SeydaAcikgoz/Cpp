#include "dugme.h"

dugme::dugme(QWidget *parent) : QPushButton(parent)
{
    setGeometry(50,50,100,100);
    show();
    connect(this,SIGNAL(clicked(bool)),this,SLOT(konumDegistir()));  //gönderici,sinyal,alıcı,sinyali yakalayacak metot
    //connect:tıklama olayı metota bağlamak için connect yazıldı
    //clicked işlemi gerçekleştikçe buton x ekseninde 20 sağa kayar

}

void dugme::mousePressEvent(QMouseEvent *ev)
{
    ilkKonum=ev->pos();//butonu mouse ile hareket ettirerek yer değiştirme
}

void dugme::mouseMoveEvent(QMouseEvent *ev)
{
    setGeometry(ev->pos().x() - ilkKonum.x()+x(),ev->pos().y()-ilkKonum.y()+y(),width(),height());
}

void dugme::konumDegistir()
{
    //setGeometry(x()+20,y(),width(),height()); aşağıdaki ile aynı
    setGeometry(geometry().x()+20,geometry().y(),width(),height());
}
