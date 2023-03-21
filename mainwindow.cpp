#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    theme = true;

    QPalette darkPalette;

    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    layout = new QStackedLayout;
    layout_2 = new QStackedLayout;
    layout_3 = new QStackedLayout;

    ui->BtnConnect->setEnabled(false);
    ui->BtnDisconect->setEnabled(false);

    layout->addWidget(ui->widget);
    layout->addWidget(ui->widget_4);
    layout_2->addWidget(ui->widget_2);
    layout_2->addWidget(ui->widget_5);
    layout_3->addWidget(ui->widget_3);
    layout_3->addWidget(ui->widget_6);

    start_dots = false;
    flag_start = true;

    arg1_x = 0.0;
    arg2_x = 0.0;
    arg3_x = 0.0;


    Td = 0.01;
    Tf = 0.3;
    s = 1.0;
    d = Tf;
    k = 20.0;

    i = 1;
    i_1 = 0;

    r = 0.0;

    u[0] = 0.0;
    u[1] = 0.0;
    u[2] = 0.0;

    x_1[0] = 1.0;
    x_1[1] = 1.0;
    x_1[2] = 0.0;

    x_2[0] = 1.0;
    x_2[1] = 1.0;
    x_2[2] = 0.0;

    x_3[0] = 1.0;
    x_3[1] = 1.0;
    x_3[2] = 0.0;

    y_1[0] = 0.0;
    y_1[1] = 0.0;
    y_1[2] = 0.0;

    y_2[0] = 0.0;
    y_2[1] = 0.0;
    y_2[2] = 0.0;

    y_3[0] = 0.0;
    y_3[1] = 0.0;
    y_3[2] = 0.0;

    doo[0] = 0.0;
    doo[1] = 0.0;
    doo[2] = 0.0;

    q = 0.0;
    q_2 = 0.0;
    q_3 = 0.0;
    q_y = 0.0;
    q_2_y = 0.0;
    q_3_y = 0.0;

    mediana[0] = 0.0;
    mediana[1] = 0.0;
    mediana[2] = 0.0;

    med = 0;

    save = 0;

    connect(ui->BaudRateBox, SIGNAL(currentIndexChanged(int)) ,this, SLOT(checkCustomBaudRatePolicy(int)));
    ui->BaudRateBox->addItem(QLatin1String("9600"), QSerialPort::Baud9600);
    ui->BaudRateBox->addItem(QLatin1String("19200"), QSerialPort::Baud19200);
    ui->BaudRateBox->addItem(QLatin1String("38400"), QSerialPort::Baud38400);
    ui->BaudRateBox->addItem(QLatin1String("115200"), QSerialPort::Baud115200);
    ui->BaudRateBox->addItem(QLatin1String("Custom"));

    thread_New = new QThread;//Создаем поток для порта платы
    Port *PortNew = new Port();//Создаем обьект по классу
    PortNew->moveToThread(thread_New);//помешаем класс  в поток
    PortNew->thisPort.moveToThread(thread_New);//Помещаем сам порт в поток


    key = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;


    connect(PortNew, SIGNAL(error_(QString)), this, SLOT(Print(QString)));//Лог ошибок
    connect(thread_New, SIGNAL(started()), PortNew, SLOT(process_Port()));//Переназначения метода run


    connect(PortNew, SIGNAL(finished_Port()), thread_New, SLOT(quit()));//Переназначение метода выход
    connect(thread_New, SIGNAL(finished()), PortNew, SLOT(deleteLater()));//Удалить к чертям поток
    connect(PortNew, SIGNAL(finished_Port()), thread_New, SLOT(deleteLater()));//Удалить к чертям поток
    connect(this,SIGNAL(savesettings(QString,int,int,int,int,int)),PortNew,SLOT(Write_Settings_Port(QString,int)));//Слот - ввод настроек!
    connect(ui->BtnConnect, SIGNAL(clicked()),PortNew,SLOT(ConnectPort()));//по нажатию кнопки подключить порт

    connect(ui->BtnConnect, SIGNAL(clicked()),this,SLOT(start()));
    connect(ui->BtnDisconect, SIGNAL(clicked()),this,SLOT(stop()));

    connect(ui->BtnDisconect, SIGNAL(clicked()),PortNew,SLOT(DisconnectPort()));//по нажатию кнопки отключить порт
    connect(PortNew, SIGNAL(outPort(QString)), this, SLOT(Print(QString)));//вывод в текстовое поле считанных данных

    connect(this,SIGNAL(writeData(QByteArray)),PortNew,SLOT(WriteToPort(QByteArray)));//отправка в порт данных
    thread_New->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dark_theme()
{
    QPalette darkPalette;

    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);
    theme = true;
}

