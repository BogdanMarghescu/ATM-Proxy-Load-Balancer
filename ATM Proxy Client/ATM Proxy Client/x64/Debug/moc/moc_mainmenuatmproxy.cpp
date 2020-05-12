/****************************************************************************
** Meta object code from reading C++ file 'mainmenuatmproxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainmenuatmproxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenuatmproxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainMenuATMproxy_t {
    QByteArrayData data[22];
    char stringdata0[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainMenuATMproxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainMenuATMproxy_t qt_meta_stringdata_MainMenuATMproxy = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MainMenuATMproxy"
QT_MOC_LITERAL(1, 17, 15), // "returnLoginMenu"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "openMainMenu"
QT_MOC_LITERAL(4, 47, 6), // "string"
QT_MOC_LITERAL(5, 54, 8), // "username"
QT_MOC_LITERAL(6, 63, 17), // "updateTableWidget"
QT_MOC_LITERAL(7, 81, 10), // "ServerList"
QT_MOC_LITERAL(8, 92, 6), // "svlist"
QT_MOC_LITERAL(9, 99, 10), // "addCommand"
QT_MOC_LITERAL(10, 110, 7), // "command"
QT_MOC_LITERAL(11, 118, 8), // "sendTask"
QT_MOC_LITERAL(12, 127, 4), // "type"
QT_MOC_LITERAL(13, 132, 3), // "op1"
QT_MOC_LITERAL(14, 136, 3), // "op2"
QT_MOC_LITERAL(15, 140, 32), // "on_chooseAlgorithmButton_clicked"
QT_MOC_LITERAL(16, 173, 27), // "on_chooseTaskButton_clicked"
QT_MOC_LITERAL(17, 201, 32), // "on_actionOpen_Log_File_triggered"
QT_MOC_LITERAL(18, 234, 26), // "on_actionLog_Out_triggered"
QT_MOC_LITERAL(19, 261, 32), // "on_commandList_itemDoubleClicked"
QT_MOC_LITERAL(20, 294, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(21, 311, 4) // "item"

    },
    "MainMenuATMproxy\0returnLoginMenu\0\0"
    "openMainMenu\0string\0username\0"
    "updateTableWidget\0ServerList\0svlist\0"
    "addCommand\0command\0sendTask\0type\0op1\0"
    "op2\0on_chooseAlgorithmButton_clicked\0"
    "on_chooseTaskButton_clicked\0"
    "on_actionOpen_Log_File_triggered\0"
    "on_actionLog_Out_triggered\0"
    "on_commandList_itemDoubleClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainMenuATMproxy[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   70,    2, 0x0a /* Public */,
       6,    1,   73,    2, 0x0a /* Public */,
       9,    1,   76,    2, 0x0a /* Public */,
      11,    3,   79,    2, 0x08 /* Private */,
      11,    2,   86,    2, 0x28 /* Private | MethodCloned */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    0,   92,    2, 0x08 /* Private */,
      17,    0,   93,    2, 0x08 /* Private */,
      18,    0,   94,    2, 0x08 /* Private */,
      19,    1,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 4,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void MainMenuATMproxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainMenuATMproxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnLoginMenu(); break;
        case 1: _t->openMainMenu((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->updateTableWidget((*reinterpret_cast< ServerList(*)>(_a[1]))); break;
        case 3: _t->addCommand((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 4: _t->sendTask((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->sendTask((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_chooseAlgorithmButton_clicked(); break;
        case 7: _t->on_chooseTaskButton_clicked(); break;
        case 8: _t->on_actionOpen_Log_File_triggered(); break;
        case 9: _t->on_actionLog_Out_triggered(); break;
        case 10: _t->on_commandList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< string >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ServerList >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< string >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainMenuATMproxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenuATMproxy::returnLoginMenu)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainMenuATMproxy::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainMenuATMproxy.data,
    qt_meta_data_MainMenuATMproxy,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainMenuATMproxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenuATMproxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenuATMproxy.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainMenuATMproxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainMenuATMproxy::returnLoginMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
