#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QPushButton button("按钮");
    QLabel label("标签");
    label.show();
    button.show();

    QObject::connect(&button,SIGNAL(clicked()),&label,SLOT(close()));

    return app.exec();
}
