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

    QList<addData> m_datalist;

    void SetContent(); //进行内容修改设置


    void setContentData(QList<addData>);





protected:
    void paintEvent(QPaintEvent *event);

private:

    void drawWidget(QPainter &painter);

    void drawScale(QPainter &painter); //刻度线绘制

    void drawPrecentShow(QPainter &painter);

    void drawArrow(QPainter &painter,qreal m_startX);

    void drawClickedArrow(QPainter &painter);

    void addSign(qreal m_startX,QColor m_Color); //进行小游标的添加

    QPointF getOrignPointF();

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
//    bool eventFilter(QObject *target, QEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);


private:
    SetInfo *setinfo;
    ColorChoose *colorchoose;
    Ui::DrawLevel *ui;

    int index;

    int NUM;

    bool m_pressed;

    bool mouse_move;

    int Count; //为添加几个数据


   DrawLevel::addData m_DATA;


private:
    qreal pre_value;

    qreal m_rectwidth;

    qreal m_Point; //记录按下滑块的位置


//    QList<qreal> m_precent;
    QList<QColor> m_color;
//    QList<QString> m_name;

    QList<QLabel> lab;

//    QList<DrawLevel::addData> DATA;

//    DrawLevel::addData one;



private slots:
    void addbtn_clicked();
    void delbtn_clicked();

    void ColorSetbtn_clicked();

    void colorbtn_clicked();




};

#endif // DRAWLEVEL_H
