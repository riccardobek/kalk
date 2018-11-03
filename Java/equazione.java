public abstract class equazione{

    private polinomio sx,dx;

    public equazione(polinomio sx, polinomio dx){
        this.sx=sx;
        this.dx=dx;
    }

    public polinomio unifica(){
        try{
            return polinomio.sottrPolinomio(sx, dx);
        }
        catch(Exception e){
            return new polinomio();
        }
    }

    public String toString(){
        return unifica().toString()+" = 0";
    }

    public abstract String getRisultato();
    public abstract String getTipo();
    public abstract String getGrado();
    public abstract equazione getDerivata() throws erroreGrado;
    
}