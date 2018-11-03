import java.util.ArrayList;

public class polinomio{

    private ArrayList<monomio> pol;

    public polinomio(){
        pol = new ArrayList<monomio>(10);
    }

    public void clear(){
        pol.clear();
    }
  
    public void addMonomio(char s,monomio m) throws erroreSimbolo, divisioneZero, esponenteDiverso{      
        if(!(s=='*' || s==':' || s=='+' || s=='-')){
            throw new erroreSimbolo();
        }

        if(s=='*'){
            if(pol.size()>0){
                pol.set(pol.size()-1,monomio.moltiplicazioneMonomio(pol.get(pol.size()-1),m));
            }
            else{
                throw new erroreSimbolo();    
            }
        }

        if(s==':'){
            if(pol.size()>0){
                pol.set(pol.size()-1,monomio.divisioneMonomio(pol.get(pol.size()-1),m));
            }
            else{
                throw new erroreSimbolo();    
            }
        }

        if(s=='+' || s=='-'){
            boolean trovato=false;
            for(int i=0;i<pol.size() && !trovato; ++i){
                try{
                    if(s=='+'){
                        pol.set(i,monomio.sommaMonomio(pol.get(i),m));
                        trovato=true;
                    }
                    else{
                        pol.set(i,monomio.sottrMonomio(pol.get(i),m));
                        trovato=true;
                    }
                }
                catch(esponenteDiverso e){}
                
            }

            if(!trovato){          
                razionale r=new razionale(0);
                if((m.getCoefficiente().minore(r) && s=='-') || s=='-'){
                    razionale menoUno= new razionale(-1);
                    monomio temp = new monomio(menoUno);
                    temp = monomio.moltiplicazioneMonomio(temp,m);
                    pol.add(temp);
                }
                else{
                    pol.add(m);
                }
            }
        }
    }


    public monomio getMonomio_pos(int i){
        return pol.get(i);
    }

    public razionale sostituisciVariabile(razionale r) throws erroreRadice, divisioneZero{
        razionale risultato = new razionale();
        for(int i=0; i<pol.size();++i){
            if(pol.get(i).getEsponente().getNumeratore()!=0)
                risultato = razionale.sommaRazionale(risultato,razionale.moltiplicazioneRazionale(pol.get(i).getCoefficiente(),razionale.potenza(r,pol.get(i).getEsponente())));
            else
                risultato = razionale.sommaRazionale(risultato,pol.get(i).getCoefficiente());
        }
        return risultato;
    }

    public polinomio getDerivata() throws erroreSimbolo, divisioneZero, esponenteDiverso{
        polinomio risultato = new polinomio();
        for(int i=0;i<pol.size();++i){
            monomio tmp = new monomio();
            if(pol.get(i).getEsponente().getNumeratore()!=0 && pol.get(i).getCoefficiente().getNumeratore()!=0){
                tmp.setCoefficiente(razionale.moltiplicazioneRazionale(pol.get(i).getCoefficiente(),pol.get(i).getEsponente()));
                tmp.setEsponente(razionale.sottrRazionale(pol.get(i).getEsponente(),new razionale(1)));
                risultato.addMonomio('+',tmp);
            }
        }
        return risultato;    
    }

    public razionale getGrado(){
        razionale max = new razionale();
        for(int i=0;i<pol.size();++i){
            if(max.minore(pol.get(i).getEsponente()) && pol.get(i).getEsponente().getNumeratore()!=0){
                max.setNumeratore(pol.get(i).getEsponente().getNumeratore());
                max.setDenominatore(pol.get(i).getEsponente().getDenominatore());
            }  
        }
        return max;
    }

    public String toString(){
        String risultato = "";
        for(int i=0;i<pol.size();++i){
            if(pol.get(i).getCoefficiente().getNumeratore()<0){
                try{
                    monomio tmp = new monomio(new razionale(-1));
                    risultato = risultato + " - " + (monomio.moltiplicazioneMonomio(pol.get(i),tmp)).toString();
                }
                catch(Exception errore){}
            }
            else if(pol.get(i).getCoefficiente().getNumeratore()>0)
                risultato = risultato + " + " + pol.get(i).toString();
        }
        
        if(risultato.length()==0) risultato="0";
        return risultato;
    }

    public int size(){
        return pol.size();
    }

    public void ordina(){
        monomio key = new monomio();
        for(int j=1;j<pol.size();++j){
            key = pol.get(j);
            int i=j-1;
            while(i>=0 && pol.get(i).getEsponente().maggiore(key.getEsponente())){
                pol.set(i+1,pol.get(i));
                --i;
            }
            pol.set(i+1,key);
        }
    }
    
    public static polinomio sommaPolinomio(polinomio p1, polinomio p2) throws erroreSimbolo, esponenteDiverso, divisioneZero{
        polinomio risultato = new polinomio();
        for(int i=0;i<p1.size();++i){
            risultato.addMonomio('+', p1.getMonomio_pos(i));
        }
        for(int i=0;i<p2.size();++i){
            risultato.addMonomio('+', p2.getMonomio_pos(i));
        }
        return risultato;
    }

    public static polinomio sottrPolinomio(polinomio p1, polinomio p2) throws erroreSimbolo, esponenteDiverso, divisioneZero{
        polinomio risultato = new polinomio();
        for(int i=0;i<p1.size();++i){
            risultato.addMonomio('+', p1.getMonomio_pos(i));
        }
        for(int i=0;i<p2.size();++i){
            risultato.addMonomio('-', p2.getMonomio_pos(i));
        }
        return risultato;
    }

    public static polinomio sommaMonoPoly(monomio m, polinomio p) throws erroreSimbolo, esponenteDiverso, divisioneZero{
        polinomio risultato = new polinomio();
        risultato.addMonomio('+', m);
        for(int i=0;i<p.size();++i){
            risultato.addMonomio('+', p.getMonomio_pos(i));
        }
        return risultato;
    }

    public static polinomio sottrMonoPoly(monomio m, polinomio p) throws erroreSimbolo, esponenteDiverso, divisioneZero{
        polinomio risultato = new polinomio();
        risultato.addMonomio('+', m);
        for(int i=0;i<p.size();++i){
            risultato.addMonomio('-', p.getMonomio_pos(i));
        }
        return risultato;
    }

    public static polinomio moltiplicazioneMonoPoly(monomio m, polinomio p) throws erroreSimbolo, esponenteDiverso, divisioneZero{
        polinomio risultato = new polinomio();
        for(int i=0; i<p.size();++i){
            risultato.addMonomio('+',(monomio.moltiplicazioneMonomio(p.getMonomio_pos(i),m)));
        }
        return risultato;
    }
    
    public static polinomio divisioneMonoPoly(monomio m, polinomio p) throws erroreSimbolo, esponenteDiverso, divisioneZero{
        polinomio risultato = new polinomio();
        for(int i=0; i<p.size();++i){
            risultato.addMonomio('+',(monomio.divisioneMonomio(p.getMonomio_pos(i),m)));
        }
        return risultato;
    }

    public static polinomio moltiplicazionePolyMono(polinomio p,monomio m) throws erroreSimbolo, esponenteDiverso, divisioneZero{
        return polinomio.moltiplicazioneMonoPoly(m, p);
    }

    public static polinomio divisionePolyMono(polinomio p,monomio m) throws erroreSimbolo, esponenteDiverso, divisioneZero{
        polinomio risultato = new polinomio();
        for(int i=0; i<p.size();++i){
            risultato.addMonomio('+',(monomio.divisioneMonomio(m,p.getMonomio_pos(i))));
        }
        return risultato;
    }

}
