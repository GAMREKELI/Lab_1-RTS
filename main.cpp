#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

//    QJsonObject recordObject;
//    recordObject.insert("Test1", QJsonValue::fromVariant("1"));
//    recordObject.insert("Test2", QJsonValue::fromVariant(123.4));
//    recordObject.insert("Test3", QJsonValue::fromVariant(43));
//    recordObject.insert("Test4", QJsonValue::fromVariant(true));
//    recordObject.insert("Test5",   QJsonValue::fromVariant(QByteArray("1,2,3,4,5")));
//          QJsonArray numbersArray;
//          numbersArray.push_back("1");
//          numbersArray.push_back("2");
//          numbersArray.push_back("3");
//          recordObject.insert("Test6",numbersArray);
//          QJsonDocument doc(recordObject);
//          QString jsonString = doc.toJson(QJsonDocument::Indented);
//          //Записываем данные в файл
//          QFile file;
//          file.setFileName("test1.json");
//          file.open(QIODevice::WriteOnly | QIODevice::Text);
//          QTextStream stream( &file );
//          stream << jsonString;
//                file.close();


    return a.exec();
}
