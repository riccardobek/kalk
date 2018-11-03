#include "kalk.h"

Kalk::Kalk(QWidget* parent):
    QMainWindow(parent), t(new QTabWidget(this)),
    kp(new KalkPolinomi), ke(new KalkEquazioni){

    t->addTab(kp,"Polinomi");
    t->addTab(ke,"Equazioni");
    t->setFixedSize(400,450);

    setFixedSize(400,450);
}
