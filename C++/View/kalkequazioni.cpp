#include "kalkequazioni.h"

KalkEquazioni::KalkEquazioni(QWidget* parent):
    QWidget(parent), t(new tastiera), schermo1(new QLineEdit),
    schermo2(new QLineEdit), layout(new QVBoxLayout(this)),
    controller(new modelEquazioni()){

    *p = new QPushButton;

    p[0] = new QPushButton("Sostituisci x");//manda un messaggio con indicato se >, <, =
    p[1] = new QPushButton("Derivata");
    p[2] = new QPushButton("Grado");
    p[3] = new QPushButton("Tipo");
    p[4] = new QPushButton("Delta");
    //fa apparire y a sinistra e il pulsante diventa "disegna", se cliccato apre un plot con la linea.

    QGridLayout* layoutG = new QGridLayout();

    layout->addWidget(schermo1);
    layout->addWidget(schermo2);
    layoutG->addWidget(p[0],3,0);
    layoutG->addWidget(p[1],3,1);
    layoutG->addWidget(p[2],3,2);
    layoutG->addWidget(p[3],4,0);
    layoutG->addWidget(p[4],4,2);

    layout->addLayout(layoutG);
    layout->addWidget(t,0,Qt::AlignCenter);


    schermo1->setFixedHeight(30);
    schermo2->setFixedHeight(30);
    p[0]->setFixedHeight(41);
    p[1]->setFixedHeight(41);
    p[2]->setFixedHeight(41);
    p[3]->setFixedHeight(41);
    p[4]->setFixedHeight(41);


    schermo1->setDisabled(true);
    schermo2->setDisabled(true);
    schermo2->setAlignment(Qt::AlignRight);

    setLayout(layout);
    setFixedSize(400,450);

    for(int i=0; i<5; ++i){
        p[i]->setEnabled(false);
    }


    for(int i=0;i<20;++i)
        connect(t->getPulsante(i),&QPushButton::clicked,this,&KalkEquazioni::inserisci);
    connect(t->getPulsante(20),&QPushButton::clicked,this,&KalkEquazioni::calcola);

    connect(p[0],&QPushButton::clicked,this,&KalkEquazioni::sostituisciX);
    connect(p[1],&QPushButton::clicked,this,&KalkEquazioni::derivata);
    connect(p[2],&QPushButton::clicked,this,&KalkEquazioni::grado);
    connect(p[3],&QPushButton::clicked,this,&KalkEquazioni::tipo);
    connect(p[4],&QPushButton::clicked,this,&KalkEquazioni::delta);

}



