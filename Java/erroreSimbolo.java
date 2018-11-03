public class erroreSimbolo extends Exception{
	private static final long serialVersionUID = 1L;

    public erroreSimbolo(){
        super("Simbolo inserito non corretto.\nSe stai inserendo per la prima volta nel polinomio\n"+
        "deve esserci o una + o una -.");
    }
}