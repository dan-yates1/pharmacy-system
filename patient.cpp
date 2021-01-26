#include "patient.h"


Patient::Patient() {

}

std::string Patient::get_fname(){
    return first_name_;
}

void Patient::set_fname(std::string fname)
{
    first_name_ = fname;
}

std::string Patient::get_lname(){
    return first_name_;
}

void Patient::set_lname(std::string lname)
{
    last_name_ = lname;
}

int Patient::get_id()
{
    return patient_id_;
}

int Patient::get_dob()
{
    return dob_;
}

void Patient::set_dob(int dob)
{
    dob_ = dob;
}
