#ifndef DRAWLEVEL_H
#define DRAWLEVEL_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

#include "setinfo.h"
#include "colorchoose.h"



namespace Ui {
class DrawLevel;
}

class DrawLevel : public QWidget
{
    Q_OBJECT

public:
    explicit DrawLevel(QWidget *parent = nullptr);
    ~DrawLevel();

    struct addData{
        double precent;
        QColor color;
        QString name;
    };

    QList<addData> m_datalist; //存放设置输入的信息

    void SetContent(); //进行内容修改设置

protected:
    void paintEvent(QPaintEvent *event);

private:

    void drawWidget(QPainter &painter); //界面样式的绘制

    void drawScale(QPainter &painter); //刻度线绘制

    void drawPrecentShow(QPainter &painter); //等级轴绘制

    void drawArrow(QPainter &painter,qreal m_startX);  //滑块绘制

    void drawClickedArrow(QPainter &painter);      //点击滑块样式绘制

    void addSign(qreal m_startX,QColor m_Color); //进行小游标的添加

    void setContentData(QList<addData> data);  //获取信息list中的信息


    QPointF getOrignPointF();  //获取原点

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);


private:
    SetInfo *setinfo;
    ColorChoose *colorchoose;
    Ui::DrawLevel *ui;

    int index; //点击选中标志：第几个滑块

    int NUM;   //设置鼠标样式标志位（移动到区域改变鼠标样式）

    bool m_pressed;  //鼠标点击标志

    bool mouse_move; //鼠标移动标志

   DrawLevel::addData m_DATA; //第一个等级信息


private:
    qreal m_Point; //记录按下滑块的位置

    QList<QColor> m_color;




private slots:
    void addbtn_clicked();
    void delbtn_clicked();

    void ColorSetbtn_clicked();

    void colorbtn_clicked();




};

#endif // DRAWLEVEL_H
