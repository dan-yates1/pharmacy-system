#ifndef CREATEPRESCRIPTION_H
#define CREATEPRESCRIPTION_H

#include <QDialog>
#include <QStringView>
#include <QDebug>
#include <iostream>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class CreatePrescription;
}

class CreatePrescription : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePrescription(QWidget *parent = nullptr);
    ~CreatePrescription();
private slots:
    void on_createPrescriptionButton_clicked();

private:
    Ui::CreatePrescription *ui;
};

#endif // CREATEPRESCRIPTION_H
