public class spuria extends secondoGrado{
    
    public spuria(polinomio sx, polinomio dx) throws erroreGrado{
        super(sx,dx); 
        polinomio temp = unifica();
        temp.ordina();
        if(temp.getMonomio_pos(0).getEsponente().diverso(new razionale(1)))
            throw new erroreGrado();
        if(temp.getMonomio_pos(1).getEsponente().diverso(new razionale(2)))
            throw new erroreGrado();
    }

    public String getRisultato(){
        polinomio temp = unifica();
        temp.ordina();
        razionale r = new razionale();
        razionale menoUno = new razionale(-1);
        try{
            r = razionale.moltiplicazioneRazionale(menoUno,razionale.divisioneRazionale(temp.getMonomio_pos(0).getCoefficiente(),temp.getMonomio_pos(1).getCoefficiente()));
        }
        catch(Exception e){}
        return "x= 0  &&  x= "+r.toString();
    }

    public String getTipo(){
        return "Equazione spuria di secondo grado";
    }

    public razionale getDelta(){
        razionale a = new razionale();
        razionale b = new razionale();
        razionale d = new razionale(4);
        polinomio temp = unifica();
        temp.ordina();
        a=temp.getMonomio_pos(1).getCoefficiente();
        b=temp.getMonomio_pos(0).getCoefficiente();
        try{
            return razionale.sottrRazionale(razionale.moltiplicazioneRazionale(b,b),razionale.moltiplicazioneRazionale(razionale.moltiplicazioneRazionale(d,a),new razionale(1)));
        }
        catch(Exception e){}
        return a;
    }
}