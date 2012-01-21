#ifndef RECEIVE_H
#define	RECEIVE_H

#include <QtGui/QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QHeaderView>
#include <QScrollArea>
#include <QGridLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QTime>
#include <QDirModel>
#include <QTreeView>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QRadioButton>
#include <QDialog>
#include <map>
#include <math.h>

//#include "MessageEditor.h"


#define MAX_TABLE_SIZE 1000

class Receive : public QGroupBox
{
    Q_OBJECT
    QGridLayout *RecLayout;

public:
    Receive(QWidget *Rec);
    typedef std::map <int,int> maskTable;
    maskTable maskTab;

private slots:
    void RecTableFilter();
    void RecTableClear();
    void ReceiveSlot(int ID,int DLC,QString DATA,QTime time);
    void RecTableSave();
    void addMask();
    void removeMask();
    void wakeUpFilter();
    void sleepFilter();
    void saveChanges();
    void quit();

private:
    QTableWidget *RecTab;
    QPushButton *RecFilterButton;
    QPushButton *RecClearButton;
    QPushButton *RecSaveButton;
    QSpacerItem *VerticalSpacer;

    int k;
    int i;
    int j;
    int mRow;

    QHBoxLayout *fltMainLayout;
    QDialog *filterWin;
    QRadioButton *withoutFilter;
    QRadioButton *idFilter;
    QVBoxLayout *rightLayout;
    QHBoxLayout *fltMaskLayout;
    QLabel *idMask;
    QLineEdit *maskLineEdit;
    QHBoxLayout *butAddRemLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QTableWidget *idMaskTab;
    QVBoxLayout *leftLayout;
    QTableWidgetItem *idMaskTab_Item;
    QHBoxLayout *fltButLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *HorizontalSpacer;

    void printMaskTab();
    void printTmpMaskTab();

//    typedef std::map <int,int> maskTable;
//    maskTable maskTab;
    int maskCount;
   // maskTable::iterator it;
    int r;
    int maskNum;
    int choose; //0 - without filter; 1 - filter
    int prevChoose; //for saving new state of choose
    maskTable tmpMaskTab;
//    maskTable removeMaskTab;

};

#endif	/* RECEIVE_H */

