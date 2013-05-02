#include "widget.h"
#include <QtGui/QApplication>
#include<QLCDNumber>
#include<QAbstractSlider>
#include<QSound>
#include<QString>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),currentFloor(1),destinationFloor(1)
{

    ui->setupUi(this);

    ui->verticalSlider->setRange(1, 99);
    ui->verticalSlider->setValue(currentFloor);
    QObject::connect(ui->verticalSlider, SIGNAL(valueChanged(int)),
                     ui->lcd2, SLOT(display(int)));


}

void Widget::slotRequestReceived(StateObject request){

}

void Widget::slotFloorChanged(int elevatorIndex, int floorNumber){

}

void Widget::slotArrived(int elevatorIndex, int floorNumber, StateObject requests[]){

}

void Widget::on_pushButton_clicked()
{
    move(false);
}


void Widget::on_pushButton_2_clicked()
{
    move(true);
}

void Widget::moveFinished(){
    if(currentFloor!=destinationFloor)
    {
        ui->verticalSlider->setValue(currentFloor);
        QObject::connect(ui->verticalSlider, SIGNAL(valueChanged(int)),
                         ui->lcd2, SLOT(display(int)));
        if(currentFloor<destinationFloor)currentFloor++;
        if(currentFloor>destinationFloor)currentFloor--;
    }else
        arrived();
}

void Widget::doorFinished(){

}

void Widget::doorOpened(){
    m_anim1= new Animation(ui->left, "pos");
    connect(m_anim1, SIGNAL(finished()),this , SLOT(doorFinished()));
    m_anim1->setEasingCurve(QEasingCurve::Linear);
    m_anim1->setEndValue(QPointF(280, 70));
    m_anim1->setStartValue(QPointF(115, 70));
    m_anim1->setDuration(2000);
    m_anim1->setLoopCount(1); // forever
    m_anim1->start();
    m_anim11 = new Animation(ui->right, "pos");
    m_anim11->setEasingCurve(QEasingCurve::Linear);
    m_anim11->setEndValue(QPointF(440, 70));
    m_anim11->setStartValue(QPointF(590, 70));
    m_anim11->setDuration(2000);
    m_anim11->setLoopCount(1); // forever
    m_anim11->start();
}

void Widget::currentInf(int elevatorIndex,int currentfloorNum)
{
    ui->verticalSlider->setValue(currentfloorNum);
}

void Widget::arrived()
{
    m_anim1= new Animation(ui->left, "pos");
    connect(m_anim1, SIGNAL(finished()),this , SLOT(doorOpened()));
    m_anim1->setEasingCurve(QEasingCurve::Linear);
    m_anim1->setStartValue(QPointF(280, 70));
    m_anim1->setEndValue(QPointF(115, 70));
    m_anim1->setDuration(2000);
    m_anim1->setLoopCount(1);
    m_anim1->start();
    m_anim11 = new Animation(ui->right, "pos");
    m_anim11->setEasingCurve(QEasingCurve::Linear);
    m_anim11->setStartValue(QPointF(460, 70));
    m_anim11->setEndValue(QPointF(590, 70));
    m_anim11->setDuration(2000);
    m_anim11->setLoopCount(1);
    m_anim11->start();
    QSound::play("sound/1.wav");

}

void Widget::move(bool isDown)
{
    m_anim1= new Animation(ui->floor, "pos");
    connect(m_anim1, SIGNAL(finished()),this , SLOT(moveFinished()));
    m_anim1->setEasingCurve(QEasingCurve::Linear);
    if(isDown){
        m_anim1->setStartValue(QPointF(ui->floor->geometry().x(), -2700));
        m_anim1->setEndValue(QPointF(ui->floor->geometry().x(), -3160));
    }else{
        m_anim1->setStartValue(QPointF(ui->floor->geometry().x(), -3160));
        m_anim1->setEndValue(QPointF(ui->floor->geometry().x(), -2700));
    }
    m_anim1->setDuration(2000);
    m_anim1->setLoopCount(1);
    m_anim1->start();
    //QSound::play("sound/1.wav");

}

Widget::~Widget()
{
    delete ui;
}
