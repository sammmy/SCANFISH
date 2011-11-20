/*
 * File:   main.cpp
 * Author: Ira
 *
 * Created on July 2, 2011, 12:59 AM
 */

#include <QtGui/QApplication>
#include <QWidget>
#include <QLabel>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include "MainWindow.h"
#include "controller.h"

void MsgHandler(QtMsgType type,const char *msg)
{
    //do nothing
}

int main(int argc, char *argv[])
{
   qInstallMsgHandler(MsgHandler);
   QApplication app(argc,argv);
   Controller *Con;
   Con=Controller::getController();

   MainWindow *MainWin=new MainWindow(NULL,Con);
   QMainWindow mw(0);
   mw.setWindowTitle("scanfish");
   mw.setCentralWidget(MainWin);
   QMenuBar *mbar=mw.menuBar();
   QMenu *menu=new QMenu("Menu");
   menu->addAction("About",MainWin,SLOT(showCredits()));
   menu->addAction("Quit",&app,SLOT(quit()));
   mbar->addMenu(menu);
   mw.show();

   MainWindow *MainWin2=new MainWindow(NULL,Con);
   QMainWindow mw2(0);
   mw2.setWindowTitle("scanfish");
   mw2.setCentralWidget(MainWin2);
   QMenuBar *mbar2=mw.menuBar();
   QMenu *menu2=new QMenu("Menu");
   menu2->addAction("About",MainWin2,SLOT(showCredits()));
   menu2->addAction("Quit",&app,SLOT(quit()));
   mbar2->addMenu(menu);
   mw2.show();

//   MainWindow *MainWin3=new MainWindow(NULL,Con);
//   QMainWindow mw3(0);
//   mw3.setWindowTitle("scanfish");
//   mw3.setCentralWidget(MainWin3);
//   QMenuBar *mbar3=mw.menuBar();
//   QMenu *menu3=new QMenu("Menu");
//   menu3->addAction("About",MainWin3,SLOT(showCredits()));
//   menu3->addAction("Quit",&app,SLOT(quit()));
//   mbar3->addMenu(menu);
//   mw3.show();

   return app.exec();
}
