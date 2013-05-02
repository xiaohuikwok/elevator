#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QFrame>
#include "request.h"
#include "ui_elevator.h"
#include <QList>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <stdio.h>
#include <cmath>

namespace Ui {
class Elevator;
}

class Elevator : public QFrame
{
    Q_OBJECT

public:

    static int indexSequence;

    static const int FLOOR_NONE = -1;
    static const int REQUEST_UNACCEPTABLE = -1;

    explicit Elevator(QWidget *parent = 0, int index = -1):
        QFrame(parent),
        ui(new Ui::Elevator),
        curFloor(1),dstFloor(FLOOR_NONE),
        passengerCount(0),inPassengerCount(0),outPassengerCount(0),
        curDirection(Request::DIRECTION_NONE),
        direction(Request::DIRECTION_NONE)
    {
        if(index==-1) id = indexSequence++;
        else id = index;
        ui->setupUi(this);
        ui->elevatorIndex->setText((new QString)->sprintf("Elevator #%d",id + 1));
        createAnimations();
        ui->man_waiting->setVisible(false);
        ui->man_waiting_2->setVisible(false);
        ui->man_waiting_3->setVisible(false);
        ui->man_waiting_4->setVisible(false);
        ui->man_in->setVisible(false);
        ui->man_out->setVisible(false);
        ui->man_board->setVisible(false);
    }

    ~Elevator()
    {
        delete ui;
    }

    int getID(){
        return id;
    }

    int evaluate(Request* req){
        int result = std::fabs(req->getDeparture()-curFloor)+req->getLength();
        if(curDirection != Request::DIRECTION_NONE){
            Request::DIRECTION dirReq = req->getDirectionToDeparture(curFloor);
            if(dirReq!=Request::DIRECTION_NONE&&curDirection != dirReq)
                return REQUEST_UNACCEPTABLE;
            int pole = getPoleDepartureInCurrentDirection();
            if(direction != req->getDirection()){
                if(curDirection==direction) return REQUEST_UNACCEPTABLE;
                if(curDirection==Request::DIRECTION_UP){
                    if(pole < req->getDeparture() || pole < req->getDestination()) return REQUEST_UNACCEPTABLE;
                }else if(curDirection==Request::DIRECTION_DOWN){
                    if(pole > req->getDeparture() || pole > req->getDestination()) return REQUEST_UNACCEPTABLE;
                }
                result+=2*std::fabs(req->getDeparture()-pole);
            }else{
                if(curDirection!=direction)
                    return REQUEST_UNACCEPTABLE;
            }
        }
        return result;
    }

    int getPoleDepartureInCurrentDirection(){
        int pole = FLOOR_NONE;
        if(curDirection==Request::DIRECTION_UP){
            for(int i = 0; i != requests.count(); i++){
                if(requests.at(i)->getDeparture()!=FLOOR_NONE){
                    if(pole==FLOOR_NONE||pole<requests.at(i)->getDeparture()) pole = requests.at(i)->getDeparture();
                }
            }
        }else if(curDirection==Request::DIRECTION_DOWN){
            for(int i = 0; i != requests.count(); i++){
                if(requests.at(i)->getDeparture()!=FLOOR_NONE){
                    if(pole==FLOOR_NONE||pole>requests.at(i)->getDeparture()) pole = requests.at(i)->getDeparture();
                }
            }
        }
        return pole;
    }

    bool addRequest(Request* req){
        //Comment this believing in ResquestDispatcher
        //if(evaluate(req)==REQUEST_UNACCEPTABLE) return false;
        if(isIdle()){
            setCurDirection(req->getDirectionToDeparture(curFloor));
            direction=req->getDirection();
            requests.push_back(req);
            nextFloor();
        }else{
            requests.push_back(req);
        }
        return true;
    }

    int getCurrentFloor(){
        return curFloor;
    }

    int getNextDestination(){
        return dstFloor;
    }

    void nextFloor(){
        bool hasDoorOpened = false;
        bool hasDeparture = false;
        /*
            if has departure
                open door
                unsetDeparture
                query whether has departure if not change curDirection
          */
        inPassengerCount = outPassengerCount = 0;
        for(int i = requests.count()-1; i >= 0; i--){
            if(curFloor==requests.at(i)->getDeparture()){
                requests.at(i)->unsetDeparture();
                passengerCount++;
                inPassengerCount++;
                hasDoorOpened=true;
            }else{
                if(requests.at(i)->getDeparture()!=FLOOR_NONE){
                    hasDeparture=true;
                }else if(curFloor==requests.at(i)->getDestination()){
                    requests.removeAt(i);
                    passengerCount--;
                    outPassengerCount++;
                    hasDoorOpened=true;
                }
            }
        }

        if(hasDoorOpened){
            if(curDirection!=direction&&hasDeparture==false){
                setCurDirection(direction);
                emit signalCanAcceptRequest(id);
            }
            action();
            return;
        }

        if(isIdle()){
            direction=Request::DIRECTION_NONE;
            setCurDirection(direction);
            emit signalCanAcceptRequest(id);
            return;
        }

        if(curDirection==Request::DIRECTION_UP)
            curFloor++;
        else if(curDirection==Request::DIRECTION_DOWN)
            curFloor--;

        action(curDirection);
    }

