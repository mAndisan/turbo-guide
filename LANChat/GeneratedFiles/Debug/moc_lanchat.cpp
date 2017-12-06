/****************************************************************************
** Meta object code from reading C++ file 'lanchat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lanchat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lanchat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LANChat_t {
    QByteArrayData data[24];
    char stringdata[409];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LANChat_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LANChat_t qt_meta_stringdata_LANChat = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 23),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 12),
QT_MOC_LITERAL(4, 46, 20),
QT_MOC_LITERAL(5, 67, 15),
QT_MOC_LITERAL(6, 83, 6),
QT_MOC_LITERAL(7, 90, 23),
QT_MOC_LITERAL(8, 114, 7),
QT_MOC_LITERAL(9, 122, 15),
QT_MOC_LITERAL(10, 138, 14),
QT_MOC_LITERAL(11, 153, 19),
QT_MOC_LITERAL(12, 173, 20),
QT_MOC_LITERAL(13, 194, 18),
QT_MOC_LITERAL(14, 213, 33),
QT_MOC_LITERAL(15, 247, 1),
QT_MOC_LITERAL(16, 249, 38),
QT_MOC_LITERAL(17, 288, 18),
QT_MOC_LITERAL(18, 307, 14),
QT_MOC_LITERAL(19, 322, 18),
QT_MOC_LITERAL(20, 341, 21),
QT_MOC_LITERAL(21, 363, 21),
QT_MOC_LITERAL(22, 385, 16),
QT_MOC_LITERAL(23, 402, 5)
    },
    "LANChat\0processPendingDatagrams\0\0"
    "sentFileName\0currentFormatChanged\0"
    "QTextCharFormat\0format\0onTextUnderline_clicked\0"
    "checked\0onClear_clicked\0onSave_clicked\0"
    "onTextcolor_clicked\0onTextitalic_clicked\0"
    "onTextbold_clicked\0onFontComboBox_currentFontChanged\0"
    "f\0onFontsizecomboBox_currentIndexChanged\0"
    "onSendfile_clicked\0onSend_clicked\0"
    "onIconQuit_clicked\0onIconSetting_clicked\0"
    "onListItemUserClicked\0QListWidgetItem*\0"
    "pItem\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LANChat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08,
       3,    1,   95,    2, 0x08,
       4,    1,   98,    2, 0x08,
       7,    1,  101,    2, 0x08,
       9,    0,  104,    2, 0x08,
      10,    0,  105,    2, 0x08,
      11,    0,  106,    2, 0x08,
      12,    1,  107,    2, 0x08,
      13,    1,  110,    2, 0x08,
      14,    1,  113,    2, 0x08,
      16,    1,  116,    2, 0x08,
      17,    0,  119,    2, 0x08,
      18,    0,  120,    2, 0x08,
      19,    0,  121,    2, 0x08,
      20,    0,  122,    2, 0x08,
      21,    1,  123,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QFont,   15,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void LANChat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LANChat *_t = static_cast<LANChat *>(_o);
        switch (_id) {
        case 0: _t->processPendingDatagrams(); break;
        case 1: _t->sentFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->currentFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 3: _t->onTextUnderline_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onClear_clicked(); break;
        case 5: _t->onSave_clicked(); break;
        case 6: _t->onTextcolor_clicked(); break;
        case 7: _t->onTextitalic_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onTextbold_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->onFontComboBox_currentFontChanged((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 10: _t->onFontsizecomboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->onSendfile_clicked(); break;
        case 12: _t->onSend_clicked(); break;
        case 13: _t->onIconQuit_clicked(); break;
        case 14: _t->onIconSetting_clicked(); break;
        case 15: _t->onListItemUserClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject LANChat::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LANChat.data,
      qt_meta_data_LANChat,  qt_static_metacall, 0, 0}
};


const QMetaObject *LANChat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LANChat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LANChat.stringdata))
        return static_cast<void*>(const_cast< LANChat*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LANChat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
