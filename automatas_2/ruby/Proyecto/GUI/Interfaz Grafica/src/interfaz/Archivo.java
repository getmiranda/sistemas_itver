package interfaz;

import java.io.*;
import java.util.*;
import javax.swing.JFileChooser;

public class Archivo {
    
    private File direccionLocal = new File(".");
    private JFileChooser jfc;
    private FileWriter fw = null;
    private File archivo = null;
    
    public Archivo(){
        try {
            String direccion = direccionLocal.getCanonicalPath();
            jfc = new JFileChooser(direccion);
        } catch (IOException e) {
            System.out.println("Error al crear el archivo");
        }
    }

    public static ArrayList<String> leerArchivo(String archivo) {
        ArrayList<String> lineas = new ArrayList();

        try {
            FileReader flujo = new FileReader(archivo);
            BufferedReader buffer = new BufferedReader(flujo);
            String linea = buffer.readLine();
            while (linea != null) {
                lineas.add(linea);
                linea = buffer.readLine();
            }
            buffer.close();
            flujo.close();
        } catch (IOException ex) {
            System.out.println("Error de archivo" + ex);
            System.exit(-1);
        }
        return lineas;
    }

    public static void grabar(String archivo,String texto){
        try {
            FileWriter flujo = new FileWriter (archivo);
            PrintWriter imprime = new PrintWriter(flujo);
            imprime.print(texto);
            imprime.close();
            flujo.close();
        } catch (Exception e) {
        }
    }
    
    public void guardar(Ventana v){
        try {
            archivo = new File("base.txt");
            fw = new FileWriter("base.txt");
            fw.write(v.getAreaTexto().getText() + "\n");
            fw.close();
            setArchivo(archivo);
        } catch (IOException ex) {
            System.out.println("Error al guardar");
        }
    }

    /**
     * @return the archivo
     */
    public File getArchivo() {
        return archivo;
    }

    /**
     * @param archivo the archivo to set
     */
    public void setArchivo(File archivo) {
        this.archivo = archivo;
    }
}