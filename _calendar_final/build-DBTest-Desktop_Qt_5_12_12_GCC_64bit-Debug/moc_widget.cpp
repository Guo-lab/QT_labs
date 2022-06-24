/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DBTest/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DayLabel_t {
    QByteArrayData data[8];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DayLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DayLabel_t qt_meta_stringdata_DayLabel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DayLabel"
QT_MOC_LITERAL(1, 9, 13), // "signalClicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "day"
QT_MOC_LITERAL(4, 28, 11), // "signalEnter"
QT_MOC_LITERAL(5, 40, 1), // "m"
QT_MOC_LITERAL(6, 42, 11), // "signalLeave"
QT_MOC_LITERAL(7, 54, 1) // "l"

    },
    "DayLabel\0signalClicked\0\0day\0signalEnter\0"
    "m\0signalLeave\0l"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DayLabel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       6,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void DayLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DayLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalEnter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signalLeave((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DayLabel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DayLabel::signalClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DayLabel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DayLabel::signalEnter)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DayLabel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DayLabel::signalLeave)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DayLabel::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_DayLabel.data,
    qt_meta_data_DayLabel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DayLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DayLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DayLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int DayLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DayLabel::signalClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DayLabel::signalEnter(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DayLabel::signalLeave(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[19];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 11), // "signalWheel"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 1), // "m"
QT_MOC_LITERAL(4, 22, 8), // "showTime"
QT_MOC_LITERAL(5, 31, 13), // "showLastMonth"
QT_MOC_LITERAL(6, 45, 13), // "showNextMonth"
QT_MOC_LITERAL(7, 59, 9), // "nianPanel"
QT_MOC_LITERAL(8, 69, 8), // "yuePanel"
QT_MOC_LITERAL(9, 78, 7), // "toToday"
QT_MOC_LITERAL(10, 86, 8), // "initDate"
QT_MOC_LITERAL(11, 95, 6), // "onyiji"
QT_MOC_LITERAL(12, 102, 13), // "sltDayClicked"
QT_MOC_LITERAL(13, 116, 3), // "day"
QT_MOC_LITERAL(14, 120, 11), // "sltDayEnter"
QT_MOC_LITERAL(15, 132, 11), // "sltDayLeave"
QT_MOC_LITERAL(16, 144, 1), // "l"
QT_MOC_LITERAL(17, 146, 11), // "sltDayWheel"
QT_MOC_LITERAL(18, 158, 10) // "updateData"

    },
    "Widget\0signalWheel\0\0m\0showTime\0"
    "showLastMonth\0showNextMonth\0nianPanel\0"
    "yuePanel\0toToday\0initDate\0onyiji\0"
    "sltDayClicked\0day\0sltDayEnter\0sltDayLeave\0"
    "l\0sltDayWheel\0updateData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   87,    2, 0x08 /* Private */,
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    1,   94,    2, 0x08 /* Private */,
      12,    1,   97,    2, 0x08 /* Private */,
      14,    1,  100,    2, 0x08 /* Private */,
      15,    1,  103,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      18,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalWheel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->showTime(); break;
        case 2: _t->showLastMonth(); break;
        case 3: _t->showNextMonth(); break;
        case 4: _t->nianPanel(); break;
        case 5: _t->yuePanel(); break;
        case 6: _t->toToday(); break;
        case 7: _t->initDate(); break;
        case 8: _t->onyiji((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->sltDayClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->sltDayEnter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->sltDayLeave((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->sltDayWheel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->updateData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::signalWheel)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void Widget::signalWheel(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
