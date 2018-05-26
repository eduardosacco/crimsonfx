/****************************************************************************
** Meta object code from reading C++ file 'crimson.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "crimson.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'crimson.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Crimson_t {
    QByteArrayData data[14];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Crimson_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Crimson_t qt_meta_stringdata_Crimson = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Crimson"
QT_MOC_LITERAL(1, 8, 18), // "slot_dialogFx_open"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "fx"
QT_MOC_LITERAL(4, 31, 21), // "slot_fx_state_changed"
QT_MOC_LITERAL(5, 53, 21), // "slot_fx_param_changed"
QT_MOC_LITERAL(6, 75, 5), // "param"
QT_MOC_LITERAL(7, 81, 5), // "value"
QT_MOC_LITERAL(8, 87, 22), // "slot_fx_preset_changed"
QT_MOC_LITERAL(9, 110, 6), // "preset"
QT_MOC_LITERAL(10, 117, 9), // "slot_exit"
QT_MOC_LITERAL(11, 127, 24), // "slot_bank_preset_changed"
QT_MOC_LITERAL(12, 152, 10), // "bankPreset"
QT_MOC_LITERAL(13, 163, 20) // "slot_dialogFx_closed"

    },
    "Crimson\0slot_dialogFx_open\0\0fx\0"
    "slot_fx_state_changed\0slot_fx_param_changed\0"
    "param\0value\0slot_fx_preset_changed\0"
    "preset\0slot_exit\0slot_bank_preset_changed\0"
    "bankPreset\0slot_dialogFx_closed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Crimson[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    1,   52,    2, 0x0a /* Public */,
       5,    3,   55,    2, 0x0a /* Public */,
       8,    2,   62,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

void Crimson::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Crimson *_t = static_cast<Crimson *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_dialogFx_open((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slot_fx_state_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slot_fx_param_changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->slot_fx_preset_changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->slot_exit(); break;
        case 5: _t->slot_bank_preset_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slot_dialogFx_closed(); break;
        default: ;
        }
    }
}

const QMetaObject Crimson::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Crimson.data,
      qt_meta_data_Crimson,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Crimson::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Crimson::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Crimson.stringdata0))
        return static_cast<void*>(const_cast< Crimson*>(this));
    return QObject::qt_metacast(_clname);
}

int Crimson::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
