/********************************************************************************
** Form generated from reading UI file 'ftpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTPCLIENT_H
#define UI_FTPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "MyQListWidget.h"

QT_BEGIN_NAMESPACE

class Ui_FTPclientClass
{
public:
    QWidget *centralWidget;
    MyQListWidget *files;
    QLineEdit *ip_text;
    QLineEdit *username_text;
    QLineEdit *password_text;
    QPushButton *query_button;
    QPushButton *download_button;
    QPushButton *quit_button;
    QLabel *ip_label;
    QLabel *username_label;
    QLabel *password_label;
    QLineEdit *dir_text;
    QLabel *dir_label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FTPclientClass)
    {
        if (FTPclientClass->objectName().isEmpty())
            FTPclientClass->setObjectName(QString::fromUtf8("FTPclientClass"));
        FTPclientClass->setEnabled(true);
        FTPclientClass->resize(482, 418);
        FTPclientClass->setAcceptDrops(false);
        centralWidget = new QWidget(FTPclientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setToolTipDuration(2);
        files = new MyQListWidget(centralWidget);
        files->setObjectName(QString::fromUtf8("files"));
        files->setGeometry(QRect(30, 140, 256, 192));
        files->setAcceptDrops(false);
        files->setDragEnabled(true);
        files->setDragDropMode(QAbstractItemView::DragDrop);
        files->setDefaultDropAction(Qt::MoveAction);
        ip_text = new QLineEdit(centralWidget);
        ip_text->setObjectName(QString::fromUtf8("ip_text"));
        ip_text->setGeometry(QRect(130, 10, 311, 21));
        username_text = new QLineEdit(centralWidget);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        username_text->setGeometry(QRect(140, 50, 113, 21));
        password_text = new QLineEdit(centralWidget);
        password_text->setObjectName(QString::fromUtf8("password_text"));
        password_text->setGeometry(QRect(350, 50, 113, 21));
        password_text->setEchoMode(QLineEdit::Password);
        query_button = new QPushButton(centralWidget);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(370, 160, 88, 23));
        download_button = new QPushButton(centralWidget);
        download_button->setObjectName(QString::fromUtf8("download_button"));
        download_button->setEnabled(false);
        download_button->setGeometry(QRect(370, 230, 88, 23));
        quit_button = new QPushButton(centralWidget);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        quit_button->setGeometry(QRect(370, 300, 88, 23));
        ip_label = new QLabel(centralWidget);
        ip_label->setObjectName(QString::fromUtf8("ip_label"));
        ip_label->setGeometry(QRect(70, 10, 51, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        ip_label->setFont(font);
        username_label = new QLabel(centralWidget);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        username_label->setGeometry(QRect(50, 50, 81, 20));
        username_label->setFont(font);
        password_label = new QLabel(centralWidget);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(290, 50, 51, 16));
        password_label->setFont(font);
        dir_text = new QLineEdit(centralWidget);
        dir_text->setObjectName(QString::fromUtf8("dir_text"));
        dir_text->setGeometry(QRect(140, 90, 311, 21));
        dir_label = new QLabel(centralWidget);
        dir_label->setObjectName(QString::fromUtf8("dir_label"));
        dir_label->setGeometry(QRect(40, 90, 91, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        dir_label->setFont(font1);
        FTPclientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FTPclientClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 482, 26));
        FTPclientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FTPclientClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FTPclientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FTPclientClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FTPclientClass->setStatusBar(statusBar);

        retranslateUi(FTPclientClass);

        QMetaObject::connectSlotsByName(FTPclientClass);
    } // setupUi

    void retranslateUi(QMainWindow *FTPclientClass)
    {
        FTPclientClass->setWindowTitle(QApplication::translate("FTPclientClass", "FTPclient", nullptr));
        ip_text->setText(QApplication::translate("FTPclientClass", "10.131.8.248", nullptr));
        username_text->setText(QApplication::translate("FTPclientClass", "drz", nullptr));
        password_text->setText(QApplication::translate("FTPclientClass", "123456", nullptr));
        query_button->setText(QApplication::translate("FTPclientClass", "\346\237\245\350\257\242", nullptr));
        download_button->setText(QApplication::translate("FTPclientClass", "\344\270\213\350\275\275", nullptr));
        quit_button->setText(QApplication::translate("FTPclientClass", "\347\231\273\345\207\272", nullptr));
        ip_label->setText(QApplication::translate("FTPclientClass", "\345\237\237\345\220\215:", nullptr));
        username_label->setText(QApplication::translate("FTPclientClass", "\347\224\250\346\210\267\345\220\215:", nullptr));
        password_label->setText(QApplication::translate("FTPclientClass", "\345\257\206\347\240\201:", nullptr));
        dir_text->setText(QApplication::translate("FTPclientClass", "D:/ftptest/", nullptr));
        dir_label->setText(QApplication::translate("FTPclientClass", "\344\277\235\345\255\230\344\275\215\347\275\256:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTPclientClass: public Ui_FTPclientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTPCLIENT_H
