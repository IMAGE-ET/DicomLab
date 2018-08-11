// Project includes
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filelistmodel.h"

// Library includes
#include <memory>

// Qt includes
#include <QMessageBox>
#include <QStringList>
#include <QStandardItemModel>

#define PLUGINS_SUBFOLDER                   "/dlplugins/"
#define LANGUAGES_SUBFOLDER                 "/languages/"
#define THEMES_SUBFOLDER                    "/themes/"
#define FILE_ON_DISK_DYNAMIC_PROPERTY       "absolute_file_path"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    loadSettings();

    populatePluginsMenu();
    populateLanguagesMenu();
    populateThemesMenu();

    setupUI();
}

MainWindow::~MainWindow()
{
    delete m_currentPlugin;
    delete m_ui;
}

void MainWindow::loadSettings()
{
    QSettings settings("DicomLab", "Dicom_Lab", this);
    m_currentThemeFile = settings.value("currentThemeFile", "").toString();
    m_currentLanguageFile = settings.value("currentLanguageFile", "").toString();
    m_currentPluginFile = settings.value("currentPluginFile", "").toString();
}

void MainWindow::saveSettings()
{
    QSettings settings("DicomLab", "Dicom_Lab", this);
    settings.setValue("currentThemeFile", m_currentThemeFile);
    settings.setValue("currentLanguageFile", m_currentLanguageFile);
    settings.setValue("currentPluginFile", m_currentPluginFile);
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        m_ui->retranslateUi(this);
    }
    else
    {
        QMainWindow::changeEvent(event);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveSettings();
    event->accept();
}

void MainWindow::populatePluginsMenu()
{
    // Load all plugins and populate the menus
    QDir pluginsDir(qApp->applicationDirPath() + PLUGINS_SUBFOLDER);
    QFileInfoList pluginFiles = pluginsDir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files, QDir::Name);
    foreach(QFileInfo pluginFile, pluginFiles)
    {
        if(QLibrary::isLibrary(pluginFile.absoluteFilePath()))
        {
            QPluginLoader pluginLoader(pluginFile.absoluteFilePath(), this);
            if(DlPluginInterface *plugin = dynamic_cast<DlPluginInterface*>(pluginLoader.instance()))
            {
                QAction *pluginAction = m_ui->menu_Plugins->addAction(plugin->title());
                pluginAction->setProperty(FILE_ON_DISK_DYNAMIC_PROPERTY, pluginFile.absoluteFilePath());
                connect(pluginAction, SIGNAL(triggered(bool)), this, SLOT(onPluginActionTriggered(bool)));
                if(m_currentPluginFile == pluginFile.absoluteFilePath())
                {
                    pluginAction->trigger();
                }
            }
            else
            {
                QMessageBox::warning(this, tr("Warning"),
                                     QString(tr("Make sure %1 is a correct plugin for this application<br>"
                                                "and it's not in use by some other application!")).arg(pluginFile.fileName()));
            }
        }
        else
        {
            QMessageBox::warning(this, tr("Warning"),
                                 QString(tr("Make sure only plugins exist in %1 folder.<br>"
                                            "%2 is not a plugin."))
                                 .arg(PLUGINS_SUBFOLDER)
                                 .arg(pluginFile.fileName()));
        }
    }

    if(m_ui->menu_Plugins->actions().count() <= 0)
    {
        QMessageBox::critical(this, tr("No Plugins"), QString(tr("This application cannot work without plugins!"
                                                                 "<br>Make sure that %1 folder exists "
                                                                 "in the same folder as the application<br>and that "
                                                                 "there are some filter plugins inside it")).arg(PLUGINS_SUBFOLDER));
        this->setEnabled(false);
    }
}

void MainWindow::populateLanguagesMenu()
{
    QMenu *languagesMenu = new QMenu(this);
    // Add default (english) language
    QAction *defaultLanguageAction = languagesMenu->addAction("English - US");
    defaultLanguageAction->setProperty(FILE_ON_DISK_DYNAMIC_PROPERTY, "");
    connect(defaultLanguageAction, SIGNAL(triggered(bool)), this, SLOT(onLanguageActionTriggered(bool)));

    // Load all languages and populate the menus
    QDir languagesDir(qApp->applicationDirPath() + LANGUAGES_SUBFOLDER);
    QFileInfoList languageFiles = languagesDir.entryInfoList(QStringList() << "*.qm", QDir::NoDotAndDotDot | QDir::Files, QDir::Name);
    foreach(QFileInfo languageFile, languageFiles)
    {
        QAction *languageAction = languagesMenu->addAction(languageFile.baseName());
        languageAction->setProperty(FILE_ON_DISK_DYNAMIC_PROPERTY, languageFile.absoluteFilePath());
        connect(languageAction, SIGNAL(triggered(bool)), this, SLOT(onLanguageActionTriggered(bool)));

        if(m_currentLanguageFile == languageFile.absoluteFilePath())
        {
            languageAction->trigger();
        }
    }
    m_ui->actionLanguage->setMenu(languagesMenu);
}

