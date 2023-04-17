
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

    Q_OBJECT // этот макрос должен включаться в классы, которые объявляют свои собственные сигналы и слоты

public:
    MY_window(QWidget *parent = 0);


private:
    QLineEdit *Student_munberGroup;
    QLineEdit *Student_lastName;

    QTableWidget *newTble;

public slots:
    void set_new_valueToColumn();
    void remove_new_valueToColumn();
    void remove_click_new_valueToColumn(int, int);
};






#endif // MY_WINDOW_H
