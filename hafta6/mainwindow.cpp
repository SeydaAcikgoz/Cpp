#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter> //çizim işlemleri için kullanılacak kütüphane
#include <QPropertyAnimation>//animasyon ekelemek için

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    kontrol = 0;
    int X = 50;
    showMaximized();
    for (int i = 0; i < 5 ;i++ ) {
        dugme *buton = new dugme(this, this);
        buton->setGeometry(X, 50, 100, 100);
        buton->setText(QString::number(i));
        buton->show();
        X += 150;
        butonlar.push_back(buton);
    }
    butonBagla();
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    noktalar.push_back(event->pos());
    cizgiciz();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (kontrol == 0) {
        ilkNokta = event->pos();
        kontrol++;
    } else {
        ikinciNokta = event->pos();
        kontrol = 0;//artık iki kere tıklanmış olduğu için kontrol 0 lanır,yeniden iki nokta seçilirse yeni çizgi çizilebilir
        cizgi.setPoints(ilkNokta, ikinciNokta);
        cizgiler.push_back(cizgi);
        update();//her şey sıfırlanır
    }
}//EKRANA FARKLI KONUMLARDA İKİ KEZ TIKLANDIĞINDA KONUMLARI DEĞİŞKENDE TUTUP İKİ KOORDİNAT ARASI ÇİZGİ ÇİZME
*/
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter el(this);//mainwindow içinde el değişkeni tanımlandı
    QPen kalem(Qt::black, Qt::SolidLine); //siyah renkte düz bir çizgi çiz
    el.setPen(kalem);//el kalemi kavradı
    //el.drawLine(ilkNokta,ikinciNokta);   tek çizgi çizer yenisi çizilirken ilki silinir
    el.drawLines(cizgiler);//drawLines ile birden fazla çizgi çizilebilir.Bunun için çizgiler vektörde tutulmalı
}

void MainWindow::butonBagla()
{
    cizgiler.clear();
    for (int i = 0; i < butonlar.size() - 1 ; i++ ) {
       cizgi.setLine(butonlar[i]->x() + 50 , butonlar[i]->y() + 50,
                     butonlar[i + 1]->x() + 50, butonlar[i + 1]->y() + 50);
       cizgiler.push_back(cizgi);

    }
    update();
}
/*
void MainWindow::cizgiciz()
{
    cizgiler.clear();
    for (int i = 0; i < noktalar.size() - 1 ; i++ ) {
        cizgi.setPoints(noktalar[i], noktalar[i + 1]);
        cizgiler.push_back(cizgi);
    }
    update();
}
*/




void MainWindow::on_pushButton_clicked()
{
    QPropertyAnimation *animasyon=new QPropertyAnimation(butonlar[1],"geometry");   //1.butonun geometrysi değişecek
    animasyon->setDuration(2000);   //hareketin tamamlanma süresi
    animasyon->setEasingCurve(QEasingCurve::OutElastic);    //hareket ne şekilde olacak
    animasyon->setStartValue(butonlar[1]->geometry());     //hareket nereden başlayacak
    animasyon->setEndValue(butonlar[3]->geometry());     //hareket nerede bitecek
    animasyon->start(); //animasyon başlasın
    ////yukaridakiler 1i 3 ün yerine almak için

    QPropertyAnimation *animasyon2=new QPropertyAnimation(butonlar[3],"geometry");   //1.butonun geometrysi değişecek
    animasyon2->setDuration(2000);   //hareketin tamamlanma süresi
    animasyon2->setEasingCurve(QEasingCurve::OutElastic);    //hareket ne şekilde olacak
    animasyon2->setStartValue(butonlar[3]->geometry());     //hareket nereden başlayacak
    animasyon2->setEndValue(butonlar[1]->geometry());     //hareket nerede bitecek
    animasyon2->start(); //animasyon başlasın

    ////buradakiler 3ü 1in yerine koymak için
}// butona basılınca 1. ve 3. butonu yer değiştir

