#include "colorchoose.h"
#include "ui_colorchoose.h"

ColorChoose::ColorChoose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorChoose)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(150,66);

    ColorCount = 0;

    ColorName.append("#E71123");
    ColorName.append("#FF7723");
    ColorName.append("#AB6103");
    ColorName.append("#F1C101");
    ColorName.append("#1DB737");
    ColorName.append("#00E4E3");
    ColorName.append("#7DCDF3");
    ColorName.append("#595198");
    ColorName.append("#9A21D2");
    ColorName.append("#E50AE6");

    btn_1 = new QPushButton(this);
    btn_1->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#E71123");

    btn_2 = new QPushButton(this);
    btn_2->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#FF7723");

    btn_3 = new QPushButton(this);
    btn_3->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#AB6103");

    btn_4 = new QPushButton(this);
    btn_4->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#F1C101");

    btn_5 = new QPushButton(this);
    btn_5->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#1DB737");

    btn_6 = new QPushButton(this);
    btn_6->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#00E4E3");

    btn_7 = new QPushButton(this);
    btn_7->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#7DCDF3");

    btn_8 = new QPushButton(this);
    btn_8->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#595198");

    btn_9 = new QPushButton(this);
    btn_9->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#9A21D2");

    btn_10 = new QPushButton(this);
    btn_10->setStyleSheet("min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;background:#E50AE6");

    hlayout_1 = new QHBoxLayout;
    hlayout_2 = new QHBoxLayout;

    vlayout = new QVBoxLayout(this);

    hlayout_1->addWidget(btn_1);
    hlayout_1->addWidget(btn_2);
    hlayout_1->addWidget(btn_3);
    hlayout_1->addWidget(btn_4);
    hlayout_1->addWidget(btn_5);

    hlayout_2->addWidget(btn_6);
    hlayout_2->addWidget(btn_7);
    hlayout_2->addWidget(btn_8);
    hlayout_2->addWidget(btn_9);
    hlayout_2->addWidget(btn_10);

    vlayout->addLayout(hlayout_1);
    vlayout->addLayout(hlayout_2);

    ui->setupUi(this);

    connect(btn_1,SIGNAL(clicked()),this,SLOT(btn_1_clicked()));
    connect(btn_2,SIGNAL(clicked()),this,SLOT(btn_2_clicked()));
    connect(btn_3,SIGNAL(clicked()),this,SLOT(btn_3_clicked()));
    connect(btn_4,SIGNAL(clicked()),this,SLOT(btn_4_clicked()));
    connect(btn_5,SIGNAL(clicked()),this,SLOT(btn_5_clicked()));
    connect(btn_6,SIGNAL(clicked()),this,SLOT(btn_6_clicked()));
    connect(btn_7,SIGNAL(clicked()),this,SLOT(btn_7_clicked()));
    connect(btn_8,SIGNAL(clicked()),this,SLOT(btn_8_clicked()));
    connect(btn_9,SIGNAL(clicked()),this,SLOT(btn_9_clicked()));
    connect(btn_10,SIGNAL(clicked()),this,SLOT(btn_10_clicked()));

}

ColorChoose::~ColorChoose()
{
    delete ui;
}

void ColorChoose::btn_1_clicked()
{
    ColorCount = 0;
    qDebug() << ColorCount;
}

void ColorChoose::btn_2_clicked()
{
    ColorCount = 1;

    qDebug() << ColorCount;

}

void ColorChoose::btn_3_clicked()
{
    ColorCount = 2;
    qDebug() << ColorCount;

}

void ColorChoose::btn_4_clicked()
{
    ColorCount = 3;
    qDebug() << ColorCount;

}

void ColorChoose::btn_5_clicked()
{
    ColorCount = 4;
    qDebug() << ColorCount;

}

void ColorChoose::btn_6_clicked()
{
    ColorCount = 5;
    qDebug() << ColorCount;

}

void ColorChoose::btn_7_clicked()
{
    ColorCount = 6;
    qDebug() << ColorCount;

}

void ColorChoose::btn_8_clicked()
{
    ColorCount = 7;
    qDebug() << ColorCount;

}

void ColorChoose::btn_9_clicked()
{
    ColorCount = 8;
    qDebug() << ColorCount;

}

void ColorChoose::btn_10_clicked()
{
    ColorCount = 9;
    qDebug() << ColorCount;
}


void ColorChoose::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    drawDialog(painter);
}

void ColorChoose::drawDialog(QPainter &painter)
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
