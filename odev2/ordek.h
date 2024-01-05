#ifndef ORDEK_H
#define ORDEK_H

#include <QLabel>
#include <QTimer>
#include <QMouseEvent>

class MainWindow;

class ordek : public QLabel
{
    Q_OBJECT
public:
    explicit ordek(MainWindow *frm, QWidget *parent = nullptr);
    ~ordek();

private slots:
    void hareketlendir();
    void yoket();

private:
    QTimer *hareketZamanlayici, *yoketZamanlayici;
    void mousePressEvent(QMouseEvent *event);
    void kacanKontrol();
    MainWindow *anafrm;
    QWidget *prnt;

signals:

};

#endif // ORDEK_H
