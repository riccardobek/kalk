public class monomio{
    private razionale coefficiente;
    private razionale esponente;

    public monomio(){
        coefficiente = new razionale();
        esponente = new razionale();
    }

    public monomio(razionale c){
        coefficiente = c;
        esponente= new razionale();
    }

    public monomio(razionale c, razionale e){
        coefficiente=c;
        esponente=e;
    }

    public monomio(monomio m){
        coefficiente=m.coefficiente;
        esponente=m.esponente;
    }

    public monomio(String s) throws divisioneZero{
        int a=s.indexOf('x', 0);
        if(a!=0){
            int b=s.indexOf('^', 0);
            try{
                esponente = new razionale(s.substring(b+1, s.length()));
            }
            catch(divisioneZero e){
                throw new divisioneZero();
            }
        }
        else{
            esponente = new razionale();
        }
        try{
            coefficiente=new razionale(s.substring(0,a));
        }
        catch(divisioneZero e){
            throw new divisioneZero();
        }
    }
	
	public razionale getEsponente() {
		return esponente;
	}
    
    public void setEsponente(razionale esponente) {
		this.esponente = esponente;
	}

	public razionale getCoefficiente() {
		return coefficiente;
	}

	public void setCoefficiente(razionale coefficiente) {
		this.coefficiente = coefficiente;
    }
    
    public String toString(){
        if(esponente.uguale(new razionale()))
            return coefficiente+"";
        return coefficiente+"x^"+esponente;
    }
    
    public boolean minore(monomio m){
        return esponente.minore(m.esponente);
    }

    public static monomio sommaMonomio(monomio m1, monomio m2) throws esponenteDiverso, divisioneZero{
        if(m1.esponente.diverso(m2.getEsponente())){
            throw new esponenteDiverso();
        }
        try{
            return new monomio(razionale.sommaRazionale(m1.coefficiente, m2.coefficiente),m1.esponente);
        }
        catch(divisioneZero e){
            throw new divisioneZero();
        }

    }

    public static monomio sottrMonomio(monomio m1, monomio m2) throws esponenteDiverso, divisioneZero{
        if(m1.esponente.diverso(m2.getEsponente())){
            throw new esponenteDiverso();
        }
        try{
            return new monomio(razionale.sottrRazionale(m1.coefficiente,m2.coefficiente),m1.esponente);
        }
        catch(divisioneZero e){
            throw new divisioneZero();
        }

    }

    public static monomio moltiplicazioneMonomio(monomio m1, monomio m2) throws esponenteDiverso,divisioneZero{
        try{
            return new monomio(razionale.moltiplicazioneRazionale(m1.coefficiente, m2.coefficiente),razionale.sommaRazionale(m1.esponente,m2.esponente));
        }
        catch(divisioneZero e){
            throw new divisioneZero();
        }
    }

    public static monomio divisioneMonomio(monomio m1, monomio m2) throws esponenteDiverso,divisioneZero{
        try{
            return new monomio(razionale.divisioneRazionale(m1.coefficiente, m2.coefficiente),razionale.sottrRazionale(m1.esponente,m2.esponente));
        }
        catch(divisioneZero e){
            throw new divisioneZero();
        }
    }

   
}