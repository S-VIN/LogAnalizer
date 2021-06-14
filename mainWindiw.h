#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <iostream>
#include <QTextEdit>

class MainWindow: public QWidget {
Q_OBJECT
private:
    QPushButton OpenLog;
    QPushButton SaveLog;
    QFileDialog ChooseLog;
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
        //LogsEdit.show();
    };

    void InstrumentsInit(){
        Instruments.addWidget(&OpenLog);
        Instruments.addWidget(&SaveLog);
        Instruments.addWidget(&ChooseLog);
    };

    void MainInWidgetInit(){

        MainInWidget.addLayout(&Instruments);
        MainInWidget.addWidget(&LogsEdit);
        this->setLayout(&MainInWidget);
    };

public:
    MainWindow(QWidget *parent = 0): QWidget(parent){
        MainInWidgetInit();
        InstrumentsInit();
        OpenLogInit();
        SaveLogInit();
        ChooseLogInit();
        LogsEditInit();

        QObject::connect(&OpenLog, SIGNAL(clicked(bool)), &ChooseLog, SLOT(open()));

    }



};