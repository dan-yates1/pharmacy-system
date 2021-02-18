#ifndef VIEWBLOODWORK_H
#define VIEWBLOODWORK_H

#include <QDialog>
#include <QList>

namespace Ui {
class viewBloodwork;
}

class viewBloodwork : public QDialog
{
    Q_OBJECT

public:
    explicit viewBloodwork(QWidget *parent = nullptr);
    ~viewBloodwork();

private:
    Ui::viewBloodwork *ui;
    void populateList();
};

#endif // VIEWBLOODWORK_H
