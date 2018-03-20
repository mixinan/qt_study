#include "Time.h"

TimeDialog::TimeDialog(){
    setWindowTitle("时间");
    m_lab = new QLabel(this);
    m_lab->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    m_lab->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    m_btn = new QPushButton("获取时间",this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_lab);
    layout->addWidget(m_btn);

    setLayout(layout);

    connect(m_btn,SIGNAL(clicked()),
            this,SLOT(timeClicked()));
}


void TimeDialog::timeClicked(){
    QString str = QTime::currentTime().toString("hh:mm:ss");
    m_lab->setText(str);
}
