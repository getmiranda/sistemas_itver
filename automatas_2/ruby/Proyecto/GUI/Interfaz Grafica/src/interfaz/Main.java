package interfaz;

public class Main {

    public static void main(String args[]) {
        Ventana ventana = new Ventana();
        Oyente oyente = new Oyente(ventana);
        ventana.addEventos(oyente);
        ventana.setSize(1450,800);
        ventana.setLocationRelativeTo(null);
        ventana.setTitle("MCVill Compiler - Ruby");
        ventana.setDefaultCloseOperation(3);
        ventana.setVisible(true);
    }
}