    bool isIdle(){
        return requests.isEmpty();
    }

private:
    Ui::Elevator *ui;
    int id;
    int curFloor,dstFloor,inPassengerCount,outPassengerCount,passengerCount;
    Request::DIRECTION curDirection,direction;

    QList<Request*> requests;

    //Animation & animation functions
    QSequentialAnimationGroup *animeDoorOpen;
    QParallelAnimationGroup *animePassengers;
    QSequentialAnimationGroup *animeDoorClose;
    QParallelAnimationGroup *animeUpward;
    QParallelAnimationGroup *animeDownward;
    QParallelAnimationGroup *animeGrpParallel;
    QSequentialAnimationGroup *animeGrpSequential;
    QPropertyAnimation *anime;

    void createAnimations(){
        animeDoorOpen = new QSequentialAnimationGroup();
        animePassengers = new QParallelAnimationGroup();
        animeDoorClose = new QSequentialAnimationGroup();
        animeUpward = new QParallelAnimationGroup();
        animeDownward = new QParallelAnimationGroup();
        createAnimationLift();
        createAnimationDoor();
        connect(animeDoorOpen,SIGNAL(finished()),this,SLOT(animeDoorOpenFinished()));
        connect(animePassengers,SIGNAL(finished()),this,SLOT(animePassengersFinished()));
        connect(animeDoorClose,SIGNAL(finished()),this,SLOT(slotAction()));
        connect(animeUpward,SIGNAL(finished()),this,SLOT(slotAction()));
        connect(animeDownward,SIGNAL(finished()),this,SLOT(slotAction()));
    }

    void createAnimationLift(){
        createAnimationUpward();
        createAnimationDownward();
    }

    void createAnimationUpward(){
        anime = new QPropertyAnimation(ui->floorNumbers,"pos");
        anime->setDuration(2000);
        anime->setEasingCurve(QEasingCurve::Linear);
        anime->setStartValue(QPointF(0,-360));
        anime->setEndValue(QPointF(0,-90));
        anime->setLoopCount(1);
        animeUpward->addAnimation(anime);
        anime = new QPropertyAnimation(ui->floors,"pos");
        anime->setDuration(2000);
        anime->setEasingCurve(QEasingCurve::Linear);
        anime->setStartValue(QPointF(0,-360));
        anime->setEndValue(QPointF(0,-90));
        anime->setLoopCount(1);
        animeUpward->addAnimation(anime);
    }

    void createAnimationDownward(){
        anime = new QPropertyAnimation(ui->floorNumbers,"pos");
        anime->setDuration(2000);
        anime->setEasingCurve(QEasingCurve::Linear);
        anime->setStartValue(QPointF(0,-90));
        anime->setEndValue(QPointF(0,-360));
        anime->setLoopCount(1);
        animeDownward->addAnimation(anime);
        anime = new QPropertyAnimation(ui->floors,"pos");
        anime->setDuration(2000);
        anime->setEasingCurve(QEasingCurve::Linear);
        anime->setStartValue(QPointF(0,-90));
        anime->setEndValue(QPointF(0,-360));
        anime->setLoopCount(1);
        animeDownward->addAnimation(anime);
    }

