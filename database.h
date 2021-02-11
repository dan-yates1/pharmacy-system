#ifndef DATABASE_H
#define DATABASE_H

#include "patient.h"
#include <QString>
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
     * @param id - patient_id_
     * @param fname - patient first name
     * @param lname - patient last name
     * @param dob - patient date of birth
     */
    bool InsertPatient(Patient patient);

    /**
     * @brief Check to see if db is open
     * @return false is not open and true if open
     */
    bool DbOpen();

    void PrintAllPatients();
private:
    QSqlDatabase db_;
};

#endif // DATABASE_H
