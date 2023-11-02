#include "mainwindow.h"

#include <QApplication>
//int argc->ana fonksiyona gönderilecek parametre sayısı char *argv[]->gönderilecek parametreler-->uygulama daha çalışmadan parametre gönderir.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
