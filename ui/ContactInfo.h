/********************************************************************************
** Form generated from reading UI file 'ContactInfo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTINFO_H
#define CONTACTINFO_H

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

class Ui_ContactInfo
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *ContactInfo)
    {
        if (ContactInfo->objectName().isEmpty())
            ContactInfo->setObjectName(QString::fromUtf8("ContactInfo"));
        ContactInfo->resize(340, 170);
        ContactInfo->setMinimumSize(QSize(340, 170));
        ContactInfo->setMaximumSize(QSize(340, 170));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ContactInfo->setWindowIcon(icon);
        label = new QLabel(ContactInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 50, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit = new QLineEdit(ContactInfo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 30, 230, 30));
        label_2 = new QLabel(ContactInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 50, 30));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_2 = new QLineEdit(ContactInfo);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 70, 230, 30));
        lineEdit_2->setInputMethodHints(Qt::ImhDigitsOnly);
        pushButton_2 = new QPushButton(ContactInfo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 110, 70, 30));
        pushButton = new QPushButton(ContactInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 110, 70, 30));
        pushButton_3 = new QPushButton(ContactInfo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 110, 70, 30));
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);

        retranslateUi(ContactInfo);
        QObject::connect(pushButton, SIGNAL(clicked()), ContactInfo, SLOT(sendMsg()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), ContactInfo, SLOT(reject()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), ContactInfo, SLOT(deleteContact()));

        QMetaObject::connectSlotsByName(ContactInfo);
    } // setupUi

    void retranslateUi(QDialog *ContactInfo)
    {
        ContactInfo->setWindowTitle(QString());
        label->setText(QApplication::translate("ContactInfo", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ContactInfo", "\346\211\213\346\234\272\345\217\267", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ContactInfo", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ContactInfo", "\345\217\221\347\237\255\344\277\241", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ContactInfo", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ContactInfo: public Ui_ContactInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTINFO_H
