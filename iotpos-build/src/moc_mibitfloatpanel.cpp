/****************************************************************************
** Meta object code from reading C++ file 'mibitfloatpanel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mibitWidgets/mibitfloatpanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mibitfloatpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MibitFloatPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   16,   16,   16, 0x0a,
      51,   16,   16,   16, 0x0a,
      70,   16,   16,   16, 0x0a,
      82,   16,   16,   16, 0x0a,
      96,   91,   16,   16, 0x08,
     109,   16,   16,   16, 0x08,
     129,   16,   16,   16, 0x08,
     142,   16,   16,   16, 0x08,
     164,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MibitFloatPanel[] = {
    "MibitFloatPanel\0\0hiddenOnUserRequest()\0"
    "showPanel()\0showPanelDelayed()\0"
    "hidePanel()\0fixPos()\0step\0animate(int)\0"
    "hideOnUserRequest()\0hideDialog()\0"
    "onAnimationFinished()\0reposition()\0"
};

void MibitFloatPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MibitFloatPanel *_t = static_cast<MibitFloatPanel *>(_o);
        switch (_id) {
        case 0: _t->hiddenOnUserRequest(); break;
        case 1: _t->showPanel(); break;
        case 2: _t->showPanelDelayed(); break;
        case 3: _t->hidePanel(); break;
        case 4: _t->fixPos(); break;
        case 5: _t->animate((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->hideOnUserRequest(); break;
        case 7: _t->hideDialog(); break;
        case 8: _t->onAnimationFinished(); break;
        case 9: _t->reposition(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MibitFloatPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MibitFloatPanel::staticMetaObject = {
    { &QSvgWidget::staticMetaObject, qt_meta_stringdata_MibitFloatPanel,
      qt_meta_data_MibitFloatPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MibitFloatPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MibitFloatPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MibitFloatPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MibitFloatPanel))
        return static_cast<void*>(const_cast< MibitFloatPanel*>(this));
    return QSvgWidget::qt_metacast(_clname);
}

int MibitFloatPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSvgWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MibitFloatPanel::hiddenOnUserRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
