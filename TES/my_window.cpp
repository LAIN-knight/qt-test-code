
#include "my_window.h"
#include <class_Stydent.h>

#include <QGridLayout>



class Stydent{
private:
    int number_group;
    QString last_name;



public:
    Stydent(QString LN, int NG){
        last_name = LN;
        number_group = NG;


        Count_stydent_Object++;

        //qDebug() << "COUNSTRUCTOR STUDEBT";
    }

    QString print(){
        QTextStream out(stdout);

        out << Count_stydent_Object;
    }


    ~Stydent(){
        Count_stydent_Object--;
        //qDebug() << "DESTRUCTOR STUDEBT";
    }

    static int Count_stydent_Object;
};



int Stydent::Count_stydent_Object = 0;



Stydent a("Ukra", 2123), b("Ukra2", 2123), c("Ukra3", 2123);

Stydent rr("Alla", 422);
Stydent r3("dasd", 477);
Stydent rw("Ayerf", 2622);
Stydent ry("53dsd", 252);
Stydent rs("Asdg", 232);














MY_window::MY_window(QWidget *parent)
    : QWidget(parent) {


    QVBoxLayout *Student_top_VBOX = new QVBoxLayout(this);


    QPushButton *plsBtn = new QPushButton("Add student");
    QPushButton *mnsBtn = new QPushButton("Remove student");
    plsBtn->resize(10, 20);
//    QPushButton *minBtn = new QPushButton("-");

    Student_munberGroup = new QLineEdit();
    Student_lastName = new QLineEdit();


    newTble = new QTableWidget;
    newTble->setRowCount(5);
    newTble->setColumnCount(2);
    //newTble->set

    newTble->setItem(0,0,new QTableWidgetItem(QString("AUTO PIDAR1")));
    newTble->setItem(0,1,new QTableWidgetItem(QString("126")));

    newTble->setItem(1,0,new QTableWidgetItem(QString("AUTO PIDAR2")));
    newTble->setItem(1,1,new QTableWidgetItem(QString("162")));

    newTble->setItem(2,0,new QTableWidgetItem(QString("AUTO PIDAR3")));
    newTble->setItem(2,1,new QTableWidgetItem(QString("148")));

    newTble->setItem(3,0,new QTableWidgetItem(QString("AUTO PIDAR4")));
    newTble->setItem(3,1,new QTableWidgetItem(QString("122")));

    //newTble->setTextAlignment(Qt::AlignVCenter);



    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addRow("Lastname:", Student_munberGroup);
    formLayout->addRow("Number Group:", Student_lastName);
    formLayout->addRow("list student(s):", newTble);
    formLayout->addRow(plsBtn);
    formLayout->addRow(mnsBtn);

    Student_top_VBOX->addLayout(formLayout);

    setLayout(Student_top_VBOX);

    connect(plsBtn, &QPushButton::clicked, this, &MY_window::set_new_valueToColumn);
    connect(mnsBtn, &QPushButton::clicked, this, &MY_window::remove_new_valueToColumn);
    connect(newTble, &QTableWidget::cellDoubleClicked, this, &MY_window::remove_click_new_valueToColumn);

}

void MY_window::set_new_valueToColumn(){


    //newTble = new QTableWidget;
    //newTble->setRowCount(5);
    //newTble->setColumnCount(2);

    //newCount = new QString;
    //int localBuff = newCount->toInt();


    QTextStream outt(stdout);


    if(Stydent::Count_stydent_Object > 0){

        newTble->setItem(0,0,new QTableWidgetItem(QString("ADDED")));
        outt << "Cout objects: " << Stydent::Count_stydent_Object << Qt::endl;

        Stydent rr("Alla", 422);
        Stydent r3("dasd", 477);
        Stydent rw("Ayerf", 2622);
        Stydent ry("53dsd", 252);
        Stydent rs("Asdg", 232);

    }
    //qDebug() << "+ | ";
}

void MY_window::remove_new_valueToColumn(){
    //newTble->setItem(0,0,new QTableWidgetItem(QString("")));

        newTble->removeRow(0);

        //int let = *num_columns_added;
        qDebug() << "- | ";


    //num_columns_added++;

    //qDebug() << *num_columns_added;
}

void MY_window::remove_click_new_valueToColumn(int row, int column){
    //newTble->removeCellWidget(row, column);
    newTble->removeRow(row);

//    qDebug() << row;
//    qDebug() << column;
}



