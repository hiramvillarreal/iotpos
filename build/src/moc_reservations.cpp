/****************************************************************************
** Meta object code from reading C++ file 'reservations.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/reservations.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reservations.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ReservationsDialogUI[] = {

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

static const char qt_meta_stringdata_ReservationsDialogUI[] = {
    "ReservationsDialogUI\0"
};

void ReservationsDialogUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ReservationsDialogUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ReservationsDialogUI::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ReservationsDialogUI,
      qt_meta_data_ReservationsDialogUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReservationsDialogUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReservationsDialogUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReservationsDialogUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReservationsDialogUI))
        return static_cast<void*>(const_cast< ReservationsDialogUI*>(this));
    if (!strcmp(_clname, "Ui::reservationsDialog"))
        return static_cast< Ui::reservationsDialog*>(const_cast< ReservationsDialogUI*>(this));
    return QFrame::qt_metacast(_clname);
}

int ReservationsDialogUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ReservationsDialog[] = {

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
      26,   20,   19,   19, 0x08,
      64,   51,   19,   19, 0x08,
     102,   19,   19,   19, 0x08,
     115,   19,   19,   19, 0x08,
     128,   19,   19,   19, 0x08,
     155,  148,   19,   19, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ReservationsDialog[] = {
    "ReservationsDialog\0\0index\0"
    "itemClicked(QModelIndex)\0index,indexp\0"
    "item_Clicked(QModelIndex,QModelIndex)\0"
    "setupModel()\0selectItem()\0cancelReservation()\0"
    "button\0slotButtonClicked(int)\0"
};

void ReservationsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ReservationsDialog *_t = static_cast<ReservationsDialog *>(_o);
        switch (_id) {
        case 0: _t->itemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->item_Clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 2: _t->setupModel(); break;
        case 3: _t->selectItem(); break;
        case 4: _t->cancelReservation(); break;
        case 5: _t->slotButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ReservationsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ReservationsDialog::staticMetaObject = {
    { &KDialog::staticMetaObject, qt_meta_stringdata_ReservationsDialog,
      qt_meta_data_ReservationsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReservationsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReservationsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReservationsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReservationsDialog))
        return static_cast<void*>(const_cast< ReservationsDialog*>(this));
    return KDialog::qt_metacast(_clname);
}

int ReservationsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
