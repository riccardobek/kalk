#include "kalkpolinomi.h"

KalkPolinomi::KalkPolinomi(QWidget* parent):
    QWidget(parent), t(new tastiera), schermo1(new QLineEdit),
    schermo2(new QLineEdit), layout(new QVBoxLayout(this)),
    controller(new modelPolinomio){

    *p = new QPushButton;

    p[0] = new QPushButton("Sostituisci x");
    p[1] = new QPushButton("Derivata");
    p[2] = new QPushButton("Grado");

    QGridLayout* layoutG = new QGridLayout();

    layout->addWidget(schermo1);
    layout->addWidget(schermo2);
    layoutG->addWidget(p[0],3,0);
    layoutG->addWidget(p[1],3,1);
    layoutG->addWidget(p[2],3,2);
    layout->addLayout(layoutG);
    layout->addWidget(t,0,Qt::AlignCenter);


    schermo1->setFixedHeight(30);
    schermo2->setFixedHeight(30);
    p[0]->setFixedHeight(41);
    p[1]->setFixedHeight(41);
    p[2]->setFixedHeight(41);

    schermo1->setDisabled(true);
    schermo2->setDisabled(true);
    schermo2->setAlignment(Qt::AlignRight);

    setLayout(layout);
    setFixedSize(400,450);

    for(int i=0;i<21;++i)
        connect(t->getPulsante(i),&QPushButton::clicked,this,&KalkPolinomi::inserisci);
    connect(p[0],&QPushButton::clicked,this,&KalkPolinomi::sostituisciX);
    connect(p[1],&QPushButton::clicked,this,&KalkPolinomi::derivata);
    connect(p[2],&QPushButton::clicked,this,&KalkPolinomi::grado);
}


