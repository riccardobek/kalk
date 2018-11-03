public class primoGrado extends equazione{

    public primoGrado(polinomio sx, polinomio dx) throws erroreGrado{
        super(sx,dx);
        polinomio p= unifica();
        p.ordina();
        razionale r= new razionale(1);
        if(p.getGrado().diverso(r)){
            throw new erroreGrado();
        }
    }

    public String getRisultato(){
        polinomio temp = unifica();
        razionale menoUno = new razionale(-1);
        temp.ordina();
        razionale r = new razionale();
        try{
            r = razionale.moltiplicazioneRazionale(menoUno,razionale.divisioneRazionale(temp.getMonomio_pos(1).getCoefficiente(),temp.getMonomio_pos(0).getCoefficiente()));
        }
        catch(Exception e){}
        return "x = "+r.toString();
    }

    public String getTipo(){
        return "Equazione di primo grado";
    }

    public String getGrado(){
        return Integer.toString(1);
    }

    public primoGrado getDerivata() throws erroreGrado{
        return this;
    }
}