void MainWindow::light_theme()
{
    qApp->setPalette(style()->standardPalette());
    theme = false;
}

void MainWindow::stop()
{
    ui->BtnConnect->setEnabled(true);
    ui->BtnDisconect->setEnabled(false);
    timer->stop();
    timer_2->stop();
    timer_3->stop();

    timer_4->stop();
    timer_5->stop();
    timer_6->stop();

    recordObject.insert("X1",numbersArray_x);
    recordObject.insert("Y1",numbersArray_y);
    recordObject.insert("X2",numbersArray_x_2);
    recordObject.insert("Y2",numbersArray_y_2);
    recordObject.insert("X3",numbersArray_x_3);
    recordObject.insert("Y3",numbersArray_y_3);

    QJsonDocument doc(recordObject);
    QString jsonString = doc.toJson(QJsonDocument::Indented);

    QFile file;

    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "", TEXT_FILE_FORMAT + ";;" + ALL_FILE_FORMAT);
    if (!filePath.isEmpty()) {
        QTextStream Qcout(stdout);
        Qcout<<filePath;
        QString filePath_tmp;
        ++save;

        QString save_tmp = QString::number(save);

        filePath_tmp = filePath + "_" + save_tmp + ".json";
        file.setFileName(filePath_tmp);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream( &file );
        stream << jsonString;

        file.close();

        QString fileNameGraf_x1(filePath + "X1" + "_" + save_tmp + ".bmp");
        QString fileNameGraf_x2(filePath + "X2" + "_" + save_tmp + ".bmp");
        QString fileNameGraf_x3(filePath + "X3" + "_" + save_tmp + ".bmp");

        QString fileNameGraf_y1(filePath + "Y1" + "_" + save_tmp + ".bmp");
        QString fileNameGraf_y2(filePath + "Y2" + "_" + save_tmp + ".bmp");
        QString fileNameGraf_y3(filePath + "Y3" + "_" + save_tmp + ".bmp");

        QFile file_x1(fileNameGraf_x1);
        QFile file_x2(fileNameGraf_x2);
        QFile file_x3(fileNameGraf_x3);

        QFile file_y1(fileNameGraf_y1);
        QFile file_y2(fileNameGraf_y2);
        QFile file_y3(fileNameGraf_y3);

        if (!file_x1.open(QIODevice::WriteOnly) || !file_x2.open(QIODevice::WriteOnly) || !file_x3.open(QIODevice::WriteOnly) ||
                !file_y1.open(QIODevice::WriteOnly) || !file_y2.open(QIODevice::WriteOnly) || !file_y3.open(QIODevice::WriteOnly))
        {
            qDebug() << file_x1.errorString();
            qDebug() << file_x2.errorString();
            qDebug() << file_x3.errorString();
            qDebug() << file_y1.errorString();
            qDebug() << file_y2.errorString();
            qDebug() << file_y3.errorString();
        }
        else
        {
            ui->widget->saveBmp(fileNameGraf_x1, 800, 800);
            ui->widget_4->saveBmp(fileNameGraf_x2, 800, 800);
            ui->widget_2->saveBmp(fileNameGraf_x3, 800, 800);
            ui->widget_5->saveBmp(fileNameGraf_y1, 800, 800);
            ui->widget_3->saveBmp(fileNameGraf_y2, 800, 800);
            ui->widget_6->saveBmp(fileNameGraf_y3, 800, 800);
        }
    }


    r = 0.0;

    u[0] = 0.0;
    u[1] = 0.0;
    u[2] = 0.0;

    x_1[0] = arg1_x;
    x_1[1] = arg1_x;
    x_1[2] = 0.0;

    x_2[0] = arg2_x;
    x_2[1] = arg2_x;
    x_2[2] = 0.0;

    x_3[0] = arg3_x;
    x_3[1] = arg3_x;
    x_3[2] = 0.0;

    y_1[0] = 0.0;
    y_1[1] = 0.0;
    y_1[2] = 0.0;

    y_2[0] = 0.0;
    y_2[1] = 0.0;
    y_2[2] = 0.0;

    y_3[0] = 0.0;
    y_3[1] = 0.0;
    y_3[2] = 0.0;

    doo[0] = 0.0;
    doo[1] = 0.0;
    doo[2] = 0.0;

    q = 0.0;
    q_2 = 0.0;
    q_3 = 0.0;
    q_y = 0.0;
    q_2_y = 0.0;
    q_3_y = 0.0;

    i_1 = 0;
    i = 1;
}

