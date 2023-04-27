
#include "my_window.h"
#include <class_Stydent.h>

#include <QGridLayout>
#include <QVector>
#include <vector>
#include <QMessageBox>
#include <typeinfo>




// CLASS TEACHER
class Teacher{
private:
    QString last_name;
    QString position;

public:
    Teacher(){
        last_name = "DEFAULT TEACHER";
        position = "DEFAULT POSITION";
    }

    Teacher(QString LN, QString PS){
        last_name = LN;
        position = PS;
    }

    ~Teacher(){
        // Debug
        qDebug() << "DESTRUCTOR: class Teacher";
    }
};



// CLASS STUDENT
class Stydent{
private:
    QString number_group;
    QString last_name;

public:
    Stydent(QString LN, QString NG){
        last_name = LN;
        number_group = NG;


        Count_stydent_Object++;

        //qDebug() << "COUNSTRUCTOR STUDEBT";
    }

    int print_count_objects(){
        return Count_stydent_Object;
    }

    void seter_last_name(QString *str_last_name){
        last_name = *str_last_name;
    }

    QString print_last_name(){
        return last_name;
    }

    QString print_number_group(){
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





// CLASS EXAM
class Exam{
private:
    QString subject_name;
    QString the_date_of_the_exam;

    int rating;
    int number_of_hours_to_study;

public:
    Exam(){
        subject_name = "ООП";
        the_date_of_the_exam = "25.04.2023";

        rating = 5;
        number_of_hours_to_study = 20;
    }

    void print(){
        qDebug() << "Назва предмету: " << subject_name;
        qDebug() << "Дата екзамену: " << the_date_of_the_exam;
        qDebug() << "Кількість годин викладання: " << number_of_hours_to_study;
        qDebug() << "Оцінка: " << rating;
    }





    ~Exam(){

    }

};





















MY_window::MY_window(QWidget *parent)
    : QWidget(parent) {


    QVBoxLayout *Student_top_VBOX = new QVBoxLayout(this);


    QPushButton *plsBtn = new QPushButton("Add student");
    QPushButton *mnsBtn = new QPushButton("Remove student");
    plsBtn->resize(10, 20);
//    QPushButton *minBtn = new QPushButton("-");

    //Student_munberGroup = new QLineEdit();
    Student_lastName = new QLineEdit();
    Student_munberGroup = new QLineEdit();

    newTble = new QTableWidget;



    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addRow("Lastname:", Student_lastName);
    formLayout->addRow("Number Group:", Student_munberGroup);
    formLayout->addRow("list student(s):", newTble);
    formLayout->addRow(plsBtn);
    formLayout->addRow(mnsBtn);

    Student_top_VBOX->addLayout(formLayout);

    setLayout(Student_top_VBOX);


    // Events
    connect(Student_lastName, &QLineEdit::textEdited, this, &MY_window::get_string_student_lastName);
    connect(Student_munberGroup, &QLineEdit::textEdited, this, &MY_window::get_string_student_munberGroup);

    connect(plsBtn, &QPushButton::clicked, this, &MY_window::set_new_valueToColumn);
    connect(mnsBtn, &QPushButton::clicked, this, &MY_window::remove_new_valueToColumn);


    connect(newTble, &QTableWidget::cellDoubleClicked, this, &MY_window::indo_click_new_valueToColumn);

}

// Slot for class creation
void MY_window::set_new_valueToColumn(){
    // Initializing streaming output
    QTextStream out(stdout);

    // Checking for a class destructor
    if(Stydent::Count_stydent_Object >= 0){
        if (set_string_student_lastName != "" && set_string_student_munberGroup != ""){
            // Debug viewing objects
            out << "Cout objects: " << Stydent::Count_stydent_Object << Qt::endl;

            //set_string_student_lastName;
            Stydents_massive.push_back(new Stydent(set_string_student_lastName, set_string_student_munberGroup));

            out << "Cout objects: " << Stydent::Count_stydent_Object << Qt::endl;


            // Setting a new value to a table
            newTble->setRowCount(Stydents_massive.size());
            newTble->setColumnCount(2);

            qDebug() << "Количество объектов: " << Stydents_massive.size();

                int vector_number_row = Stydents_massive.size();

            newTble->setItem((vector_number_row - 1),0,new QTableWidgetItem(QString(Stydents_massive[vector_number_row - 1]->print_last_name())));
            newTble->setItem((vector_number_row - 1),1,new QTableWidgetItem(QString(Stydents_massive[vector_number_row - 1]->print_number_group())));

            Student_munberGroup->setText("");
            Student_lastName->setText("");

            set_string_student_lastName = "";
            set_string_student_munberGroup = "";
        } else {
            QMessageBox msgBox;

            msgBox.setText("Заповніть всі поля!");
            msgBox.exec();
        }
    }
//    set_string_student_lastName = "dasd";
//    qDebug() << "+ | set_string_student_lastName = " << set_string_student_lastName;
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

void MY_window::indo_click_new_valueToColumn(int row, int column){
    //newTble->removeCellWidget(row, column);
    //newTble->removeRow(row);

    qDebug() << row;
    qDebug() << column;

    QMessageBox msgBox;

    QString DAD_class = typeid(*Stydents_massive[row]).name();
    QString number_object = QString::number(row);

    msgBox.setText("Class: " + DAD_class + "\nObject number from the array: " + number_object);
    msgBox.exec();
}




void MY_window::get_string_student_lastName(const QString &text){
    //qDebug() << "get_string_student_lastName | " << text;
    //set_string_student_lastName = new QString;
    //qDebug() << "set_string_student_lastName | " << *set_string_student_lastName;

    set_string_student_lastName = text;
}

void MY_window::get_string_student_munberGroup(const QString &text){
    qDebug() << "get_string_student_munberGroup | " << text;

    set_string_student_munberGroup = text;
}
