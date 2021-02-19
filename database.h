#ifndef DATABASE_H
#define DATABASE_H

#include "patient.h"
#include "bloodwork.h"
#include "prescription.h"
#include <QString>
#include <QList>
#include <QSqlDatabase>

class Database
{
public:
    /**
     * @brief Database
     */
    Database();

    ~Database();

    /**
     * @brief CreateConnection
     * @return
     */
    bool CreateConnection();

    /**
     * @brief Add patient to db
     * @param patient - patient object
     */
    bool InsertPatient(Patient patient);

    /**
     * @brief Check to see if db is open
     * @return false is not open and true if open
     */
    bool DbOpen();

    /**
     * @brief InsertBloodwork
     * @return
     */
    bool InsertBloodwork(Bloodwork b);

    bool InsertPrescription(Prescription p);

    void PrintAllPatients();

    int GetPatientId(QString name);

    QString GetPatient(int id);

    QList<Bloodwork> GetBloodwork();

    QList<Prescription> GetPrescription();

    QList<Patient> GetPatients();
private:
    QSqlDatabase db_;
};

#endif // DATABASE_H
