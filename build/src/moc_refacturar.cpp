/****************************************************************************
** Meta object code from reading C++ file 'refacturar.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/refacturar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'refacturar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RefacturarDialogUI[] = {

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

static const char qt_meta_stringdata_RefacturarDialogUI[] = {
    "RefacturarDialogUI\0"
};

void RefacturarDialogUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RefacturarDialogUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RefacturarDialogUI::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_RefacturarDialogUI,
      qt_meta_data_RefacturarDialogUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RefacturarDialogUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RefacturarDialogUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RefacturarDialogUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RefacturarDialogUI))
        return static_cast<void*>(const_cast< RefacturarDialogUI*>(this));
    if (!strcmp(_clname, "Ui::refacturarDialog"))
        return static_cast< Ui::refacturarDialog*>(const_cast< RefacturarDialogUI*>(this));
    return QFrame::qt_metacast(_clname);
}

int RefacturarDialogUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_RefacturarDialog[] = {

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
      24,   18,   17,   17, 0x08,
      62,   49,   17,   17, 0x08,
     100,   17,   17,   17, 0x08,
     113,   17,   17,   17, 0x08,
     133,  126,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_RefacturarDialog[] = {
    "RefacturarDialog\0\0index\0"
    "itemClicked(QModelIndex)\0index,indexp\0"
    "item_Clicked(QModelIndex,QModelIndex)\0"
    "setupModel()\0selectItem()\0button\0"
    "slotButtonClicked(int)\0"
};

void RefacturarDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RefacturarDialog *_t = static_cast<RefacturarDialog *>(_o);
        switch (_id) {
        case 0: _t->itemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->item_Clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 2: _t->setupModel(); break;
        case 3: _t->selectItem(); break;
        case 4: _t->slotButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RefacturarDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RefacturarDialog::staticMetaObject = {
    { &KDialog::staticMetaObject, qt_meta_stringdata_RefacturarDialog,
      qt_meta_data_RefacturarDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RefacturarDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RefacturarDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RefacturarDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RefacturarDialog))
        return static_cast<void*>(const_cast< RefacturarDialog*>(this));
    return KDialog::qt_metacast(_clname);
}

int RefacturarDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
