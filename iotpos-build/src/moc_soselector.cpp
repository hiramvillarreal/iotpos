/****************************************************************************
** Meta object code from reading C++ file 'soselector.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/soselector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soselector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SOSelectorUI[] = {

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

static const char qt_meta_stringdata_SOSelectorUI[] = {
    "SOSelectorUI\0"
};

void SOSelectorUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SOSelectorUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SOSelectorUI::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_SOSelectorUI,
      qt_meta_data_SOSelectorUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SOSelectorUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SOSelectorUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SOSelectorUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SOSelectorUI))
        return static_cast<void*>(const_cast< SOSelectorUI*>(this));
    if (!strcmp(_clname, "Ui::soSelector"))
        return static_cast< Ui::soSelector*>(const_cast< SOSelectorUI*>(this));
    return QFrame::qt_metacast(_clname);
}

int SOSelectorUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SOSelector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      32,   26,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      90,   83,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_SOSelector[] = {
    "SOSelector\0\0applyFilter()\0index\0"
    "itemClicked(QModelIndex)\0setupModel()\0"
    "selectItem()\0button\0slotButtonClicked(int)\0"
};

void SOSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SOSelector *_t = static_cast<SOSelector *>(_o);
        switch (_id) {
        case 0: _t->applyFilter(); break;
        case 1: _t->itemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->setupModel(); break;
        case 3: _t->selectItem(); break;
        case 4: _t->slotButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SOSelector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SOSelector::staticMetaObject = {
    { &KDialog::staticMetaObject, qt_meta_stringdata_SOSelector,
      qt_meta_data_SOSelector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SOSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SOSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SOSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SOSelector))
        return static_cast<void*>(const_cast< SOSelector*>(this));
    return KDialog::qt_metacast(_clname);
}

int SOSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
