#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>


class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TableModel(QObject *parent = 0);

    void populateData(const QList<QString> &patient,const QList<QString> &reason,const QList<QString> &date);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> tm_patient;
    QList<QString> tm_reason;
    QList<QString> tm_date;

};

#endif // TABLEMODEL_H
