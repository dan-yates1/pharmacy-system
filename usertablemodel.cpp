#include "usertablemodel.h"

userTableModel::userTableModel(QObject *parent) : QAbstractTableModel(parent)
{
}

void userTableModel::populateData(const QList<QString> &patient,const QList<QString> &reason,const QList<QString> &date)
{
    tm_fname.clear();
    tm_fname = patient;
    tm_lname.clear();
    tm_lname = reason;
    tm_dob.clear();
    tm_dob = date;
    return;
}

int userTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_fname.length();
}

int userTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant userTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return tm_fname[index.row()];
    } else if (index.column() == 1) {
        return tm_lname[index.row()];
    } else if (index.column() == 2) {
        return tm_dob[index.row()];
    }
    return QVariant();
}

QVariant userTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("First Name");
        } else if (section == 1) {
            return QString("Last Name");
        } else if (section == 2) {
            return QString("Date of Birth");
        }
    }
    return QVariant();
}
