#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <iostream>
#include <QTextEdit>
#include <QDebug>
#include <QTextDocumentWriter>

class MainWindow: public QWidget {
Q_OBJECT
private:
    QPushButton OpenLog;
    QPushButton SaveLog;
    QPushButton SaveAsLog;
    QTextEdit LogsEdit;
    QVBoxLayout MainInWidget;
    QHBoxLayout Instruments;
    QString LogFileName;

    void OpenLogInit(){
        OpenLog.setText("Open");
    };

    void SaveLogInit(){
        SaveLog.setText("Save");
    };

    void SaveAsLogInit(){
        SaveAsLog.setText("Save as");
    };

    void ChooseLogInit(){

    };

    void LogsEditInit(){

    };

    void InstrumentsInit(){
        Instruments.addWidget(&OpenLog);
        Instruments.addWidget(&SaveLog);
        Instruments.addWidget(&SaveAsLog);
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
        SaveAsLogInit();
        ChooseLogInit();
        LogsEditInit();
    }

public:
    MainWindow(QWidget *parent = 0): QWidget(parent){
        ComponentsInit();
        this->setGeometry(this->geometry().x(), this->geometry().y(),800, 800);
        QObject::connect(&OpenLog, SIGNAL(clicked(bool)), this, SLOT(ChooseLog()));
        QObject::connect(&SaveLog, SIGNAL(clicked(bool)), this, SLOT(FileSave()));
        QObject::connect(&SaveAsLog, SIGNAL(clicked(bool)), this, SLOT(FileSaveAs()));
    }

private slots:
    void ChooseLog(){
       LogFileName = QFileDialog::getOpenFileName(this, tr("Open log"), "/home");
       QFile LogFile(LogFileName);
       LogFile.open(QIODevice::ReadWrite);
       LogsEdit.clear();
       QTextStream in(&LogFile);
       while (!in.atEnd()) {
            QString line = in.readLine();
            LogsEdit.append(line);
       }
    };

    void FileSave(){
        if (LogFileName.isEmpty())
            return FileSaveAs();
        if (LogFileName.startsWith(QStringLiteral(":/")))
            return FileSaveAs();

        QTextDocumentWriter writer(LogFileName);
        bool success = writer.write(LogsEdit.document());
        if (success) {
            LogsEdit.document()->setModified(false);
        }
    }

    void FileSaveAs()
    {
        QFileDialog fileDialog(this, tr("Save as..."));
        fileDialog.setAcceptMode(QFileDialog::AcceptSave);
        fileDialog.setDefaultSuffix("txt");
        if (fileDialog.exec() != QDialog::Accepted)
            return;
        const QString fn = fileDialog.selectedFiles().first();
        LogFileName = fn;
        FileSave();
    }
};