#ifndef ETIKET_H
#define ETIKET_H

#include <QLabel>
#include <QMouseEvent>

class MainWindow;

class etiket : public QLabel
{
    Q_OBJECT
public:
    explicit etiket(QWidget *parent = 0);
    MainWindow *anafrm;
    void resimYukle(int);
    void kapat();
    void setBulundu();
    QString getSakliResim();

private:
    void mousePressEvent(QMouseEvent*);
    QString sakliResim;
    bool bulundu;

signals:

public slots:

};

#endif // ETIKET_H
