public class erroreGrado extends Exception{
	private static final long serialVersionUID = 1L;

    public erroreGrado(){
        super("L'equazione ha un grado diverso da quello che si desidera allocare.");
    }
}