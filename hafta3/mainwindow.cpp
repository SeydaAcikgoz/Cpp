#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->kadin->setChecked(true);    //form açıldığında buton seçili olarak gelir
    ui->bekar->setChecked(true);
    ui->araba->setCheckable(false); //araba seçilemez

    //QLabel *etiket= new QLabel(); ayrı bir form sayfasında açar->parentı yok
    QLabel *etiket= new QLabel(ui->label);   //mainwindow içinde oluşturur->parent ı bu sınıf
    etiket->setGeometry(30,150,100,20);
    etiket->setText("deneme");
    etiket->show();

    int Y=150;

    for(int i=0;i<5;i++){
        QLabel *etiket2= new QLabel(this);
        etiket2->setGeometry(30,Y,100,20);
        etiket2->setText("deneme");
        etiket2->show();
        etiketler.push_back(etiket2);//vektör dizisinin sonuna yer aç ve etiket2 yi ekle
        Y+=30;
    }

    Y=150;
    for(int i=0;i<5;i++){
        QLineEdit *kutu= new QLineEdit(this);
        kutu->setGeometry(150,Y,100,20);
        kutu->setText("0");
        kutu->show();
        editler.push_back(kutu);//vektör dizisinin sonuna yer aç ve editler2 yi ekle
        Y+=30;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString cevap;
    if(ui->erkek->isChecked()){
        cevap=ui->erkek->text();
    }

    if(ui->kadin->isChecked()){
        cevap=ui->kadin->text();
    }
    cevap+="\n";
    if(ui->bekar->isChecked()){
        cevap+=ui->bekar->text();
    }

    if(ui->evli->isChecked()){
        cevap+=ui->evli->text();
    }

    if(ui->ev->isChecked()){
        cevap+="\n"+ui->ev->text();
    }
    if(ui->araba->isChecked()){
        cevap+="\n"+ui->araba->text();
    }
    if(ui->is->isChecked()){
        cevap+="\n"+ui->is->text();
    }
    cevap+="\n";
    ui->label->setText(cevap);
}


void MainWindow::on_pushButton_2_clicked()
{
    int toplam=0;
    for(int i=0;i<editler.size();i++){
        toplam+=editler[i]->text().toInt();
    }
    ui->toplam->setText(QString::number(toplam));
}

