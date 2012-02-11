#include <QtGui/QApplication>
#include <QWidget>
#include <QLabel>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QTabWidget>
#include <QTabBar>
#include <QToolButton>

#include "generalScreen.h"
#include "MainWindow.h"
#include "controller.h"
#include "MainWindowTab.h"

void MsgHandler(QtMsgType type,const char *msg)
{
    //do nothing
}

int main(int argc, char *argv[])
{
   qInstallMsgHandler(MsgHandler);
   QApplication app(argc,argv);

   MainWindow *MainWin=new MainWindow(NULL);
   MainWindowTab *MainWinTab=new MainWindowTab(NULL);

   QMainWindow mw(0);
   mw.setWindowTitle("scanfish");
   mw.setCentralWidget(MainWinTab);
   QMenuBar *mbar=mw.menuBar();
   QMenu *menu=new QMenu("Menu");
   menu->addAction("About",MainWin,SLOT(showCredits()));
   menu->addAction("Quit",&app,SLOT(quit()));
   mbar->addMenu(menu);

   mw.setGeometry(100,100,850,550);
   mw.show();

   return app.exec();
  // return 0;
}
