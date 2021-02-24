#ifndef EXPIREDVIEW_H
#define EXPIREDVIEW_H

#include <QDialog>

namespace Ui {
class ExpiredView;
}

class ExpiredView : public QDialog
{
    Q_OBJECT

public:
    explicit ExpiredView(QWidget *parent = nullptr);
    ~ExpiredView();

    void PopulatePrescriptions();

    void PopulateBloodwork();

private:
    Ui::ExpiredView *ui;
};

#endif // EXPIREDVIEW_H
