/********************************************************************************
** Form generated from reading UI file 'drawlevel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWLEVEL_H
#define UI_DRAWLEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawLevel
{
public:

    void setupUi(QWidget *DrawLevel)
    {
        if (DrawLevel->objectName().isEmpty())
            DrawLevel->setObjectName(QString::fromUtf8("DrawLevel"));
        DrawLevel->resize(562, 300);

        retranslateUi(DrawLevel);

        QMetaObject::connectSlotsByName(DrawLevel);
    } // setupUi

    void retranslateUi(QWidget *DrawLevel)
    {
        DrawLevel->setWindowTitle(QApplication::translate("DrawLevel", "DrawLevel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawLevel: public Ui_DrawLevel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWLEVEL_H
