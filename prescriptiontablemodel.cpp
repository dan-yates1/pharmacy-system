#include "prescriptiontablemodel.h"

prescriptionTableModel::prescriptionTableModel(QObject *parent) : QAbstractTableModel(parent)
{
}

void prescriptionTableModel::populateData(const QList<QString> &patient,const QList<QString> &medication,const QList<QString> &startdate,const QList<QString> &enddate)
{
    tm_patient.clear();
    tm_patient = patient;
    tm_medication.clear();
    tm_medication = medication;
    tm_startdate.clear();
    tm_startdate = startdate;
    tm_enddate.clear();
    tm_enddate = enddate;
    return;
}

int prescriptionTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_patient.length();
}

int prescriptionTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

QVariant prescriptionTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return tm_patient[index.row()];
    } else if (index.column() == 1) {
        return tm_medication[index.row()];
    } else if (index.column() == 2) {
        return tm_startdate[index.row()];
    } else if (index.column() == 3) {
        return tm_enddate[index.row()];
    }
    return QVariant();
}

QVariant prescriptionTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Patient");
        } else if (section == 1) {
            return QString("Medication");
        } else if (section == 2) {
            return QString("Start Date");
        } else if (section == 3) {
            return QString("End Date");
        }
    }
    return QVariant();
}
