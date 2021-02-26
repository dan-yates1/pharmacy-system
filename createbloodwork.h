#ifndef CREATEBLOODWORK_H
#define CREATEBLOODWORK_H

#include <QDialog>
#include "bloodwork.h"
#include "database.h"

namespace Ui {
class CreateBloodwork;
}

class CreateBloodwork : public QDialog
{
    Q_OBJECT

public:
    explicit CreateBloodwork(QWidget *parent = nullptr);
    ~CreateBloodwork();

    /**
     * @brief UpdateReasons
     */
    void UpdateReasons();

    /**
     * @brief UpdatePatients
     */
    void UpdatePatients();

    /**
     * @brief InsertBloodwork
     * @param b - Bloodwork object
     * @return
     */
    bool InsertBloodwork(Bloodwork b);

    /**
     * @brief PopulateBloodwork
     * @return
     */
    Bloodwork PopulateBloodwork();

    void set_patient(int id);
private slots:
    void on_submitBloodworkButton_clicked();

private:
    Ui::CreateBloodwork *ui;
};

#endif // CREATEBLOODWORK_H
