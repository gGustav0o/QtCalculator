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
    QByteArrayData data[20];
    char stringdata0[253];
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
QT_MOC_LITERAL(5, 63, 13), // "numberPressed"
QT_MOC_LITERAL(6, 77, 6), // "number"
QT_MOC_LITERAL(7, 84, 17), // "changeSignPressed"
QT_MOC_LITERAL(8, 102, 16), // "operationPressed"
QT_MOC_LITERAL(9, 119, 13), // "equalsPressed"
QT_MOC_LITERAL(10, 133, 12), // "clearPressed"
QT_MOC_LITERAL(11, 146, 10), // "dotPressed"
QT_MOC_LITERAL(12, 157, 14), // "bracketPressed"
QT_MOC_LITERAL(13, 172, 14), // "percentPressed"
QT_MOC_LITERAL(14, 187, 9), // "setResult"
QT_MOC_LITERAL(15, 197, 12), // "setCalcValue"
QT_MOC_LITERAL(16, 210, 12), // "getCalcValue"
QT_MOC_LITERAL(17, 223, 9), // "calcValue"
QT_MOC_LITERAL(18, 233, 6), // "result"
QT_MOC_LITERAL(19, 240, 12) // "resultLength"

    },
    "Calculator\0calcValueChanged\0\0resultChanged\0"
    "resultLengthChanged\0numberPressed\0"
    "number\0changeSignPressed\0operationPressed\0"
    "equalsPressed\0clearPressed\0dotPressed\0"
    "bracketPressed\0percentPressed\0setResult\0"
    "setCalcValue\0getCalcValue\0calcValue\0"
    "result\0resultLength"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       3,  106, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   87,    2, 0x0a /* Public */,
       7,    0,   90,    2, 0x0a /* Public */,
       8,    1,   91,    2, 0x0a /* Public */,
       9,    0,   94,    2, 0x0a /* Public */,
      10,    0,   95,    2, 0x0a /* Public */,
      11,    0,   96,    2, 0x0a /* Public */,
      12,    0,   97,    2, 0x0a /* Public */,
      13,    0,   98,    2, 0x0a /* Public */,
      14,    1,   99,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      16,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QChar,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // properties: name, type, flags
      17, QMetaType::QString, 0x00495903,
      18, QMetaType::Double, 0x00495903,
      19, QMetaType::Int, 0x00495801,

 // properties: notify_signal_id
       0,
       1,
       2,

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
        case 3: _t->numberPressed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->changeSignPressed(); break;
        case 5: _t->operationPressed((*reinterpret_cast< const QChar(*)>(_a[1]))); break;
        case 6: _t->equalsPressed(); break;
        case 7: _t->clearPressed(); break;
        case 8: _t->dotPressed(); break;
        case 9: _t->bracketPressed(); break;
        case 10: _t->percentPressed(); break;
        case 11: _t->setResult((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 12: _t->setCalcValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->getCalcValue(); break;
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
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Calculator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->calcValue(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->result(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->resultLength(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Calculator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCalcValue(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setResult(*reinterpret_cast< double*>(_v)); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
