public class secondoGrado extends equazione{
    
    public secondoGrado(polinomio sx, polinomio dx) throws erroreGrado{
        super(sx,dx); 
        polinomio p= unifica();
        p.ordina();
        razionale r= new razionale(2);
        if(p.getGrado().diverso(r)){
            throw new erroreGrado();
        }
    }

    public String getRisultato(){
        polinomio temp = unifica();
        temp.ordina();
        razionale delta = new razionale();
        delta = getDelta();
        try{
            razionale risultato1 = new razionale();
            razionale risultato2 = new razionale();
            razionale menoUno = new razionale(-1);
            razionale radice = new razionale(1,2);
            
            if (!delta.minore(new razionale(0))){
                risultato1 = razionale.sottrRazionale(razionale.moltiplicazioneRazionale(menoUno, temp.getMonomio_pos(1).getCoefficiente()),razionale.potenza(delta,radice));
                risultato1 = razionale.divisioneRazionale(risultato1, (razionale.moltiplicazioneRazionale(new razionale(2),temp.getMonomio_pos(2).getCoefficiente())));
                risultato2 = razionale.sommaRazionale(razionale.moltiplicazioneRazionale(menoUno, temp.getMonomio_pos(1).getCoefficiente()),razionale.potenza(delta,radice));
                risultato2 = razionale.divisioneRazionale(risultato2, (razionale.moltiplicazioneRazionale(new razionale(2),temp.getMonomio_pos(2).getCoefficiente())));

                return "x= "+risultato1.toString() + "  &&  x= " + risultato2.toString();
            }
            else
                return "Delta negativo: "+delta.toString();
        }
        catch(Exception e){}
        return "";
    }

    public String getTipo(){
        return "Equazione di secondo grado";
    }

    public String getGrado(){
        return Integer.toString(2);
    }

    public primoGrado getDerivata() throws erroreGrado{
        polinomio temp = unifica();
        try{
            return new primoGrado(temp.getDerivata(), new polinomio());
        }
        catch(Exception e){ 
            return new primoGrado(new polinomio(), new polinomio());
        }
    }

    public razionale getDelta(){
        razionale a = new razionale();
        razionale b = new razionale();
        razionale c = new razionale();
        razionale d = new razionale(4);
        polinomio temp = unifica();
        temp.ordina();
        a=temp.getMonomio_pos(2).getCoefficiente();
        b=temp.getMonomio_pos(1).getCoefficiente();
        c=temp.getMonomio_pos(0).getCoefficiente();
        try{
            return razionale.sottrRazionale(razionale.moltiplicazioneRazionale(b,b),razionale.moltiplicazioneRazionale(razionale.moltiplicazioneRazionale(d,a),c));
        }
        catch(Exception e){}
        return a;
    }
}