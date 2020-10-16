/********************************************************************************
** Form generated from reading UI file 'colorchoose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORCHOOSE_H
#define UI_COLORCHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ColorChoose
{
public:

    void setupUi(QDialog *ColorChoose)
    {
        if (ColorChoose->objectName().isEmpty())
            ColorChoose->setObjectName(QString::fromUtf8("ColorChoose"));
        ColorChoose->resize(400, 300);

        retranslateUi(ColorChoose);

        QMetaObject::connectSlotsByName(ColorChoose);
    } // setupUi

    void retranslateUi(QDialog *ColorChoose)
    {
        ColorChoose->setWindowTitle(QApplication::translate("ColorChoose", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorChoose: public Ui_ColorChoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORCHOOSE_H
