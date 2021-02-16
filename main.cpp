#include "patient.h"
#include "medication.h"
#include "loginwindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow l;
    l.setFixedSize(l.size());
    l.setWindowTitle("Login");
    l.setWindowIcon(QIcon(":/icons/lock-icon.png"));
    l.show();
    return a.exec();  
}
