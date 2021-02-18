#ifndef VIEWPRESCRIPTION_H
#define VIEWPRESCRIPTION_H

#include <QDialog>
#include <QList>

namespace Ui {
class viewPrescription;
}

class viewPrescription : public QDialog
{
    Q_OBJECT

public:
    explicit viewPrescription(QWidget *parent = nullptr);
    ~viewPrescription();

private:
    Ui::viewPrescription *ui;
    void populateList();
};

#endif // VIEWPRESCRIPTION_H