void MainWindow::start()
{
    ui->BtnConnect->setEnabled(false);
    ui->BtnDisconect->setEnabled(true);
    if (flag_start == true)
    {
        usleep(100000);
        data_in = "\r";
        writeData(data_in.toLocal8Bit());
        usleep(50000);
        writeData(data_in.toLocal8Bit());
        sleep(4);
        pw = "les\r";
        writeData(pw);
        flag_start = false;
    }


    key = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    timer = new QTimer();
    timer_2 = new QTimer();
    timer_3 = new QTimer();

    timer_4 = new QTimer();
    timer_5 = new QTimer();
    timer_6 = new QTimer();

    ui->widget->clearGraphs();
    ui->widget_4->clearGraphs();
    ui->widget_2->clearGraphs();
    ui->widget_5->clearGraphs();
    ui->widget_3->clearGraphs();
    ui->widget_6->clearGraphs();

    ui->widget->addGraph(); // blue line
    ui->widget->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    ui->widget_2->addGraph(); // blue line
    ui->widget_2->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    ui->widget_3->addGraph(); // blue line
    ui->widget_3->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    ui->widget_4->addGraph(); // blue line
    ui->widget_4->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    ui->widget_5->addGraph(); // blue line
    ui->widget_5->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    ui->widget_6->addGraph(); // blue line
    ui->widget_6->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->widget->xAxis->setTicker(0);
    ui->widget->axisRect()->setupFullAxesBox();
    ui->widget->yAxis->setRange(-1, 1);

    QSharedPointer<QCPAxisTickerTime> timeTicker_2(new QCPAxisTickerTime);
    timeTicker_2->setTimeFormat("%h:%m:%s");
    ui->widget_2->xAxis->setTicker(0);
    ui->widget_2->axisRect()->setupFullAxesBox();
    ui->widget_2->yAxis->setRange(-1, 1);

    QSharedPointer<QCPAxisTickerTime> timeTicker_3(new QCPAxisTickerTime);
    timeTicker_3->setTimeFormat("%h:%m:%s");
    ui->widget_3->xAxis->setTicker(0);
    ui->widget_3->axisRect()->setupFullAxesBox();
    ui->widget_3->yAxis->setRange(-1, 1);


    QSharedPointer<QCPAxisTickerTime> timeTicker_4(new QCPAxisTickerTime);
    timeTicker_4->setTimeFormat("%h:%m:%s");
    ui->widget_4->xAxis->setTicker(0);
    ui->widget_4->axisRect()->setupFullAxesBox();
    ui->widget_4->yAxis->setRange(-1, 1);

    QSharedPointer<QCPAxisTickerTime> timeTicker_5(new QCPAxisTickerTime);
    timeTicker_5->setTimeFormat("%h:%m:%s");
    ui->widget_5->xAxis->setTicker(0);
    ui->widget_5->axisRect()->setupFullAxesBox();
    ui->widget_5->yAxis->setRange(-1, 1);

    QSharedPointer<QCPAxisTickerTime> timeTicker_6(new QCPAxisTickerTime);
    timeTicker_6->setTimeFormat("%h:%m:%s");
    ui->widget_6->xAxis->setTicker(0);
    ui->widget_6->axisRect()->setupFullAxesBox();
    ui->widget_6->yAxis->setRange(-1, 1);


    ui->widget->yAxis->setLabel("Y");
    ui->widget_2->yAxis->setLabel("Y");
    ui->widget_3->yAxis->setLabel("Y");

    ui->widget_4->yAxis->setLabel("X");
    ui->widget_5->yAxis->setLabel("X");
    ui->widget_6->yAxis->setLabel("X");

    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));

    connect(timer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));

    connect(ui->widget_4->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_4->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget_4->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_4->yAxis2, SLOT(setRange(QCPRange)));

    connect(timer_4, SIGNAL(timeout()), this, SLOT(realtimeDataSlot_4()));

    connect(ui->widget_2->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_2->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget_2->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_2->yAxis2, SLOT(setRange(QCPRange)));

    connect(timer_2, SIGNAL(timeout()), this, SLOT(realtimeDataSlot_2()));

    connect(ui->widget_5->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_5->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget_5->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_5->yAxis2, SLOT(setRange(QCPRange)));

    connect(timer_5, SIGNAL(timeout()), this, SLOT(realtimeDataSlot_5()));

    connect(ui->widget_3->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_3->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget_3->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_3->yAxis2, SLOT(setRange(QCPRange)));

    connect(timer_3, SIGNAL(timeout()), this, SLOT(realtimeDataSlot_3()));

    connect(ui->widget_6->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_6->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget_6->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_6->yAxis2, SLOT(setRange(QCPRange)));

    connect(timer_6, SIGNAL(timeout()), this, SLOT(realtimeDataSlot_6()));

    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget_2->setInteraction(QCP::iRangeZoom, true);
    ui->widget_3->setInteraction(QCP::iRangeZoom, true);

    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget_2->setInteraction(QCP::iRangeDrag, true);
    ui->widget_3->setInteraction(QCP::iRangeDrag, true);

    ui->widget_4->setInteraction(QCP::iRangeZoom, true);
    ui->widget_5->setInteraction(QCP::iRangeZoom, true);
    ui->widget_6->setInteraction(QCP::iRangeZoom, true);

    ui->widget_4->setInteraction(QCP::iRangeDrag, true);
    ui->widget_5->setInteraction(QCP::iRangeDrag, true);
    ui->widget_6->setInteraction(QCP::iRangeDrag, true);

    ui->widget->replot();
    ui->widget_2->replot();
    ui->widget_3->replot();

    ui->widget_4->replot();
    ui->widget_5->replot();
    ui->widget_6->replot();

    layout->setCurrentWidget(ui->widget);
    layout_2->setCurrentWidget(ui->widget_2);
    layout_3->setCurrentWidget(ui->widget_3);

    timer->start(0);
    timer_2->start(0);
    timer_3->start(0);

    timer_4->start(0);
    timer_5->start(0);
    timer_6->start(0);
}

