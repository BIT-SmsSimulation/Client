/********************************************************************************
** Form generated from reading UI file 'Contacts.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTS_H
#define CONTACTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Contacts
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Contacts)
    {
        if (Contacts->objectName().isEmpty())
            Contacts->setObjectName(QString::fromUtf8("Contacts"));
        Contacts->resize(290, 340);
        Contacts->setMinimumSize(QSize(290, 340));
        Contacts->setMaximumSize(QSize(290, 340));
        lineEdit = new QLineEdit(Contacts);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 30, 100, 30));
        pushButton = new QPushButton(Contacts);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 30, 70, 30));
        label = new QLabel(Contacts);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 40, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        listWidget = new QListWidget(Contacts);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 70, 230, 200));
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton_2 = new QPushButton(Contacts);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 280, 70, 30));
        pushButton_3 = new QPushButton(Contacts);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 280, 70, 30));
        QWidget::setTabOrder(lineEdit, pushButton);
        QWidget::setTabOrder(pushButton, listWidget);
        QWidget::setTabOrder(listWidget, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);

        retranslateUi(Contacts);
        QObject::connect(pushButton, SIGNAL(clicked()), Contacts, SLOT(search()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Contacts, SLOT(contactInfo()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Contacts, SLOT(reject()));
        QObject::connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), Contacts, SLOT(contactInfo(QListWidgetItem*)));

        QMetaObject::connectSlotsByName(Contacts);
    } // setupUi

    void retranslateUi(QDialog *Contacts)
    {
        Contacts->setWindowTitle(QApplication::translate("Contacts", "\350\201\224\347\263\273\344\272\272", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Contacts", "\346\220\234\347\264\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Contacts", "\345\205\263\351\224\256\345\255\227", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Contacts", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Contacts", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Contacts: public Ui_Contacts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTS_H
