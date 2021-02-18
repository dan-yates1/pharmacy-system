#include "viewbloodwork.h"
#include "ui_viewbloodwork.h"
#include "database.h"
#include "tablemodel.h"
#include <QSqlTableModel>
#include <QDebug>

viewBloodwork::viewBloodwork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewBloodwork)
{
    ui->setupUi(this);
    populateList();
}

viewBloodwork::~viewBloodwork()
{
    delete ui;
}

void viewBloodwork::populateList()
{
    Database db;
    QList<Bloodwork> bloodworkList = db.GetBloodwork();
    QStringList reasonList;
    QStringList idList;
    QStringList dateList;

    QList<Bloodwork>::iterator iter = bloodworkList.begin();
    while(iter != bloodworkList.end()){
        Bloodwork& b = *iter;
        QString id = db.GetPatient(b.get_patient_id());
        idList << id;
        QString reason = b.get_reason();
        reasonList << reason;
        QString date = b.get_date().toString("dd-MM-yyyy");
        dateList << date;
        qDebug() << date;
        iter++;
    }

    TableModel *BloodworkModel = new TableModel(this);
    BloodworkModel->populateData(idList, reasonList, dateList);
    ui->tableView->setModel(BloodworkModel);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(150);
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();
}

