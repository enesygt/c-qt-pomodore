#include "QtGuiApplication2.h"
#include <QTime>
#include <QDateTime>
#include <string>
#include <sstream>

QtGuiApplication2::QtGuiApplication2(QWidget * parent)
    : QMainWindow(parent)
{
    /**  Call main setup function. */
    main_setup();
}

void QtGuiApplication2::main_setup()
{
    ui.setupUi(this);

    timer = new
      QTimer(this);

    /** Timer show style changed.*/
    t = QTime::fromString("00:03", "mm:ss");

    QString time_text = t.toString("mm:ss");
    ui.label->setText(time_text);

    ui.durum->setText("Ready :)");

    connect(timer, &QTimer::timeout, this, &QtGuiApplication2::myfunction);
    QObject::connect(ui.startButton, &QPushButton::clicked, this, &QtGuiApplication2::chrono_start);
    QObject::connect(ui.stopButton, &QPushButton::clicked, this, &QtGuiApplication2::chrono_stop);
    QObject::connect(ui.reset_button, &QPushButton::clicked, this, &QtGuiApplication2::reset);


    // This can be used if you want  to use slot.
    //   QObject::connect(ui.selectMinutes, SIGNAL(currentTextChanged(QString)), this,
    //   SLOT(chrono_stop_2()) );

    QObject::connect(ui.selectMinutes, &QComboBox::currentTextChanged, this,
      &QtGuiApplication2::change_minutes);

    ui.selectMinutes->setDisabled(false);
    ui.startButton->setDisabled(false);
    ui.stopButton->setDisabled(true);
    ui.reset_button->setDisabled(true);
}

void QtGuiApplication2::myfunction()
{
    QString time_text1 = t.toString("mm:ss");

    /** If pressed run button. */
    if (run_flag) {
        if (ui.selectMinutes->currentText() == "130 Minutes") {
            if (t.toString("hh:mm:ss") != "00:00:00") {
                t2 = t.addSecs(-1);
                t  = t2;

                QString time_text = t.toString("hh:mm:ss");
                ui.label->setText(time_text);
            }
        } else {
            if (t.toString("mm:ss") != "00:00") {
                t2 = t.addSecs(-1);
                t  = t2;

                QString time_text = t.toString("mm:ss");
                ui.label->setText(time_text);
            } else {
                if (checkbox_counter < 4) {
                    checkbox_counter++;

                    ui.durum->setText("Time finished :)");
                }

                switch (checkbox_counter) {
                    case 1:
                        ui.checkBox->setChecked(1);
                        ui.checkBox_2->setChecked(false);

                        ui.checkBox_3->setChecked(false);
                        ui.checkBox_4->setChecked(false);
                        t = QTime::fromString("00:03", "mm:ss");
                        ui.label->setText(time_text1);
                        break;

                    case 2:
                        ui.checkBox->setChecked(true);
                        ui.checkBox_2->setChecked(true);
                        ui.checkBox_3->setChecked(false);
                        ui.checkBox_4->setChecked(false);
                        t = QTime::fromString("00:03", "mm:ss");
                        ui.label->setText(time_text1);
                        break;

                    case 3:
                        ui.checkBox->setChecked(true);
                        ui.checkBox_2->setChecked(true);
                        ui.checkBox_3->setChecked(true);
                        ui.checkBox_4->setChecked(false);
                        t = QTime::fromString("00:03", "mm:ss");
                        ui.label->setText(time_text1);
                        break;

                    case 4:
                        ui.checkBox->setChecked(true);
                        ui.checkBox_2->setChecked(true);
                        ui.checkBox_3->setChecked(true);
                        ui.checkBox_4->setChecked(true);
                        t = QTime::fromString("00:03", "mm:ss");
                        ui.label->setText(time_text1);
                        checkbox_counter = 0;
                        break;
                }
            }
        }
    }
} // QtGuiApplication2::myfunction

void
QtGuiApplication2::chrono_start()
{
    if (!run_flag) {
        /**  Timer start to work for  one second*/
        timer->start(1000);
        run_flag = true;

        ui.selectMinutes->setDisabled(true);

        ui.startButton->setDisabled(true);
        ui.stopButton->setDisabled(false);
        ui.reset_button->setDisabled(false);

        ui.durum->setText("Work Hard :)");
    }
}

void
QtGuiApplication2::chrono_stop()
{
    timer->stop();
    run_flag = false;
    ui.selectMinutes->setDisabled(false);
    ui.startButton->setDisabled(false);
    ui.stopButton->setDisabled(true);
    ui.reset_button->setDisabled(false);

    ui.durum->setText("Stopped");
}

void QtGuiApplication2::change_minutes()
{
    if (ui.selectMinutes->currentText() == "25 Minutes") {
        t = QTime::fromString("00:03", "mm:ss");
        QString time_text = t.toString("mm:ss");
        ui.label->setText(time_text);
    } else if (ui.selectMinutes->currentText() == "40 Minutes") {
        t = QTime::fromString("40:00", "mm:ss");
        QString time_text = t.toString("mm:ss");
        ui.label->setText(time_text);
    } else if (ui.selectMinutes->currentText() == "130 Minutes") {
        t = QTime::fromString("02:10:00", "hh:mm:ss");
        QString time_text = t.toString("hh:mm:ss");
        ui.label->setText(time_text);
    }
}

void QtGuiApplication2::reset()
{
    timer->stop();
    run_flag = false;
    ui.selectMinutes->setDisabled(false);
    ui.startButton->setDisabled(false);
    ui.stopButton->setDisabled(true);
    ui.reset_button->setDisabled(true);

    ui.durum->setText("Ready :)");
    if (ui.selectMinutes->currentText() == "25 Minutes") {
        t = QTime::fromString("00:03", "mm:ss");
        QString time_text = t.toString("mm:ss");
        ui.label->setText(time_text);
    } else if (ui.selectMinutes->currentText() == "40 Minutes") {
        t = QTime::fromString("40:00", "mm:ss");
        QString time_text = t.toString("mm:ss");
        ui.label->setText(time_text);
    } else if (ui.selectMinutes->currentText() == "130 Minutes") {
        t = QTime::fromString("02:10:00", "hh:mm:ss");
        QString time_text = t.toString("hh:mm:ss");
        ui.label->setText(time_text);
    }
}

/** This function is for example of slot connection with function. */
void
QtGuiApplication2::chrono_stop_2()
{
    timer->stop();
    run_flag = false;
}
