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
    t = QTime::fromString("25:00", "mm:ss");

    QString time_text = t.toString("mm:ss");
    ui.label->setText(time_text);

    connect(timer, &QTimer::timeout, this, &QtGuiApplication2::myfunction);
    QObject::connect(ui.startButton, &QPushButton::clicked, this, &QtGuiApplication2::chrono_start);
    QObject::connect(ui.stopButton, &QPushButton::clicked, this, &QtGuiApplication2::chrono_stop);

    // This can be used if you want  to use slot.
    //   QObject::connect(ui.selectMinutes, SIGNAL(currentTextChanged(QString)), this,
    //   SLOT(chrono_stop_2()) );

    QObject::connect(ui.selectMinutes, &QComboBox::currentTextChanged, this,
      &QtGuiApplication2::change_minutes);
}

void QtGuiApplication2::myfunction()
{
    /** If pressed run button. */
    if (run_flag) {
        if (t.toString("mm:ss") != "00:00") {
            t2 = t.addSecs(-1);
            t  = t2;


            QString time_text = t.toString("mm:ss");
            ui.label->setText(time_text);
        }
    }
}

void
QtGuiApplication2::chrono_start()
{
    if (!run_flag) {
        /**  Timer start to work for  one second*/
        timer->start(1000);
        run_flag = true;

        ui.selectMinutes->setDisabled(true);
    }
}

void
QtGuiApplication2::chrono_stop()
{
    timer->stop();
    run_flag = false;
	ui.selectMinutes->setDisabled( false );

}

void QtGuiApplication2::change_minutes()
{
    if (ui.selectMinutes->currentText() == "25 Minutes") {
        t = QTime::fromString("25:00", "mm:ss");
        QString time_text = t.toString("mm:ss");
        ui.label->setText(time_text);
    } else if (ui.selectMinutes->currentText() == "40 Minutes") {
        t = QTime::fromString("40:00", "mm:ss");
        QString time_text = t.toString("mm:ss");
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
