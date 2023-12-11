#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>//dosyayı kaydederken kaydet menüsü çıkar,ya da açmada
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //QMessageBox::information(this," Bilgilendirme mesaj basligi","Yeni menusune tiklandi."); //information:bilgi amaçlı mesaj verme
    QMessageBox::critical(this,"Kritik mesaj  basligi","Yeni menusune tiklandi."); //critical:kritik mesaj verme
}


void MainWindow::dosyaAc()
{
    QFile dosya(yol);   //yol:dosya nereden okunacak
    if(dosya.open(QFile::ReadOnly)){
        QTextStream okunacak(&dosya);//dosya okunacağı için bu değişken türü daha mantıklı->okur ve değişkende tutar
        QString okunan=okunacak.readAll();//okunana veri okunan değişkenine geldi
        ui->textEdit_2->setText(okunan);
         dosya.close();//eğer dosya geri kapatılmazsa dosya boş kalır
    }//dosya sadece okumak için açılıyor

}

void MainWindow::dosyaKaydet()
{
    QFile dosya(yol);
    if(dosya.open(QFile::WriteOnly)){
        QTextStream yazilacak(&dosya);
        yazilacak << ui->textEdit_2->toPlainText();//içindeki veriyi QString tipine dönüştürüp gönder
        dosya.flush();  //bir çıkış akışının tamponunu (buffer) boşaltmak için
        dosya.close();
    }

}
//sürükle bırak:mainWindow un acceptDrop aktif olmalı,textedit inki kapalı olmalı
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();//sürüklenen nesneyi kabul et
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> yollar=event->mimeData()->urls();//birden fazla dosya gelebileceği için listede tut
    if(yollar.isEmpty()){
        return;
    }
    yol=yollar.first().toLocalFile();//toLocalFile:dosya dönüştürülüp Qstring yap
    dosyaAc();
}

void MainWindow::on_actionYeni_triggered()
{
    //text edit ve yol clear edilmeli
    ui->textEdit_2->clear();
    yol.clear();
}

void MainWindow::on_actionAc_triggered()
{
     yol=QFileDialog::getOpenFileName(this,"Text dosya aç","C:/Users/90505/OneDrive/Masaüstü/ders/yariyil_5/gorsel_programlama/a.txt"); //tek dosya açılacaksa
     if(yol.isEmpty()){
        return;
     }//dosya seçilmediyse bitir
     dosyaAc();
}

void MainWindow::on_actionKaydet_triggered()
{
    if(yol.isEmpty()){
        yol=QFileDialog::getSaveFileName(this,"Text dosya kaydet","C:\\Users\\90505\\OneDrive\\Masaüstü\\ders\\yariyil_5\\gorsel_programlama\\a.txt"); //tek dosya açılacaksa
    }//yol boşsa soracak ama dosya açılmışsa o dosyaya kaydedecek
    dosyaKaydet();
}//çift slaş ya da tek ters slaşla yazılabilir


void MainWindow::on_actionFarkl_Kaydet_triggered()
{

    yol=QFileDialog::getSaveFileName(this,"Text dosya aç","C:/Users/90505/OneDrive/Masaüstü/ders/yariyil_5/gorsel_programlama/a.txt"); //tek dosya açılacaksa
    if(yol.isEmpty()){
       return;
    }//dosya seçilmediyse bitir
    dosyaKaydet();
}

