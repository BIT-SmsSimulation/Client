/********************************************************************************
** Form generated from reading UI file 'WriteMsg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WRITEMSG_H
#define WRITEMSG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WriteMsg
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *WriteMsg)
    {
        if (WriteMsg->objectName().isEmpty())
            WriteMsg->setObjectName(QString::fromUtf8("WriteMsg"));
        WriteMsg->resize(290, 340);
        WriteMsg->setMinimumSize(QSize(290, 340));
        WriteMsg->setMaximumSize(QSize(290, 340));
        label = new QLabel(WriteMsg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 40, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit = new QLineEdit(WriteMsg);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 30, 100, 30));
        pushButton = new QPushButton(WriteMsg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 30, 70, 30));
        plainTextEdit = new QPlainTextEdit(WriteMsg);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(30, 70, 230, 200));
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton_2 = new QPushButton(WriteMsg);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 280, 70, 30));
        pushButton_3 = new QPushButton(WriteMsg);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 280, 70, 30));
        pushButton_4 = new QPushButton(WriteMsg);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(190, 280, 70, 30));
        QWidget::setTabOrder(lineEdit, pushButton);
        QWidget::setTabOrder(pushButton, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);

        retranslateUi(WriteMsg);
        QObject::connect(pushButton, SIGNAL(clicked()), WriteMsg, SLOT(chooseContacts()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), WriteMsg, SLOT(sendMsg()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), WriteMsg, SLOT(sendTimedMsg()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), WriteMsg, SLOT(reject()));

        QMetaObject::connectSlotsByName(WriteMsg);
    } // setupUi

    void retranslateUi(QDialog *WriteMsg)
    {
        WriteMsg->setWindowTitle(QApplication::translate("WriteMsg", "\345\206\231\347\237\255\344\277\241", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WriteMsg", "\346\224\266\344\273\266\344\272\272", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("WriteMsg", "\350\201\224\347\263\273\344\272\272", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("WriteMsg", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("WriteMsg", "\345\256\232\346\227\266\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("WriteMsg", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WriteMsg: public Ui_WriteMsg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WRITEMSG_H
