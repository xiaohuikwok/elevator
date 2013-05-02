/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Sat Sep 3 18:59:22 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      34,    7,    7,    7, 0x08,
      58,    7,    7,    7, 0x08,
      73,    7,    7,    7, 0x08,
      88,    7,    7,    7, 0x08,
     109,  101,    7,    7, 0x08,
     168,  142,    7,    7, 0x08,
     229,  194,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0moveFinished()\0"
    "doorFinished()\0doorOpened()\0request\0"
    "slotRequestReceived(StateObject)\0"
    "elevatorIndex,floorNumber\0"
    "slotFloorChanged(int,int)\0"
    "elevatorIndex,floorNumber,requests\0"
    "slotArrived(int,int,StateObject[])\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_2_clicked(); break;
        case 1: on_pushButton_clicked(); break;
        case 2: moveFinished(); break;
        case 3: doorFinished(); break;
        case 4: doorOpened(); break;
        case 5: slotRequestReceived((*reinterpret_cast< StateObject(*)>(_a[1]))); break;
        case 6: slotFloorChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: slotArrived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< StateObject(*)[]>(_a[3]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
