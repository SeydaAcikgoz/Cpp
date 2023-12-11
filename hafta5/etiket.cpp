#include "etiket.h"
#include "mainwindow.h"//mainwindiw daki fonkları kullanabilmek için bunu eklemek lazım ve etiket.h ta class MAinwindow yazarak bu sunufın olduğunu söylemeliyiz
#include <QTimer>

//obsiyonel(yazılmasa da olur) parametreler sona bırakılmalı ->(obsiyonel,obsiyoneldeğil):burada her ikisi de gönderilmek zorunda(parametre1,parametre2)
//                                                           ->(obsiyoneldeğil,obsiyonel): obsiyoneldeğil gönderilse yeter(parametre)
etiket::etiket(MainWindow *frm, QWidget *parent) : QLabel(parent)
{
    setGeometry(frm->size().width() / 2, frm->size().height() / 2, 100, 50);
    setFrameShape(QFrame::Box);//çerçeve
    show();
    hareketKontrol = true;
    zaman = new QTimer(this);
    connect(zaman, SIGNAL(timeout()), this, SLOT(hareketlendir()));
    zaman->start(100);
}

void etiket::mousePressEvent(QMouseEvent *)
{
    if (hareketKontrol) {
        zaman->stop();
        hareketKontrol = !hareketKontrol;
    } else {
        zaman->start(100);
        hareketKontrol = !hareketKontrol;
    }
}

void etiket::hareketlendir()
{
    setGeometry(x() + 10, y(), width(), height());
}
//formun orta noktasında label oluştur ve belli zaman aralıklarında sağa kaysın.üzerine tıklanınca da dursun ve tekrar basınca hareket etsin
