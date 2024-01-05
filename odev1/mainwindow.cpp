#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sayac = 0;
    ilk = NULL;
    srand(time(NULL));
    int X = 10;
    int Y = 10;
    int resimindis = 0;
    QList<int> resimler;
    QList<int> siralama;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k) {
            resimler.push_back(i);
            siralama.push_back(rand() % 500);
        }
     }
    resimler = sirala(resimler, siralama);
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k) {
            etiket *kart = new etiket(this);
            kart->setGeometry(X, Y, 100, 100);
            kart->anafrm = this;
            kart->resimYukle(resimler[resimindis]);
            kart->show();
            resimindis++;
            Y += 110;
        }
        X += 110;
        Y = 10;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::kontrol(etiket *gelen)
{
    if (ilk == NULL) {
        ilk = gelen;
    } else if (ilk->getSakliResim() == gelen->getSakliResim()) {
        gelen->setBulundu();
        ilk->setBulundu();
        ilk = NULL;
    } else {
        QApplication::processEvents();
        QThread::sleep(1);//1 sn sonra açılanları kapat
        ilk->kapat();
        gelen->kapat();
        ilk = NULL;
        sayac++;
        ui->label_2->setText(QString::number(sayac));//başarısız deneme sayısı
    }
}

QList<int> MainWindow::sirala(QList<int> resimler, QList<int> siralama)
{
    int durum = 0;
    int tmp;
    while (durum == 0) {
        durum = 1;
        for (int i = 0; i < resimler.size() - 1; ++i) {
            if (siralama[i] > siralama[i + 1]) {
                tmp = siralama[i];
                siralama[i] = siralama[i + 1];
                siralama[i + 1] = tmp;
                tmp = resimler[i];
                resimler[i] = resimler[i + 1];
                resimler[i + 1] = tmp;
                durum = 0;
            }
        }//bubble sort ile sıralama ve resimler listesi sıralandı
    }
    return resimler;
}

