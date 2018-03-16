#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    
    QLabel label("我是标签");
    QPushButton button("button");

    label.show();
    button.show();

    QObject::connect(&button,SIGNAL(clicked(void)),
            &app,SLOT(quit(void)));

    return app.exec();

}
