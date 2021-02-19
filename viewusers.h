#ifndef VIEWUSERS_H
#define VIEWUSERS_H

#include <QDialog>
#include <QList>

namespace Ui {
class viewUsers;
}

class viewUsers : public QDialog
{
    Q_OBJECT

public:
    explicit viewUsers(QWidget *parent = nullptr);
    ~viewUsers();

private:
    Ui::viewUsers *ui;
    void populateList();
};

#endif // VIEWUSERS_H