void MainWindow::realtimeDataSlot()
{
    if (start_dots == true)
    {
        if (y_1[2] > q_y)
        {
            q_y = y_1[2];
            ui->widget->yAxis->setRange((-1 * (q_y + 10)), q_y + 10);
        }
        ui->widget->graph(0)->addData(i_1, y_1[2]);
        ui->widget->xAxis->setRangeUpper(i_1 + 1);
        ui->widget->replot();
   }
}

void MainWindow::realtimeDataSlot_4()
{
    if (start_dots == true)
    {
        if (x_1[2] > q)
        {
            q = x_1[2];
            ui->widget_4->yAxis->setRange((-1 * (q + 10)), q + 10);
        }
        ui->widget_4->graph(0)->addData(i_1, x_1[2]);
        ui->widget_4->xAxis->setRangeUpper(i_1 + 1);
        ui->widget_4->replot();
    }
}

void MainWindow::realtimeDataSlot_2()
{
    if (start_dots == true)
    {
        if (y_2[2] > q_2_y)
        {
            q_2_y = y_2[2];
            ui->widget_2->yAxis->setRange((-1 * (q_2_y + 10)), q_2_y + 10);
        }
        ui->widget_2->graph(0)->addData(i_1, y_2[2]);
        ui->widget_2->xAxis->setRangeUpper(i_1 + 1);
        ui->widget_2->replot();
    }
}

