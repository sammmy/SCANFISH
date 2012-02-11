#include "Receive.h"
#include <QTime>
#include <QHeaderView>

Receive :: Receive(QWidget *Rec) : QGroupBox (Rec)
{
    k=0; //
    choose=0;
    prevChoose=0;
    maskCount=0; //number of masks

    setTitle("    Receive");
    RecTab = new QTableWidget(0,4);
    RecTab->setColumnWidth(0,130);
    RecTab->setColumnWidth(1,130);
    RecTab->setColumnWidth(2,130);
    RecTab->setColumnWidth(3,294);

    QTableWidgetItem *RecTab_Item0 = new QTableWidgetItem
            (QString::fromLocal8Bit("Timestamp"));
    RecTab->setHorizontalHeaderItem(0,RecTab_Item0);
    QTableWidgetItem *RecTab_Item1 = new QTableWidgetItem
            (QString::fromLocal8Bit("ID"));
    RecTab->setHorizontalHeaderItem(1,RecTab_Item1);
    QTableWidgetItem *RecTab_Item2 = new QTableWidgetItem
            (QString::fromLocal8Bit("DLC"));
    RecTab->setHorizontalHeaderItem(2,RecTab_Item2);
    QTableWidgetItem *RecTab_Item3 = new QTableWidgetItem
            (QString::fromLocal8Bit("DATA"));
    RecTab->setHorizontalHeaderItem(3,RecTab_Item3);

   RecFilterButton=new QPushButton ("Filter");
   RecFilterButton->setFixedSize (95,27);
   //RecFilterButton->setEnabled(false);

   RecClearButton = new QPushButton("Clear");
   RecClearButton->setFixedSize(95,27);
   RecClearButton->setEnabled(false);

   RecSaveButton=new QPushButton ("Save");
   RecSaveButton->setFixedSize (95,27);
   RecSaveButton->setEnabled(false);

   VerticalSpacer = new QSpacerItem (10,0,QSizePolicy::Expanding,
           QSizePolicy::Minimum);

   RecLayout = new QGridLayout;
   RecLayout->addWidget(RecTab,1,1,-1,1,Qt::AlignTop);
   RecLayout->addWidget(RecFilterButton,1,2,Qt::AlignTop);
   RecLayout->addWidget(RecSaveButton,2,2,Qt::AlignTop);
   RecLayout->addWidget(RecClearButton,3,2,Qt::AlignTop);
   RecLayout->addItem(VerticalSpacer,3,2,3,0,Qt::AlignTop);

   setLayout(RecLayout);

   RecTab->horizontalHeader()->setResizeMode(3,QHeaderView::Stretch);
   RecTab->verticalHeader()->setVisible(false);

   connect (RecFilterButton,SIGNAL(clicked()),this,SLOT(RecTableFilter()));
   connect (RecClearButton,SIGNAL(clicked()),this,SLOT(RecTableClear()));
   connect (RecSaveButton,SIGNAL(clicked()),this,SLOT(RecTableSave()));

}

void Receive :: RecTableClear()
{
    k=0;
    RecTab->clearContents();
    RecTab->setRowCount(0);
    RecSaveButton->setEnabled(false);
    RecClearButton->setEnabled(false);

}

void Receive :: ReceiveSlot(int ID,int DLC,QString DATA,QTime time)
{
    k++;
    int filter=0;
    maskTable::iterator it;
    QString idText;
    int checkingId;
    bool ok;
    idText = QVariant(ID).toString();
    checkingId=idText.toInt(&ok,10);

    if (choose==1)
    {
        for (it=maskTab.begin(); it!=maskTab.end(); it++)
        {
            if (it->second==checkingId)
            {
                filter=1;
                break;
            }
        }
    }

    if (filter==0)
    {
        RecTab->setSortingEnabled(false);
        RecFilterButton->setEnabled(true);
        RecClearButton->setEnabled(true);
        RecSaveButton->setEnabled(true);

        RecTab->insertRow(0);
        RecTab->setRowHeight(0,15);
        QString text;

        int count=RecTab->rowCount();
        if(count>MAX_TABLE_SIZE)
        {
           RecTab->removeRow(count-1);
        }

        text=time.toString("hh:mm:ss.zzz");

        QTableWidgetItem *T_Item1 = new QTableWidgetItem;
        T_Item1->setText(text);
        RecTab->setItem(0,0,T_Item1);
        RecTab->item(0,0)->setTextAlignment(Qt::AlignCenter);

        text = QVariant(ID).toString();

        QTableWidgetItem *T_Item2 = new QTableWidgetItem;
        T_Item2->setText(text);
        RecTab->setItem(0,1,T_Item2);
        RecTab->item(0,1)->setTextAlignment(Qt::AlignCenter);

        text = QVariant(DLC).toString();
        QTableWidgetItem *T_Item3 = new QTableWidgetItem
                (QString::fromLocal8Bit(""));
        T_Item3->setText(text);
        RecTab->setItem(0,2,T_Item3);
        RecTab->item(0,2)->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *T_Item4 = new QTableWidgetItem
                (QString::fromLocal8Bit(""));

        T_Item4->setText(DATA);
        RecTab->setItem(0,3,T_Item4);
        RecTab->item(0,3)->setTextAlignment(Qt::AlignCenter);

        RecTab->setSortingEnabled(true);
    }
}

