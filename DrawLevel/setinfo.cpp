#include "setinfo.h"
#include "ui_setinfo.h"

#pragma execution_character_set("utf-8")


SetInfo::SetInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetInfo)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(430,90);

    name_lab = new QLabel(this);
    postion_lab = new QLabel(this);
    colorname_lab = new QLabel(this);
    precent_lab = new QLabel(this);

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(12);

    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor("#333333"));

    name_lab->setFont(font);
    name_lab->setPalette(pa);
    name_lab->setText("名称：");

    postion_lab->setFont(font);
    postion_lab->setPalette(pa);
    postion_lab->setText("位置：");

    precent_lab->setText("%");

    colorname_lab->setFont(font);
    colorname_lab->setPalette(pa);
    colorname_lab->setText("颜色：");


    Colorename_btn = new QPushButton(this);
    Colorename_btn->setMaximumSize(20,20);
    Colorename_btn->setMinimumSize(20,20);
    Colorename_btn->setStyleSheet("border:none;border-radius:4px;padding:2px 4px;");



    color_btn = new QPushButton(this);
    color_btn->setStyleSheet("width: 40px;height: 20px;background: #FFFFFF;border: 1px solid #333333;border-radius: 4px;\
                      color: black; border-style: outset;}"
"QPushButton:hover{border: 1px solid #619FA9;;background-color:#FFFFFF;color: #619FA9}" ); // 按键本色和鼠标停放时的色彩




    add_btn = new QPushButton(this);

    add_btn->setStyleSheet("width: 50px;height: 24px;background: #FFFFFF;border: 1px solid #333333;border-radius: 4px;\
                      color: black; border-style: outset;}"
"QPushButton:hover{border: 1px solid #619FA9;;background-color:#FFFFFF;color: #619FA9}" ); // 按键本色和鼠标停放时的色彩



    delete_btn = new QPushButton(this);
    delete_btn->setStyleSheet("width: 50px;height: 24px;background: #FFFFFF;border: 1px solid #333333;border-radius: 4px;\
                      color: black; border-style: outset;}"
"QPushButton:hover{border: 1px solid #619FA9;;background-color:#FFFFFF;color: #619FA9}");  // 按键本色和鼠标停放时的色彩



    color_btn->setText("选择");

    add_btn->setText("新增");
    delete_btn->setText("删除");

    Line_name = new QLineEdit(this);
    Line_name->setStyleSheet("min-width: 100px; min-height: 24px;max-width:100px; max-height: 24px;border-radius: 4px;background:#E4E4E4");
    Line_postion = new QLineEdit(this);
    Line_postion->setStyleSheet("min-width: 100px; min-height: 24px;max-width:100px; max-height: 24px;border-radius: 4px;background:#E4E4E4");

    QHBoxLayout *hlayout_1 = new QHBoxLayout;
    QHBoxLayout *hlayout_2 = new QHBoxLayout;
    QHBoxLayout *hlayout_3 = new QHBoxLayout;
    QHBoxLayout *hlayout_4 = new QHBoxLayout;
    QHBoxLayout *mainlayout = new QHBoxLayout(this);

    QVBoxLayout *vlayout_1 = new QVBoxLayout;
    QVBoxLayout *vlayout_2 = new QVBoxLayout;


    item = new QSpacerItem(precent_lab->width(),precent_lab->height());
    hlayout_1->addWidget(name_lab);
    hlayout_1->addWidget(Line_name);
    hlayout_1->addSpacerItem(item);
    hlayout_1->addSpacerItem(item);

    item_2 = new QSpacerItem(precent_lab->width(),precent_lab->height());
    hlayout_2->addWidget(postion_lab);
    hlayout_2->addWidget(Line_postion);
    hlayout_2->addWidget(precent_lab);
    hlayout_2->addSpacerItem(item_2);



    hlayout_3->addWidget(colorname_lab);
    hlayout_3->addWidget(Colorename_btn);
    hlayout_3->addWidget(colorname_lab);

    hlayout_3->addWidget(color_btn);

    hlayout_4->addWidget(add_btn);
    hlayout_4->addWidget(delete_btn);

    vlayout_1->addLayout(hlayout_1);
    vlayout_1->addLayout(hlayout_2);

    vlayout_2->addLayout(hlayout_3);
    vlayout_2->addLayout(hlayout_4);

    mainlayout->addLayout(vlayout_1);
    mainlayout->addLayout(vlayout_2);

}

SetInfo::~SetInfo()
{
    delete ui;
}

void SetInfo::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    drawWidget(painter);
}

void SetInfo::drawWidget(QPainter &painter)
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

void SetInfo::ChangeColor(QString name)
{
//    Colorename_btn->setFlat(true);
//    Colorename_btn->setAutoFillBackground(true);  //一定要这句，否则不行
//    QPalette palette = Colorename_btn->palette();
//    palette.setColor(QPalette::Button, QColor(name));
//    Colorename_btn->setPalette(palette);

        QString m_color_set_SheetStyle = "min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;border-radius: 4px;background:"; //; background:#FC5660

        Colorename_btn->setStyleSheet(m_color_set_SheetStyle.append(name));

}
