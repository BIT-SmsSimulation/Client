/********************************************************************************
** Form generated from reading UI file 'ChooseContacts.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CHOOSECONTACTS_H
#define CHOOSECONTACTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChooseContacts
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *ChooseContacts)
    {
        if (ChooseContacts->objectName().isEmpty())
            ChooseContacts->setObjectName(QString::fromUtf8("ChooseContacts"));
        ChooseContacts->resize(290, 300);
        ChooseContacts->setMinimumSize(QSize(290, 300));
        ChooseContacts->setMaximumSize(QSize(290, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ChooseContacts->setWindowIcon(icon);
        listWidget = new QListWidget(ChooseContacts);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 30, 230, 200));
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        pushButton_2 = new QPushButton(ChooseContacts);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 240, 70, 30));
        pushButton = new QPushButton(ChooseContacts);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 240, 70, 30));
        QWidget::setTabOrder(listWidget, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(ChooseContacts);
        QObject::connect(pushButton, SIGNAL(clicked()), ChooseContacts, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), ChooseContacts, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChooseContacts);
    } // setupUi

    void retranslateUi(QDialog *ChooseContacts)
    {
        ChooseContacts->setWindowTitle(QApplication::translate("ChooseContacts", "\351\200\211\346\213\251\350\201\224\347\263\273\344\272\272", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ChooseContacts", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ChooseContacts", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChooseContacts: public Ui_ChooseContacts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CHOOSECONTACTS_H