    void createAnimationDoor(){
        animeGrpParallel = new QParallelAnimationGroup();
        anime = new QPropertyAnimation(ui->ldoor,"pos");
        anime->setDuration(1000);
        anime->setEasingCurve(QEasingCurve::OutQuart);
        anime->setStartValue(QPointF(0,40));
        anime->setEndValue(QPointF(-90,40));
        anime->setLoopCount(1);
        animeGrpParallel->addAnimation(anime);
        anime = new QPropertyAnimation(ui->rdoor,"pos");
        anime->setDuration(1000);
        anime->setEasingCurve(QEasingCurve::OutQuart);
        anime->setStartValue(QPointF(90,40));
        anime->setEndValue(QPointF(180,40));
        anime->setLoopCount(1);
        animeGrpParallel->addAnimation(anime);
        animeDoorOpen->addAnimation(animeGrpParallel);
        //Exchange Passengers
        animeGrpSequential = new QSequentialAnimationGroup();
        anime = new QPropertyAnimation(ui->man_in,"pos");
        anime->setDuration(500);
        anime->setEasingCurve(QEasingCurve::InQuart);
        anime->setStartValue(QPointF(-70,270));
        anime->setEndValue(QPointF(10,270));
        anime->setLoopCount(1);
        animeGrpSequential->addAnimation(anime);
        anime = new QPropertyAnimation(ui->man_in,"pos");
        anime->setDuration(1000);
        anime->setEasingCurve(QEasingCurve::OutQuart);
        anime->setStartValue(QPointF(10,270));
        anime->setEndValue(QPointF(30,220));
        anime->setLoopCount(1);
        animeGrpSequential->addAnimation(anime);
        animePassengers->addAnimation(animeGrpSequential);
        animeGrpSequential = new QSequentialAnimationGroup();
        anime = new QPropertyAnimation(ui->man_out,"pos");
        anime->setDuration(1000);
        anime->setEasingCurve(QEasingCurve::InQuart);
        anime->setStartValue(QPointF(30,220));
        anime->setEndValue(QPointF(130,270));
        anime->setLoopCount(1);
        animeGrpSequential->addAnimation(anime);
        anime = new QPropertyAnimation(ui->man_out,"pos");
        anime->setDuration(500);
        anime->setEasingCurve(QEasingCurve::OutQuart);
        anime->setStartValue(QPointF(130,270));
        anime->setEndValue(QPointF(220,270));
        anime->setLoopCount(1);
        animeGrpSequential->addAnimation(anime);
        animePassengers->addAnimation(animeGrpSequential);
        //close the door
        animeGrpParallel = new QParallelAnimationGroup();
        anime = new QPropertyAnimation(ui->ldoor,"pos");
        anime->setDuration(1000);
        anime->setEasingCurve(QEasingCurve::OutQuart);
        anime->setStartValue(QPointF(-90,40));
        anime->setEndValue(QPointF(0,40));
        anime->setLoopCount(1);
        animeGrpParallel->addAnimation(anime);
        anime = new QPropertyAnimation(ui->rdoor,"pos");
        anime->setDuration(1000);
        anime->setEasingCurve(QEasingCurve::OutQuart);
        anime->setStartValue(QPointF(180,40));
        anime->setEndValue(QPointF(90,40));
        anime->setLoopCount(1);
        animeGrpParallel->addAnimation(anime);
        animeDoorClose->addAnimation(animeGrpParallel);
    }

    //Play all 5 animations with this function
    void action(Request::DIRECTION direction = Request::DIRECTION_NONE){
        if(animeDoorOpen->state()==QAbstractAnimation::Running) return;
        if(direction==Request::DIRECTION_UP){
            ui->fn1->setText(QString::number(curFloor+1));
            ui->fn2->setText(QString::number(curFloor));
            ui->fn3->setText(QString::number(curFloor-1));
            ui->fn4->setText(QString::number(curFloor-2));
        }else if(direction==Request::DIRECTION_DOWN){
            ui->fn1->setText(QString::number(curFloor+2));
            ui->fn2->setText(QString::number(curFloor+1));
            ui->fn3->setText(QString::number(curFloor));
            ui->fn4->setText(QString::number(curFloor-1));
        }
        if(direction==Request::DIRECTION_UP)
            animeUpward->start();
        else if(direction==Request::DIRECTION_DOWN)
            animeDownward->start();
        else
            animeDoorOpen->start();
    }

    void setCurDirection(Request::DIRECTION curDir){
        curDirection=curDir;
        if(curDirection==Request::DIRECTION_UP){
            ui->light_up->setStyleSheet("image: url(:/image/upward);\nbackground-color: rgba(255, 255, 127, 255);");
            ui->light_down->setStyleSheet("image: url(:/image/downward);\nbackground-color: rgba(255, 255, 127, 0);");
        }else if(curDirection==Request::DIRECTION_DOWN){
            ui->light_up->setStyleSheet("image: url(:/image/upward);\nbackground-color: rgba(255, 255, 127, 0);");
            ui->light_down->setStyleSheet("image: url(:/image/downward);\nbackground-color: rgba(255, 255, 127, 255);");
        }else{
            ui->light_up->setStyleSheet("image: url(:/image/upward);\nbackground-color: rgba(255, 255, 127, 0);");
            ui->light_down->setStyleSheet("image: url(:/image/downward);\nbackground-color: rgba(255, 255, 127, 0);");
        }
    }

signals:
    void signalCanAcceptRequest(int elevatorIndex);

private slots:

    void slotAction(){
        nextFloor();
    }

    void animeDoorOpenFinished(){
        ui->man_board->setVisible(passengerCount!=inPassengerCount&&passengerCount!=0);
        ui->count_board->setVisible(passengerCount-inPassengerCount!=1);
        ui->count_board->setText(QString::number(passengerCount-inPassengerCount));
        ui->man_in->setVisible(inPassengerCount!=0);
        ui->man_out->setVisible(outPassengerCount!=0);
        ui->count_in->setVisible(inPassengerCount!=1);
        ui->count_out->setVisible(outPassengerCount!=1);
        ui->count_in->setText(QString::number(inPassengerCount));
        ui->count_out->setText(QString::number(outPassengerCount));
        animePassengers->start();
    }

    void animePassengersFinished(){
        ui->man_board->setVisible(passengerCount!=0);
        ui->count_board->setVisible(passengerCount!=1);
        ui->count_board->setText(QString::number(passengerCount));
        ui->man_in->setVisible(false);
        ui->man_out->setVisible(false);
        animeDoorClose->start();
    }

};

#endif // ELEVATOR_H
