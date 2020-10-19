#include "drawlevel.h"
#include <QApplication>

#include "setinfo.h"

#include "colorchoose.h"

#pragma execution_character_set("utf-8")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawLevel w;


    w.show();

//    ColorChoose c;
//    c.show();

//    SetInfo s;
//    s.ChangeColor("#9A21D2");
//    s.show();

    return a.exec();
}
