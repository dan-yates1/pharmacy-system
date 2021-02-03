#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QtSql>
#include <QMessageBox>
#include "patient.h"

class Database
{
public:
    Database();
    ~Database();
    QString get_host_name();
    void set_host_name(QString host_name);
    QString get_db_name();
    void set_db_name(QString db_name);
    QString get_user_name();
    void set_user_name(QString user_name);
    QString get_password();
    void set_password(QString password);

    bool CreateConnection();
    void SearchQuery(QString query);
    void InsertQuery(QString query);
    void InsertPatient(int id, QString fname, QString lname, QDate dob);
private:
    QString host_name_ = "eu-cdbr-west-03.cleardb.net";
    QString db_name_ = "heroku_3b02253450d4321";
    QString user_name_ = "bb28d403eafa14";
    QString password_ = "dccd0f34";
};

#endif // DATABASE_H