void KalkEquazioni::inserisci(){

    QPushButton* pulsante = qobject_cast<QPushButton*>(sender());
    std::string y = pulsante->text().toStdString();


    if(y=="0" || y=="1" || y=="2" || y=="3" || y=="4" ||
       y=="5" || y=="6" || y=="7" || y=="8" || y=="9"){
        schermo2->setText(schermo2->text() + QString::fromStdString(y));
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
        t->getPulsante(20)->setText("=");

        for(int i=0; i<5; ++i){
            p[i]->setEnabled(false);
        }

        t->getPulsante(20)->setEnabled(true);

        return;
    }

    if(y=="x"){
        schermo2->setText(schermo2->text()+'x');
        return;
    }

    try{

        if(y=="M"){

            if(controller->getMemoryPopulated() && schermo1->text().length()==0){
                controller->insertMemoryInPoly();
                schermo1->setText(QString::fromStdString(controller->getEquazione()));
                return;
            }

            if(controller->getMemoryPopulated() && controller->getOpInserita()){
                controller->setClickM();
                controller->calcolaPolinomi();
                schermo1->setText(QString::fromStdString(controller->getEquazione()));
                controller->resetMemory();
                return;
            }

            if(!controller->getMemoryPopulated() && controller->getUguale()){
                QMessageBox::warning(this,"Errore di utilizzo","Il pulsante M memorizza un valore inserito in un polinomio. Per memorizzare un valore in esso scrivere un polinomio prima dell'uguale e premere M.");
                schermo2->clear();
                return;
            }

            controller->memorizza();
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
                controller->inseritoCirconflesso();
            }
            return;
        }



        if(y=="+"){
            if(controller->getCirconflesso()){
                schermo2->setText(QString::fromStdString(controller->potenzaRazionale(schermo2->text().toStdString())));
            }
            controller->creaMonomio(schermo2->text().toStdString());
            controller->calcolaPolinomi();
            controller->inserisciOperazione(simbolo('+'));
            schermo1->setText(QString::fromStdString(controller->getEquazione()+" +"));
            schermo2->clear();
            controller->resetCirconflesso();
            return;
        }

        if(y=="-"){
            if(*(--(schermo2->text().toStdString().end()))=='/' || *(--(schermo2->text().toStdString().end()))=='^' || (schermo2->text().length()==0 && schermo1->text().length()!=0 && controller->getOpInserita())){
                schermo2->setText(schermo2->text() + "-");
            }
            else{
                if(controller->getCirconflesso()){
                    schermo2->setText(QString::fromStdString(controller->potenzaRazionale(schermo2->text().toStdString())));
                }
                controller->creaMonomio(schermo2->text().toStdString());
                controller->calcolaPolinomi();
                controller->inserisciOperazione(simbolo('-'));
                schermo1->setText(QString::fromStdString(controller->getEquazione()+" -"));
                controller->resetCirconflesso();
                schermo2->clear();
            }

            return;
        }

        if(y=="*"){
            if(controller->getCirconflesso()){
                schermo2->setText(QString::fromStdString(controller->potenzaRazionale(schermo2->text().toStdString())));
            }
            controller->creaMonomio(schermo2->text().toStdString());
            controller->calcolaPolinomi();
            controller->inserisciOperazione(simbolo('*'));
            schermo1->setText(QString::fromStdString(controller->getEquazione()+" *"));
            schermo2->clear();
            controller->resetCirconflesso();
            return;
        }

        if(y==":"){
            if(controller->getCirconflesso()){
                schermo2->setText(QString::fromStdString(controller->potenzaRazionale(schermo2->text().toStdString())));
            }
            controller->creaMonomio(schermo2->text().toStdString());
            controller->calcolaPolinomi();
            controller->inserisciOperazione(simbolo(':'));
            schermo1->setText(QString::fromStdString(controller->getEquazione()+" :"));
            controller->resetCirconflesso();
            schermo2->clear();
            return;
        }


    }
    catch(nonGestito n){
        QMessageBox::warning(this,"Non gestito","La M può essere usata solo dopo l'inserimento di un polinomio prima del uguale.");
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
    catch(divisioneZero e){
        QMessageBox::warning(this,"Errore di inserimento","Un numero non puo' essere diviso per zero.");
        schermo2->clear();
    }
    catch(std::exception e){
        QMessageBox::warning(this,"Errore di inserimento","Scrivere un razionale nella forma m/n o nella forma r1x^r2, dove r1 ed r2 sono razionali.");
        schermo2->clear();
    }
}

