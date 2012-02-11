#include <QtGui/QApplication>
#include <QWidget>
#include <QPushButton>

#include "controller.h"
#include "MainWindow.h"


#ifndef MAINWINDOWTAB_H
#define	MAINWINDOWTAB_H

class MainWindowTab:public QTabWidget
{
    Q_OBJECT
public:
    MainWindowTab(QTabWidget *TabWid);
    QPushButton *addBut;
    QTabWidget *tab;
    MainWindow *MainWin;
    MainWindow *MainWin2;

public slots:
    void addNewTab();
    void changeTabText();

private:
    int numTab;
    //Connection *Con;

};

#endif	/* MAINWINDOWTAB_H */

