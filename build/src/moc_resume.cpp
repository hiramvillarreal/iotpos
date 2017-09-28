/****************************************************************************
** Meta object code from reading C++ file 'resume.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/resume.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resume.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ResumeDialogUI[] = {

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

static const char qt_meta_stringdata_ResumeDialogUI[] = {
    "ResumeDialogUI\0"
};

void ResumeDialogUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ResumeDialogUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ResumeDialogUI::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ResumeDialogUI,
      qt_meta_data_ResumeDialogUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ResumeDialogUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ResumeDialogUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ResumeDialogUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResumeDialogUI))
        return static_cast<void*>(const_cast< ResumeDialogUI*>(this));
    if (!strcmp(_clname, "Ui::resumeDialog"))
        return static_cast< Ui::resumeDialog*>(const_cast< ResumeDialogUI*>(this));
    return QFrame::qt_metacast(_clname);
}

int ResumeDialogUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ResumeDialog[] = {

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
      20,   14,   13,   13, 0x08,
      58,   45,   13,   13, 0x08,
      96,   13,   13,   13, 0x08,
     109,   13,   13,   13, 0x08,
     122,   13,   13,   13, 0x08,
     144,  137,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ResumeDialog[] = {
    "ResumeDialog\0\0index\0itemClicked(QModelIndex)\0"
    "index,indexp\0item_Clicked(QModelIndex,QModelIndex)\0"
    "setupModel()\0selectItem()\0filterClient()\0"
    "button\0slotButtonClicked(int)\0"
};

void ResumeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ResumeDialog *_t = static_cast<ResumeDialog *>(_o);
        switch (_id) {
        case 0: _t->itemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->item_Clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 2: _t->setupModel(); break;
        case 3: _t->selectItem(); break;
        case 4: _t->filterClient(); break;
        case 5: _t->slotButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ResumeDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ResumeDialog::staticMetaObject = {
    { &KDialog::staticMetaObject, qt_meta_stringdata_ResumeDialog,
      qt_meta_data_ResumeDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ResumeDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ResumeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ResumeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResumeDialog))
        return static_cast<void*>(const_cast< ResumeDialog*>(this));
    return KDialog::qt_metacast(_clname);
}

int ResumeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