void KalkEquazioni::calcola(){
    QPushButton* pulsante = qobject_cast<QPushButton*>(sender());
    std::string y = pulsante->text().toStdString();
    if(y=="="){
        try{
            if(controller->getCirconflesso()){
                schermo2->setText(QString::fromStdString(controller->potenzaRazionale(schermo2->text().toStdString())));
            }
            controller->creaMonomio(schermo2->text().toStdString());
            controller->calcolaPolinomi();
            schermo1->setText(QString::fromStdString(controller->getEquazione()+" = "));
            controller->setUguale(true);
            schermo2->clear();
            controller->resetCirconflesso();
            t->getPulsante(20)->setText("Calcola");
        }
        catch(divisioneZero e){
            QMessageBox::warning(this,"Errore di inserimento","Un numero non puo' essere diviso per zero.");
            schermo2->clear();
        }
        catch(errorePotenza p){
            QMessageBox::warning(this,"Errore di inserimento","Per calcolare la potenza di un razonale scrivere (r1)^r2, dove r1 e r2 sono razionali.");
            schermo2->clear();
        }
        catch(std::exception e){
            QMessageBox::warning(this,"Errore di inserimento","Scrivere un razionale nella forma m/n o nella forma r1x^r2, dove r1 ed r2 sono razionali.");
            schermo2->clear();
        }
    }
    if(y=="Calcola"){
        try{
            controller->creaMonomio(schermo2->text().toStdString());
            controller->calcolaPolinomi();
            controller->calcola();
            schermo1->setText(QString::fromStdString(controller->getEquazione()));
            t->getPulsante(20)->setText("Valore delle x");
            schermo2->clear();

            for(int i=0; i<5; ++i){
                p[i]->setEnabled(true);
            }
        }
        catch(divisioneZero e){
            QMessageBox::warning(this,"Errore di inserimento","Un numero non puo' essere diviso per zero.");
            schermo2->clear();
        }
        catch(errorePotenza p){
            QMessageBox::warning(this,"Errore di inserimento","Per calcolare la potenza di un razonale scrivere (r1)^r2, dove r1 e r2 sono razionali.");
            schermo2->clear();
        }
        catch(std::exception e){
            QMessageBox::warning(this,"Errore di inserimento","Scrivere un razionale nella forma m/n o nella forma r1x^r2, dove r1 ed r2 sono razionali.");
            schermo2->clear();
        }
    }
    if(y=="Valore delle x"){
        schermo1->setText(QString::fromStdString(controller->valoreX()));
        t->getPulsante(20)->setText("=");
        t->getPulsante(20)->setEnabled(false);
        controller->AC();
        for(int i=0; i<5; ++i){
            p[i]->setEnabled(false);
        }

    }
}

void KalkEquazioni::grado(){
    try{
        QMessageBox::about(this,"Grado equazione su display","Il grado del polinomio sul display è "+QString::fromStdString(controller->eseguiGrado()));
    }
    catch(nonGestito e){
        QMessageBox::about(this,"Grado equazione su display","Le equazioni gestite sono quelle di primo e secondo grado.");
    }
}

void KalkEquazioni::tipo(){
    QMessageBox::about(this,"Tipo equazione su display",QString::fromStdString(controller->restituisciTipo()));
}

void KalkEquazioni::delta(){
    try{
        if(controller->eseguiGrado()==razionale(2).toString())
            QMessageBox::about(this,"Delta","Il delta è "+QString::fromStdString(controller->eseguiDelta()));
        else
            QMessageBox::about(this,"Delta","Equazione di grado diverso da 2");
    }
    catch(nonGestito e){
        QMessageBox::about(this,"Delta","Equazione di grado diverso da 2");
    }
}

void KalkEquazioni::derivata(){
    try{
    schermo1->setText(QString::fromStdString(controller->eseguiDerivata()));
    }
    catch(x_Assente){
         QMessageBox::about(this,"Errore derivata","Per le equazioni di primo grado non viene eseguita la derivata.");
    }
    catch(nonGestito){
        QMessageBox::about(this,"Non gestito","Le equazioni gestite sono quelle di primo e secondo grado.");
    }
}


void KalkEquazioni::sostituisciX(){
    try{
    controller->creaRazionale(schermo2->text().toStdString());
    schermo1->setText(QString::fromStdString(controller->eseguiSostituzioneX()));
    schermo2->clear();
    t->getPulsante(20)->setEnabled(false);
    }
    catch(nonGestito){
        QMessageBox::about(this,"Non gestito","Le equazioni gestite sono quelle di primo e secondo grado.");
    }
    catch(std::exception e){
        QMessageBox::warning(this,"Errore di inserimento","Scrivere un razionale nella forma m/n ed in seguito premere sostituisci x.");
        schermo2->clear();
    }
}
