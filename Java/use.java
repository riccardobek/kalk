public class use{
    public static void main(String[] args){

        //RAZIONALE
        System.out.println("RAZIONALI");
        //Errore razionale con denominatore a zero
        try{
            razionale a = new razionale(2,0);
        }
        catch(Exception errore){
            System.out.println(errore.getMessage());
        }
        //Errore potenza con denominatore pari di un numero negativo 
        try{
            razionale a = new razionale(-2,7);
            razionale b = new razionale(1,2);
            System.out.println(a.toString()+"^"+b.toString());
            a=razionale.potenza(a, b);
        }
        catch(Exception errore){
            System.out.println(errore.getMessage());
        }

        try{
            razionale a = new razionale();
            razionale b = new razionale(5);
            razionale c = new razionale(10,2);
            razionale d = new razionale(13,5);
            razionale e = new razionale("7/9");
            razionale exp1 = new razionale(-2);
            razionale exp2 = new razionale(-1,2);
            razionale f = new razionale(8);

            System.out.println(" A = "+a.toString()+"\n B = "+b.toString()+"\n C = "+c.toString()+"\n D = "+d.toString()+"\n E = "+e.toString());
            System.out.println("B + E = "+razionale.sommaRazionale(b,e).toString());
            System.out.println("B - E = "+razionale.sottrRazionale(b,e).toString());
            System.out.println("B * E = "+razionale.moltiplicazioneRazionale(b,e).toString());
            System.out.println("B : E = "+razionale.divisioneRazionale(b,e).toString());
            d=razionale.potenza(d, exp1);
            System.out.println("D = D^-2 = "+d);
            d=razionale.potenza(d, exp2);
            System.out.println("D = D^-1/2 = "+d);
            f=razionale.potenza(f, exp2);
            System.out.println("F = 8^1/2 = "+f);

            if(c.minore(d)){
                System.out.println("C è minore di D");
            }
            else{
                System.out.println("C è maggiore o uguale a D");
            }

            if(c.maggiore(d)){
                System.out.println("C è maggiore di D");
            }
            else{
                System.out.println("C è minore o uguale a D");
            }

            if(c.uguale(d)){
                System.out.println("C è uguale a D");
            }

            if(c.diverso(d)){
                System.out.println("C è diverso da D");
            }

            

        }
        catch(Exception errore){
            System.out.println(errore.getMessage());
        }

        //MONOMIO
        System.out.println("MONOMI");
        //Errore di creazione tramite parsing di stringa
        try{
            System.out.println("Cerco di creare un monomio scrivendo 8/7x5 \n che e' errato perchè la forma richiesta deve essere 8/7x^5");
            monomio m = new monomio("8/7x5"); 
        }
        catch(Exception e){
            if(e.equals(new divisioneZero())){
                System.out.println(e.getMessage());
            }
            else{
                //viene usato l'errore predefinito
                System.out.println("Valore inserito in modo errato");    
            }
        }

        //Somma di monomi con esponente diverso
        try{
            razionale r1 = new razionale(2,3);
            razionale r2 = new razionale(2);
            razionale r3 = new razionale(2,3);
            monomio a = new monomio(r1,r2);
            monomio b = new monomio(r3);
            System.out.println(" A = "+a.toString()+"\n B = "+b.toString());
            System.out.println("A + B = "+monomio.sommaMonomio(a,b).toString());        
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }

        try{
            monomio a = new monomio();
            monomio b = new monomio(new razionale(2, 3),new razionale(2));
            monomio c = new monomio(new razionale(5, 4),new razionale(2));
            monomio d = new monomio(new razionale(2, 3));
            monomio e = new monomio("7/8x^5/2");
            System.out.println(" A = "+a.toString()+"\n B = "+b.toString()+"\n C = "+c.toString()+"\n D = "+d.toString()+"\n E = "+e.toString());
            System.out.println("B + C = "+monomio.sommaMonomio(b,c).toString());
            System.out.println("B - C = "+monomio.sottrMonomio(b,c).toString());
            System.out.println("B * C = "+monomio.moltiplicazioneMonomio(b,c).toString());
            System.out.println("B : C = "+monomio.divisioneMonomio(b,c).toString());
            System.out.println("B * D = "+monomio.moltiplicazioneMonomio(b,d).toString());
            System.out.println("B : D = "+monomio.divisioneMonomio(b,d).toString());        
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }

        //POLINOMIO
        System.out.println("POLINOMIO");

        try{
            razionale r1 = new razionale(8,2);
            razionale r2 = new razionale(2);
            razionale r3 = new razionale(3,2);
            razionale r4 = new razionale(3);
            razionale r5 = new razionale();
            razionale r6 = new razionale(1,2);
            razionale r7 = new razionale(7,5);

            monomio a = new monomio(r1,r2);
            monomio b = new monomio(r3,r4);
            monomio c = new monomio(r6,r5);
            monomio d = new monomio(r7,r2);
            monomio e = new monomio(r7,r5);
            monomio f = new monomio("7/5x^1/1");
            monomio g = new monomio("5/4x^0/1");
            
            polinomio poly = new polinomio();
            poly.addMonomio('-',a);
            System.out.println(poly);
            poly.addMonomio('+',b);
            System.out.println(poly);
            poly.addMonomio('*',c);
            System.out.println(poly);
            poly.addMonomio('+',d);
            System.out.println(poly);
            poly.addMonomio('+',e);
            System.out.println(poly);

            razionale r=new razionale(1);
            r=poly.sostituisciVariabile(r);
            
            System.out.println("Sostituzione della x con 1 = "+r);
            System.out.println("Derivata del polinomio = "+poly.getDerivata());
            System.out.println("Grado del polinomio = "+poly.getGrado());

            poly.ordina();
            System.out.println("Polinomio ordinato = "+poly);
            polinomio poly2 = new polinomio();
            poly2.addMonomio('-', e); 
            poly2.addMonomio('-', d); 
            poly2.addMonomio('+', a); 
            poly2.addMonomio('-', c); 
            System.out.println("Polinomio A = "+poly);
            System.out.println("Polinomio B = "+poly2);
            System.out.println("A + B = "+polinomio.sommaPolinomio(poly, poly2));
            System.out.println("A - B = "+polinomio.sottrPolinomio(poly, poly2));
            System.out.println("7/5x^1 + A = "+polinomio.sommaMonoPoly(f, poly)); 
            System.out.println("5/4 - A = "+polinomio.sottrMonoPoly(g, poly));
            System.out.println("7/5x^1 * A = "+polinomio.moltiplicazioneMonoPoly(f, poly)); 
            System.out.println("5/4 / A = "+polinomio.divisioneMonoPoly(g, poly));
            System.out.println("B / 5/4 = "+polinomio.divisionePolyMono(poly2, g));
            System.out.println("B * 7/5x^1 = "+polinomio.moltiplicazionePolyMono(poly2, f)); 
        }
        catch(Exception errore){
            System.out.println(errore.getMessage());        
        }

        System.out.println("EQUAZIONI");
        try{
            monomio m6 = new monomio("8/3x^0/1");
            monomio m5 = new monomio("2/1x^0/1");
            polinomio sxPG = new polinomio();
            sxPG.addMonomio('+', m6);
            polinomio dxPG = new polinomio();
            sxPG.addMonomio('+', m5);

            equazione equ = new primoGrado(sxPG, dxPG);

        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }


        try{
            monomio m1 = new monomio("10/3x^2/1");
            monomio m2 = new monomio("2/3x^1/1");
            monomio m3 = new monomio("10/5x^1/1");
            monomio m4 = new monomio("4/5x^2/1");
            monomio m5 = new monomio("2/1x^0/1");
            monomio m6 = new monomio("8/3x^0/1");

            //PRIMO GRADO
            polinomio sxPG = new polinomio();
            sxPG.addMonomio('+', m2);
            sxPG.addMonomio('+', m6);            
            polinomio dxPG = new polinomio();
            dxPG.addMonomio('+', m3);
            dxPG.addMonomio('-', m6);
            
            //SECONDO GRADO
            polinomio sxSG = new polinomio();
            sxSG.addMonomio('-', m4);
            sxSG.addMonomio('+', m6);
            sxSG.addMonomio('+', m2);
            polinomio dxSG = new polinomio();
            dxSG.addMonomio('+', m4);
            dxSG.addMonomio('+', m5);

            //PURA
            polinomio sxP = new polinomio();
            sxP.addMonomio('-', m4);
            sxP.addMonomio('+', m5);
            polinomio dxP = new polinomio();
            dxP.addMonomio('+', m6);

            //SPURIA
            polinomio sxS = new polinomio();
            sxS.addMonomio('-', m4);
            sxS.addMonomio('+', m2);
            polinomio dxS = new polinomio();
            dxS.addMonomio('+', m1);

            equazione e1 = new primoGrado(sxPG,dxPG);
            equazione e2 = new secondoGrado(sxSG, dxSG);
            equazione e3 = new pura(sxP,dxP);
            equazione e4 = new spuria(sxS,dxS);
            
            System.out.println("Equazione di primo grado A = "+e1);
            System.out.println("Equazione di secondo grado B = "+e2);
            System.out.println("Equazione pura di secondo grado C = "+e3);
            System.out.println("Equazione spuria di secondo grado D = "+e4);

            System.out.println("Derivata A = "+e1.getDerivata());
            System.out.println("Derivata B = "+e2.getDerivata());
            System.out.println("Derivata C = "+e3.getDerivata());
            System.out.println("Derivata D = "+e4.getDerivata());

            System.out.println("Delta B = "+((secondoGrado)e2).getDelta());
            System.out.println("Delta C = "+((secondoGrado)e3).getDelta());
            System.out.println("Delta D = "+((secondoGrado)e4).getDelta());

            System.out.println("Grado A = "+e1.getGrado());
            System.out.println("Grado B = "+e2.getGrado());
            System.out.println("Grado C = "+e3.getGrado());
            System.out.println("Grado D = "+e4.getGrado());
            
            
            System.out.println("Tipo A = "+e1.getTipo());
            System.out.println("Tipo B = "+e2.getTipo());
            System.out.println("Tipo C = "+e3.getTipo());
            System.out.println("Tipo D = "+e4.getTipo());

        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
        
    }
}