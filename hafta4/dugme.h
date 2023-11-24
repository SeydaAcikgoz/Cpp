#ifndef DUGME_H
#define DUGME_H

#include <QPushButton>
#include <QMouseEvent>

class dugme : public QPushButton
{
    Q_OBJECT
public:
    explicit dugme(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent*);//mouse bastığım anda bu
    void mouseMoveEvent(QMouseEvent*);//hareket ettikçe çalışır

private:
    QPoint ilkKonum;

private slots:  //yeni oluşan butonlara slot atanacak
    void konumDegistir();


signals:

};

#endif // DUGME_H
