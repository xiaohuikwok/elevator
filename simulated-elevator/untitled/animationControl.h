#ifndef ANIMATIONCONTROL_H
#define ANIMATIONCONTROL_H
#include"widget.h"
#include<QtGui>
#include"stateobject.h"

class AnimationControl: public QObject
{
      Q_OBJECT
public:
public slots:
    void slotRequestReceived(StateObject request);
    void slotFloorChanged(int elevatorIndex, int floorNumber);
    void slotArrived(int elevatorIndex, int floorNumber, StateObject requests[]);
};
#endif // ANIMATIONCONTROL_H


