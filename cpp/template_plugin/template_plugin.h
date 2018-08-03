#ifndef TEMPLATE_PLUGIN_H
#define TEMPLATE_PLUGIN_H

#include "template_plugin_global.h"
#include "dlplugininterface.h"

namespace Ui {
    class PluginGui;
}

class TEMPLATE_PLUGINSHARED_EXPORT Template_Plugin: public QObject, public DlPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.dicomlab.dlplugininterface")
    Q_INTERFACES(DlPluginInterface)
public:
    Template_Plugin();
    ~Template_Plugin();

    QString title();
    QString version();
    QString description();
    QString help();
    void setupUi(QWidget *parent);

signals:
    void updateNeeded();
    void errorMessage(QString msg);
    void infoMessage(QString msg);

private:
    Ui::PluginGui *m_ui;
};

#endif // TEMPLATE_PLUGIN_H
