#ifndef KALK_H
#define KALK_H

#include "kalkpolinomi.h"
#include "kalkequazioni.h"
#include <QTabWidget>
#include <QMainWindow>

class Kalk: public QMainWindow
{
    Q_OBJECT
public:
    explicit Kalk(QWidget* parent =0);
private:
    QTabWidget* t;
    KalkPolinomi* kp;
    KalkEquazioni* ke;
};

#endif // KALK_H
