#ifndef FILEITEMSMODEL_H
#define FILEITEMSMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QStringList>

class FileListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    FileListModel(QObject *parent = 0);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QStringList getFileList() const;
    int getFileCount() const;

signals:
    void numberPopulated(int number);

public slots:
    void setDirPath(const QString& path);

protected:
    bool canFetchMore(const QModelIndex& parent) const override;
    void fetchMore(const QModelIndex& parent) override;

private:
    QStringList m_fileList;
    int m_fileCount;
};

#endif // FILEITEMSMODEL_H
