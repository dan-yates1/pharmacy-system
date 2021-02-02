#ifndef MEDICATION_H
#define MEDICATION_H

#include <QString>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QVector>
#include <iterator>
#include <iostream>

class Medication
{
public:
    Medication();
    int get_id(QString medication_name);
    int get_access(int id);
    QString get_name(int id);
    QVector<QString> get_names();
    void UpdateMedications();
    void UpdateNames();
    void UpdateAccess();
private:
    QMap<int, QString> medication_names;
    QMap<int, int> medication_access;
};

#endif // MEDICATION_H
