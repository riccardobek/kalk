public class pura extends secondoGrado{
    
    public pura(polinomio sx, polinomio dx) throws erroreGrado{
        super(sx,dx); 
        polinomio temp = unifica();
        temp.ordina();
        if(temp.getMonomio_pos(0).getEsponente().diverso(new razionale()))
            throw new erroreGrado();
        if(temp.getMonomio_pos(1).getEsponente().diverso(new razionale(2)))
            throw new erroreGrado();
    }

    public String getRisultato(){
        polinomio temp = unifica();
        temp.ordina();
        if(temp.getMonomio_pos(1).getCoefficiente().getNumeratore()==0)
            return "x = 0";
        razionale r = new razionale();
        razionale menoUno = new razionale(-1);
        try{
        razionale radice = new razionale(1,2);
            r =  razionale.moltiplicazioneRazionale(menoUno,razionale.divisioneRazionale(temp.getMonomio_pos(0).getCoefficiente(),temp.getMonomio_pos(1).getCoefficiente()));
            r = razionale.potenza(r,radice);
        }
        catch(Exception e){}
        return "x= +"+r.toString()+"  &&  x= -"+r.toString();
    }

    public String getTipo(){
        return "Equazione pura di secondo grado";
    }

    public razionale getDelta(){
        razionale a = new razionale();
        razionale c = new razionale();
        razionale d = new razionale(4);
        polinomio temp = unifica();
        temp.ordina();
        a=temp.getMonomio_pos(1).getCoefficiente();
        c=temp.getMonomio_pos(0).getCoefficiente();
        try{
            return razionale.sottrRazionale(new razionale(-1),razionale.moltiplicazioneRazionale(razionale.moltiplicazioneRazionale(d,a),c));
        }
        catch(Exception e){}
        return a;
    }

}