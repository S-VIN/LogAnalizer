#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <iostream>
#include <QTextEdit>
#include <QDebug>

class MainWindow: public QWidget {
Q_OBJECT
private:
    QPushButton OpenLog;
    QPushButton SaveLog;
    QTextEdit LogsEdit;
    QVBoxLayout MainInWidget;
    QHBoxLayout Instruments;


    void OpenLogInit(){
        OpenLog.setText("openLog");
    };

    void SaveLogInit(){
        SaveLog.setText("saveLog");
    };

    void ChooseLogInit(){

    };

    void LogsEditInit(){

    };

    void InstrumentsInit(){
        Instruments.addWidget(&OpenLog);
        Instruments.addWidget(&SaveLog);

    };

    void MainInWidgetInit(){
        MainInWidget.addLayout(&Instruments);
        MainInWidget.addWidget(&LogsEdit);
        this->setLayout(&MainInWidget);
    };

    void ComponentsInit(){
        MainInWidgetInit();
        InstrumentsInit();
        OpenLogInit();
        SaveLogInit();
        ChooseLogInit();
        LogsEditInit();
    }

public:
    MainWindow(QWidget *parent = 0): QWidget(parent){
        ComponentsInit();
        this->setGeometry(this->geometry().x(), this->geometry().y(),800, 800);
        QObject::connect(&OpenLog, SIGNAL(clicked(bool)), this, SLOT(ChooseLog()));
    }

private slots:
    void ChooseLog(){
       QString FileName = QFileDialog::getOpenFileName(this, tr("Open log"), "/home");
       qDebug() << FileName;
       QFile LogFile(FileName);
       LogFile.open(QIODevice::ReadWrite);
       QTextStream in(&LogFile);
       while (!in.atEnd()) {
            QString line = in.readLine();
            qDebug() << line;
            LogsEdit.append(line);
       }
    };


};