#include "tastiera.h"

tastiera::tastiera(QWidget* parent):
    QWidget(parent), layout(new QGridLayout(this)){

    *p = new QPushButton;

    for(int i=0;i<3;++i){
        p[i] = new QPushButton(QString::number(i+1),this);
    }
    p[3] = new QPushButton("M",this);
    p[4] = new QPushButton("^",this);
    for(int i=5;i<8;++i){
        p[i] = new QPushButton(QString::number(i+1 - 2),this);
    }
    p[8] = new QPushButton("+",this);
    p[9] = new QPushButton("-",this);
    for(int i=10;i<13;++i){
        p[i] = new QPushButton(QString::number(i+1 - 4),this);
    }
    p[13] = new QPushButton("*",this);
    p[14] = new QPushButton(":",this);
    p[15] = new QPushButton("m/n",this);
    p[16] = new QPushButton("0",this);
    p[17] = new QPushButton("x",this);
    p[18] = new QPushButton("DEL",this);
    p[19] = new QPushButton("AC",this);

    for(int i=0;i<20;++i){
        p[i]->setFixedSize(41,41);
        layout->addWidget(p[i],i/5,i%5);
    }
    p[20] = new QPushButton("=");
    p[20]->setFixedSize(230,41);
    layout->addWidget(p[20]);

    setLayout(layout);
    setFixedSize(250,250);

}


QPushButton*& tastiera::getPulsante(int i){
    return p[i];
}
