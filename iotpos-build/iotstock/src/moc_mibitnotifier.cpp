/****************************************************************************
** Meta object code from reading C++ file 'mibitnotifier.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mibitWidgets/mibitnotifier.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mibitnotifier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MibitNotifier[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x08,
      33,   14,   14,   14, 0x08,
      46,   14,   14,   14, 0x08,
      66,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MibitNotifier[] = {
    "MibitNotifier\0\0step\0animate(int)\0"
    "hideDialog()\0hideOnUserRequest()\0"
    "onAnimationFinished()\0"
};

void MibitNotifier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MibitNotifier *_t = static_cast<MibitNotifier *>(_o);
        switch (_id) {
        case 0: _t->animate((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->hideDialog(); break;
        case 2: _t->hideOnUserRequest(); break;
        case 3: _t->onAnimationFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MibitNotifier::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MibitNotifier::staticMetaObject = {
    { &QSvgWidget::staticMetaObject, qt_meta_stringdata_MibitNotifier,
      qt_meta_data_MibitNotifier, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MibitNotifier::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MibitNotifier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MibitNotifier::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MibitNotifier))
        return static_cast<void*>(const_cast< MibitNotifier*>(this));
    return QSvgWidget::qt_metacast(_clname);
}

int MibitNotifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSvgWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
