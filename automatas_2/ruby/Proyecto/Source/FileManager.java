import java.io.FileOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

//Clase para la gestion del flujo de archivos
public class FileManager {

	private FileOutputStream fileOut;
	private DataOutputStream dataOut;
	private boolean cont = true;

	public void crearFile( String name ) {
		try{
			fileOut = new FileOutputStream( name );
			dataOut = new DataOutputStream(fileOut);
		}
		catch(IOException ioe){

		}
	}
	
	public void cerrarFile() {
		try{
			fileOut.close();
		}
		catch(IOException ioe){

		}
	}

	public void writeFile(StringBuilder t, String msj) {
		try{
			String lineas = "\t+-----------------------------------------------+-------------------------------------+\n";
			if (cont == true) {
				dataOut.writeBytes(lineas);
				dataOut.writeBytes("\t|                    LEXEMA                     |                TOKEN                |\n");
				dataOut.writeBytes(lineas);
				cont = false;
			}
			String cad = String.format("\t| %-45s | %-35s |", t, msj);
			dataOut.writeBytes(cad);
			dataOut.writeBytes(lineas);
			//fileOut.write('\n');
		}
		catch(IOException ioe){

		}
		
	}

	public void writeErrorSyntax(String cad) {
		try{
			dataOut.writeBytes(cad);
			fileOut.write('\n');
		}
		catch(IOException ioe){
		}
	}
}