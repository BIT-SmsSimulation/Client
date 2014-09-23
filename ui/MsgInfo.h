/********************************************************************************
** Form generated from reading UI file 'MsgInfo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MSGINFO_H
#define MSGINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MsgInfo
{
public:
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_3;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *MsgInfo)
    {
        if (MsgInfo->objectName().isEmpty())
            MsgInfo->setObjectName(QString::fromUtf8("MsgInfo"));
        MsgInfo->resize(350, 420);
        MsgInfo->setMinimumSize(QSize(350, 420));
        MsgInfo->setMaximumSize(QSize(350, 420));
        label = new QLabel(MsgInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 50, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_2 = new QLineEdit(MsgInfo);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setGeometry(QRect(90, 70, 230, 30));
        lineEdit_2->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_2->setReadOnly(true);
        lineEdit = new QLineEdit(MsgInfo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(90, 30, 230, 30));
        lineEdit->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit->setReadOnly(true);
        label_2 = new QLabel(MsgInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 50, 30));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        plainTextEdit = new QPlainTextEdit(MsgInfo);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setEnabled(true);
        plainTextEdit->setGeometry(QRect(89, 150, 230, 200));
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setReadOnly(true);
        label_3 = new QLabel(MsgInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 150, 50, 30));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(MsgInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 110, 50, 30));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateTimeEdit = new QDateTimeEdit(MsgInfo);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(true);
        dateTimeEdit->setGeometry(QRect(90, 110, 230, 30));
        dateTimeEdit->setReadOnly(true);
        pushButton_2 = new QPushButton(MsgInfo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 360, 70, 30));
        pushButton = new QPushButton(MsgInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 360, 70, 30));
        pushButton_3 = new QPushButton(MsgInfo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 360, 70, 30));
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);

        retranslateUi(MsgInfo);
        QObject::connect(pushButton_3, SIGNAL(clicked()), MsgInfo, SLOT(reject()));
        QObject::connect(pushButton, SIGNAL(clicked()), MsgInfo, SLOT(sendMsg()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MsgInfo, SLOT(deleteMsg()));

        QMetaObject::connectSlotsByName(MsgInfo);
    } // setupUi

    void retranslateUi(QDialog *MsgInfo)
    {
        MsgInfo->setWindowTitle(QApplication::translate("MsgInfo", "\347\237\255\344\277\241\350\257\246\346\203\205", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MsgInfo", "\345\217\221\351\200\201\350\200\205", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MsgInfo", "\346\216\245\346\224\266\350\200\205", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MsgInfo", "\347\237\255\344\277\241\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MsgInfo", "\346\216\245\346\224\266\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MsgInfo", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MsgInfo", "\345\233\236\345\244\215", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MsgInfo", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MsgInfo: public Ui_MsgInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MSGINFO_H
