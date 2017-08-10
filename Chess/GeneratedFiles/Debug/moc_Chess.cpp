/****************************************************************************
** Meta object code from reading C++ file 'Chess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Chess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Chess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chess_t {
    QByteArrayData data[11];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chess_t qt_meta_stringdata_Chess = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Chess"
QT_MOC_LITERAL(1, 6, 9), // "send_text"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 12), // "receive_text"
QT_MOC_LITERAL(4, 30, 11), // "std::string"
QT_MOC_LITERAL(5, 42, 3), // "str"
QT_MOC_LITERAL(6, 46, 11), // "set_restart"
QT_MOC_LITERAL(7, 58, 15), // "ask_for_restart"
QT_MOC_LITERAL(8, 74, 9), // "choose_go"
QT_MOC_LITERAL(9, 84, 14), // "choose_go_bang"
QT_MOC_LITERAL(10, 99, 15) // "take_back_stone"

    },
    "Chess\0send_text\0\0receive_text\0std::string\0"
    "str\0set_restart\0ask_for_restart\0"
    "choose_go\0choose_go_bang\0take_back_stone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chess[] = {

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
       1,    0,   49,    2, 0x0a /* Public */,
       3,    1,   50,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,
       9,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Chess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chess *_t = static_cast<Chess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_text(); break;
        case 1: _t->receive_text((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->set_restart(); break;
        case 3: _t->ask_for_restart(); break;
        case 4: _t->choose_go(); break;
        case 5: _t->choose_go_bang(); break;
        case 6: _t->take_back_stone(); break;
        default: ;
        }
    }
}

const QMetaObject Chess::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Chess.data,
      qt_meta_data_Chess,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Chess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chess::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Chess.stringdata0))
        return static_cast<void*>(const_cast< Chess*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Chess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
