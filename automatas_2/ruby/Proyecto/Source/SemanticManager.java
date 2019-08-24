import java.util.TreeMap;

public class SemanticManager{

	//Tabla de variables
	private static TreeMap<String, String> mapaVariables = new TreeMap<String, String>();
  private static final int INT = 41;
  private static final int STRING = 39;
  private static final int STRING2 = 40;
  private static final int FLOAT = 42;
  private static final int ID = 43;


    public static void addVariable( Token token, String value ) throws SemanticException { 

      if ( (boolean)mapaVariables.containsKey( token.image ) ){
        String t = mapaVariables.get(token.image);
        if (!compareTypes2( value, t )) {
          throw new SemanticException( SemanticError.DIFFERENT_DECLARATED, token.image, token.beginLine );
        }
      }
      else{
        mapaVariables.put( token.image, value );
      }
      
    }
    /*
	//Metodo para verificar duplicidad en variables
   	public static void addVariable( Token token, String value ) throws SemanticException { 

   		if ( (boolean)mapaVariables.containsKey( token.image ) )
   			throw new SemanticException( SemanticError.DECLARED, token.image, token.beginLine );
   		else
   			mapaVariables.put( token.image, value );
   		
   	}*/

   	//Metodo para verificar si existe una variable
   	public boolean checkVariable( Token token ) throws SemanticException { 
      
   		if ( (boolean)!mapaVariables.containsKey( token.image ) )
        throw new SemanticException( SemanticError.NOT_DECLARED, token.image, token.beginLine );
      else
        return true;
   	}
/*
    public static Token get(Token variable) throws SemanticException {
                                  //"b"
      return mapaVariables.get( variable );

    }*/

    /*
   	//************************
   	public static void tiposIguales(String tipo1,String tipo2)throws SemanticException
    {
        if(((tipo1 =="Integer" || tipo1=="Double") && (tipo2=="Integer" || tipo2=="Double") || tipo1 == "String" && tipo2=="String"))
        {}
        else {
            throw new SemanticException(SemanticError.DIFFERENT_TYPES,"Tipos Diferentes", tipo2.beginLine );
        }        
    }
    */
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
}