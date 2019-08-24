using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;

namespace InterfazGrafica
{
    public partial class Form1 : Form
    {
        String direccion = "";
        String[] directorios;
        String nombreArchivo;
        String defaultTemporaryFile;
        String contenidoCode;

        public Form1()
        {
            InitializeComponent();
        }

        //LOAD ANALIZADOR SINTACTICO
        private void Form1_Load(object sender, EventArgs e)
        {
            //Se guardara en la variable "defaultTemporaryFile" lo que tenga el archivo temporal
            defaultTemporaryFile = File.ReadAllText("temporary_file.mju");

            //Mostramos en el editor de codigo el contenido de la variable "defaultTemporaryFile"
            codeText.Text = defaultTemporaryFile;

            lineRefresh.Interval = 1;
            lineRefresh.Start();

            etiquetaNomArch.Text = "Temporary File";
        }

        //EXIT ANALIZADOR SINTACTICO
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            //Significa que no se ha guardado nada, ni abierto nada
            if (etiquetaNomArch.Text.Equals("Temporary File"))
            {
                //Si se ha modificado el editor de codigo pregunta si decea guardar antes de cerrar
                if (codeText.Text != defaultTemporaryFile)
                {
                    //Si elije guardar manda a llamar el metodo guardarComo()
                    if (MessageBox.Show("Archivo nuevo ha sido modificado, ¿Guardar cambios?", "Analizador Sintáctico", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                    {
                        guardarComo();
                    }
                    else
                        Application.Exit();
                }
                else
                    Application.Exit();
            }
            //Ha guardado o abierto algo
            else
            {
                //Si se ha modificado el editor de codigo pregunta si decea guardar antes de cerrar
                if (codeText.Text != contenidoCode)
                {
                    //Si elije guardar manda a llamar el metodo guardarExistente()
                    if (MessageBox.Show("Archivo nuevo ha sido modificado, ¿Guardar cambios?", "Analizador Sintáctico2", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                    {
                        guardarExistente();
                    }
                    else
                        Application.Exit();
                }
                else
                    Application.Exit();
            }

            //Solo vuelve a asignar el codigo por defecto, como cuando lo abrio por primera vez 
            try
            {
                File.WriteAllText("temporary_file.mju", defaultTemporaryFile);
            }
            catch (Exception)
            {

            }
        }

        //BOTON ANALIZAR
        private void analizar_Click_1(object sender, EventArgs e)
        {
            guardarCodeTemporal();
            outResult.Clear();

            String result;
            Process analizar = new Process();

            analizar.StartInfo.UseShellExecute = false;
            analizar.StartInfo.RedirectStandardOutput = true;
            analizar.StartInfo.FileName = "EJECUTABLE.exe";
            analizar.StartInfo.Arguments = "temporary_file.mju";
            analizar.Start();
            result = analizar.StandardOutput.ReadToEnd();

            //Acentos
            result = result.Replace("linea", "línea");
            result = result.Replace("invalido", "inválido");
            result = result.Replace("aritmetico", "aritmético");
            result = result.Replace("parametro", "parámetro");
            result = result.Replace("libreria", "librería");
            result = result.Replace("COMPILACION", "COMPILACIÓN");
            result = result.Replace("simbolo", "símbolo");

            analizar.WaitForExit();
            outResult.AppendText(result);
        }

        //ABRIR ARCHIVO VENTANA (MENU)
        private void abrirMenu_Click(object sender, EventArgs e)
        {
            abrirArchivo();
        }

        //ABRIR ARCHIVO VENTANA (BOTON)
        private void botonAbrir_Click(object sender, EventArgs e)
        {
            abrirArchivo();
        }

        //GUARDAR COMO (MENU)
        private void guardarComoMenu_Click(object sender, EventArgs e)
        {
            guardarComo();
        }

        //GUARDAR COMO (BOTON)
        private void botonGuardarComo_Click(object sender, EventArgs e)
        {
            guardarComo();
        }

        //GUARDAR (MENU)
        private void guardarMenu_Click(object sender, EventArgs e)
        {
            guardarExistente();
        }

        //GUARDAR (BOTON)
        private void botonGuardar_Click(object sender, EventArgs e)
        {
            guardarExistente();
        }

        private void guardarExistente()
        {
            /*Al arrancar el programa la variable direccion contiene nada
             * el programa obliga a "guardar como" por primera vez
             * despues se puede volver a usar y no se volvera a abrir la ventana de guardar como
            */
            if (direccion.Equals(""))
            {
                guardarComo();
            }
            else
            {
                using (var guardar_archivo = new StreamWriter(direccion))
                {
                    contenidoCode = codeText.Text;
                    guardar_archivo.Write(contenidoCode);
                }
            }
        }


        private void guardarCodeTemporal()
        {
            try
            {
                File.WriteAllText("temporary_file.mju", codeText.Text);
            }
            catch (Exception)
            {

            }
        }
        
        private void guardarComo()
        {
            try
            {
                guardarVentana.InitialDirectory = "C:\\Users\\Miranda\\Documents\\MJU";
                guardarVentana.Filter = "Archivo MJU(*.mju) | *.mju";
                guardarVentana.FileName = "New_Code.mju";

                if (guardarVentana.ShowDialog() == DialogResult.OK)
                {
                    //Guarda la direccion completa en la variable "direccion"
                    direccion = guardarVentana.FileName;

                    //Obtenemos el nombre del archivo
                    nombreArchivo = getNameFile(direccion);

                    using (var guardar_archivo = new System.IO.StreamWriter(direccion))
                    {
                        contenidoCode = codeText.Text;
                        guardar_archivo.Write(contenidoCode);

                        //Asignamos el nombre del archivo a la etiqueta destinada para mostrar su nombre
                        etiquetaNomArch.Text = nombreArchivo;
                    }
                }

            }
            catch (Exception)
            {
                MessageBox.Show("Error al guardar el archivo");
            }
        }

        private void abrirArchivo()
        {
            abrirVentana.Filter = "Archivo MJU(*.mju) | *.mju";
            abrirVentana.InitialDirectory = "C:\\Users\\Miranda\\Documents\\MJU";
            try
            {
                if (abrirVentana.ShowDialog() == DialogResult.OK)
                {
                    codeText.Clear();
                    outResult.Clear();

                    //Guarda la direccion completa en la variable "direccion"
                    direccion = abrirVentana.FileName;

                    //Guardamos en la variable "contenido" el contenido del archivo que se abrió
                    contenidoCode = File.ReadAllText(direccion);

                    //Mostramos en el editor de codigo el contenido de la variable
                    codeText.Text = contenidoCode;

                    //Obtenemos el nombre del archivo 
                    nombreArchivo = getNameFile(direccion);
                    
                    //Asignamos el nombre del archivo a la etiqueta destinada para mostrar su nombre
                    etiquetaNomArch.Text = nombreArchivo;
                }

            }
            catch (Exception)
            {
                MessageBox.Show("Error al abrir el archivo");
            }
        }


        private string getNameFile(string direccion)
        {
            //OBTENER SOLO EL NOMBRE DEL ARCHIVO Y NO LA RUTA COMPLETA

            //Guardará en el arreglo "directorios" cada directorio y nombre de archivo que se encuentre en cada "\\"
            directorios = direccion.Split('\\');

            /*Sabemos que en la ultima posicion se encuentra el nombre del archivo
              Ejemplo {directorio1, directorio2, ... , directorioN, nombre.mju}
              guardamos el nombre del archivo en la variable "nombre"*/

            return directorios[directorios.Length - 1];
        }

        private void Salir_Click_1(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }

        private void copiar_Click_1(object sender, EventArgs e)
        {
            codeText.Copy();
        }

        private void cortar_Click_1(object sender, EventArgs e)
        {
            codeText.Cut();
        }

        private void pegar_Click_1(object sender, EventArgs e)
        {
            codeText.Paste();
        }

        private void limpiar_Click_1(object sender, EventArgs e)
        {
            codeText.Clear();
            outResult.Clear();

        }

        private void color_Click_1(object sender, EventArgs e)
        {
            var color = colorDialog1.ShowDialog();
            if (color == DialogResult.OK)
            {
                codeText.ForeColor = colorDialog1.Color;
            }
            
        }

        private void formato_Click_1(object sender, EventArgs e)
        {
            var formato = fontDialog1.ShowDialog();
            if (formato == DialogResult.OK)
            {
                codeText.Font = fontDialog1.Font;
            }
        }



        private void lineCode_Paint(object sender, PaintEventArgs e)
        {

            int contador = codeText.GetPositionFromCharIndex(0).Y;
            if (codeText.Lines.Length > 0)
            {
                for (int i = 0; i < codeText.Lines.Length; i++)
                {
                    contador = codeText.GetPositionFromCharIndex(codeText.GetFirstCharIndexFromLine(i)).Y;
                    e.Graphics.DrawString((i + 1).ToString(), codeText.Font, Brushes.Black, lineCode.Width - (e.Graphics.MeasureString((i + 1).ToString(), codeText.Font).Width + 10), contador);
                }
            }
            else
            {
                e.Graphics.DrawString("1", codeText.Font, Brushes.Black, lineCode.Width - (e.Graphics.MeasureString("1", codeText.Font).Width + 10), contador);
            }
        }

        private void lineRefresh_Tick(object sender, EventArgs e)
        {
            lineCode.Refresh();
        }


        private void btnAcerca_Click(object sender, EventArgs e)
        {
            Acerca acerca = new Acerca();
            acerca.Show();
        }

        private void botonDeshacer_Click(object sender, EventArgs e)
        {
            codeText.Undo();
        }

        private void deshacerMenu_Click(object sender, EventArgs e)
        {
            codeText.Undo();
        }

        private void rehacerBoton_Click(object sender, EventArgs e)
        {
            codeText.Redo();
        }

        private void rehacerMenu_Click(object sender, EventArgs e)
        {
            codeText.Redo();
        }

        
    }
}
