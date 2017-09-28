/****************************************************************************
** Meta object code from reading C++ file 'mibitpassworddlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mibitWidgets/mibitpassworddlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mibitpassworddlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MibitPasswordDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   37,   20,   20, 0x08,
      55,   20,   20,   20, 0x08,
      65,   37,   20,   20, 0x08,
      77,   20,   20,   20, 0x08,
      99,   20,   20,   20, 0x0a,
     107,   20,   20,   20, 0x0a,
     128,  114,   20,   20, 0x0a,
     167,  163,   20,   20, 0x2a,
     187,   20,   20,   20, 0x2a,
     200,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MibitPasswordDialog[] = {
    "MibitPasswordDialog\0\0returnPressed()\0"
    "step\0animate(int)\0shakeIt()\0waveIt(int)\0"
    "onAnimationFinished()\0shake()\0wave()\0"
    "msg,animation\0showDialog(QString,AnimationTypeP)\0"
    "msg\0showDialog(QString)\0showDialog()\0"
    "hideDialog()\0"
};

void MibitPasswordDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MibitPasswordDialog *_t = static_cast<MibitPasswordDialog *>(_o);
        switch (_id) {
        case 0: _t->returnPressed(); break;
        case 1: _t->animate((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->shakeIt(); break;
        case 3: _t->waveIt((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->onAnimationFinished(); break;
        case 5: _t->shake(); break;
        case 6: _t->wave(); break;
        case 7: _t->showDialog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< AnimationTypeP(*)>(_a[2]))); break;
        case 8: _t->showDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->showDialog(); break;
        case 10: _t->hideDialog(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MibitPasswordDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MibitPasswordDialog::staticMetaObject = {
    { &QSvgWidget::staticMetaObject, qt_meta_stringdata_MibitPasswordDialog,
      qt_meta_data_MibitPasswordDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MibitPasswordDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MibitPasswordDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MibitPasswordDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MibitPasswordDialog))
        return static_cast<void*>(const_cast< MibitPasswordDialog*>(this));
    return QSvgWidget::qt_metacast(_clname);
}

int MibitPasswordDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSvgWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MibitPasswordDialog::returnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
