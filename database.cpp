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
    QString fname = "John";
    QString lname = "Brown";
    QString dob = "01-01-1990";

    QSqlQuery qry;
    qry.prepare("INSERT INTO patient (first_name,last_name,dob) VALUES(:first_name,:last_name,:dob)");
    //qry.bindValue(":id", patient.get_fname());
    qry.bindValue(":first_name", patient.get_fname());
    qry.bindValue(":last_name", patient.get_lname());
    qry.bindValue(":dob", "1990-01-01");

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
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM patient");
    int idName = query.record().indexOf("first_name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}
