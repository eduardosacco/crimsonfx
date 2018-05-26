/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[466];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "signal_fx_state_toggled"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 2), // "fx"
QT_MOC_LITERAL(4, 39, 20), // "signal_dialogFx_open"
QT_MOC_LITERAL(5, 60, 25), // "signal_bankPreset_changed"
QT_MOC_LITERAL(6, 86, 6), // "preset"
QT_MOC_LITERAL(7, 93, 30), // "on_btnCompressorState_released"
QT_MOC_LITERAL(8, 124, 33), // "on_btnCompressorSettings_rele..."
QT_MOC_LITERAL(9, 158, 30), // "on_btnOverdrive1State_released"
QT_MOC_LITERAL(10, 189, 33), // "on_btnOverdrive1Settings_rele..."
QT_MOC_LITERAL(11, 223, 29), // "on_btnEqualizerState_released"
QT_MOC_LITERAL(12, 253, 27), // "on_btnEqualizerSet_released"
QT_MOC_LITERAL(13, 281, 27), // "on_btnReverb1State_released"
QT_MOC_LITERAL(14, 309, 30), // "on_btnReverb1Settings_released"
QT_MOC_LITERAL(15, 340, 26), // "on_btnDelay1State_released"
QT_MOC_LITERAL(16, 367, 29), // "on_btnDelay1Settings_released"
QT_MOC_LITERAL(17, 397, 22), // "on_btnPreset1_released"
QT_MOC_LITERAL(18, 420, 22), // "on_btnPreset2_released"
QT_MOC_LITERAL(19, 443, 22) // "on_btnPreset3_released"

    },
    "MainWindow\0signal_fx_state_toggled\0\0"
    "fx\0signal_dialogFx_open\0"
    "signal_bankPreset_changed\0preset\0"
    "on_btnCompressorState_released\0"
    "on_btnCompressorSettings_released\0"
    "on_btnOverdrive1State_released\0"
    "on_btnOverdrive1Settings_released\0"
    "on_btnEqualizerState_released\0"
    "on_btnEqualizerSet_released\0"
    "on_btnReverb1State_released\0"
    "on_btnReverb1Settings_released\0"
    "on_btnDelay1State_released\0"
    "on_btnDelay1Settings_released\0"
    "on_btnPreset1_released\0on_btnPreset2_released\0"
    "on_btnPreset3_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       5,    1,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  103,    2, 0x08 /* Private */,
       8,    0,  104,    2, 0x08 /* Private */,
       9,    0,  105,    2, 0x08 /* Private */,
      10,    0,  106,    2, 0x08 /* Private */,
      11,    0,  107,    2, 0x08 /* Private */,
      12,    0,  108,    2, 0x08 /* Private */,
      13,    0,  109,    2, 0x08 /* Private */,
      14,    0,  110,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_fx_state_toggled((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signal_dialogFx_open((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signal_bankPreset_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_btnCompressorState_released(); break;
        case 4: _t->on_btnCompressorSettings_released(); break;
        case 5: _t->on_btnOverdrive1State_released(); break;
        case 6: _t->on_btnOverdrive1Settings_released(); break;
        case 7: _t->on_btnEqualizerState_released(); break;
        case 8: _t->on_btnEqualizerSet_released(); break;
        case 9: _t->on_btnReverb1State_released(); break;
        case 10: _t->on_btnReverb1Settings_released(); break;
        case 11: _t->on_btnDelay1State_released(); break;
        case 12: _t->on_btnDelay1Settings_released(); break;
        case 13: _t->on_btnPreset1_released(); break;
        case 14: _t->on_btnPreset2_released(); break;
        case 15: _t->on_btnPreset3_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signal_fx_state_toggled)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signal_dialogFx_open)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signal_bankPreset_changed)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_fx_state_toggled(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signal_dialogFx_open(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::signal_bankPreset_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
