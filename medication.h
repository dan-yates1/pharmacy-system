#ifndef MEDICATION_H
#define MEDICATION_H

#include <QString>
#include <fstream>
#include <string>
#include <iostream>

class Medication
{
public:
    Medication();
private:
    QString medication_list_[134];
};

#endif // MEDICATION_H
