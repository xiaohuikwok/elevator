#ifndef STATEOBJECT_H
#define STATEOBJECT_H

class StateObject
{
public:
    StateObject(int f,int t){
        from=f;
        to=t;
    }
    int getFrom(){return from;}
    int getTo(){return to;}
private:
    int  from;
    int  to;
};

#endif // STATEOBJECT_H
