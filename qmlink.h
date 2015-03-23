#ifndef QMLINK_H
#define QMLINK_H

#include <QtGui>
#include "link.h"
#include "basicmodel.h"
class PendulumView;
// This is available in all editors.

class PendulumView:public BasicModel
{
public:
    PendulumView(){;}
    QWidget * parent;
    void init(QWidget* t);

    void updata(){
        ;
    }
};
class QMLink : public QPushButton
{
    Q_OBJECT
public:
    explicit QMLink(QWidget *parent = 0);
    BasicModel * robot;
    int  sign;
    bool	hitButton ( const QPoint & pos ) ;
    void  focusInEvent ( QFocusEvent * e );
    void 	paintEvent ( QPaintEvent * );
    void cal();

    void setPos(int x,int y){
        setGeometry(x,y,16,16);
    }
    void setAngle(double a){
        PendulumView::changeAngle(sign,a);
    }
    void changeAngle(double a){
        PendulumView::changeAngle(sign,a);
    }


    QPainterPath shape();
    QRectF boundingRect() const
        {
            return QRectF(-65, -65, 130, 130);
        }
signals:

public slots:

private:

};
extern QMLink* cur_link;

#endif // QMLINK_H
