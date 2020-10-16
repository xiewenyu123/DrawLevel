#ifndef COLORCHOOSE_H
#define COLORCHOOSE_H

#include <QDialog>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include <QDebug>

namespace Ui {
class ColorChoose;
}

class ColorChoose : public QDialog
{
    Q_OBJECT

public:
    explicit ColorChoose(QWidget *parent = nullptr);
    ~ColorChoose();

public:
//    QString color_1;
//    QString color_2;
//    QString color_3;
//    QString color_4;
//    QString color_5;
//    QString color_6;
//    QString color_7;
//    QString color_8;
//    QString color_9;
//    QString color_10;

    QList<QString> ColorName;

    int ColorCount; //为第几个按钮



protected:
    void paintEvent(QPaintEvent *event);

private:
    void drawDialog(QPainter &painter);



private:
    Ui::ColorChoose *ui;

    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_10;

    QHBoxLayout *hlayout_1;
    QHBoxLayout *hlayout_2;

    QVBoxLayout *vlayout;


private slots:
    void btn_1_clicked();
    void btn_2_clicked();
    void btn_3_clicked();
    void btn_4_clicked();
    void btn_5_clicked();
    void btn_6_clicked();
    void btn_7_clicked();
    void btn_8_clicked();
    void btn_9_clicked();
    void btn_10_clicked();



};

#endif // COLORCHOOSE_H
