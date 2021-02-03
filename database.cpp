#include "database.h"

Database::Database()
{

}

Database::~Database()
{
    // close connection when object is destroyed
    //db.close();
}
/*
bool Database::CreateConnection()
{
    return true if connection made
    db.setHostName(host_name_);
    db.setDatabaseName(db_name_);
    db.setUserName(user_name_);
    db.setPassword(password_);

    // check database connection
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("DATABASE OPEN"),db.lastError().text());
        return false;
    }
    return true;
}

void Database::SearchQuery(QString query)
{
    if(db.open())
    {
        QSqlQuery qry(db);
        if(qry.exec(query))
        {
            while(qry.next())
            {
                qDebug() << qry.value(0).toString();
            }
        }
    }
    db.close();
}

void Database::InsertQuery(QString query)
{
    if(db.open())
    {
        QSqlQuery qry(db);
        qry.prepare("insert into patient (patient_id,first_name,las_name,dob) value(2,'Jane','Doe',1996-01-10");
        if(qry.exec())
        {
            qDebug() << "Yes";
        }
    }
}
*/
void Database::InsertPatient(int id, QString fname, QString lname, QDate dob)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "pharmacy-db");
    // return true if connection made
    db.setHostName(host_name_);
    db.setDatabaseName(db_name_);
    db.setUserName(user_name_);
    db.setPassword(password_);

    // check database connection
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("DATABASE OPEN"),db.lastError().text());
    } else {
        QSqlQuery qry(db);
        qry.prepare("INSERT INTO patient(patient_id,first_name,last_name,dob) VALUES (:id,':first_name',':last_name',':dob')");
        qry.bindValue(":id",id);
        qry.bindValue(":first_name",fname);
        qry.bindValue(":last_name",lname);
        qry.bindValue(":dob","1999-04-02");
        qry.exec();
    }
    db.close();
}