void MainWindow::realtimeDataSlot_5()
{
    if (start_dots == true)
    {
        if (x_2[2] > q_2)
        {
            q_2 = x_2[2];
            ui->widget_5->yAxis->setRange((-1 * (q_2 + 10)), q_2 + 10);
        }
        ui->widget_5->graph(0)->addData(i_1, x_2[2]);
        ui->widget_5->xAxis->setRangeUpper(i_1 + 1);
        ui->widget_5->replot();
    }
}

void MainWindow::realtimeDataSlot_3()
{
    if (start_dots == true)
    {
        if (y_3[2] > q_3_y)
        {
            q_3_y = y_3[2];
            ui->widget_3->yAxis->setRange((-1 * (q_3_y + 10)), q_3_y + 10);
        }
        ui->widget_3->graph(0)->addData(i_1, y_3[2]);
        ui->widget_3->xAxis->setRangeUpper(i_1 + 1);
        ui->widget_3->replot();
    }
}

void MainWindow::realtimeDataSlot_6()
{
    if (start_dots == true)
    {
        if (x_3[2] > q_3)
        {
            q_3 = x_3[2];
            ui->widget_6->yAxis->setRange((-1 * (q_3 + 10)), q_3 + 10);
        }
        ui->widget_6->graph(0)->addData(i_1, x_3[2]);
        ui->widget_6->xAxis->setRangeUpper(i_1 + 1);
        ui->widget_6->replot();
    }
}


//void MainWindow::on_pushButton_3_clicked()  //Кнопка Устойчивость
//{
//    QMessageBox::StandardButton reply = QMessageBox::question(this, "Window",
//                 "Устойчивость?", QMessageBox::Yes | QMessageBox::No);
//    if (reply == QMessageBox::Yes)
//    {
//        //Блок код устойчивости
//        QApplication::quit(); //Тестовая функция
//    }

//}

void MainWindow::on_doubleSpinBox_228_valueChanged(double arg1)
{
    Td = 0.0;
    Td = arg1;
    Td_tmp = arg1;
}




void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    Tf = 0.0;
    Tf = arg1;
    Tf_tmp = arg1;
}


void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
    s = 0.0;
    s = arg1;
    s_tmp = arg1;
}

void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    k = 0.0;
    k = arg1;
    k_tmp = arg1;
}

void MainWindow::on_Btn_Serch_clicked()
{
    ui->PortNameBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
        ui->PortNameBox->addItem(info.portName());
        }
}

void MainWindow::checkCustomBaudRatePolicy(int idx)
{
    bool isCustomBaudRate = !ui->BaudRateBox->itemData(idx).isValid();
    ui->BaudRateBox->setEditable(isCustomBaudRate);
    if (isCustomBaudRate) {
        ui->BaudRateBox->clearEditText();
    }
}

void    MainWindow::dots(double r)
{
    ++ i_1;
    tmp = 10.0 / 3.0;

    if (i_1 == 1)
    {
        doo[i_1 - 1] = 2.0 * r * tmp;
        u[i_1 - 1] = doo[i_1 - 1];
    }
    if (i_1 == 2)
    {
        doo[i_1 - 1] = 2.0 * r * tmp;
        u[i_1 - 1] = doo[i_1 - 1];
    }
    if (i_1 >= 3)
    {

        // реализация расчёта
        doo[i_1 - i] = 2.0 * r * tmp;
        u[i_1 - i] = doo[i_1 - i];

        x_1[i_1 - i] = x_1[i_1 - i - 1] * (1 - s * Td * k) + u[i_1 - i] - u[i_1 - i - 1];
        y_1[i_1 - i] = u[i_1 - i] - x_1[i_1 - i];

        x_2[i_1 - i] = (1.0 / Tf) * (x_2[i_1 - i - 1] * (-Td + Tf - s * k * Td) + u[i_1 - i - 1] * (Td - Tf)) + u[i_1 - i];
        y_2[i_1 - i] = u[i_1 - i] - x_2[i_1 - i];

        x_3[i_1 - i] = x_3[i_1- i - 1] * (2 - Td * s *k * Tf) - x_3[i_1 - i - 2] * (1 + s * k * pow(Td, 2) - s * k * Td * Tf) + u[i_1 - i] - 2 * u[i_1 - i - 1] + u[i_1 - i - 2];
        y_3[i_1 - i] = u[i_1 - i] - x_3[i_1 - i];

        u[i_1 - i - 2] = u[i_1 - i - 1];
        u[i_1 - i - 1] = u[i_1 - i];

        x_1[i_1 - i - 2] = x_1[i_1 - i - 1];
        x_1[i_1 - i - 1] = x_1[i_1 - i];

        x_2[i_1 - i - 2] = x_2[i_1 - i - 1];
        x_2[i_1 - i - 1] = x_2[i_1 - i];

        x_3[i_1 - i - 2] = x_3[i_1 - i - 1];
        x_3[i_1 - i - 1] = x_3[i_1 - i];

        numbersArray_x.push_back(x_1[i_1 - i]);
        numbersArray_y.push_back(y_1[i_1 - i]);

        numbersArray_x_2.push_back(x_2[i_1 - i]);
        numbersArray_y_2.push_back(y_2[i_1 - i]);

        numbersArray_x_3.push_back(x_3[i_1 - i]);
        numbersArray_y_3.push_back(y_3[i_1 - i]);

        ++ i;

    }
}

