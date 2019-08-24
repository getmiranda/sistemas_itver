package interfaz;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ArchivosSalidasLSS {

    private File archivo = null;
    private FileReader fr = null;

    public void abrirLexico(Ventana v) {
        try {
            fr = new FileReader("RubyLexico.txt");
            int caracter;
            v.getAreaLexico().setText("");
            String texto = "";
            while ((caracter = fr.read()) != -1) {
                texto = texto + (char) caracter;
            }
            v.getAreaLexico().setText(texto);
            fr.close();
        } catch (FileNotFoundException ex) {
            System.out.println("Error al abrir el archivo lexico");
        } catch (IOException ex) {
            System.out.println("Error al leer el contenido del archivo lexico");
        }
    }
   

    public void abrirSintactico(Ventana v) {
        try {
            fr = new FileReader("RubySintactico.txt");
            int caracter;
            v.getAreaSintactico().setText("");
            String texto = "";
            while ((caracter = fr.read()) != -1) {
                texto = texto + (char) caracter;
            }
            v.getAreaSintactico().setText(texto);
            fr.close();
        } catch (FileNotFoundException ex) {
            System.out.println("Error al abrir el archivo sintactico");
        } catch (IOException ex) {
            System.out.println("Error al leer el contenido del archivo sintactico");
        }
    }

    public void abrirSemantico(Ventana v) {
        try {
            fr = new FileReader("RubySemantico.txt");
            int caracter;
            v.getAreaSemantico().setText("");
            String texto = "";
            while ((caracter = fr.read()) != -1) {
                texto = texto + (char) caracter;
            }
            v.getAreaSemantico().setText(texto);
            fr.close();
        } catch (FileNotFoundException ex) {
            System.out.println("Error al abrir el archivo semantico");
        } catch (IOException ex) {
            System.out.println("Error al leer el contenido del archivo semantico");
        }
    }
}
