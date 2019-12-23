#pragma once
#include <QTime>

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication2.h"
#include "QTimer.h"
class QtGuiApplication2 : public QMainWindow
{
    Q_OBJECT

public:
    QtGuiApplication2(QWidget * parent = Q_NULLPTR);

    void
    main_setup();
    void
    myfunction();
    void
    chrono_start();
    void
    chrono_stop();
    void
    change_minutes();
    void
    reset();
    QTimer * timer;

    int a = 0;
    QTime t;
    QTime t2;
    bool run_flag;

	int checkbox_counter = 0;
private:
    /** Main interface*/
    Ui::QtGuiApplication2Class ui;

    /** This is using for slot type methots. */
private slots:
    void
    chrono_stop_2();
    // QTimer * timer;
};
