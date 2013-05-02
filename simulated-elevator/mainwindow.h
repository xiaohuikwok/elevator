#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "dispatcher.h"
#include "receiver.h"
#include <QObject>
#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0) :
        QMainWindow(parent)
    {
        ui.setupUi(this);
        dispatcher = new Dispatcher();
        reciever = new Receiver();
        QObjectList l = ui.centralWidget->children();
        for(int i = 0; i != l.count(); i++){
            Elevator* v = dynamic_cast<Elevator*>(l.at(i));
            if(v != 0) {
               dispatcher->takeInControl(v);
            }
        }
        connect(reciever,SIGNAL(signalRequestReceived(Request*)),dispatcher,SLOT(requestReceived(Request*)));
    }

private:
    Ui::SimElevators ui;
    Dispatcher* dispatcher;
    Receiver* reciever;
};

#endif // MAINWINDOW_H
