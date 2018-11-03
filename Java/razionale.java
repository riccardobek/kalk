import java.lang.Math;

public class razionale{
    
	private int num=0;
    private int den=1;

    //Costruttore vuoto
    public razionale(){
        num=0;
        den=1;
    }
    //Costruttore ad una variabile
    public razionale(int a){
        num=a;
    }
    //costruttore a due variabili
    public razionale(int a, int b) throws divisioneZero{
        if(b!=0){
            num=a;
            den=b;
        }
        else{
            throw new divisioneZero();
        }
        semplifica();
    }

    //Costruttore del razionale tramite parsing di una stringa
    public razionale(String s) throws divisioneZero{
        int a=s.indexOf('/', 0);
        if(a!=0){
            den=Integer.parseInt(s.substring(a+1, s.length()));
        }
        else{
            den=1;
        }
        if(den==0){ throw new divisioneZero(); }
        else{
            num=Integer.parseInt(s.substring(0,a));
        }
        semplifica();
    }
    
    //Semplifica il razionale
    private void semplifica(){
        int i=2;
        int min=0;
        if(den<0){
            num*=-1;
            den*=-1;
        }
        do{
            if(num<den) min=den;
            else min=num;

            if((num%i==0)&&(den%i==0)){
                num=num/i;
                den=den/i;
            }
            else ++i;
        }while(i<=min);
    }

    //Getter
    public int getNumeratore(){
        return num;
    }

    public int getDenominatore(){
        return den;
    }

    //Setter
    public void setNumeratore(int a){
        num=a;
    }

    public void setDenominatore(int b){
        den=b;
    }

    //Stampa l'oggetto sottoforma di stringa
    public String toString(){
        if(den==1){
            return Integer.toString(num);
        }
        return Integer.toString(num)+"/"+Integer.toString(den);
    }

    public static razionale potenza(razionale b, razionale e) throws erroreRadice, divisioneZero{
        if(b.num<=0 && e.den%2==0){
            throw new erroreRadice();
        }

        razionale exp = e;
        razionale risultato = b;

        if(e.num<0){
            exp.num = exp.num * -1;
            int tmp = risultato.num;
            risultato.num = risultato.den;
            risultato.den = tmp;
        }

        double tmpN = Math.pow((double)risultato.num,razToDouble(exp))*100.0;
        double tmpD = Math.pow((double)risultato.den,razToDouble(exp))*100.0;
       
        razionale tmp1;
        razionale tmp2;

        try{
            tmp1 = new razionale((int)tmpN,100);
            tmp2 = new razionale((int)tmpD,100);
        }
        catch(divisioneZero k){ 
            throw new divisioneZero();
        }
        risultato=razionale.divisioneRazionale(tmp1,tmp2);

        return risultato;
    }

    static public double razToDouble(razionale r){
        return (double)r.num / (double)r.den;
    }

    public boolean uguale(razionale r){
        return num==r.num && den==r.den;
    }
    
    public boolean diverso(razionale r){
        return num!=r.num || den!=r.den;
    }
    
    public boolean minore(razionale r){
        if(num*r.den < den*r.num){
            return true;
        }
        return false;
    }

    public boolean maggiore(razionale r){
        if(num*r.den > den*r.num){
            return true;
        }
        return false;
    }

    public static razionale sommaRazionale(razionale r1,razionale r2) throws divisioneZero{
        int a = r1.num*r2.den + r2.den*r2.num;
        int b = r1.den*r2.den;
        try{
            return new razionale(a, b); 
        }
        catch(divisioneZero e){
            throw new divisioneZero();
        }
    }

    public static razionale sottrRazionale(razionale r1, razionale r2) throws divisioneZero{
        int a = r1.num*r2.den - r1.den*r2.num;
        int b = r1.den*r2.den;
        try{
            return new razionale(a, b); 
        }
        catch(divisioneZero e){
            throw new divisioneZero();
        }
    }

    public static razionale moltiplicazioneRazionale(razionale r1, razionale r2) throws divisioneZero{
        int a = r1.num * r2.num;
        int b = r1.den * r2.den;
        try{
            return new razionale(a, b); 
        }
        catch(divisioneZero e){
            throw new divisioneZero();
        }
    }

    public static razionale divisioneRazionale(razionale r1, razionale r2) throws divisioneZero{
        int a = r1.num * r2.den;
        int b = r1.den * r2.num;
        try{
            return new razionale(a, b); 
        }
        catch(divisioneZero e){
            throw new divisioneZero();
        }
    }

}