/****************************************************************************
** Meta object code from reading C++ file 'animationControl.h'
**
** Created: Sat Sep 3 01:21:52 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/animationControl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animationControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AnimationControl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   18,   17,   17, 0x0a,
      85,   59,   17,   17, 0x0a,
     146,  111,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AnimationControl[] = {
    "AnimationControl\0\0request\0"
    "slotRequestReceived(StateObject)\0"
    "elevatorIndex,floorNumber\0"
    "slotFloorChanged(int,int)\0"
    "elevatorIndex,floorNumber,requests\0"
    "slotArrived(int,int,StateObject[])\0"
};

const QMetaObject AnimationControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AnimationControl,
      qt_meta_data_AnimationControl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AnimationControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AnimationControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AnimationControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationControl))
        return static_cast<void*>(const_cast< AnimationControl*>(this));
    return QObject::qt_metacast(_clname);
}

int AnimationControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotRequestReceived((*reinterpret_cast< StateObject(*)>(_a[1]))); break;
        case 1: slotFloorChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: slotArrived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< StateObject(*)[]>(_a[3]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
