#ifndef CREATEBLOODWORK_H
#define CREATEBLOODWORK_H

#include <QDialog>

namespace Ui {
class CreateBloodwork;
}

class CreateBloodwork : public QDialog
{
    Q_OBJECT

public:
    explicit CreateBloodwork(QWidget *parent = nullptr);
    ~CreateBloodwork();
    void UpdateReasons();
    void UpdatePatients();
private slots:
    void on_bookBloodworkButton_clicked();
    void on_submitBloodworkButton_clicked();

private:
    Ui::CreateBloodwork *ui;
};

#endif // CREATEBLOODWORK_H
