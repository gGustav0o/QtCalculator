/****************************************************************************
** Meta object code from reading C++ file 'calculator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../calculator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calculator_t {
    QByteArrayData data[22];
    char stringdata0[313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator_t qt_meta_stringdata_Calculator = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Calculator"
QT_MOC_LITERAL(1, 11, 16), // "calcValueChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "resultChanged"
QT_MOC_LITERAL(4, 43, 19), // "resultLengthChanged"
QT_MOC_LITERAL(5, 63, 26), // "isSecretMenuVisibleChanged"
QT_MOC_LITERAL(6, 90, 15), // "equalsActivated"
QT_MOC_LITERAL(7, 106, 13), // "numberPressed"
QT_MOC_LITERAL(8, 120, 6), // "number"
QT_MOC_LITERAL(9, 127, 17), // "changeSignPressed"
QT_MOC_LITERAL(10, 145, 16), // "operationPressed"
QT_MOC_LITERAL(11, 162, 13), // "equalsPressed"
QT_MOC_LITERAL(12, 176, 12), // "clearPressed"
QT_MOC_LITERAL(13, 189, 10), // "dotPressed"
QT_MOC_LITERAL(14, 200, 14), // "bracketPressed"
QT_MOC_LITERAL(15, 215, 14), // "percentPressed"
QT_MOC_LITERAL(16, 230, 9), // "setResult"
QT_MOC_LITERAL(17, 240, 12), // "setCalcValue"
QT_MOC_LITERAL(18, 253, 22), // "setIsSecretMenuVisible"
QT_MOC_LITERAL(19, 276, 9), // "calcValue"
QT_MOC_LITERAL(20, 286, 6), // "result"
QT_MOC_LITERAL(21, 293, 19) // "isSecretMenuVisible"

    },
    "Calculator\0calcValueChanged\0\0resultChanged\0"
    "resultLengthChanged\0isSecretMenuVisibleChanged\0"
    "equalsActivated\0numberPressed\0number\0"
    "changeSignPressed\0operationPressed\0"
    "equalsPressed\0clearPressed\0dotPressed\0"
    "bracketPressed\0percentPressed\0setResult\0"
    "setCalcValue\0setIsSecretMenuVisible\0"
    "calcValue\0result\0isSecretMenuVisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       3,  120, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   98,    2, 0x0a /* Public */,
       7,    1,   99,    2, 0x0a /* Public */,
       9,    0,  102,    2, 0x0a /* Public */,
      10,    1,  103,    2, 0x0a /* Public */,
      11,    0,  106,    2, 0x0a /* Public */,
      12,    0,  107,    2, 0x0a /* Public */,
      13,    0,  108,    2, 0x0a /* Public */,
      14,    0,  109,    2, 0x0a /* Public */,
      15,    0,  110,    2, 0x0a /* Public */,
      16,    1,  111,    2, 0x0a /* Public */,
      17,    1,  114,    2, 0x0a /* Public */,
      18,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QChar,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // properties: name, type, flags
      19, QMetaType::QString, 0x00495903,
      20, QMetaType::QString, 0x00495903,
      21, QMetaType::Bool, 0x00495903,

 // properties: notify_signal_id
       0,
       1,
       3,

       0        // eod
};

void Calculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Calculator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->calcValueChanged(); break;
        case 1: _t->resultChanged(); break;
        case 2: _t->resultLengthChanged(); break;
        case 3: _t->isSecretMenuVisibleChanged(); break;
        case 4: _t->equalsActivated(); break;
        case 5: _t->numberPressed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->changeSignPressed(); break;
        case 7: _t->operationPressed((*reinterpret_cast< const QChar(*)>(_a[1]))); break;
        case 8: _t->equalsPressed(); break;
        case 9: _t->clearPressed(); break;
        case 10: _t->dotPressed(); break;
        case 11: _t->bracketPressed(); break;
        case 12: _t->percentPressed(); break;
        case 13: _t->setResult((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->setCalcValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->setIsSecretMenuVisible((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Calculator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculator::calcValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Calculator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculator::resultChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Calculator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculator::resultLengthChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Calculator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculator::isSecretMenuVisibleChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Calculator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->calcValue(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->result(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isSecretMenuVisible(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Calculator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCalcValue(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setResult(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setIsSecretMenuVisible(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Calculator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator.data,
    qt_meta_data_Calculator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Calculator::calcValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Calculator::resultChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Calculator::resultLengthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Calculator::isSecretMenuVisibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
