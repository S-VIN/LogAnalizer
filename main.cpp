#include <QApplication>
#include <QPushButton>
#include <QTextStream>
#include <QFileInfo>
#include <QFileDialog>
#include "main.moc"
#include "mainWindiw.h"
#include <QLabel>
#include <QLineEdit>
#include <QTableView>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow MainWindow;
    MainWindow.show();

    return QApplication::exec();
}
