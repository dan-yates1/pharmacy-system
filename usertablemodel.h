#ifndef USERTABLEMODEL_H
#define USERTABLEMODEL_H


#include <QAbstractTableModel>


class userTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    userTableModel(QObject *parent = 0);

    void populateData(const QList<QString> &fname,const QList<QString> &lname,const QList<QString> &dob);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> tm_fname;
    QList<QString> tm_lname;
    QList<QString> tm_dob;

};

#endif // USERTABLEMODEL_H
