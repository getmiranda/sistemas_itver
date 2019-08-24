package interfaz;
public class IOManager {

	private static String lineas = "\t+-----------------------------------------------+-------------------------------------+";
	private static FileManager file;
	private static FileManager file2;
	private static FileManager file3;
	private static boolean band = true;

	public IOManager(FileManager file1, FileManager file2, FileManager file3){
		this.file = file1;
		this.file2 = file2;
		this.file3 = file3;
	}

	public static void showMessage(StringBuilder t, String msj) {
		
		if (band) {
		 	System.out.println(lineas);
		 	band = false;
		} 

		System.out.printf("\t| %-30s | %-25s |\n", t, msj);
		System.out.println(lineas);
		file.writeFile(t, msj);

	}

	public static void errorSyntax(ParseException pe){
		System.out.println( "\nMCVill:> Ha ocurrido un error sintactico.");
		System.out.println( "Detalles:\n\t" + pe.getMessage() + "\n");
		file2.writeErrorSyntax( "\nMCVill:> Ha ocurrido un error sintactico." );
		file2.writeErrorSyntax( "Detalles:\n\t" + pe.getMessage() );
	}

	public static void errorSemantic(SemanticException se){
		System.out.println( "\nMCVill:> Ha ocurrido un error semantico.");
		System.out.println( "Detalles:\n\t" + se.getMessage() + "\n");
		file3.writeErrorSyntax( "\nMCVill:> Ha ocurrido un error semantico." );
		String detalle = se.getMessage();
		file3.writeErrorSyntax( "Detalles:\n\t" + detalle );
	}

	
}