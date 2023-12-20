#include "etiket.h"
#include <QMimeData>
#include <QDrag>

etiket::etiket(QWidget *parent) : QLabel(parent)
{
    setFrameShape(QFrame::Box);
    setScaledContents(true);//widget'ın içeriğini mevcut alana sığacak şekilde otomatik olarak ölçekleyeceği ve ayarlayacağı anlamına gelir.
    setAcceptDrops(true);
}

void etiket::dragEnterEvent(QDragEnterEvent *event)
{
   event->accept();
}


void etiket::dropEvent(QDropEvent *event)
{
    ////uygulama içinde sürükle bırak yapma

    //qobject_cast->herhangi bir objenin adresini verir
    //event->source()->sürüklenen nesnenin adresini verir
    etiket *gelen=qobject_cast<etiket*>(event->source());//gelen nesne etiket tipinden olacak
    if(gelen && gelen!=this){
        QImage birakilan(pixmap()->toImage());
        setPixmap(QPixmap::fromImage(gelen->pixmap()->toImage()));
        gelen->setPixmap(QPixmap::fromImage(birakilan));
        return; //eğer uygulama içinde değişme yapıldıysa bitir
    //sürüklenen ve üzerine gelinen resimlerin yerini değiştirdik
    }//gelen adresi doluysa ve kendi adresinden farklıysa


    ////uygulamaya dışarıdan sürükle bırak yapma
   QList<QUrl> yollar=event->mimeData()->urls();//birden fazla dosya gelebileceği için listede tut
   if(yollar.isEmpty()){
       return;
   }
   QString yol=yollar.first().toLocalFile();//toLocalFile:dosya dönüştürülüp Qstring yap
   QImage resim(yol);
   setPixmap(QPixmap::fromImage(resim));//resmi sürükleyip label üzerine bırakıldı ve resim gözüktü
}

void etiket::mouseMoveEvent(QMouseEvent *event)
{
    QMimeData *mdata=new QMimeData();
    mdata->setImageData(pixmap()->toImage());
    QDrag *suruklenen=new QDrag(this);
    suruklenen->setMimeData(mdata);
    suruklenen->setPixmap(mdata->imageData().value<QPixmap>());
    suruklenen->exec(Qt::MoveAction);//hareket devam ettiği sürece çalış
}
