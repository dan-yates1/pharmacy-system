#include "database.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Database::Database()
{
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName("pharmacy.db");

    if (!db_.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

Database::~Database()
{
    if (db_.open())
    {
        db_.close();
    }
}

bool Database::InsertPatient(Patient patient)
{
    bool success = false;

    QSqlQuery qry;
    qry.prepare("INSERT INTO patient (first_name,last_name,dob) VALUES(:first_name,:last_name,:dob)");
    qry.bindValue(":first_name", patient.get_fname());
    qry.bindValue(":last_name", patient.get_lname());
    qry.bindValue(":dob", patient.get_dob().toString("dd-MM-yyyy"));

    if(qry.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add patient failed: " << qry.lastError();
    }

    return success;
}

bool Database::InsertBloodwork(Bloodwork b)
{
    bool success = false;

    QSqlQuery qry;
    qry.prepare("INSERT INTO bloodwork (patient_id,reason,date) VALUES(:patient_id,:reason,:date)");
    qry.bindValue(":patient_id", b.get_patient_id());
    qry.bindValue(":reason", b.get_reason());
    qry.bindValue(":date", b.get_date().toString("yyyy-MM-dd"));

    if(qry.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add bloodwork failed: " << qry.lastError();
    }

    return success;
}

bool Database::InsertPrescription(Prescription p)
{
    bool success = false;

    QSqlQuery qry;
    qry.prepare("INSERT INTO prescription (patient_id,medication,start_date,end_date) VALUES(:patient_id,:medication,:start_date,:end_date)");
    qry.bindValue(":patient_id", p.get_patient_id());
    qry.bindValue(":medication", p.get_drug());
    qry.bindValue(":start_date", p.get_start_date().toString("yyyy-MM-dd"));
    qry.bindValue(":end_date", p.get_end_date().toString("yyyy-MM-dd"));

    if(qry.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add prescription failed: " << qry.lastError();
    }

    return success;
}

void Database::PrintAllPatients()
{
    QSqlQuery query("SELECT * FROM patient");
    int patientId = query.record().indexOf("first_name");
    while (query.next())
    {
        QString name = query.value(patientId).toString();
        qDebug()<< name;
    }
}

int Database::GetPatientId(QString name)
{
    int id;
    QSqlQuery query("SELECT id FROM patient WHERE");
    int index = query.record().indexOf("id");
    while (query.next())
    {
        id = query.value(index).toInt();
    }
    return id;
}

QString Database::GetPatient(int id)
{
    QSqlQuery query("SELECT * FROM patient");
    int fnameIndex = query.record().indexOf("first_name");
    int lnameIndex = query.record().indexOf("last_name");
    int idIndex = query.record().indexOf("id");
    QString fname;
    QString lname;
    while (query.next())
    {
        int patientId = query.value(idIndex).toInt();
        if (patientId == id)
        {
            fname = query.value(fnameIndex).toString();
            lname = query.value(lnameIndex).toString();
        }
    }
    return fname + " " + lname;
}

QList<Bloodwork> Database::GetBloodwork()
{
    QSqlQuery query("SELECT * FROM bloodwork");
    int idIndex = query.record().indexOf("patient_id");
    int reasonIndex = query.record().indexOf("reason");
    int dateIndex = query.record().indexOf("date");
    QList<Bloodwork> bList;
    while (query.next())
    {
        Bloodwork b;
        b.set_patient_id(query.value(idIndex).toInt());
        b.set_reason(query.value(reasonIndex).toString());
        b.set_date(query.value(dateIndex).toDate());
        bList.append(b);
    }
    return bList;
}

QList<Prescription> Database::GetPrescription()
{
    QSqlQuery query("SELECT * FROM prescription");
    int idIndex = query.record().indexOf("patient_id");
    int medIndex = query.record().indexOf("medication");
    int startDateIndex = query.record().indexOf("start_date");
    int endDateIndex = query.record().indexOf("end_date");
    QList<Prescription> pList;
    while (query.next())
    {
        Prescription p;
        p.set_patient_id(query.value(idIndex).toInt());
        p.set_drug(query.value(medIndex).toString());
        p.set_start_date(query.value(startDateIndex).toDate());
        p.set_end_date(query.value(endDateIndex).toDate());
        pList.append(p);
    }
    return pList;
}
