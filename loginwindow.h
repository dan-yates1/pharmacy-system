#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    void set_username(QString username);
    QString get_username();
    void set_password(QString password);
    QString get_password();
    void set_user_type(QString type);
    QString get_user_type();

    /**
     * @brief InsertUser
     * @return
     */
    bool InsertUser();

    /**
     * @brief AlreadyExists
     * @return
     */
    bool AlreadyExists();

    /**
     * @brief CheckPassword
     * @return
     */
    bool CheckPassword();

    /**
     * @brief ValidateInputs
     * @return
     */
    bool ValidateInputs();
private slots:
    void on_loginButton_clicked();

    void on_createButton_clicked();

private:
    Ui::LoginWindow *ui;
    QString username_;
    QString password_;
    QString user_type_;
};

#endif // LOGINWINDOW_H
