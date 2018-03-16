#include <QApplication>
#include <QDialog>
#include <QSlider>
#include <QSpinBox>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    
    QDialog parent;
    parent.resize(200,100);

    QSlider slider(Qt::Horizontal,&parent);
    slider.move(20,20);
    slider.setRange(0,100);

    QSpinBox spin(&parent);
    spin.move(120,20);
    spin.setRange(0,100);

    parent.show();

    QObject::connect(&slider,SIGNAL(valueChanged(int)),
                &spin,SLOT(setValue(int)));


    QObject::connect(&spin,SIGNAL(valueChanged(int)),
                &slider,SLOT(setValue(int)));

    return app.exec();
}