void Receive :: RecTableSave()
{

    QString fileName = QFileDialog::getSaveFileName(this, 
            tr("Save File"), "Receive",tr("Text Files (*.txt);"));
    if (fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            // error message
        }
        else
        {
            QTextStream stream(&file);

            QString text;
            text="Timestamp";
            stream<<text;
            stream<<"\t\t\t";
            text="ID";
            stream<<text;
            stream<<"\t\t\t";
            text="DLC";
            stream<<text;
            stream<<"\t\t\t";     //   RecTab->sortByColumn(1); //Sorting by ID
     //   RecTab->sortByColumn(0,Qt::AscendingOrder); //Sorting by Timestamp
            text=" DATA";
            stream<<text;
            stream<<"\n\n";
            j=0;
            i=0;
            while (j!=k)
            {
                text = RecTab->item(j,i)->text();
                stream<<text;
                stream<<"\t\t\t";
                i++;
                text = RecTab->item(j,i)->text();
                stream<<text;
                stream<<"\t\t\t";
                i++;
                text = RecTab->item(j,i)->text();
                stream<<text;
                stream<<"\t\t\t";
                i++;
                text = RecTab->item(j,i)->text();
                stream<<text;
                stream<<"\n";
                i=0;
                j++;
            }        
            file.close();
        }
    }
}


void Receive :: RecTableFilter()
{
    fltMainLayout = new QHBoxLayout;
    filterWin = new QDialog;
    filterWin->setWindowTitle("Filter");
    withoutFilter=new QRadioButton ("Without filter");
    idFilter=new QRadioButton ("ID filter");

    rightLayout = new QVBoxLayout;
    rightLayout->addWidget(withoutFilter);
    rightLayout->addWidget(idFilter);
    fltMaskLayout=new QHBoxLayout;
    idMask=new QLabel("      ID Mask:   ");
    maskLineEdit=new QLineEdit;
    maskLineEdit->setPlaceholderText("FFFFFF");
    maskLineEdit->setFocusPolicy(Qt::ClickFocus);
    fltMaskLayout->addWidget(idMask);
    fltMaskLayout->addWidget(maskLineEdit);
    rightLayout->addLayout(fltMaskLayout);
    butAddRemLayout=new QHBoxLayout;
    addButton=new QPushButton("Add");
    addButton->setFixedSize (95,27);
    removeButton=new QPushButton("Remove");
    removeButton->setFixedSize (95,27);
    butAddRemLayout->addWidget(addButton);
    butAddRemLayout->addWidget(removeButton);
    rightLayout->addLayout(butAddRemLayout);

    if (choose==0)
    {
        addButton->setEnabled(false);
        removeButton->setEnabled(false);
        withoutFilter->setChecked(true);
    }
    else
    {
        addButton->setEnabled(true);
        removeButton->setEnabled(true);
        idFilter->setChecked(true);
    }


    idMaskTab = new QTableWidget(0,1);
    idMaskTab->setColumnWidth(0,255);
    idMaskTab->verticalHeader()->setVisible(false);

    leftLayout = new QVBoxLayout;
    idMaskTab_Item = new QTableWidgetItem
            (QString::fromLocal8Bit("ID Mask"));
    idMaskTab->setHorizontalHeaderItem(0,idMaskTab_Item);
    leftLayout->addWidget(idMaskTab);
    fltButLayout=new QHBoxLayout;
    okButton=new QPushButton("Ok");
    okButton->setFixedSize (95,27);
    cancelButton=new QPushButton("Cnacel");
    cancelButton->setFixedSize (95,27);

    HorizontalSpacer = new QSpacerItem (10,0,
            QSizePolicy::Expanding,QSizePolicy::Minimum);
    fltButLayout->addItem(HorizontalSpacer);

    fltButLayout->addWidget(okButton,0,Qt::AlignRight);
    fltButLayout->addWidget(cancelButton,0,Qt::AlignRight);
    leftLayout->addLayout(fltButLayout);

    fltMainLayout->addLayout(rightLayout);
    fltMainLayout->addLayout(leftLayout);

    printMaskTab();

    maskTable::iterator it;
    for(it=maskTab.begin();it!=maskTab.end();it++)
    {
        tmpMaskTab.insert(std::pair<int,int>(it->first,it->second));
    }

    QObject::connect(addButton,SIGNAL(clicked()),this,SLOT(addMask()));
    QObject::connect(okButton,SIGNAL(clicked()),filterWin,SLOT(close()));
    QObject::connect(okButton,SIGNAL(clicked()),this,SLOT(saveChanges()));
    QObject::connect(removeButton,SIGNAL(clicked()),this,SLOT(removeMask()));
    QObject::connect(idFilter,SIGNAL(clicked()),this,SLOT(wakeUpFilter()));
    QObject::connect(withoutFilter,SIGNAL(clicked()),this,SLOT(sleepFilter()));
    QObject::connect(cancelButton,SIGNAL(clicked()),filterWin,SLOT(close()));
    QObject::connect(cancelButton,SIGNAL(clicked()),this,SLOT(quit()));

    filterWin->setLayout(fltMainLayout);
    filterWin->show();

}

