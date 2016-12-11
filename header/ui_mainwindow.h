/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *next;
    QGraphicsView *graphicsView;
    QTextEdit *texture_name;
    QTextBrowser *save_name;
    QPushButton *previous;
    QLabel *label;
    QLabel *label_2;
    QPushButton *save;
    QPushButton *new_2;
    QPushButton *view;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(775, 661);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        next = new QPushButton(centralWidget);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(540, 460, 191, 51));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(65, 101, 651, 341));
        texture_name = new QTextEdit(centralWidget);
        texture_name->setObjectName(QString::fromUtf8("texture_name"));
        texture_name->setGeometry(QRect(250, 450, 81, 70));
        save_name = new QTextBrowser(centralWidget);
        save_name->setObjectName(QString::fromUtf8("save_name"));
        save_name->setGeometry(QRect(340, 10, 256, 71));
        save_name->setMinimumSize(QSize(256, 71));
        previous = new QPushButton(centralWidget);
        previous->setObjectName(QString::fromUtf8("previous"));
        previous->setGeometry(QRect(340, 460, 171, 51));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 20, 231, 51));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(28, 453, 201, 71));
        save = new QPushButton(centralWidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(30, 541, 711, 61));
        new_2 = new QPushButton(centralWidget);
        new_2->setObjectName(QString::fromUtf8("new_2"));
        new_2->setGeometry(QRect(620, 20, 81, 41));
        view = new QPushButton(centralWidget);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(10, 0, 101, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 775, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        next->setText(QApplication::translate("MainWindow", "next", 0, QApplication::UnicodeUTF8));
        previous->setText(QApplication::translate("MainWindow", "previous", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Atually saved for the texture", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Enter the name of the texture:", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("MainWindow", "Save the atlas", 0, QApplication::UnicodeUTF8));
        new_2->setText(QApplication::translate("MainWindow", "New image", 0, QApplication::UnicodeUTF8));
        view->setText(QApplication::translate("MainWindow", "view bounding", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
