/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGraphicsView *graphicsView;
    QGraphicsView *man2;
    QLCDNumber *lcd2;
    QGraphicsView *graphicsView_3;
    QGraphicsView *man1;
    QLabel *left;
    QLabel *right;
    QSlider *verticalSlider;
    QGraphicsView *floor;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(832, 673);
        Widget->setMaximumSize(QSize(832, 673));
        Widget->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Adobe Garamond Pro\";"));
        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(270, 60, 331, 441));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/n/images/real.png);"));
        man2 = new QGraphicsView(Widget);
        man2->setObjectName(QString::fromUtf8("man2"));
        man2->setGeometry(QRect(490, 330, 31, 71));
        man2->setStyleSheet(QString::fromUtf8("border-image: url(:/n/images/huochaiman.png);\n"
"border-image: url(:/n/images/huochaiman.png);"));
        lcd2 = new QLCDNumber(Widget);
        lcd2->setObjectName(QString::fromUtf8("lcd2"));
        lcd2->setGeometry(QRect(410, 70, 71, 51));
        lcd2->setSmallDecimalPoint(false);
        lcd2->setDigitCount(2);
        graphicsView_3 = new QGraphicsView(Widget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(40, 290, 31, 61));
        graphicsView_3->setStyleSheet(QString::fromUtf8("border-image: url(:/n/images/huochaiman.png);"));
        man1 = new QGraphicsView(Widget);
        man1->setObjectName(QString::fromUtf8("man1"));
        man1->setGeometry(QRect(360, 270, 71, 131));
        man1->setStyleSheet(QString::fromUtf8("border-image: url(:/n/images/huochaiman.png);"));
        left = new QLabel(Widget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(240, 70, 161, 421));
        left->setStyleSheet(QString::fromUtf8("border-image: url(:/n/images/subleft.jpg);"));
        right = new QLabel(Widget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(510, 70, 151, 421));
        right->setStyleSheet(QString::fromUtf8("border-image: url(:/n/images/subright.jpg);"));
        verticalSlider = new QSlider(Widget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(120, 0, 20, 641));
        verticalSlider->setOrientation(Qt::Vertical);
        floor = new QGraphicsView(Widget);
        floor->setObjectName(QString::fromUtf8("floor"));
        floor->setGeometry(QRect(610, -3160, 50, 4580));
        floor->setStyleSheet(QString::fromUtf8("border-image: url(:/n/images/\347\224\265\346\242\257.png);"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(730, 150, 75, 51));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 210, 75, 51));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        left->setText(QString());
        right->setText(QString());
        pushButton->setText(QApplication::translate("Widget", "Up", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "Down", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
