#include "tablemodel.h"

TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent)
{
}

void TableModel::populateData(const QList<QString> &patient,const QList<QString> &reason,const QList<QString> &date)
{
    tm_patient.clear();
    tm_patient = patient;
    tm_reason.clear();
    tm_reason = reason;
    tm_date.clear();
    tm_date = date;
    return;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_patient.length();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return tm_patient[index.row()];
    } else if (index.column() == 1) {
        return tm_reason[index.row()];
    } else if (index.column() == 2) {
        return tm_date[index.row()];
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Patient");
        } else if (section == 1) {
            return QString("Reason");
        } else if (section == 2) {
            return QString("Booked Date");
        }
    }
    return QVariant();
}
