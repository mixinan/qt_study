#ifndef __CALCULATORDIALOG_H
#define __CALCULATORDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDoubleValidator>

class CalculatorDialog:public QDialog{
    Q_OBJECT
public:
    CalculatorDialog(void);
private slots:
    void enableCalcButton(void);
    void calcClicked(void);
private:
    QLineEdit* m_editX;
    QLineEdit* m_editY;
    QLineEdit* m_editZ;
    QLabel* m_label;
    QPushButton* m_btnCalc;
};

#endif
