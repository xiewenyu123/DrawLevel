#include "drawlevel.h"
#include "ui_drawlevel.h"

#pragma execution_character_set("utf-8")

#include <QDebug>

#include <QGraphicsDropShadowEffect>

#define SHADOW_WIDTH 2
#define BORDER_RADIUS 4  //窗口边角弧度
#define TRIANGLE_WIDTH 15               // 小三角的宽度;
#define TRIANGLE_HEIGHT 8              // 小三角的高度;

#define RECT_WIDTH 440
#define RECT_HEIGHT 30



DrawLevel::DrawLevel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawLevel)
{
    setinfo = new SetInfo(this);

    setinfo->color_name = "red";


    colorchoose = new ColorChoose(this);
    colorchoose->hide();

    setinfo->move(35,130);

    setWindowFlags(Qt::FramelessWindowHint);

    setAttribute(Qt::WA_TranslucentBackground);


    setFixedSize(500,250);

     pre_value = 0;

     index = 0; //标志：第几个滑块

     NUM = 0; //设置鼠标样式标志位

     m_Point = 0;

     m_pressed = false;

     mouse_move = false;

     m_DATA.name = "未知";
     m_DATA.color = "#1EB838";
     m_DATA.precent = 1;

     m_datalist.append(m_DATA);

    ui->setupUi(this);
    this->setMouseTracking(true); //开启鼠标追踪

    connect(setinfo->add_btn,SIGNAL(clicked()),this,SLOT(addbtn_clicked())); //增加等级
    connect(setinfo->delete_btn,SIGNAL(clicked()),this,SLOT(delbtn_clicked())); //删除等级
    connect(setinfo->color_btn,SIGNAL(clicked()),this,SLOT(colorbtn_clicked())); //颜色确定
    connect(setinfo->Colorename_btn,SIGNAL(clicked()),this,SLOT(ColorSetbtn_clicked())); //显示调色板
}

DrawLevel::~DrawLevel()
{
    delete ui;

}

void DrawLevel::SetContent()
{
    if(m_pressed == true && m_datalist.size() > 1)
    {
        if(index == 0)
        {
            if(setinfo->Line_postion->text().toDouble() / 100 < m_datalist[index + 1].precent)
            {
                m_datalist[index].precent = setinfo->Line_postion->text().toDouble() / 100;
                m_datalist[index].name = setinfo->Line_name->text();
            }
            else {
//                setinfo->Line_postion->setText("请再次输入！");
                setinfo->Line_postion->setText(QString::number(m_datalist[index].precent *100,'f',2));

            }
        }
        else if (index == m_datalist.size() - 1) {
            m_datalist[index].precent = 1;
            m_datalist[index].name = setinfo->Line_name->text();
        }
        else {
            if(setinfo->Line_postion->text().toDouble() / 100 > m_datalist[index - 1].precent && setinfo->Line_postion->text().toDouble() / 100 < m_datalist[index + 1].precent)
            {
                m_datalist[index].precent = setinfo->Line_postion->text().toDouble() / 100;
                m_datalist[index].name = setinfo->Line_name->text();

                setinfo->Line_postion->setText(QString::number(m_datalist[index].precent *100,'f',2));
            }
        }
    }
    else if (m_pressed == true && m_datalist.size() == 1) {
        m_datalist[index].precent = 1;
        m_datalist[index].name = setinfo->Line_name->text();

        setinfo->Line_postion->setText(QString::number(m_datalist[index].precent *100,'f',2));
    }
    this->update();

}

void DrawLevel::ColorSetbtn_clicked()
{
    colorchoose->move(300,170);
    colorchoose->show();
}

//颜色按钮

void DrawLevel::colorbtn_clicked()
{
    setinfo->color_name = colorchoose->ColorName[colorchoose->ColorCount];
    qDebug() << setinfo->color_name;

    setinfo->ChangeColor(setinfo->color_name);

    if(m_pressed == true)
    {
        m_datalist[index].color = QColor(setinfo->color_name);
    }
    update();

}


void DrawLevel::setContentData(QList<addData> data)
{
    m_color.clear();
    for(int i = 0;i < data.size();i++)
    {
        m_color.append(m_datalist[i].color);
    }
    this->update();
}


//删除按钮
void DrawLevel::delbtn_clicked()
{
    qreal num;

    if( m_datalist.size() > 1)
    {
        if(m_pressed == true && index != 0 && index != m_datalist.size() - 1)
        {
            qreal nextprecent;
            nextprecent = m_datalist[index + 1].precent;

            m_datalist.removeAt(index);
            m_datalist[index].precent = nextprecent;
            m_pressed = false;
        }
        else {
            num = m_datalist[m_datalist.size() - 1].precent - m_datalist[m_datalist.size() - 2].precent;

            if(index == m_datalist.size() - 1)
            {
                index -= 1;
                NUM -= 1;
                m_pressed = false;
            }

            m_datalist.pop_back();

            for(int i = 0;i < m_datalist.size();i++)
            {
                m_datalist[i].precent += num;
            }
        }
    }
    else {
        qDebug() << "无";
    }
    update();
}

