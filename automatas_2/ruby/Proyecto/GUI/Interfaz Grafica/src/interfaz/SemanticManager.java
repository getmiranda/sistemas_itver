package interfaz;
import java.util.TreeMap;

public class SemanticManager{

  //Tabla de variables
  private static TreeMap<String, String> mapaVariables = new TreeMap<String, String>();
  private static final int INT = 102;
  private static final int STRING = 100;
  private static final int STRING2 = 101;
  private static final int FLOAT = 103;
  private static final int ID = 104;


    public static void addVariable( Token token, String type ) throws SemanticException { 

      if ( (boolean)mapaVariables.containsKey( token.image ) ){
        String t = mapaVariables.get(token.image);
        if (!compareTypes2( type, t )) {
          throw new SemanticException( SemanticError.DIFFERENT_DECLARATED, token.image, token.beginLine );
        }
        else
          mapaVariables.put( token.image, type );
      }
      else{
        mapaVariables.put( token.image, type );
      }
    }

    //Metodo para verificar si existe una variable
    public boolean checkVariable( Token token ) throws SemanticException { 
      
      if ( (boolean)!mapaVariables.containsKey( token.image ) )
        throw new SemanticException( SemanticError.NOT_DECLARED, token.image, token.beginLine );
      else
        return true;
    }

    public static String compareTypes( Token tipo1, Token tipo2 ) throws SemanticException {

      String type = "";

      if ( tipo1.kind == INT && tipo2.kind == INT )
        type = "int";

      else if ( tipo1.kind == STRING && tipo2.kind == STRING )
        type = "string";

      else if ( tipo1.kind == STRING && tipo2.kind == STRING2 )
        type = "string";

      else if ( tipo1.kind == STRING2 && tipo2.kind == STRING2 )
        type = "string";

      else if ( tipo1.kind == STRING2 && tipo2.kind == STRING )
        type = "string";

      else if ( tipo1.kind == FLOAT && tipo2.kind == FLOAT )
        type = "float";

      else if ( tipo1.kind == INT && tipo2.kind == FLOAT )
        type = "int";

      else if ( tipo1.kind == FLOAT && tipo2.kind == INT )
        type = "float";

      else
        throw new SemanticException( SemanticError.DIFFERENT_TYPES, "", tipo2.beginLine );

      return type;

    }

    private static boolean compareTypes2( String tipo1, String tipo2 ) {

      if ( tipo1 == "int" && tipo2 == "int" )
        return true;
      else if ( tipo1 == "string" && tipo2 == "string" )
        return true;
      else if ( tipo1 == "float" && tipo2 == "float" )
        return true;
      else if ( tipo1 == "int" && tipo2 == "float" )
        return true;
      else if ( tipo1 == "float" && tipo2 == "int" )
        return true;
      else
        return false;
    }

    public static void clearMap(){
      mapaVariables.clear();
    }
}