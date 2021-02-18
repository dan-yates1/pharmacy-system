#ifndef PRESCRIPTIONTABLEMODEL_H
#define PRESCRIPTIONTABLEMODEL_H


#include <QAbstractTableModel>


class prescriptionTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    prescriptionTableModel(QObject *parent = 0);

    void populateData(const QList<QString> &patient,const QList<QString> &medication,const QList<QString> &startdate,const QList<QString> &enddate);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> tm_patient;
    QList<QString> tm_medication;
    QList<QString> tm_startdate;
    QList<QString> tm_enddate;
};

#endif // PRESCRIPTIONTABLEMODEL_H
