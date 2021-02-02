#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include <QString>
#include <QDate>

class Technician
// technician can log into and interact with system
{
public:
    Technician();
    int get_id();
    void set_id(int id);
    QString get_first_name();
    void set_first_name(QString first_name);
    QString get_last_name();
    void set_last_name(QString last_name);
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
