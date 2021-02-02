#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include <QString>
#include <QDate>

class Technician
// technician can log in and use system
{
public:
    Technician();
    int get_id();
    void set_id(int id);
    QString get_fname();
    void set_fname(QString first_name);
    QString get_lname();
    void set_lname(QString last_name);
    QDate get_dob();
    void set_dob(QDate dob);
    QString get_password();
    void set_password(QString password);
private:
    int id_;
    QString first_name_;
    QString last_name_;
    QDate dob_;
    QString password_;
};

#endif // TECHNICIAN_H