//添加按钮
void DrawLevel::addbtn_clicked()
{

    DrawLevel::addData one;

    one.color = "#F1C101";
    one.name = "未知";
    one.precent = 1;

    if(m_datalist.size() < 10)
    {

        for(int i = 0;i < m_datalist.size();i++)
        {
            if(m_datalist[i].precent > (i + 1) * 0.05)
            {

                m_datalist[i].precent -= 0.05;

            }
        }

        m_datalist.append(one);
    }
    else {
        qDebug() << "越界";
    }
    update();
}


void DrawLevel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    drawWidget(painter);

    drawScale(painter);

    setContentData(m_datalist);

    SetContent();

    setinfo->ChangeColor(colorchoose->ColorName[colorchoose->ColorCount]);


    drawPrecentShow(painter);

    drawClickedArrow(painter);

}

//画圆界面角矩形
void DrawLevel::drawWidget(QPainter &painter)
{
    painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;

    painter.setPen(QPen(QColor("#E4E4E4"),1));
    painter.setBrush(QColor("white"));

    QPainterPath drawPath;   //画区域

    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    drawPath.addRoundedRect(rect, 4, 4);
    painter.drawPath(drawPath);
}

//刻度绘制
void DrawLevel::drawScale(QPainter &painter)
{
    QPointF originPoint = getOrignPointF();
    painter.translate(originPoint.x(),originPoint.y());

    painter.setPen(QPen(QColor("#E4E4E4"),1));
    painter.drawLine(0,0,440,0);

    QFont font;

    painter.setPen(QPen(QColor("#999999"),1,Qt::SolidLine));

    font.setPixelSize(12);
    painter.setFont(font);

    int textWidth = 0;


    for(int i = 0;i <= 4;i++)
    {
        painter.drawLine(i * 110,0,i* 110,-5);

        textWidth = QFontMetrics(font).width(QString::number(100 * i / 4));

        painter.drawText(i * 110 - textWidth / 2,-10,QString::number(100* i / 4));
    }
}


//进行等级绘制
void DrawLevel::drawPrecentShow(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);

    painter.setPen(QPen(QColor("#E4E4E4"),1));

    QPainterPath drawPath;   //画区域
    drawPath.addRoundedRect(QRect(0,2,440,30),BORDER_RADIUS, BORDER_RADIUS);
    painter.drawPath(drawPath);

    if(m_datalist.size() == 1)
    {

        painter.setBrush(m_datalist[0].color);
        m_datalist[0].precent = 1;
        painter.drawRoundedRect(QRectF(0,2,RECT_WIDTH * m_datalist[0].precent,RECT_HEIGHT),BORDER_RADIUS, BORDER_RADIUS);
        painter.drawText(QRectF(0,2,RECT_WIDTH * m_datalist[0].precent,RECT_HEIGHT), Qt::AlignCenter, m_datalist[0].name);  //第一个绘制区域为圆角矩形
    }
    else
    {
        for(int i = 0; i < m_datalist.size();i++)
        {
            if(i == 0)
            {
                painter.setBrush(m_datalist[0].color);
                painter.drawRoundedRect(QRectF(0,2,RECT_WIDTH * m_datalist[0].precent,RECT_HEIGHT),BORDER_RADIUS, BORDER_RADIUS);
                painter.drawText(QRectF(0,2,RECT_WIDTH * m_datalist[0].precent,RECT_HEIGHT), Qt::AlignCenter, m_datalist[0].name);  //第一个绘制区域为圆角矩形
            }
            else {
                painter.setBrush(m_datalist[i].color);
                painter.drawRoundedRect(QRectF(RECT_WIDTH * m_datalist[i - 1].precent,2,RECT_WIDTH * (m_datalist[i].precent - m_datalist[i-1].precent),RECT_HEIGHT),BORDER_RADIUS, BORDER_RADIUS);
                painter.drawText(QRectF(RECT_WIDTH * m_datalist[i - 1].precent,2,RECT_WIDTH * (m_datalist[i].precent - m_datalist[i-1].precent),RECT_HEIGHT), Qt::AlignCenter, m_datalist[i].name);
            }

            qDebug() <<" DATA[0].precent" << i;
        }
    }
}


//滑块绘制
void DrawLevel::drawArrow(QPainter &painter,qreal m_startX)
{
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPolygonF trianglePolygon; //正三角
    trianglePolygon << QPointF(m_startX, 36);
    trianglePolygon << QPointF(m_startX - TRIANGLE_WIDTH / 2, TRIANGLE_HEIGHT + 36);
    trianglePolygon << QPointF(m_startX + TRIANGLE_WIDTH / 2, TRIANGLE_HEIGHT + 36);

    QPainterPath drawPath;
    drawPath.addPolygon(trianglePolygon);
    painter.fillPath(drawPath,QColor("#333333"));

    QPainterPath drawRoundPath;

    drawRoundPath.addRoundedRect(QRectF(m_startX - TRIANGLE_WIDTH / 2, TRIANGLE_HEIGHT + 38,\
                                        TRIANGLE_WIDTH, 16),BORDER_RADIUS, BORDER_RADIUS);

    painter.drawPath(drawRoundPath);
}

