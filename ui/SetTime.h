/********************************************************************************
** Form generated from reading UI file 'SetTime.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SETTIME_H
#define SETTIME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetTime
{
public:
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *SetTime)
    {
        if (SetTime->objectName().isEmpty())
            SetTime->setObjectName(QString::fromUtf8("SetTime"));
        SetTime->resize(290, 130);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SetTime->setWindowIcon(icon);
        dateTimeEdit = new QDateTimeEdit(SetTime);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(30, 30, 230, 30));
        pushButton_2 = new QPushButton(SetTime);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 70, 70, 30));
        pushButton_3 = new QPushButton(SetTime);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 70, 70, 30));

        retranslateUi(SetTime);
        QObject::connect(pushButton_2, SIGNAL(clicked()), SetTime, SLOT(accept()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), SetTime, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetTime);
    } // setupUi

    void retranslateUi(QDialog *SetTime)
    {
        SetTime->setWindowTitle(QApplication::translate("SetTime", "\351\200\211\346\213\251\345\217\221\351\200\201\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("SetTime", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("SetTime", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetTime: public Ui_SetTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETTIME_H
