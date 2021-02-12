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
    if (db_.isOpen())
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