void Receive::printMaskTab()
{
    if (maskCount!=0)
    {
        QString text;
        maskTable::iterator it;

        for (it=maskTab.begin(); it!=maskTab.end(); it++)
        {
            idMaskTab->insertRow(0);
            idMaskTab->setRowHeight(0,15);
            QTableWidgetItem *addItem = new QTableWidgetItem;
            text.setNum(it->second);
            addItem->setText(text);
            idMaskTab->setItem(0,0,addItem);
            idMaskTab->item(0,0)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void Receive::printTmpMaskTab()
{
        QString text;
        maskTable::iterator it;

        for (it=tmpMaskTab.begin(); it!=tmpMaskTab.end(); it++)
        {
            idMaskTab->insertRow(0);
            idMaskTab->setRowHeight(0,15);
            QTableWidgetItem *addItem = new QTableWidgetItem;
            text.setNum(it->second);
            addItem->setText(text);
            idMaskTab->setItem(0,0,addItem);
            idMaskTab->item(0,0)->setTextAlignment(Qt::AlignCenter);
        }
}

void Receive::addMask()
{
    bool ok;
    int id;
    QString text;

    maskTable::iterator it;
    maskCount++;
    maskNum=maskCount;
    int isThere=0;
    id=maskLineEdit->text().toUInt(&ok,10);
    for (it=tmpMaskTab.begin();it!=tmpMaskTab.end();it++)
    {
        if(it->second==id)
            isThere=1;
    }

    if (isThere==0)
    {
        tmpMaskTab.insert(std::pair<int,int>(maskCount,id));
        idMaskTab->insertRow(0);
        idMaskTab->setRowHeight(0,15);
        QTableWidgetItem *addItem = new QTableWidgetItem;
        text.setNum(id);
        addItem->setText(text);
        idMaskTab->setItem(0,0,addItem);
        idMaskTab->item(0,0)->setTextAlignment(Qt::AlignCenter);
        
    }
}

void Receive::removeMask()
{
    maskTable::iterator it;
    QTableWidgetItem *removeItem = new QTableWidgetItem;
    removeItem=idMaskTab->currentItem();
    int text;
    bool ok;
    text=removeItem->text().toUInt(&ok,10);
    for(it=tmpMaskTab.begin();it!=tmpMaskTab.end();it++)
    {
        if (it->second==text)
        {
            tmpMaskTab.erase(it);
        }
    }
    for (r=maskCount;r>=0;r--)
        idMaskTab->removeRow(r);
    printTmpMaskTab();
}

void Receive::sleepFilter()
{
    addButton->setEnabled(false);
    removeButton->setEnabled(false);
    choose=0;
    maskTable::iterator it;
}

void Receive::wakeUpFilter()
{
    addButton->setEnabled(true);
    removeButton->setEnabled(true);
    choose=1;
}

void Receive::saveChanges()
{
    maskTable::iterator it;
    maskNum=1;
    int isThere=0;
    maskTab.clear();
    for(it=tmpMaskTab.begin();it!=tmpMaskTab.end();it++)
    {
        if (isThere==0)
        {
            maskTab.insert(std::pair<int,int>(maskNum,it->second));
            maskNum++;
        }
    }
    tmpMaskTab.clear();
    for(it=maskTab.begin();it!=maskTab.end();it++)
    {
        tmpMaskTab.insert(std::pair<int,int>(it->first,it->second));
    }
    prevChoose=choose;
}

void Receive::quit()
{
    tmpMaskTab.clear();
    if (prevChoose==0)
        choose=0;
    else
        choose=1;
}