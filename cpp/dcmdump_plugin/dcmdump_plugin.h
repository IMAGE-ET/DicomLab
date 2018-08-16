#ifndef DCMDUMP_PLUGIN_H
#define DCMDUMP_PLUGIN_H

#include "dcmdump_plugin_global.h"
#include "dlplugininterface.h"

namespace Ui {
class PluginGui;
}

class DCMDUMP_PLUGINSHARED_EXPORT Dcmdump_Plugin : public QObject, public DlPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.dicomlab.dlplugininterface")
    Q_INTERFACES(DlPluginInterface)

public:
    Dcmdump_Plugin();
    ~Dcmdump_Plugin();

    QString title();
    QString version();
    QString description();
    QString help();
    void setupUi(QWidget *parent);

signals:
    void updateNeeded();
    void errorMessage(QString msg);
    void infoMessage(QString msg);

private slots:
    void onStartDumpButtonClicked();

private:
    void dumpDcmFile();

private:
    Ui::PluginGui *m_ui;
};

#endif // TEMPLATE_PLUGIN_H
