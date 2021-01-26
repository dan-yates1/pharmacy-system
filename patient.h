#ifndef PATIENT_H
#define PATIENT_H

#include <string>


class Patient
{
public:
    int patient_id_;
    std::string first_name_;
    std::string last_name_;
    int dob_;

    Patient();

    std::string get_fname();
    void set_fname(std::string fname);
    std::string get_lname();
    void set_lname(std::string lname);
    int get_id();
    int get_dob();
    void set_dob(int dob);
};

#endif // PATIENT_H