void MainWindow::parseMath(QString data)
{
    QString tmp = data;
    tmp.chop(1);
    QStringList list = tmp.split('=');
    if (list.length() == 2)
    {
        r = list.at(1).toDouble();
        mediana[0] = mediana[1];
        mediana[1] = mediana[2];
        mediana[2] = r;
        double sort_tmp;
        if (mediana[0] > mediana[1])
        {
            sort_tmp = mediana[1];
            mediana[1] = mediana[0];
            mediana[0] = sort_tmp;
        }
        if (mediana[1] > mediana[2])
        {
            sort_tmp = mediana[2];
            mediana[2] = mediana[1];
            mediana[1] = sort_tmp;
        }
        if (mediana[0] > mediana[1])
        {
            sort_tmp = mediana[1];
            mediana[1] = mediana[0];
            mediana[0] = sort_tmp;
        }

        r = fabs(mediana[2] - mediana[0]) / 2;

        if (med > 2)
        {
            start_dots = false;
            dots(r);
            start_dots = true;
        }
        ++ med;
    }

}

void MainWindow::Print(QString data)
{
    parseMath(data);
    ui->consol->textCursor().insertText(data+'\r'); // Вывод текста в консоль
    ui->consol->moveCursor(QTextCursor::End);//Scroll
}

void MainWindow::on_BtnSave_clicked()
{

    savesettings(ui->PortNameBox->currentText(), ui->BaudRateBox->currentText().toInt(), 8,
             0, 2, 0);
    ui->BtnConnect->setEnabled(true);

}

void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
    x_1[0] = arg1;
    x_1[1] = arg1;
    arg1_x = arg1;
}


void MainWindow::on_doubleSpinBox_7_valueChanged(double arg1)
{
    x_2[0] = arg1;
    x_2[1] = arg1;
    arg2_x = arg1;
}

void MainWindow::on_doubleSpinBox_8_valueChanged(double arg1)
{
    x_3[0] = arg1;
    x_3[1] = arg1;
    arg3_x = arg1;
}


void MainWindow::on_pushButton_8_clicked()
{
    layout->setCurrentWidget(ui->widget);
    ui->widget->yAxis->setLabel("Y");
}


void MainWindow::on_pushButton_7_clicked()
{
    layout_2->setCurrentWidget(ui->widget_2);
    ui->widget_2->yAxis->setLabel("Y");
}


void MainWindow::on_pushButton_9_clicked()
{
    layout_3->setCurrentWidget(ui->widget_3);
    ui->widget_3->yAxis->setLabel("Y");
}


void MainWindow::on_pushButton_4_clicked()
{
    layout->setCurrentWidget(ui->widget_4);
    ui->widget->yAxis->setLabel("X");
}


void MainWindow::on_pushButton_5_clicked()
{
    layout_2->setCurrentWidget(ui->widget_5);
    ui->widget_2->yAxis->setLabel("X");
}


void MainWindow::on_pushButton_6_clicked()
{
    layout_3->setCurrentWidget(ui->widget_6);
    ui->widget_3->yAxis->setLabel("X");
}

void MainWindow::on_pushButton_clicked()
{
    if (theme == true)
        light_theme();
    else
        dark_theme();
}
