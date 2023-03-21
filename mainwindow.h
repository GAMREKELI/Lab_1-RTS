#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QAction>
#include <QSpinBox>

#include <qdebug.h>
#include "Port.h"
#include <cmath>
#include "qcustomplot.h"

#include <QFile>
#include <QTextStream>

#include <QIODevice>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

#include <QThread>
#include <QMessageBox>
#include <QString>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <unistd.h>
#include <errno.h>


#include <stdio.h>
#include <string.h>

#include <stdlib.h>

#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <stdlib.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
//    QAction *action_2;
    QMenu *fileMenu;

    QTimer *timer;
    QTimer *timer_2;
    QTimer *timer_3;

    QTimer *timer_4;
    QTimer *timer_5;
    QTimer *timer_6;

    QThread *thread_New;

    QStackedLayout *layout;
    QStackedLayout *layout_2;
    QStackedLayout *layout_3;

    QString data_in;
    QByteArray pw;


    char* data;
    int size;

    double lastPointKey;
    double lastPointKey_2;
    double lastPointKey_3;

    double lastPointKey_4;
    double lastPointKey_5;
    double lastPointKey_6;

    double lastPointKey_4_y;
    double lastPointKey_5_y;
    double lastPointKey_6_y;

    double key;
    double time_tmp = 0.0;
    double lastPointKey_y;
    double lastPointKey_2_y;
    double lastPointKey_3_y;
    double time_tmp_y = 0.0;


    int i;
    int i_1;

    int med;

    int save;

    double  r;

    double q;
    double q_2;
    double q_3;

    double q_y;
    double q_2_y;
    double q_3_y;

    int flag, flag_2, flag_3 = 1;

    double  u[3];

    bool    start_dots;
    bool    flag_start;

    double  x_1[3];
    double  x_2[3];
    double  x_3[3];

    double  y_1[3];
    double  y_2[3];
    double  y_3[3];

    double  doo[3];

    double  Td;
    double  Tf;
    double  s;
    double  d;
    double  k;

    double tmp = 0.0;

    double arg1_x;
    double arg2_x;
    double arg3_x;

    double  Td_tmp;
    double  Tf_tmp;
    double  s_tmp;
    double  d_tmp;
    double  k_tmp;

    double mediana[3];

    bool theme;

    const QString TEXT_FILE_FORMAT = "Json Files (*.json)";
    const QString ALL_FILE_FORMAT = "All Files (*.*)";


signals:
    void savesettings(QString name, int baudrate, int DataBits, int Parity, int StopBits, int FlowControl);
    void writeData(QByteArray data);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void    drawGraf(double a);

    void    parseMath(QString data);
    void    setTime(double time);
    void    Const_time(double contime);
    void    setAwesomeness(double awecomeness);
    void    dots(double r);
    void    dark_theme();
    void    light_theme();

    QJsonObject recordObject;

    QJsonArray numbersArray_x;
    QJsonArray numbersArray_y;

    QJsonArray numbersArray_x_2;
    QJsonArray numbersArray_y_2;

    QJsonArray numbersArray_x_3;
    QJsonArray numbersArray_y_3;



private slots:
//    void    dark_theme();
    void    on_doubleSpinBox_2_valueChanged(double arg1);
    void    on_doubleSpinBox_3_valueChanged(double arg1);

    void    checkCustomBaudRatePolicy(int idx);

    void    on_Btn_Serch_clicked();

    void    Print(QString data);
    void    on_BtnSave_clicked();
    void    on_doubleSpinBox_4_valueChanged(double arg1);
    void    realtimeDataSlot();
    void    realtimeDataSlot_2();
    void    realtimeDataSlot_3();

    void    realtimeDataSlot_4();
    void    realtimeDataSlot_5();
    void    realtimeDataSlot_6();

    void    start();
    void    stop();
    void    on_doubleSpinBox_6_valueChanged(double arg1);
    void    on_doubleSpinBox_7_valueChanged(double arg1);
    void    on_doubleSpinBox_8_valueChanged(double arg1);
    void    on_pushButton_8_clicked();
    void    on_pushButton_7_clicked();
    void    on_pushButton_9_clicked();
    void    on_pushButton_4_clicked();
    void    on_pushButton_5_clicked();
    void    on_pushButton_6_clicked();
    void on_doubleSpinBox_228_valueChanged(double arg1);
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
