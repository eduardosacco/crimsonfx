/****************************************************************************
** Meta object code from reading C++ file 'dialogfx.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogfx.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogfx.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DialogFx_t {
    QByteArrayData data[15];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogFx_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogFx_t qt_meta_stringdata_DialogFx = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DialogFx"
QT_MOC_LITERAL(1, 9, 23), // "signal_fx_state_changed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 2), // "fx"
QT_MOC_LITERAL(4, 37, 23), // "signal_fx_param_changed"
QT_MOC_LITERAL(5, 61, 5), // "param"
QT_MOC_LITERAL(6, 67, 8), // "position"
QT_MOC_LITERAL(7, 76, 16), // "signal_destroyed"
QT_MOC_LITERAL(8, 93, 23), // "slot_dial0_valueChanged"
QT_MOC_LITERAL(9, 117, 23), // "slot_dial1_valueChanged"
QT_MOC_LITERAL(10, 141, 23), // "slot_dial2_valueChanged"
QT_MOC_LITERAL(11, 165, 23), // "slot_dial3_valueChanged"
QT_MOC_LITERAL(12, 189, 23), // "slot_dial4_valueChanged"
QT_MOC_LITERAL(13, 213, 20), // "on_btnClose_released"
QT_MOC_LITERAL(14, 234, 20) // "on_btnOnOff_released"

    },
    "DialogFx\0signal_fx_state_changed\0\0fx\0"
    "signal_fx_param_changed\0param\0position\0"
    "signal_destroyed\0slot_dial0_valueChanged\0"
    "slot_dial1_valueChanged\0slot_dial2_valueChanged\0"
    "slot_dial3_valueChanged\0slot_dial4_valueChanged\0"
    "on_btnClose_released\0on_btnOnOff_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogFx[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    3,   67,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   75,    2, 0x08 /* Private */,
       9,    1,   78,    2, 0x08 /* Private */,
      10,    1,   81,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogFx::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogFx *_t = static_cast<DialogFx *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_fx_state_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signal_fx_param_changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->signal_destroyed(); break;
        case 3: _t->slot_dial0_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slot_dial1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slot_dial2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slot_dial3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slot_dial4_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_btnClose_released(); break;
        case 9: _t->on_btnOnOff_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogFx::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogFx::signal_fx_state_changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DialogFx::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogFx::signal_fx_param_changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DialogFx::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogFx::signal_destroyed)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DialogFx::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogFx.data,
      qt_meta_data_DialogFx,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DialogFx::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogFx::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DialogFx.stringdata0))
        return static_cast<void*>(const_cast< DialogFx*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogFx::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DialogFx::signal_fx_state_changed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DialogFx::signal_fx_param_changed(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DialogFx::signal_destroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
