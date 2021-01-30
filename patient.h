#ifndef PATIENT_H
#define PATIENT_H

#include <QString>


class Patient
{
public:
    Patient();
    QString get_fname();
    void set_fname(QString fname);
    QString get_lname();
    void set_lname(QString lname);
    int get_id();
    void set_id();
    int get_dob();
    void set_dob(int dob);
private:
    int patient_id_;
    QString first_name_;
    QString last_name_;
    int dob_;
};

#endif // PATIENT_H
