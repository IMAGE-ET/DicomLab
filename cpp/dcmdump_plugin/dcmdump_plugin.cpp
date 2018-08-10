#include "dcmdump_plugin.h"
#include "ui_plugin.h"

#include <QMessageBox>
#include <QDebug>

// DCMTK includes
#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/dcdeftag.h"
#include "dcmtk/dcmdata/dcfilefo.h"

Dcmdump_Plugin::Dcmdump_Plugin()
{
    // Insert initialization codes here ...
}

Dcmdump_Plugin::~Dcmdump_Plugin()
{
    // Insert cleanup codes here ...
}

QString Dcmdump_Plugin::title()
{
    return this->metaObject()->className();
}

QString Dcmdump_Plugin::version()
{
    return "1.0.0";
}

QString Dcmdump_Plugin::description()
{
    return "A <b>Template</b> plugin";
}

QString Dcmdump_Plugin::help()
{
    return "This is a <b>Template</b> plugin. Clone and use it to create new plugins.";
}

void Dcmdump_Plugin::setupUi(QWidget *parent)
{
    m_ui = new Ui::PluginGui;
    m_ui->setupUi(parent);

    // Connect signals for GUI elemnts manually here since they won't be connected by name in a plugin
    // ...
    // emit updateNeeded(); should be added whenever parameters on the plugin GUI change
    connect(m_ui->btnProcess, SIGNAL(clicked(bool)), this, SLOT(onStartDumpButtonClicked()));
}

void Dcmdump_Plugin::onStartDumpButtonClicked()
{
    dumpDcmFile();
}

// test whether DCMTK is working or not.
// Currently loads a test DICOM file and dumps some information
void Dcmdump_Plugin::dumpDcmFile()
{
    // get the test data to load
    QString filePath = "c:\\temp\\liver.dcm";

    qDebug() << "\nTest data file path: \n" << filePath << "\n";

    DcmFileFormat fileFormat;
    OFCondition status = fileFormat.loadFile(filePath.toStdString().c_str());

    if (!status.good()) {
        qDebug() << "Error in loading a DICOM file.";
        return;
    }

    OFString patientName;
    if (fileFormat.getDataset()->findAndGetOFString(DCM_PatientName,patientName).good()) {
        qDebug() << "Patient's Name: " << patientName.c_str();
    }
    else {
        qDebug() << "Cannot access Patient's Name.";
    }

    OFString patientID;
    if (fileFormat.getDataset()->findAndGetOFString(DCM_PatientID, patientID).good()) {
        qDebug() << "Patient's ID: " << patientID.c_str();
    }
    else {
        qDebug() << "Cannot access Patient's ID.";
    }

    OFString studyInstanceUID;
    if (fileFormat.getDataset()->findAndGetOFString(DCM_StudyInstanceUID, studyInstanceUID).good()) {
        qDebug() << "Study Instance UID ID: " << studyInstanceUID.c_str();
    }
    else {
        qDebug() << "Cannot access Patient's ID.";
    }

    QStringList msgList;
    patientName = "Patient Name: " + patientName;
    msgList << patientName.c_str();
    patientID = "Patient Id: " + patientID;
    msgList << patientID.c_str();
    studyInstanceUID = "Study Instance UID: " + studyInstanceUID;
    msgList << studyInstanceUID.c_str();

    msgList << "End of DCMTK test.";
    QString msg = msgList.join("\n");

    QMessageBox::information(nullptr,tr("Contents of DICOM file"),msg);

    return;
}
