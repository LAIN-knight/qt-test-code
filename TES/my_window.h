
#ifndef MY_WINDOW_H
#define MY_WINDOW_H


#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QTableWidget>
#include <QString>
#include <QTextStream>





class MY_window : public QWidget {

    Q_OBJECT // этот макрос должен включатьс€ в классы, которые объ€вл€ют свои собственные сигналы и слоты

public:
    MY_window(QWidget *parent = 0);
    //QString set_string_student_lastName;
    QString set_string_student_lastName;
    QString set_string_student_munberGroup;


private:
    QLineEdit *Student_munberGroup;
    QLineEdit *Student_lastName;

    QTableWidget *newTble;

    //QString *set_string_student_lastName;
    //QString *set_string_student_munberGroup;

public slots:
    void set_new_valueToColumn();
    void remove_new_valueToColumn();

    void indo_click_new_valueToColumn(int, int);

    void get_string_student_lastName(const QString &);
    void get_string_student_munberGroup(const QString &);

};






#endif // MY_WINDOW_H