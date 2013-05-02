#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>
#include <QMap>
#include <QList>
#include "request.h"
#include "elevator.h"

class Dispatcher : public QObject
{
    Q_OBJECT
public:

    explicit Dispatcher(QObject *parent = 0) :
        QObject(parent)
    {
    }

    void takeInControl(Elevator* elevator){
        elevators.insert(elevator->getID(),elevator);
        connect(elevator,SIGNAL(signalCanAcceptRequest(int)),this,SLOT(dispatchRequestPool()));
    }

private:
    QMap<int,Elevator*> elevators;
    QList<Request*> requestPool;

signals:

public slots:

    void requestReceived(Request* req){
        if(req->getDeparture()==Elevator::FLOOR_NONE||req->getDestination()==Elevator::FLOOR_NONE) return;
        requestPool.push_back(req);
        dispatchRequestPool();
    }

    void dispatchRequestPool(){
        if(elevators.count()==0) return;
        if(requestPool.count()==0) return;
        for(int i = 0; i != requestPool.count(); i++){
            Elevator* choice = NULL;
            int lowestCost=-1;
            for(QMap<int,Elevator*>::Iterator elevator = elevators.begin(); elevator != elevators.end(); elevator++){
                if(lowestCost==-1){
                    lowestCost = elevator.value()->evaluate(requestPool[i]);
                    choice = elevator.value();
                }else{
                    int cost = elevator.value()->evaluate(requestPool[i]);
                    if(cost> 0 && cost<lowestCost){
                        lowestCost = cost;
                        choice = elevator.value();
                    }
                }
            }
            if(lowestCost>0){
                Request* tmp = requestPool[i];
                requestPool.removeAt(i);
                choice->addRequest(tmp);
                i--;
            }
        }
    }
};

#endif // DISPATCHER_H
