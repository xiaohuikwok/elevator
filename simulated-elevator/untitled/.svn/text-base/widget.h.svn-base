#ifndef WIDGET_H
#define WIDGET_H
#include<QWidget>
#include "ui_widget.h"
#include"animation.h"
#include "stateobject.h"
#include<QGraphicsWidget>
#include<vector>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
   ~Widget();
   void currentInf(int elevatorIndex,int currentfloorNum);//显示电梯的号码以及电梯当前所在的楼层

private:
   void arrived();
   void move(bool);
    Ui::Widget *ui;
    Animation *m_anim;
    Animation *m_anim1;
    Animation *m_anim11;
    int currentFloor,destinationFloor;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void moveFinished();
    void doorFinished();
    void doorOpened();

    void slotRequestReceived(StateObject request);
    void slotFloorChanged(int elevatorIndex, int floorNumber);
    void slotArrived(int elevatorIndex, int floorNumber, StateObject requests[]);
};
#endif // WIDGET_H
