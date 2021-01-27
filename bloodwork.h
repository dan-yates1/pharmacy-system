#ifndef BLOODWORK_H
#define BLOODWORK_H

#include "patient.h"


class Bloodwork
{
public:
    Bloodwork();
private:
    int bloodwork_id_;
    Patient patient_;
    //QDate test_date_;
    //QDate valid_till_;
};

#endif // BLOODWORK_H
