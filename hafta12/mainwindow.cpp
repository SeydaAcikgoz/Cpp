#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //database kullanılacak ise pro dosyasına QT       +=sql  satırını ekle

    ui->setupUi(this);
    db=QSqlDatabase::addDatabase("QSQLITE");    //kullanılacak veritabanının tipi
    db.setDatabaseName("C:/qt_kodlari/Hafta12.db");    //kullanılacak veritabanı dosyası

    if(!db.open()){
        QMessageBox::critical(this,"Bağlantı hatası",db.lastError().text());
    }
    sorgu=new QSqlQuery(db);
    model=new QSqlQueryModel();
    listele();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //burada sırayla yazmak önemli
    sorgu->prepare("insert into Ogrenci values(?, ?, ?)");
    sorgu->addBindValue(ui->numara->text());//sorgudaki ? ile yazılmış yerlere sırayla parametre gönderiyoruz
    sorgu->addBindValue(ui->adi->text());
    sorgu->addBindValue(ui->soyadi->text());

    if(!sorgu->exec()){
        QMessageBox::critical(this,"Kayıt ekleme hatası",sorgu->lastError().text());
    }//sorguda hata varsa

    listele();//insert update delete sorgularında listele kullanılır
}

void MainWindow::listele()
{
    sorgu->exec("select * from Ogrenci ");  //sorgu buraya yazılacak
    model->setQuery(*sorgu);    //sorgudan dönen değer modele aktarıldı.Veriler kullanılabilir ama görüntülenemez şuan için
    ui->tableView->setModel(model);
}//insert update delete sorgularında listele kullanılır


void MainWindow::on_aranacak_returnPressed()
{
    sorgu->prepare("select * from Ogrenci where Adi=? or Soyadi=?");//hem adına göre hem de soyadına göre arama yapar
    sorgu->addBindValue(ui->aranacak->text());
    sorgu->addBindValue(ui->aranacak->text());

    if(!sorgu->exec()){
        QMessageBox::critical(this,"Kayıt bulma hatası",sorgu->lastError().text());
    }
    model->setQuery(*sorgu);
    ui->tableView->setModel(model);

}//enter a basıldığında çalışan slot


void MainWindow::on_aranacak_textChanged(const QString &arg1)
{
    //QString a="select *from Ogrenci where Adi like '"+ ui->aranacak->text()+"%'";
    //QMessageBox::information(this,"test",a);
    bool kontrol=sorgu->exec("select *from Ogrenci where Adi like '"+ ui->aranacak->text()+"%'");//değişken kullanmadan sorgu yazıldığı için prepare yerine exec kullandık

    if(!kontrol){
        QMessageBox::critical(this,"Sorgu hatası",sorgu->lastError().text());
    }
    model->setQuery(*sorgu);
    ui->tableView->setModel(model);


}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    //satırlardan herhangi birine tıklanınca label a numarayı yaz
    veri=model->index(index.row(),0).data().toString();//0 dediğimiz için numara geldi
    ui->label_6->setText(veri);



    //listedeki satıra tıklandığında ilgili lineditlere alınan verileri yaz
    ui->numara->setText(model->index(index.row(),0).data().toString());
    ui->adi->setText(model->index(index.row(),1).data().toString());
    ui->soyadi->setText(model->index(index.row(),2).data().toString());
}//table view tıklandığında(parametre de hangi index e tıklandığını verir)


void MainWindow::on_pushButton_2_clicked()
{
    sorgu->prepare("update Ogrenci set numara = ? ,Adi=?,Soyadi=? where numara=?");
    sorgu->addBindValue(ui->numara->text());
    sorgu->addBindValue(ui->adi->text());
    sorgu->addBindValue(ui->soyadi->text());
    sorgu->addBindValue(veri);


    if(!sorgu->exec()){
        QMessageBox::critical(this,"Güncelleme hatası",sorgu->lastError().text());
    }

    listele();
}

