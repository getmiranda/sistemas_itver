package interfaz;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Vector;
import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;
//import static interfaz.Perl.*;

public class Oyente implements ActionListener, KeyListener, MouseWheelListener {

    private MCVillCompiler analizador;
    private final Ventana ventana;
    private Archivo archivo = new Archivo();

    private static FileManager file = new FileManager();
    private static FileManager file2 = new FileManager();
    private static FileManager file3 = new FileManager();

    private static SemanticManager sm = new SemanticManager();
    private static ArrayList<Token> listValues = new ArrayList<Token>();
    private static boolean band = true;

    private boolean compilado = false;
    private int numLin = 0;
    private Vector<String> filas = new Vector<String>();
    ArchivosSalidasLSS salidas = new ArchivosSalidasLSS();

    public Oyente(Ventana ventana) {
        this.ventana = ventana;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JComponent origen = (JComponent) e.getSource();
        switch (origen.getName()) {
            case "abrir":
                abrirArchivo();
                break;
            case "guardar":
                guardarArchivo();
                break;
            case "salir":
                salir();
                break;
            case "limpiar":
                limpiar();
                break;
            case "compilar":
                compilar();
                break;
        }
    }

    public void abrirArchivo() {
        
        JFileChooser seleccion = new JFileChooser("C:\\Program Files (x86)\\MCVill\\Compiler\\Examples");
        FileNameExtensionFilter filtro = new FileNameExtensionFilter("Archivos de Ruby", "txt");
        seleccion.setDialogTitle("Abrir archivo...");
        
        seleccion.setFileFilter(filtro);
        int opcion = seleccion.showOpenDialog(ventana);
        if (opcion == JFileChooser.APPROVE_OPTION) {
            String archivo = "" + seleccion.getSelectedFile();
            ArrayList<String> lineas = Archivo.leerArchivo(archivo);
            String texto = "";
            for (int i = 0; i < lineas.size(); i++) {
                ventana.getAreaTexto().append(lineas.get(i) + "\n");
            }
            guardaFilas();
            poneNumLineas();
        }
    }

    public void guardarArchivo() {
        
        JFileChooser seleccion = new JFileChooser();
        int opcion = seleccion.showSaveDialog(ventana);
        
        if (opcion == JFileChooser.APPROVE_OPTION) {
            String archivo = "" + seleccion.getSelectedFile() + ".mcv";
            String texto = ventana.getAreaTexto().getText();
            Archivo.grabar(archivo, texto);
        }
    }

    public void salir() {
        System.exit(0);
    }

    public void limpiar() {
        ventana.getAreaTexto().setText("");
        ventana.getAreaLexico().setText("");
        ventana.getAreaSintactico().setText("");
        ventana.getAreaSemantico().setText("");
        ventana.getTxtNumLineas().setText("");
        
    }
    public void cleanOut() {
        
        ventana.getAreaLexico().setText("");
        ventana.getAreaSintactico().setText("");
        ventana.getAreaSemantico().setText("");
        
        
    }

    public void compilar() {
        cleanOut();
        try {
            if (compilado) {
                sm.clearMap();
                archivo.guardar(ventana);
                analizador.ReInit(new java.io.FileInputStream("" + archivo.getArchivo()));
                file.crearFile("RubyLexico.txt");
                file2.crearFile("RubySintactico.txt");
                file3.crearFile("RubySemantico.txt");
                IOManager iom = new IOManager(file, file2, file3);
                analizador.start();
                file.cerrarFile();
                file2.cerrarFile();
                file3.cerrarFile();
                salidas.abrirLexico(ventana);
                salidas.abrirSintactico(ventana);
                salidas.abrirSemantico(ventana);
            } else {
                archivo.guardar(ventana);
                analizador = new MCVillCompiler(new java.io.FileInputStream("" + archivo.getArchivo()));
                file.crearFile("RubyLexico.txt");
                file2.crearFile("RubySintactico.txt");
                file3.crearFile("RubySemantico.txt");
                IOManager iom = new IOManager(file, file2, file3);
                analizador.start();
                file.cerrarFile();
                file2.cerrarFile();
                file3.cerrarFile();
                salidas.abrirLexico(ventana);
                salidas.abrirSintactico(ventana);
                salidas.abrirSemantico(ventana);
                compilado = true;
            }
        } catch (Exception e) {
            System.out.println("Error al compilar (evento de boton)");
            salidas.abrirLexico(ventana);
            salidas.abrirSintactico(ventana);
            salidas.abrirSemantico(ventana);
        }
        catch(TokenMgrError e){
            String msj = "\nMCVill:> Ha ocurrido un error lexico." + "\nDetalles: " + e.getMessage();
            System.out.println( msj );
            ventana.getAreaSintactico().setText(msj);
            salidas.abrirLexico(ventana);
            salidas.abrirSemantico(ventana);
        }
        
    }
    
    public void presionaTecla(KeyEvent evt) {
        
        if (evt.getKeyCode() == KeyEvent.VK_ENTER) {
            numLin++;
            ventana.getTxtNumLineas().append(numLin + "\n");
        } else if (evt.getKeyCode() == KeyEvent.VK_BACK_SPACE || evt.getKeyCode() == KeyEvent.VK_DELETE) {
            
            guardaFilas();
            ventana.getTxtNumLineas().setText("");
            numLin = 1;
            
            filas.stream().map((_item) -> {
                ventana.getTxtNumLineas().append(numLin + "\n");
                return _item;
            }).forEachOrdered((_item) -> {
                numLin++;
            });
            numLin--;
            
            if (ventana.getAreaTexto().getText().equals("")) {
                ventana.getTxtNumLineas().append(1 + "\n");
                numLin = 1;
            }
        }
    }
    
    public void guardaFilas() {
        filas = new Vector<String>();
        StringTokenizer st = new StringTokenizer(ventana.getAreaTexto().getText(), "\n");
        while (st.hasMoreTokens()) {
            filas.add(st.nextToken());
        }
    }
    
    public void poneNumLineas() {
        filas.stream().map((_item) -> {
            numLin++;
            return _item;
        }).forEachOrdered((_item) -> {
            ventana.getTxtNumLineas().append(numLin + "\n");
        });
    }

    @Override
    public void keyTyped(KeyEvent e) {
    }

    @Override
    public void keyPressed(KeyEvent e) {
    }

    @Override
    public void keyReleased(KeyEvent e) {
        presionaTecla(e);
    }

    @Override
    public void mouseWheelMoved(MouseWheelEvent e) {
        ventana.getAreaTextoP().getVerticalScrollBar().setModel(ventana.getTxtNumLineasP().getVerticalScrollBar().getModel());
    }


}
