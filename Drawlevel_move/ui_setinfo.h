/********************************************************************************
** Form generated from reading UI file 'setinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETINFO_H
#define UI_SETINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetInfo
{
public:

    void setupUi(QWidget *SetInfo)
    {
        if (SetInfo->objectName().isEmpty())
            SetInfo->setObjectName(QString::fromUtf8("SetInfo"));
        SetInfo->resize(400, 300);

        retranslateUi(SetInfo);

        QMetaObject::connectSlotsByName(SetInfo);
    } // setupUi

    void retranslateUi(QWidget *SetInfo)
    {
        SetInfo->setWindowTitle(QApplication::translate("SetInfo", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetInfo: public Ui_SetInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETINFO_H
