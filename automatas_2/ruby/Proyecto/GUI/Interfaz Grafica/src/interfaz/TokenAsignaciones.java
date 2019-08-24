package interfaz;

import java.util.Hashtable;

public class TokenAsignaciones {
    //Tabla que almacenara los tokens declarados

    private static Hashtable tabla = new Hashtable();

                                        //variable          //tipoDato
    public static void insertarSimbolo(Token identificador, int tipo) {
        //En este metodo se agrega a la tabla de tokens el identificador que esta siendo declarado junto con su tipo de dato
        tabla.put(identificador.image, tipo);
    }

    //Metodo que verifica si un identificador ha sido declarado
    public static String checkVariable(Token checkTok) {
        try {
            //Intenta obtener el token a verificar(checkTok) de la tabla de los tokens
            int tipoIdent1 = (Integer) tabla.get(checkTok.image);
            return " ";
        } catch (Exception e) {
            //Si no lo puede obtener, manda el error
            return "Error: El identificador " + checkTok.image + " no ha sido declarado, linea: " + checkTok.beginLine;
        }
    }
}
