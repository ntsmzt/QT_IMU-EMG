/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *Xsens;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QPushButton *pushButton_connectMaster;
    QPushButton *pushButton_connectSensors;
    QPushButton *pushButton_startMeasurement;
    QLabel *label_9;
    QTextBrowser *textBrowser;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_8;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *PortBox;
    QLabel *label_2;
    QComboBox *BaudBox;
    QLabel *label_3;
    QComboBox *BitBox;
    QLabel *label_5;
    QComboBox *StopBitBox;
    QLabel *label_4;
    QComboBox *ParityBox;
    QPushButton *OpenSerialButton;
    QLabel *label_6;
    QTextEdit *textEdit;
    QPushButton *Clean;
    QLabel *label_7;
    QTextEdit *textEdit_2;
    QPushButton *SendButton;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QWidget *widget_4;
    QFormLayout *formLayout_2;
    QLabel *label_12;
    QComboBox *PortBox_2;
    QLabel *label_13;
    QComboBox *BaudBox_2;
    QLabel *label_14;
    QComboBox *BitBox_2;
    QLabel *label_15;
    QComboBox *StopBitBox_2;
    QLabel *label_16;
    QComboBox *ParityBox_2;
    QPushButton *OpenSerialButton_2;
    QLabel *label_17;
    QTextEdit *textEdit_3;
    QLabel *label_18;
    QTextEdit *textEdit_4;
    QPushButton *SendButton_2;
    QPushButton *Ping;
    QPushButton *test;
    QLCDNumber *lcdNumber;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1080, 575);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Xsens = new QWidget(centralwidget);
        Xsens->setObjectName(QString::fromUtf8("Xsens"));
        Xsens->setGeometry(QRect(560, 30, 221, 281));
        verticalLayout_4 = new QVBoxLayout(Xsens);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_10 = new QLabel(Xsens);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_10->setFont(font);

        verticalLayout_4->addWidget(label_10);

        pushButton_connectMaster = new QPushButton(Xsens);
        pushButton_connectMaster->setObjectName(QString::fromUtf8("pushButton_connectMaster"));
        pushButton_connectMaster->setMinimumSize(QSize(200, 30));
        pushButton_connectMaster->setMaximumSize(QSize(200, 30));

        verticalLayout_4->addWidget(pushButton_connectMaster);

        pushButton_connectSensors = new QPushButton(Xsens);
        pushButton_connectSensors->setObjectName(QString::fromUtf8("pushButton_connectSensors"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(30);
        sizePolicy1.setHeightForWidth(pushButton_connectSensors->sizePolicy().hasHeightForWidth());
        pushButton_connectSensors->setSizePolicy(sizePolicy1);
        pushButton_connectSensors->setMinimumSize(QSize(200, 30));
        pushButton_connectSensors->setMaximumSize(QSize(200, 30));
        pushButton_connectSensors->setIconSize(QSize(32, 20));

        verticalLayout_4->addWidget(pushButton_connectSensors);

        pushButton_startMeasurement = new QPushButton(Xsens);
        pushButton_startMeasurement->setObjectName(QString::fromUtf8("pushButton_startMeasurement"));
        pushButton_startMeasurement->setMinimumSize(QSize(200, 30));
        pushButton_startMeasurement->setMaximumSize(QSize(200, 30));

        verticalLayout_4->addWidget(pushButton_startMeasurement);

        label_9 = new QLabel(Xsens);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        textBrowser = new QTextBrowser(Xsens);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_4->addWidget(textBrowser);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(280, 30, 251, 531));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(225, 30));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        label_8->setFont(font1);
        label_8->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(label_8);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 30));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        PortBox = new QComboBox(widget);
        PortBox->setObjectName(QString::fromUtf8("PortBox"));
        PortBox->setMinimumSize(QSize(150, 30));

        formLayout->setWidget(0, QFormLayout::FieldRole, PortBox);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 30));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        BaudBox = new QComboBox(widget);
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->setObjectName(QString::fromUtf8("BaudBox"));
        BaudBox->setMinimumSize(QSize(150, 30));

        formLayout->setWidget(1, QFormLayout::FieldRole, BaudBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 30));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        BitBox = new QComboBox(widget);
        BitBox->addItem(QString());
        BitBox->addItem(QString());
        BitBox->setObjectName(QString::fromUtf8("BitBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(BitBox->sizePolicy().hasHeightForWidth());
        BitBox->setSizePolicy(sizePolicy2);
        BitBox->setMinimumSize(QSize(150, 30));

        formLayout->setWidget(2, QFormLayout::FieldRole, BitBox);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(50, 30));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        StopBitBox = new QComboBox(widget);
        StopBitBox->addItem(QString());
        StopBitBox->addItem(QString());
        StopBitBox->setObjectName(QString::fromUtf8("StopBitBox"));
        StopBitBox->setMinimumSize(QSize(150, 30));

        formLayout->setWidget(3, QFormLayout::FieldRole, StopBitBox);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(50, 30));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        ParityBox = new QComboBox(widget);
        ParityBox->addItem(QString());
        ParityBox->addItem(QString());
        ParityBox->setObjectName(QString::fromUtf8("ParityBox"));
        ParityBox->setMinimumSize(QSize(150, 30));

        formLayout->setWidget(4, QFormLayout::FieldRole, ParityBox);


        verticalLayout->addWidget(widget);

        OpenSerialButton = new QPushButton(widget_2);
        OpenSerialButton->setObjectName(QString::fromUtf8("OpenSerialButton"));
        OpenSerialButton->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(10);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(OpenSerialButton->sizePolicy().hasHeightForWidth());
        OpenSerialButton->setSizePolicy(sizePolicy3);
        OpenSerialButton->setMinimumSize(QSize(225, 30));

        verticalLayout->addWidget(OpenSerialButton);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        textEdit = new QTextEdit(widget_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        Clean = new QPushButton(widget_2);
        Clean->setObjectName(QString::fromUtf8("Clean"));

        verticalLayout->addWidget(Clean);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        textEdit_2 = new QTextEdit(widget_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout->addWidget(textEdit_2);

        SendButton = new QPushButton(widget_2);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        SendButton->setMinimumSize(QSize(225, 30));
        SendButton->setMaximumSize(QSize(225, 30));

        verticalLayout->addWidget(SendButton);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(20, 30, 242, 531));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(225, 30));
        label_11->setFont(font1);
        label_11->setTextFormat(Qt::AutoText);

        verticalLayout_2->addWidget(label_11);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        formLayout_2 = new QFormLayout(widget_4);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_12 = new QLabel(widget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(50, 30));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_12);

        PortBox_2 = new QComboBox(widget_4);
        PortBox_2->setObjectName(QString::fromUtf8("PortBox_2"));
        PortBox_2->setMinimumSize(QSize(150, 30));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, PortBox_2);

        label_13 = new QLabel(widget_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(50, 30));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_13);

        BaudBox_2 = new QComboBox(widget_4);
        BaudBox_2->addItem(QString());
        BaudBox_2->addItem(QString());
        BaudBox_2->addItem(QString());
        BaudBox_2->setObjectName(QString::fromUtf8("BaudBox_2"));
        BaudBox_2->setMinimumSize(QSize(150, 30));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, BaudBox_2);

        label_14 = new QLabel(widget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(50, 30));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_14);

        BitBox_2 = new QComboBox(widget_4);
        BitBox_2->addItem(QString());
        BitBox_2->addItem(QString());
        BitBox_2->setObjectName(QString::fromUtf8("BitBox_2"));
        sizePolicy2.setHeightForWidth(BitBox_2->sizePolicy().hasHeightForWidth());
        BitBox_2->setSizePolicy(sizePolicy2);
        BitBox_2->setMinimumSize(QSize(150, 30));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, BitBox_2);

        label_15 = new QLabel(widget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(50, 30));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_15);

        StopBitBox_2 = new QComboBox(widget_4);
        StopBitBox_2->addItem(QString());
        StopBitBox_2->addItem(QString());
        StopBitBox_2->setObjectName(QString::fromUtf8("StopBitBox_2"));
        StopBitBox_2->setMinimumSize(QSize(150, 30));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, StopBitBox_2);

        label_16 = new QLabel(widget_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(50, 30));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_16);

        ParityBox_2 = new QComboBox(widget_4);
        ParityBox_2->addItem(QString());
        ParityBox_2->addItem(QString());
        ParityBox_2->setObjectName(QString::fromUtf8("ParityBox_2"));
        ParityBox_2->setMinimumSize(QSize(150, 30));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, ParityBox_2);


        verticalLayout_2->addWidget(widget_4);

        OpenSerialButton_2 = new QPushButton(widget_3);
        OpenSerialButton_2->setObjectName(QString::fromUtf8("OpenSerialButton_2"));
        OpenSerialButton_2->setEnabled(true);
        sizePolicy3.setHeightForWidth(OpenSerialButton_2->sizePolicy().hasHeightForWidth());
        OpenSerialButton_2->setSizePolicy(sizePolicy3);
        OpenSerialButton_2->setMinimumSize(QSize(225, 30));

        verticalLayout_2->addWidget(OpenSerialButton_2);

        label_17 = new QLabel(widget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_2->addWidget(label_17);

        textEdit_3 = new QTextEdit(widget_3);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));

        verticalLayout_2->addWidget(textEdit_3);

        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_2->addWidget(label_18);

        textEdit_4 = new QTextEdit(widget_3);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));

        verticalLayout_2->addWidget(textEdit_4);

        SendButton_2 = new QPushButton(widget_3);
        SendButton_2->setObjectName(QString::fromUtf8("SendButton_2"));
        SendButton_2->setMinimumSize(QSize(225, 30));
        SendButton_2->setMaximumSize(QSize(225, 30));

        verticalLayout_2->addWidget(SendButton_2);

        Ping = new QPushButton(centralwidget);
        Ping->setObjectName(QString::fromUtf8("Ping"));
        Ping->setGeometry(QRect(570, 420, 75, 23));
        test = new QPushButton(centralwidget);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(840, 490, 75, 23));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(820, 410, 64, 23));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        BaudBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LiSir", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "IMU\346\216\247\345\210\266\347\253\257\345\217\243", nullptr));
        pushButton_connectMaster->setText(QCoreApplication::translate("MainWindow", "Connect Master", nullptr));
        pushButton_connectSensors->setText(QCoreApplication::translate("MainWindow", "Connect Sensors", nullptr));
        pushButton_startMeasurement->setText(QCoreApplication::translate("MainWindow", "Start Measurement", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "States:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "ARM\344\270\213\344\275\215\346\234\272\346\216\247\345\210\266\347\253\257\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        BaudBox->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        BaudBox->setItemText(1, QCoreApplication::translate("MainWindow", "115200", nullptr));
        BaudBox->setItemText(2, QCoreApplication::translate("MainWindow", "57600", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        BitBox->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        BitBox->setItemText(1, QCoreApplication::translate("MainWindow", "7", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        StopBitBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        StopBitBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        ParityBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        ParityBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));

        OpenSerialButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256:", nullptr));
        Clean->setText(QCoreApplication::translate("MainWindow", "Clean", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256\357\274\232", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">FF FF FD 00 FE 03 00 01 31 42</span></p></body></html>", nullptr));
        SendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\344\270\212\350\202\242\344\275\223\346\216\247\345\210\266\347\253\257\345\217\243", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        BaudBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        BaudBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "115200", nullptr));
        BaudBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "576000", nullptr));

        label_14->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        BitBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        BitBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "7", nullptr));

        label_15->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        StopBitBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        StopBitBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        ParityBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        ParityBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));

        OpenSerialButton_2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256\357\274\232", nullptr));
        SendButton_2->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        Ping->setText(QCoreApplication::translate("MainWindow", "Ping", nullptr));
        test->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
