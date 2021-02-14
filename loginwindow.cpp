#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "database.h"
#include "mainscreen.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::set_username(QString username)
{
    username_ = username;
}

QString LoginWindow::get_username()
{
    return username_;
}

void LoginWindow::set_password(QString password)
{
    password_ = password;
}

QString LoginWindow::get_password()
{
    return password_;
}

void LoginWindow::set_user_type(QString type)
{
    user_type_ = type;
}

QString LoginWindow::get_user_type()
{
    return user_type_;
}

bool LoginWindow::InsertUser()
{
    Database db;

    bool success = false;

    QSqlQuery qry;
    qry.prepare("INSERT INTO login (username,password,usertype) VALUES(:username,:password,:usertype)");
    qry.bindValue(":username", get_username());
    qry.bindValue(":password", get_password());
    qry.bindValue(":usertype", get_user_type());

    if(qry.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add user failed: " << qry.lastError();
    }

    return success;
}

bool LoginWindow::AlreadyExists()
{
    Database db;

    bool exists = false;

    QSqlQuery query("SELECT username FROM login");
    int id = query.record().indexOf("username");
    while (query.next())
    {
        QString name = query.value(id).toString();
        if (name == get_username())
        {
            exists = true;
        }
    }
    return exists;
}

bool LoginWindow::CheckPassword()
{
    bool correct = false;

    Database db;

    QSqlQuery query("SELECT username, password FROM login");
    int user_index = query.record().indexOf("username");
    int password_index = query.record().indexOf("password");
    while (query.next())
    {
        QString password = query.value(password_index).toString();
        QString name = query.value(user_index).toString();
        if (name == get_username())
        {
            if(password == get_password())
            {
                correct = true;
            }
        }
    }
    return correct;
}

void LoginWindow::on_loginButton_clicked()
{
    set_username(ui->usernameEdit->text());
    set_password(ui->passwordEdit->text());
    set_user_type(ui->userType->currentText());

    if(AlreadyExists())
    {
        if(CheckPassword())
        {
            this->hide();
            delete ui;
            MainScreen m;
            m.setWindowTitle("Pharmacy App - Home");
            m.setWindowIcon(QIcon(":/icons/window-icon.svg"));
            m.setFixedSize(m.size());
            m.setModal(true);
            m.exec();
        } else
        {
            QMessageBox::information(this,"Notification",QString("Password incorrect"));
        }
    } else
    {
        QMessageBox::information(this,"Notification",QString("User does not exist"));
    }
}

void LoginWindow::on_createButton_clicked()
{
    set_username(ui->usernameEdit->text());
    set_password(ui->passwordEdit->text());
    set_user_type(ui->userType->currentText());

    if(!AlreadyExists())
    {
        InsertUser();
        QMessageBox::information(this,"Notification",QString("User: %1 created").arg(ui->usernameEdit->text()));
    } else {
        QMessageBox::information(this,"Notification",QString("Username already in use"));
    }
}