void MainWindow::populateThemesMenu()
{
    QMenu *themesMenu = new QMenu(this);
    // Add default (native) theme
    QAction *defaultThemeAction = themesMenu->addAction("Default");
    defaultThemeAction->setProperty(FILE_ON_DISK_DYNAMIC_PROPERTY, "");
    connect(defaultThemeAction, SIGNAL(triggered(bool)), this, SLOT(onThemeActionTriggered(bool)));

    // Load all themes and populate the menus
    QDir themesDir(qApp->applicationDirPath() + THEMES_SUBFOLDER);
    QFileInfoList themeFiles = themesDir.entryInfoList(QStringList() << "*.thm", QDir::NoDotAndDotDot | QDir::Files, QDir::Name);
    foreach(QFileInfo themeFile, themeFiles)
    {
        QAction *themeAction = themesMenu->addAction(themeFile.baseName());
        themeAction->setProperty(FILE_ON_DISK_DYNAMIC_PROPERTY, themeFile.absoluteFilePath());
        connect(themeAction, SIGNAL(triggered(bool)), this, SLOT(onThemeActionTriggered(bool)));

        if(m_currentThemeFile == themeFile.absoluteFilePath())
        {
            themeAction->trigger();
        }
    }
    m_ui->actionTheme->setMenu(themesMenu);
}

void MainWindow::updateFileCount(int number)
{
    m_ui->txtbLogViewer->append(tr("%1 items added").arg(number));
}

void MainWindow::updateOnClickHandler(const QModelIndex& index)
{
    clearLogViewer();
    m_ui->txtbLogViewer->append(tr("%1 row %2 column clicked.").arg(index.row()).arg(index.column()));
    m_ui->txtbLogViewer->append(tr("Value of clicked item: %1").arg(index.data().toString()));
}

void MainWindow::clearLogViewer()
{
    m_ui->txtbLogViewer->clear();
}

void MainWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::onPluginActionTriggered(bool)
{
    if(!m_currentPlugin.isNull())
    {
        delete m_currentPlugin;
        delete m_currentPluginGui;
    }

    m_currentPluginFile = QObject::sender()->property(FILE_ON_DISK_DYNAMIC_PROPERTY).toString();
    m_currentPlugin = new QPluginLoader(m_currentPluginFile, this);
    m_currentPluginGui = new QWidget(this);
    m_ui->pluginLayout->addWidget(m_currentPluginGui);
    DlPluginInterface *currentPluginInstance = dynamic_cast<DlPluginInterface*>(m_currentPlugin->instance());

    if(currentPluginInstance)
    {
        currentPluginInstance->setupUi(m_currentPluginGui);
        connect(m_currentPlugin->instance(), SIGNAL(updateNeeded()), this, SLOT(onCurrentPluginUpdateNeeded()));
        connect(m_currentPlugin->instance(), SIGNAL(infoMessage(QString)), this, SLOT(onCurrentPluginInfoMessage(QString)));
        connect(m_currentPlugin->instance(), SIGNAL(errorMessage(QString)), this, SLOT(onCurrentPluginErrorMessage(QString)));
    }
}

void MainWindow::onLanguageActionTriggered(bool)
{
    m_currentLanguageFile = QObject::sender()->property(FILE_ON_DISK_DYNAMIC_PROPERTY).toString();
    qApp->removeTranslator(&m_translator);
    if(!m_currentLanguageFile.isEmpty())
    {
        m_translator.load(m_currentLanguageFile);
        qApp->installTranslator(&m_translator);
        m_ui->retranslateUi(this);
    }
}

void MainWindow::onThemeActionTriggered(bool)
{
    m_currentThemeFile = QObject::sender()->property(FILE_ON_DISK_DYNAMIC_PROPERTY).toString();
    QFile themeFile(m_currentThemeFile);
    if(m_currentThemeFile.isEmpty())
    {
        qApp->setStyleSheet("");
    }
    else
    {
        themeFile.open(QFile::ReadOnly | QFile::Text);
        QString styleSheet = themeFile.readAll();
        qApp->setStyleSheet(styleSheet);
        themeFile.close();
    }
}

void MainWindow::on_actionOpenImage_triggered()
{
}

void MainWindow::onCurrentPluginUpdateNeeded()
{
    // TODO
    QString msg = "Signal from Plugin received";
    QMessageBox::information(nullptr,tr("Trapped Plugin signal"),msg);
}

void MainWindow::on_actionSaveImage_triggered()
{
    // TODO
}

void MainWindow::onCurrentPluginErrorMessage(QString msg)
{
    qDebug() << "Plugin Error Message : " << msg;
}

void MainWindow::onCurrentPluginInfoMessage(QString msg)
{
    qDebug() << "Plugin Info Message : " << msg;
}

void MainWindow::on_action_Camera_triggered()
{

}

void MainWindow::setupUI()
{
    m_fileListModel = new FileListModel(this);
    QString defaultPath = "C:\\temp\\dcmtestdata";
    m_fileListModel->setDirPath(defaultPath);
    m_ui->lstFileList->setModel(m_fileListModel);

    m_ui->edtSourceDirectory->setText(defaultPath);

    connect(m_ui->edtSourceDirectory, &QLineEdit::textChanged,
            m_fileListModel, &FileListModel::setDirPath);
    connect(m_fileListModel, &FileListModel::numberPopulated,
            this, &MainWindow::updateFileCount);
    connect(m_ui->lstFileList, &QListView::clicked,
            this, &MainWindow::updateOnClickHandler);
}
