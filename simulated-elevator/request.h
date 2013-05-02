#ifndef REQUEST_H
#define REQUEST_H

#include <cmath>

class Request
{
public:

    static const int FLOOR_NONE = -1;

    enum DIRECTION{DIRECTION_UP, DIRECTION_DOWN, DIRECTION_NONE};

    Request(int f,int t){
        departure=f;
        destination=t;
    }

    void unsetDeparture(){
        departure=FLOOR_NONE;
    }

    void unsetDestination(){
        destination=FLOOR_NONE;
    }

    int getDeparture(){
        return departure;
    }

    int getDestination(){
        return destination;
    }

    int getLength(){
        return std::fabs(departure-destination);
    }

    DIRECTION getDirection(){
        if(departure>destination){
            return DIRECTION_DOWN;
        }else if(departure<destination){
            return DIRECTION_UP;
        }else{
            return DIRECTION_NONE;
        }
    }

    DIRECTION getDirectionToDeparture(int floor){
        if(departure<floor){
            return DIRECTION_DOWN;
        }else if(departure>floor){
            return DIRECTION_UP;
        }else{
            return DIRECTION_NONE;
        }
    }

    DIRECTION getDirectionToDestination(int floor){
        if(floor<destination){
            return DIRECTION_DOWN;
        }else if(floor>destination){
            return DIRECTION_UP;
        }else{
            return DIRECTION_NONE;
        }
    }

private:
    int  departure;
    int  destination;
};

#endif // REQUEST_H
