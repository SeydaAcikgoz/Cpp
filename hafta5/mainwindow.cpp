#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();
    QTimer *zamanlayici = new QTimer(this);
    connect(zamanlayici, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked()));
    zamanlayici->start(500);//her yarım saniyede bir otomatik olarak buton tıklanır ve resim değişir
    etiket *etiketler = new etiket(this, this);
//buradaki son 3 satır olmasa butona tıklandıkça resim değişir
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int sayi = QRandomGenerator::global()->bounded(10);//global sınıfı QRandomGenerator içinde,global içinde de bounded metodu var
    QImage resim(":/res/resimler/"+QString::number(sayi)+".jpg");//resource prefixi olduğunu belirtmek için 2 nokta koyduk
    ui->label->setPixmap(QPixmap::fromImage(resim));//resim label a göre yyeniden düzenlendi
    ui->label_2->setText(QString::number(sayi));//üretilen rastgele sayi ekrana yazıldı
}
//resource den çekilen resimler belirli aralıklarla değişsin
