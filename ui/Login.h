/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGIN_H
#define LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(300, 170);
        Login->setMinimumSize(QSize(300, 170));
        Login->setMaximumSize(QSize(300, 170));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 50, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit = new QLineEdit(Login);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 30, 190, 30));
        lineEdit->setInputMethodHints(Qt::ImhDigitsOnly);
        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 110, 70, 30));
        pushButton_2 = new QPushButton(Login);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 110, 70, 30));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 50, 30));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_2 = new QLineEdit(Login);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 70, 40, 30));
        lineEdit_2->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(Login);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 70, 40, 30));
        lineEdit_3->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_4 = new QLineEdit(Login);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(180, 70, 40, 30));
        lineEdit_4->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_5 = new QLineEdit(Login);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(230, 70, 40, 30));
        lineEdit_5->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_5->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(Login);
        QObject::connect(pushButton, SIGNAL(clicked()), Login, SLOT(login()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Login, SLOT(reject()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Login", "\346\211\213\346\234\272\345\217\267", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Login", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Login", "\346\234\215\345\212\241\345\231\250IP", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("Login", "10", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("Login", "12", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("Login", "38", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setText(QApplication::translate("Login", "114", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGIN_H