void KalkPolinomi::inserisci(){

    QPushButton* pulsante = qobject_cast<QPushButton*>(sender());
    QString y = pulsante->text();

    if(y=="0" || y=="1" || y=="2" || y=="3" || y=="4" ||
       y=="5" || y=="6" || y=="7" || y=="8" || y=="9"){
        schermo2->setText(schermo2->text() + y);
        return;
    }


    if(y=="m/n"){
        schermo2->setText(schermo2->text() + '/');
        return;
    }

    if(y=="DEL"){
        schermo2->clear();
        controller->DEL();
        return;
    }

    if(y=="AC"){
        schermo1->clear();
        schermo2->clear();
        controller->AC();
        return;
    }

    if(y=="x"){
        schermo2->setText(schermo2->text()+'x');
        return;
    }
    try{
        if(y=="M"){

            if(controller->getMemory() && schermo1->text().length()==0){
                schermo1->setText(QString::fromStdString(controller->setPolyUMemory()));
                return;
            }

            if(controller->getMemory()&&controller->getOperazione()){
                controller->calcola();
                schermo1->setText(QString::fromStdString(controller->polyOpMemory()));
                return;
            }

            controller->memorizzaPoly();
            schermo1->clear();
            return;
        }


        if(y=="^"){
            if(*(--(schermo2->text().toStdString().end()))=='x'){
                schermo2->setText(schermo2->text()+'^');
            }
            else{
                controller->creaRazionale(schermo2->text().toStdString());
                schermo2->setText('('+schermo2->text()+")^");
                controller->setCirconflesso(true);
            }
            return;
        }

        if(y=="+"){
            if(controller->getCirconflesso()){
                schermo2->setText(QString::fromStdString(controller->calcolaPotenza(schermo2->text().toStdString())));
                controller->setCirconflesso(false);
            }
            controller->creaMonomio(schermo2->text().toStdString());
            controller->calcola();
            controller->setOperazione(simbolo('+'));
            schermo1->setText(QString::fromStdString(controller->getPolinomio()+" +"));
            schermo2->clear();
            return;
        }

        if(y=="-"){
            if(*(--(schermo2->text().toStdString().end()))=='/' || *(--(schermo2->text().toStdString().end()))=='^' || (schermo2->text().length()==0 && schermo1->text().length()!=0 && controller->getOperazione())){
                schermo2->setText(schermo2->text() + "-");
            }
            else{
                if(controller->getCirconflesso()){
                    schermo2->setText(QString::fromStdString(controller->calcolaPotenza(schermo2->text().toStdString())));
                    controller->setCirconflesso(false);
                }
                controller->creaMonomio(schermo2->text().toStdString());
                controller->calcola();
                controller->setOperazione(simbolo('-'));
                schermo1->setText(QString::fromStdString(controller->getPolinomio()+" -"));
                schermo2->clear();
            }

            return;
        }

        if(y=="*"){
            if(controller->getCirconflesso()){
                schermo2->setText(QString::fromStdString(controller->calcolaPotenza(schermo2->text().toStdString())));
                controller->setCirconflesso(false);
            }
            controller->creaMonomio(schermo2->text().toStdString());
            controller->calcola();
            controller->setOperazione(simbolo('*'));
            schermo1->setText(QString::fromStdString(controller->getPolinomio()+" *"));
            schermo2->clear();
            return;
        }

        if(y==":"){
            if(controller->getCirconflesso()){
                schermo2->setText(QString::fromStdString(controller->calcolaPotenza(schermo2->text().toStdString())));
                controller->setCirconflesso(false);
            }
            controller->creaMonomio(schermo2->text().toStdString());
            controller->calcola();
            controller->setOperazione(simbolo(':'));
            schermo1->setText(QString::fromStdString(controller->getPolinomio()+" :"));
            schermo2->clear();
            return;
        }

        if(y=="="){
            if(controller->getCirconflesso()){
                schermo2->setText(QString::fromStdString(controller->calcolaPotenza(schermo2->text().toStdString())));
                controller->setCirconflesso(false);
            }
            controller->creaMonomio(schermo2->text().toStdString());
            controller->calcola();
            schermo1->setText(QString::fromStdString(controller->getPolinomio()));
            schermo2->clear();
        }
    }
    catch(nonGestito n){
        QMessageBox::warning(this,"Non gestito","La M può essere usata solo quando il la schermata è vuota per inserire un valore o dopo con '+', '-', '*' e ':'. \n Chiudendo la finestra il programma ripartirà da zero.");
        controller->AC();
        schermo1->clear();
        schermo2->clear();
    }
    catch(errorePotenza p){
        QMessageBox::warning(this,"Errore di inserimento","Per calcolare la potenza di un razonale scrivere (r1)^r2, dove r1 e r2 sono razionali.");
        schermo2->clear();
    }
    catch(erroreSimbolo s){
        QMessageBox::warning(this,"Errore di inserimento","Il primo valore inserito deve essere o la '+' o la '-' .");
        schermo2->clear();
        if(schermo1->text().length()==0){
            controller->AC();
        }
    }
    catch(divisioneZero z){
        QMessageBox::warning(this,"Errore di inserimento","Un numero non può essere diviso per zero.");
        schermo2->clear();
    }
    catch(std::exception e){
        QMessageBox::warning(this,"Errore di inserimento","Scrivere un razionale nella forma m/n o nella forma r1x^r2, dove r1 ed r2 sono razionali.");
        schermo2->clear();
    }
}

void KalkPolinomi::sostituisciX(){
    try{
    controller->creaRazionale(schermo2->text().toStdString());
    schermo1->setText(QString::fromStdString(controller->sostituzioneX()));
    schermo2->clear();
    }
    catch(std::exception e){
        QMessageBox::warning(this,"Errore di inserimento","Scrivere un razionale nella forma m/n ed in seguito premere sostituisci x.");
        schermo2->clear();
    }
}

void KalkPolinomi::derivata(){
    schermo1->setText(QString::fromStdString(controller->derivata()));
}

void KalkPolinomi::grado(){
    QMessageBox::about(this,"Grado polinomio su display","Il grado del polinomio sul display è "+QString::fromStdString(controller->grado()));
}
