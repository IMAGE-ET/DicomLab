#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDir>
#include <QFileInfoList>
#include <QLibrary>
#include <QPluginLoader>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QTranslator>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QMutex>
#include <QWaitCondition>

#include "dlplugininterface.h"

QT_BEGIN_NAMESPACE
class FileListModel;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);

private slots:
    void onPluginActionTriggered(bool);
    void onLanguageActionTriggered(bool);
    void onThemeActionTriggered(bool);
    void onCurrentPluginUpdateNeeded();
    void onCurrentPluginErrorMessage(QString msg);
    void onCurrentPluginInfoMessage(QString msg);
    void on_actionAboutQt_triggered();
    void on_actionExit_triggered();
    void on_actionOpenImage_triggered();
    void on_actionSaveImage_triggered();
    void on_action_Camera_triggered();

private:
    void setupUI();
    void loadSettings();
    void saveSettings();
    void populatePluginsMenu();
    void populateLanguagesMenu();
    void populateThemesMenu();

private slots:
    void updateFileCount(int number);
    void updateOnClickHandler(const QModelIndex& index);
    void clearLogViewer();

private:
    Ui::MainWindow *m_ui;
    QString m_currentThemeFile;
    QString m_currentLanguageFile;
    QString m_currentPluginFile;
    QPointer<QPluginLoader> m_currentPlugin;
    QPointer<QWidget> m_currentPluginGui;
    QTranslator m_translator;
    FileListModel* m_fileListModel;
};

#endif // MAINWINDOW_H
