#ifndef DLPLUGIN_H
#define DLPLUGIN_H

#include <QObject>
#include <QWidget>
#include <QString>

// DCMTK includes
#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/dcdeftag.h"

class DlPluginInterface
{
public:
    virtual ~DlPluginInterface() {}
    virtual QString title() = 0;
    virtual QString version() = 0;
    virtual QString description() = 0;
    virtual QString help() = 0;
    virtual void setupUi(QWidget *parent) = 0;
};

#define DLPLUGININTERFACE_IID "com.dicomlab.dlplugininterface"
Q_DECLARE_INTERFACE(DlPluginInterface, DLPLUGININTERFACE_IID)

#endif // DLPLUGIN_H
