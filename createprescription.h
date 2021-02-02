#ifndef CREATEPRESCRIPTION_H
#define CREATEPRESCRIPTION_H

#include <QDialog>
#include <QStringView>
#include <QDebug>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>

namespace Ui {
class CreatePrescription;
}

class CreatePrescription : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePrescription(QWidget *parent = nullptr);
    ~CreatePrescription();
    void ConnectToDatabase();
    void UpdateMedications();
    void UpdatePatients();
private slots:
    void on_createPrescriptionButton_clicked();

private:
    Ui::CreatePrescription *ui;
};

#endif // CREATEPRESCRIPTION_H
