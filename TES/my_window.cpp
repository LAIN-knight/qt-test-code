
#include "my_window.h"
#include <class_Stydent.h>

#include <QGridLayout>
#include <QVector>
#include <vector>


class Stydent{
private:
    int number_group;
    QString last_name;



public:
//    Stydent(){
//        last_name = "VECTOR_CLASS";
//        number_group = 77777;


//        Count_stydent_Object++;

//        //qDebug() << "COUNSTRUCTOR STUDEBT";
//    }

    Stydent(QString LN, int NG){
        last_name = LN;
        number_group = NG;


        Count_stydent_Object++;

        //qDebug() << "COUNSTRUCTOR STUDEBT";
    }

    int print_count_objects(){
        return Count_stydent_Object;
    }

    QString print_last_name(){
        return last_name;
    }

    int print_number_group(){
        return number_group;
    }


//    ~Stydent(){
//        Count_stydent_Object--;
//        //qDebug() << "DESTRUCTOR STUDENT";
//    }

    virtual ~Stydent(){
        Count_stydent_Object--;
        //qDebug() << "DESTRUCTOR STUDENT";
    }


    static int Count_stydent_Object;
};

int Stydent::Count_stydent_Object = 0;





QVector <Stydent *> Stydents_massive;
//Stydents_massive.append(new Stydent());






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




    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addRow("Lastname:", Student_munberGroup);
    formLayout->addRow("Number Group:", Student_lastName);
    formLayout->addRow("list student(s):", newTble);
    formLayout->addRow(plsBtn);
    formLayout->addRow(mnsBtn);

    Student_top_VBOX->addLayout(formLayout);

    setLayout(Student_top_VBOX);


    // Events
    connect(plsBtn, &QPushButton::clicked, this, &MY_window::set_new_valueToColumn);
    connect(mnsBtn, &QPushButton::clicked, this, &MY_window::remove_new_valueToColumn);
    connect(newTble, &QTableWidget::cellDoubleClicked, this, &MY_window::remove_click_new_valueToColumn);

}

// Slot for class creation
void MY_window::set_new_valueToColumn(){
    // Initializing streaming output
    QTextStream out(stdout);

    // Checking for a class destructor
    if(Stydent::Count_stydent_Object >= 0){
        // Debug viewing objects
        out << "Cout objects: " << Stydent::Count_stydent_Object << Qt::endl;

        Stydents_massive.push_back(new Stydent("mmmmmm", 126));

        out << "Cout objects: " << Stydent::Count_stydent_Object << Qt::endl;


        // Setting a new value to a table
        newTble->setRowCount(Stydents_massive.size());
        newTble->setColumnCount(2);

        qDebug() << "Количество объектов: " << Stydents_massive.size();

        int vector_number_row = Stydents_massive.size();

        newTble->setItem((vector_number_row - 1),0,new QTableWidgetItem(QString(Stydents_massive[vector_number_row - 1]->print_last_name())));
        newTble->setItem((vector_number_row - 1),1,new QTableWidgetItem(QString::number(Stydents_massive[vector_number_row - 1]->print_number_group())));
        //newTble->setItem(vector_number_row,1,new QTableWidgetItem(QString::number(d->print_number_group())));

    }
    //qDebug() << "+ | ";
}







void MY_window::remove_new_valueToColumn(){
    //newTble->setItem(0,0,new QTableWidgetItem(QString("")));

        //newTble->removeRow(0);
    if(Stydent::Count_stydent_Object > 0){

        int index_remove_rows = Stydents_massive.size();
        Stydents_massive[index_remove_rows - 1]->~Stydent();
        Stydents_massive.pop_back();

        newTble->removeRow(index_remove_rows - 1);

        if(Stydent::Count_stydent_Object == 0){
            newTble->removeColumn(0);
            newTble->removeColumn(0);
        }

        //int let = *num_columns_added;
        qDebug() << "REMOVE ROW | " << index_remove_rows;
    }
}

void MY_window::remove_click_new_valueToColumn(int row, int column){
    //newTble->removeCellWidget(row, column);
    newTble->removeRow(row);

//    qDebug() << row;
//    qDebug() << column;
}


