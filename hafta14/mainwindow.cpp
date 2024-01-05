#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db=QSqlDatabase::addDatabase("QSQLITE");    //kullanılacak veritabanının tipi
    db.setDatabaseName("C:/qt_kodlari/Hafta12.db");    //kullanılacak veritabanı dosyası

    if(!db.open()){
        QMessageBox::critical(this,"Bağlantı hatası",db.lastError().text());
    }
    sorgu=new QSqlQuery(db);
    model=new QSqlQueryModel;
    sorguliste=new QSqlQuery(db);
    modelliste=new QSqlQueryModel;
    sorgu->exec("Select distinct sinifi from Ogrenci");
    model->setQuery(*sorgu);
    QStringList itemler;

    for(int i=0;i<model->rowCount();i++){
       itemler << model->index(i,0).data().toString();
    }//sorgu ile sınıfları çektik
    ui->comboBox->addItems(itemler);    //comnobox a sınıfların olduğu listeyi gönderdik


/*
    for(int i=0;i<4;i++){
        QLineEdit *edit=new QLineEdit();
        ui->tableWidget->setCellWidget(i,3,edit);   //tablewidgetın hücresine lineedit ı koyduk(satır,sütün,eklenecek widget)
    }
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int toplam = 0;
    for(int i=0;i<4;i++){
        QLineEdit *ed=(QLineEdit*) ui->tableWidget->cellWidget(i,3);    //tablewidgetın ilgili hücresindeki lineeditı aldık
        toplam += ed->text().toInt();
    }
    ui->label->setText(QString::number(toplam));
}   //lineditın içindeki sayıları topla ve labela yaz


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    sorguliste->prepare("select numara,Adi,Soyadi from Ogrenci where sinifi=?");
    sorguliste->addBindValue(arg1);//arg1->comboboxtaki seçilen olan sınıfı getirir
    sorguliste->exec();
    modelliste->setQuery(*sorguliste);
    ui->tableWidget->setRowCount(modelliste->rowCount());    //tablewidget in satır sayısı

    ui->tableWidget->setColumnCount(5);     //tablewidget in sütun sayısı

    QStringList baslik;
    //QStringList baslik={ "Numarası","Adı","Soyadı" ,"Vizesi"} böyle de başlık listesi oluşturabiliriz
    baslik << "Numarası" << "Adı" << "Soyadı" << "Vizesi";
    ui->tableWidget->setHorizontalHeaderLabels(baslik); //başlık ekleme
    for(int i=0;i<modelliste->rowCount();i++){
        QLabel *numara=new QLabel(this);
        numara->setText(modelliste->index(i,0).data().toString());
        ui->tableWidget->setCellWidget(i,0,numara);

        QLabel *ad=new QLabel(this);
        ad->setText(modelliste->index(i,1).data().toString());
        ui->tableWidget->setCellWidget(i,1,ad);


        QLabel *soyad=new QLabel(this);
        soyad->setText(modelliste->index(i,2).data().toString());
        ui->tableWidget->setCellWidget(i,2,soyad);

        QLineEdit *edit=new QLineEdit();
        ui->tableWidget->setCellWidget(i,3,edit);   //vizeleri girebilmek için linedit koyduk

        QComboBox *combo=new QComboBox(this);
        combo->addItems(baslik);
        ui->tableWidget->setCellWidget(i,4,combo);
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    for(int i=0;i<modelliste->rowCount();i++){
        // QString no=ui->tableWidget->cellWidget(i,0); bu şekilde tablewidgetten de alabiliriz
        QLineEdit *vizesi=(QLineEdit*)ui->tableWidget->cellWidget(i,3);
        genel->prepare("insert into Notlar(numara,DersKodu,Vİze) values (?,?,?)");
        genel->addBindValue(modelliste->index(i,0).data().toString());
        genel->addBindValue(700);
        genel->addBindValue(vizesi->text());
        genel->exec();


    }
}

