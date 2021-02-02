#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDate>

class Patient
{
public:
    Patient();
    QString get_fname();
    void set_fname(QString fname);
    QString get_lname();
    void set_lname(QString lname);
    int get_id();
    void set_id(int id);
    QDate get_dob();
    void set_dob(QDate dob);

    void AddToDatabase();
private:
    int patient_id_;
    QString first_name_;
    QString last_name_;
    QDate dob_;
};

#endif // PATIENT_H
