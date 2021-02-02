#include "medication.h"

Medication::Medication()
{
    // update both maps via csv file upon object instalization
    UpdateMedications();
}

int Medication::get_id(QString medication_name)
{

}

int Medication::get_access(int id)
{
    return medication_access[id];
}

QString Medication::get_name(int id)
{
    return medication_names[id];
}

QVector<QString> Medication::get_names()
{
    QVector<QString> medications_list;
    for(auto m : medication_names.keys())
    {
        medications_list.append(medication_names.value(m));
    }
    return medications_list;
}

void Medication::UpdateMedications()
{
    UpdateAccess();
    UpdateNames();
}

void Medication::UpdateNames()
{
    // populate medication names map via csv file
    QFile file(":/csv/medications.csv");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QString medication_name = line.split(',').at(1);
            int id = (line.split(',').at(0)).toInt();
            medication_names.insert(id, medication_name);
        }
        file.close();
    }
}

void Medication::UpdateAccess()
{
    // populate medication access levels map via csv file
    QFile file(":/csv/medications.csv");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            int access_level = (line.split(',').at(2)).toInt();
            int id = (line.split(',').at(0)).toInt();
            medication_access.insert(id, access_level);
        }
        file.close();
    }
}
