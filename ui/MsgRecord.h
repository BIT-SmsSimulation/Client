/********************************************************************************
** Form generated from reading UI file 'MsgRecord.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MSGRECORD_H
#define MSGRECORD_H

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
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgRecord
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listWidget;
    QWidget *tab_2;
    QListWidget *listWidget_2;
    QWidget *tab_3;
    QListWidget *listWidget_3;
    QWidget *tab_4;
    QListWidget *listWidget_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *MsgRecord)
    {
        if (MsgRecord->objectName().isEmpty())
            MsgRecord->setObjectName(QString::fromUtf8("MsgRecord"));
        MsgRecord->resize(350, 340);
        MsgRecord->setMinimumSize(QSize(350, 340));
        MsgRecord->setMaximumSize(QSize(350, 340));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MsgRecord->setWindowIcon(icon);
        pushButton = new QPushButton(MsgRecord);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 30, 70, 30));
        label = new QLabel(MsgRecord);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 50, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit = new QLineEdit(MsgRecord);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 30, 160, 30));
        tabWidget = new QTabWidget(MsgRecord);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 70, 292, 202));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 288, 178));
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        listWidget_2 = new QListWidget(tab_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(0, 0, 288, 178));
        listWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        listWidget_3 = new QListWidget(tab_3);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setGeometry(QRect(0, 0, 288, 178));
        listWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        listWidget_4 = new QListWidget(tab_4);
        listWidget_4->setObjectName(QString::fromUtf8("listWidget_4"));
        listWidget_4->setGeometry(QRect(0, 0, 288, 178));
        listWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(tab_4, QString());
        pushButton_2 = new QPushButton(MsgRecord);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 280, 70, 30));
        pushButton_3 = new QPushButton(MsgRecord);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 280, 70, 30));
        QWidget::setTabOrder(lineEdit, pushButton);
        QWidget::setTabOrder(pushButton, listWidget);
        QWidget::setTabOrder(listWidget, listWidget_2);
        QWidget::setTabOrder(listWidget_2, listWidget_3);
        QWidget::setTabOrder(listWidget_3, listWidget_4);
        QWidget::setTabOrder(listWidget_4, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, tabWidget);

        retranslateUi(MsgRecord);
        QObject::connect(pushButton, SIGNAL(clicked()), MsgRecord, SLOT(search()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MsgRecord, SLOT(clear()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MsgRecord, SLOT(reject()));
        QObject::connect(listWidget_2, SIGNAL(itemDoubleClicked(QListWidgetItem*)), MsgRecord, SLOT(msgInfo(QListWidgetItem*)));
        QObject::connect(listWidget_3, SIGNAL(itemDoubleClicked(QListWidgetItem*)), MsgRecord, SLOT(msgInfo(QListWidgetItem*)));
        QObject::connect(listWidget_4, SIGNAL(itemDoubleClicked(QListWidgetItem*)), MsgRecord, SLOT(msgInfo(QListWidgetItem*)));
        QObject::connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), MsgRecord, SLOT(msgInfo(QListWidgetItem*)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MsgRecord);
    } // setupUi

    void retranslateUi(QDialog *MsgRecord)
    {
        MsgRecord->setWindowTitle(QApplication::translate("MsgRecord", "\347\237\255\344\277\241\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MsgRecord", "\346\220\234\347\264\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MsgRecord", "\345\205\263\351\224\256\345\255\227", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MsgRecord", "\346\224\266\344\273\266\347\256\261", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MsgRecord", "\345\217\221\344\273\266\347\256\261", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MsgRecord", "\350\215\211\347\250\277\347\256\261", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MsgRecord", "\345\256\232\346\227\266\347\237\255\344\277\241", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MsgRecord", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MsgRecord", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MsgRecord: public Ui_MsgRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MSGRECORD_H