void DrawLevel::drawClickedArrow(QPainter &painter)
{

//    setContentData(m_datalist);

    if(m_pressed == false)
    {

        for(int n =0;n < m_datalist.size();n++)
        {
            painter.setBrush(m_datalist[n].color);
            drawArrow(painter,m_datalist[n].precent * RECT_WIDTH);
        }
    }
    else
    {
        for (int i = 0;i < m_color.size();i++)
        {
            if(m_color.size() > index)
            {
                m_color.replace(index,QColor("#333333"));
            }
            else {
                m_pressed = false;
            }
            painter.setBrush(m_color[i]);
            drawArrow(painter,m_datalist[i].precent * RECT_WIDTH);
        }
        if(m_color.size() > index)
        {
            for(int j = 0;j < m_datalist.size();j++)
            {
                m_color.replace(j,m_datalist[j].color);
            }
        }
    }
}

//刻度线原点
QPointF DrawLevel::getOrignPointF()
{
    return QPointF(30,40);
}


void DrawLevel::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();
    qreal m_Xpoint;

    for(int i = 0; i < m_datalist.size();i++)
    {
        m_Xpoint = RECT_WIDTH * m_datalist[i].precent;

       QRectF rect = QRectF(QPointF(30 + m_Xpoint - TRIANGLE_WIDTH / 2,40 + 38),QSizeF(15,20)); //测试

       if(rect.contains(event->pos()))
       {
           NUM = i;
           qDebug() << "qq" << i;
           qDebug() << event->pos().x();
       }
    }

    QRectF m_rect = QRectF(30 + RECT_WIDTH * m_datalist[NUM].precent - TRIANGLE_WIDTH / 2, 40 + 38,15,20); //30是绘制刻度线距离左边距离，40是绘制刻度线距离顶部距离,15为滑块长,20为滑块高

    if(m_rect.contains(event->pos()))
    {
        this->setCursor(Qt::PointingHandCursor); //鼠标样式
    }
    else {
        this->setCursor(Qt::ArrowCursor);      //范围之外变回原来形状

    }

    if(m_datalist.size() != 0)
    {

        //滑块的范围

        if(m_pressed)
        {
            if(mouse_move == true)
            {
                qreal precent; //记录按下时百分比

                precent = m_datalist[index].precent;

                if(m_datalist.size() > 1)
                {
//                    if(event->pos().x() >= 30 && event->pos().x() <= 470)
//                    {
//                        m_datalist[index].precent = (static_cast<qreal>(event->pos().x()) - 30) / 440;
//                        setinfo->Line_postion->setText(QString::number((static_cast<double>(event->pos().x()) - 30) / 440 * 100,'f',2)); //保留两位小数
//                    }
                    if(index == 0 && event->pos().x() >= 30 && event->pos().x() <= m_datalist[1].precent * RECT_WIDTH + 30)
                    {
                        setinfo->Line_postion->setText(QString::number((static_cast<double>(event->pos().x()) - 30) / 440 * 100,'f',2)); //保留两位小数

                        m_datalist[index].precent = (static_cast<qreal>(event->pos().x()) - 30) / 440;
                    }
                    else if(index > 0 && index != m_datalist.size() - 1 && event->pos().x() >= m_datalist[index - 1].precent * RECT_WIDTH + 30 && event->pos().x() <= m_datalist[index + 1].precent * RECT_WIDTH + 30)
                    {
                        m_datalist[index].precent = (static_cast<qreal>(event->pos().x()) - 30) / 440;
                        setinfo->Line_postion->setText(QString::number((static_cast<double>(event->pos().x()) - 30) / 440 * 100,'f',2)); //保留两位小数
                    }

                }

            }
        }
//        else {
//            this->setCursor(Qt::ArrowCursor);      //范围之外变回原来形状
//        }
    }
}

void DrawLevel::mousePressEvent(QMouseEvent *event)
{
    m_pressed = false;
    colorchoose->hide();
    qDebug() << m_pressed;
    qreal m_Xpoint;

    for(int i = 0; i < m_datalist.size();i++)
    {
        m_Xpoint = RECT_WIDTH * m_datalist[i].precent;

        QRectF rect = QRectF(QPointF(30 + m_Xpoint - TRIANGLE_WIDTH / 2,40 + 38),QSizeF(15,20)); //测试

        if(rect.contains(event->pos()))
        {
            if(event->button() == Qt::LeftButton)
            {
                index = i;
                m_pressed = true;
                mouse_move = true;

                m_Point = m_datalist[i].precent * RECT_WIDTH + 30;

                this->update();

                setinfo->Line_name->setText(m_datalist[index].name);
                setinfo->Line_postion->setText(QString::number(m_datalist[index].precent * 100,'f',2));

                qDebug() << i;
                qDebug() << m_pressed;
            }
            else {
                setinfo->Line_name->setText("未知");

                setinfo->Line_postion->setText("");
//                index = 0;
            }
        }
    }
}

void DrawLevel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    mouse_move = false;
}




















