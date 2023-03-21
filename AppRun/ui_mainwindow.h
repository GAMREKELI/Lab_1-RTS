/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QPushButton *BtnConnect;
    QPushButton *BtnDisconect;
    QGroupBox *groupBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_228;
    QGroupBox *groupBox_2;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_5;
    QSpinBox *spinBox;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_15;
    QLabel *label_16;
    QCustomPlot *widget_3;
    QCustomPlot *widget_2;
    QCustomPlot *widget;
    QLabel *label_17;
    QComboBox *PortNameBox;
    QComboBox *BaudRateBox;
    QPushButton *Btn_Serch;
    QLabel *label_18;
    QPushButton *BtnSave;
    QTextEdit *consol;
    QCustomPlot *widget_4;
    QCustomPlot *widget_5;
    QCustomPlot *widget_6;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1571, 1035);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        BtnConnect = new QPushButton(centralwidget);
        BtnConnect->setObjectName(QStringLiteral("BtnConnect"));
        BtnConnect->setGeometry(QRect(1000, 30, 80, 36));
        BtnDisconect = new QPushButton(centralwidget);
        BtnDisconect->setObjectName(QStringLiteral("BtnDisconect"));
        BtnDisconect->setGeometry(QRect(1090, 30, 80, 36));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1030, 150, 191, 452));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(10, 170, 161, 42));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMaximum(1);
        doubleSpinBox_2->setSingleStep(0.0001);
        doubleSpinBox_2->setValue(0.3);
        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(10, 270, 161, 42));
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMinimum(0);
        doubleSpinBox_3->setMaximum(100);
        doubleSpinBox_3->setSingleStep(0.0001);
        doubleSpinBox_3->setValue(1);
        doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(10, 370, 161, 42));
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMaximum(100);
        doubleSpinBox_4->setSingleStep(0.0001);
        doubleSpinBox_4->setValue(20);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 66, 19));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 140, 161, 19));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 240, 71, 19));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 340, 171, 19));
        doubleSpinBox_228 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_228->setObjectName(QStringLiteral("doubleSpinBox_228"));
        doubleSpinBox_228->setGeometry(QRect(10, 70, 161, 42));
        doubleSpinBox_228->setDecimals(4);
        doubleSpinBox_228->setMaximum(1);
        doubleSpinBox_228->setSingleStep(0.0001);
        doubleSpinBox_228->setValue(0.01);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1250, 150, 281, 452));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        doubleSpinBox_6 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(60, 170, 161, 42));
        doubleSpinBox_6->setDecimals(4);
        doubleSpinBox_6->setMaximum(100);
        doubleSpinBox_6->setSingleStep(0.0001);
        doubleSpinBox_6->setValue(1);
        doubleSpinBox_7 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(60, 270, 161, 42));
        doubleSpinBox_7->setDecimals(4);
        doubleSpinBox_7->setMaximum(100);
        doubleSpinBox_7->setSingleStep(0.0001);
        doubleSpinBox_7->setValue(1);
        doubleSpinBox_8 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(60, 370, 161, 42));
        doubleSpinBox_8->setDecimals(4);
        doubleSpinBox_8->setMaximum(100);
        doubleSpinBox_8->setSingleStep(0.0001);
        doubleSpinBox_8->setValue(1);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 40, 151, 19));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(10, 70, 161, 42));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 180, 51, 19));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 280, 51, 19));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 380, 51, 19));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(230, 180, 41, 19));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(230, 280, 41, 19));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(230, 380, 41, 19));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(440, 460, 101, 31));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(150, 30, 101, 31));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(550, 30, 101, 31));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1110, 640, 80, 36));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(1110, 690, 80, 36));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(1110, 740, 80, 36));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(1220, 690, 80, 36));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(1220, 640, 80, 36));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(1220, 740, 80, 36));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(1140, 610, 66, 19));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(1240, 610, 66, 19));
        widget_3 = new QCustomPlot(centralwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(20, 500, 971, 421));
        widget_2 = new QCustomPlot(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(500, 80, 491, 341));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 80, 461, 341));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(1000, 90, 121, 31));
        PortNameBox = new QComboBox(centralwidget);
        PortNameBox->setObjectName(QStringLiteral("PortNameBox"));
        PortNameBox->setGeometry(QRect(1350, 90, 126, 37));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PortNameBox->sizePolicy().hasHeightForWidth());
        PortNameBox->setSizePolicy(sizePolicy);
        BaudRateBox = new QComboBox(centralwidget);
        BaudRateBox->setObjectName(QStringLiteral("BaudRateBox"));
        BaudRateBox->setGeometry(QRect(1140, 90, 126, 37));
        Btn_Serch = new QPushButton(centralwidget);
        Btn_Serch->setObjectName(QStringLiteral("Btn_Serch"));
        Btn_Serch->setGeometry(QRect(1420, 30, 103, 36));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(1290, 90, 41, 31));
        BtnSave = new QPushButton(centralwidget);
        BtnSave->setObjectName(QStringLiteral("BtnSave"));
        BtnSave->setGeometry(QRect(1210, 30, 181, 36));
        consol = new QTextEdit(centralwidget);
        consol->setObjectName(QStringLiteral("consol"));
        consol->setGeometry(QRect(1030, 790, 511, 191));
        widget_4 = new QCustomPlot(centralwidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(20, 80, 461, 341));
        widget_5 = new QCustomPlot(centralwidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(500, 80, 491, 341));
        widget_6 = new QCustomPlot(centralwidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(20, 500, 971, 421));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(10, 10, 51, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1571, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LAB1", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\275\321\213\320\271", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\320\241\320\262\320\265\321\202\320\273\321\213\320\271", nullptr));
        BtnConnect->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        BtnDisconect->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\320\276\321\217\320\275\320\275\320\260\321\217 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\321\200\321\203\321\202\320\270\320\267\320\275\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \321\203\321\201\320\270\320\273\320\265\320\275\320\270\321\217", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\265 \321\203\321\201\320\273\320\276\320\262\320\270\321\217", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\320\262\320\276 \320\276\321\202\321\201\321\207\320\265\321\202\320\276\320\262", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "x1(0) =", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "x2(0) =", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "x3(0) =", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\234\320\241", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\234\320\241", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\234\320\241", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 \342\204\2263", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 \342\204\2261", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 \342\204\2262", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "3", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "x(t)", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "y(t)", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
        Btn_Serch->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202", nullptr));
        BtnSave->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
