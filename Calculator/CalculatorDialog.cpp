#include "CalculatorDialog.h"
#include <QDebug>
CalculatorDialog::CalculatorDialog(void){
    
    setWindowTitle("加法计算器");

    m_editX = new QLineEdit(this);
    m_editX->setAlignment(Qt::AlignRight);
    m_editX->setValidator(new QDoubleValidator(this));

    
    m_editY = new QLineEdit(this);
    m_editY->setAlignment(Qt::AlignRight);
    m_editY->setValidator(new QDoubleValidator(this));

    m_label = new QLabel("+",this);

    m_btnCalc = new QPushButton("=",this);
    m_btnCalc->setEnabled(false);

    m_editZ = new QLineEdit(this);
    m_editZ->setAlignment(Qt::AlignRight);
    m_editZ->setReadOnly(true);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_editX);
    layout->addWidget(m_label);
    layout->addWidget(m_editY);
    layout->addWidget(m_btnCalc);
    layout->addWidget(m_editZ);

    setLayout(layout);

    //信号和槽连接
    connect(m_editX,SIGNAL(textChanged(QString)),
            this,SLOT(enableCalcButton()));
    connect(m_editY,SIGNAL(textChanged(QString)),
            this,SLOT(enableCalcButton()));

    connect(m_btnCalc,SIGNAL(clicked()),
            this,SLOT(calcClicked()));
}

void CalculatorDialog::enableCalcButton(){
    //qDebug("test1");
    bool bXok;
    bool bYok;
    m_editX->text().toDouble(&bXok);
    m_editY->text().toDouble(&bYok);

    m_btnCalc->setEnabled(bXok && bYok);


}

void CalculatorDialog::calcClicked(){
    //qDebug() << "test2";
    double res = m_editX->text().toDouble() + m_editY->text().toDouble();
    QString str = QString::number(res,'g',15);
    m_editZ->setText(str);
}
