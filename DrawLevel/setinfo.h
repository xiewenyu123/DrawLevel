#ifndef SETINFO_H
#define SETINFO_H

#include <QWidget>

#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QSpacerItem>

namespace Ui {
class SetInfo;
}

class SetInfo : public QWidget
{
    Q_OBJECT

public:
    explicit SetInfo(QWidget *parent = nullptr);
    ~SetInfo();

    QString color_name;

    void ChangeColor(QString name);

protected:
    void paintEvent(QPaintEvent *event);

private:
    void drawWidget(QPainter &painter);

private:
    Ui::SetInfo *ui;


public:
    QLabel *name_lab;     //"名称："
    QLabel *postion_lab;  //"位置："
    QLabel *colorname_lab;//"颜色："

    QPushButton *Colorename_btn; //颜色显示及颜色选择按钮

    QLabel *precent_lab; //"%"

    QLineEdit *Line_name;    //名称输入框
    QLineEdit *Line_postion; //位置（比例）输入框

    QPushButton *color_btn;  //颜色选择确认按钮
    QPushButton *add_btn;
    QPushButton *delete_btn;

    QSpacerItem *item;
    QSpacerItem *item_2;



};

#endif // SETINFO_H
