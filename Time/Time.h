#ifndef __TIME_H
#define __TIME_H

#include <QDialog>
#include <QTime>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class TimeDialog:public QDialog{
    Q_OBJECT
public:
    TimeDialog(void);
private slots:
    void timeClicked(void);
private:
    QLabel* m_lab;
    QPushButton* m_btn;
};


#endif
