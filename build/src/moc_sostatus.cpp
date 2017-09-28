/****************************************************************************
** Meta object code from reading C++ file 'sostatus.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/sostatus.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sostatus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SOStatusUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_SOStatusUI[] = {
    "SOStatusUI\0"
};

void SOStatusUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SOStatusUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SOStatusUI::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_SOStatusUI,
      qt_meta_data_SOStatusUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SOStatusUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SOStatusUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SOStatusUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SOStatusUI))
        return static_cast<void*>(const_cast< SOStatusUI*>(this));
    if (!strcmp(_clname, "Ui::soStatus"))
        return static_cast< Ui::soStatus*>(const_cast< SOStatusUI*>(this));
    return QFrame::qt_metacast(_clname);
}

int SOStatusUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SOStatus[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      30,   24,    9,    9, 0x08,
      55,    9,    9,    9, 0x08,
      68,    9,    9,    9, 0x08,
      81,    9,    9,    9, 0x08,
     110,  103,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_SOStatus[] = {
    "SOStatus\0\0applyFilter()\0index\0"
    "itemClicked(QModelIndex)\0setupModel()\0"
    "selectItem()\0populateStatusCombo()\0"
    "button\0slotButtonClicked(int)\0"
};

void SOStatus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SOStatus *_t = static_cast<SOStatus *>(_o);
        switch (_id) {
        case 0: _t->applyFilter(); break;
        case 1: _t->itemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->setupModel(); break;
        case 3: _t->selectItem(); break;
        case 4: _t->populateStatusCombo(); break;
        case 5: _t->slotButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SOStatus::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SOStatus::staticMetaObject = {
    { &KDialog::staticMetaObject, qt_meta_stringdata_SOStatus,
      qt_meta_data_SOStatus, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SOStatus::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SOStatus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SOStatus::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SOStatus))
        return static_cast<void*>(const_cast< SOStatus*>(this));
    return KDialog::qt_metacast(_clname);
}

int SOStatus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
