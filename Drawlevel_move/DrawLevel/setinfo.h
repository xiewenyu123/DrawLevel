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
    QLabel *name_lab;
    QLabel *postion_lab;
    QLabel *colorname_lab;

    QPushButton *Colorename_btn;

    QLabel *colorset_lab;
    QLabel *precent_lab;

    QLineEdit *Line_name;
    QLineEdit *Line_postion;

    QPushButton *color_btn;
    QPushButton *add_btn;
    QPushButton *delete_btn;

    QSpacerItem *item;
    QSpacerItem *item_2;



};

#endif // SETINFO_H
