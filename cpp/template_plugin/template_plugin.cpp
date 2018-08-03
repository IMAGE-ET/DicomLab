#include "template_plugin.h"

#include "ui_plugin.h"

Template_Plugin::Template_Plugin()
{
    // Insert initialization codes here ...
}

Template_Plugin::~Template_Plugin()
{
    // Insert cleanup codes here ...
}

QString Template_Plugin::title()
{
    return this->metaObject()->className();
}

QString Template_Plugin::version()
{
    return "1.0.0";
}

QString Template_Plugin::description()
{
    return "A <b>Template</b> plugin";
}

QString Template_Plugin::help()
{
    return "This is a <b>Template</b> plugin. Clone and use it to create new plugins.";
}

void Template_Plugin::setupUi(QWidget *parent)
{
    m_ui = new Ui::PluginGui;
    m_ui->setupUi(parent);

    // Connect signals for GUI elemnts manually here since they won't be connected by name in a plugin
    // ...
    // emit updateNeeded(); should be added whenever parameters on the plugin GUI change
}
