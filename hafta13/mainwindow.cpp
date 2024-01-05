#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Sql sorguları ile yapabileceğimiz işlemleri farklı yöntemle yapma

    db=QSqlDatabase::addDatabase("QSQLITE");    //kullanılacak veritabanının tipi
    db.setDatabaseName("C:/qt_kodlari/Hafta12.db");    //kullanılacak veritabanı dosyası

    if(!db.open()){
        QMessageBox::critical(this,"Bağlantı hatası",db.lastError().text());
    }

    tablemodel=new QSqlTableModel();
    tablemodel->setTable("Ogrenci"); //değişkenin üzerinde çalışacağı tablo
    tablemodel->select();   //şartsız seçme sorgusu
    ui->tableView->setModel(tablemodel);    //sorgu sonucunu ekrana yazma

    ogrenciler=new QSqlQuery(db);
    ogrmodel = new QSqlQueryModel();
    ogrenciler->exec("select * from Ogrenci");
    ogrmodel->setQuery(*ogrenciler);
    ui->tableView_2->setModel(ogrmodel);

    notlari  = new QSqlQuery(db);
    notlarmodel = new QSqlQueryModel();








}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //tablemodel->insertRow(2);    //kaçıncı sıraya eklenecekse parametre olarak verilir(hangi satıra eklersen ekle databasede son satıra eklenir)
    tablemodel->insertRow(tablemodel->rowCount());  //tablo sonuna satır ekler
    //tablemodel->insertRow(ui->tableView->model()->rowCount());->bu da tablo sonuna satır ekler
}


void MainWindow::on_pushButton_2_clicked()
{
    //tablemodel->setFilter("numara = "+ui->lineEdit->text());    //linedit e yazılan numaraya ait satırı göster
    //tablemodel->setFilter("Adi = "+ui->lineEdit->text());

    if(ui->lineEdit->text().isEmpty()){
        //QMessageBox::critical(this,"Bağlantı hatası","db.lastError().text()");
        tablemodel->select();
        ui->tableView->setModel(tablemodel);
    }else{
        tablemodel->setFilter("Adi = '" + ui->lineEdit->text()+"'");
    }

}


void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{

    numara=ogrmodel->index(index.row(),0).data().toString();//0 dediğimiz için numara geldi

    notlari->prepare("select * from Notlar where numara = ?");
    notlari->addBindValue(numara);
    notlari->exec();
    notlarmodel->setQuery(*notlari);
    ui->tableView_3->setModel(notlarmodel);

}


void MainWindow::on_Notlarikaydet_clicked()
{
    notlari->prepare("insert into Notlar values(?,?,?,?,?)");
    notlari->addBindValue(numara);
    notlari->addBindValue(ui->dersKodu->text());
    notlari->addBindValue(ui->Vize->text());
    notlari->addBindValue(ui->Finali->text());
    notlari->addBindValue(QString::number(
                              ui->Vize->text().toInt() * 0.4 + ui->Finali->text().toInt() * 0.6
                              ));
    notlari->exec();
    //veri çekiyorsak model ile db arasında ilişki kurulmalı ama insert update de gerek yoktur

    notListele();


}

void MainWindow::notListele()
{
    notlari->prepare("select * from Notlar where numara = ?");
    notlari->addBindValue(numara);
    notlari->exec();
    notlarmodel->setQuery(*notlari);
    ui->tableView_3->setModel(notlarmodel);
}

