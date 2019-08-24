namespace InterfazGrafica
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.archivoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.abrirMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.guardarMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.guardarComoMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.Salir = new System.Windows.Forms.ToolStripMenuItem();
            this.edicionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.copiar = new System.Windows.Forms.ToolStripMenuItem();
            this.cortar = new System.Windows.Forms.ToolStripMenuItem();
            this.pegar = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.deshacerMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.rehacerMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.limpiar = new System.Windows.Forms.ToolStripMenuItem();
            this.color = new System.Windows.Forms.ToolStripMenuItem();
            this.formato = new System.Windows.Forms.ToolStripMenuItem();
            this.ayudaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnAcerca = new System.Windows.Forms.ToolStripMenuItem();
            this.abrirVentana = new System.Windows.Forms.OpenFileDialog();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.botonAnalizar = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.botonAbrir = new System.Windows.Forms.ToolStripButton();
            this.botonGuardar = new System.Windows.Forms.ToolStripButton();
            this.botonGuardarComo = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.botonDeshacer = new System.Windows.Forms.ToolStripButton();
            this.botonRehacer = new System.Windows.Forms.ToolStripButton();
            this.guardarVentana = new System.Windows.Forms.SaveFileDialog();
            this.fontDialog1 = new System.Windows.Forms.FontDialog();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.codeText = new System.Windows.Forms.RichTextBox();
            this.toolStrip2 = new System.Windows.Forms.ToolStrip();
            this.etiquetaNomArch = new System.Windows.Forms.ToolStripLabel();
            this.lineCode = new System.Windows.Forms.PictureBox();
            this.lineRefresh = new System.Windows.Forms.Timer(this.components);
            this.panel2 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.outResult = new System.Windows.Forms.RichTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.toolStrip2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lineCode)).BeginInit();
            this.panel2.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.archivoToolStripMenuItem,
            this.edicionToolStripMenuItem,
            this.color,
            this.formato,
            this.ayudaToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(8, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(1067, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // archivoToolStripMenuItem
            // 
            this.archivoToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.abrirMenu,
            this.guardarMenu,
            this.guardarComoMenu,
            this.toolStripSeparator1,
            this.Salir});
            this.archivoToolStripMenuItem.Name = "archivoToolStripMenuItem";
            this.archivoToolStripMenuItem.Size = new System.Drawing.Size(71, 24);
            this.archivoToolStripMenuItem.Text = "Archivo";
            // 
            // abrirMenu
            // 
            this.abrirMenu.Name = "abrirMenu";
            this.abrirMenu.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.A)));
            this.abrirMenu.Size = new System.Drawing.Size(284, 26);
            this.abrirMenu.Text = "Abrir";
            this.abrirMenu.Click += new System.EventHandler(this.abrirMenu_Click);
            // 
            // guardarMenu
            // 
            this.guardarMenu.Name = "guardarMenu";
            this.guardarMenu.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.guardarMenu.Size = new System.Drawing.Size(284, 26);
            this.guardarMenu.Text = "Guardar";
            this.guardarMenu.Click += new System.EventHandler(this.guardarMenu_Click);
            // 
            // guardarComoMenu
            // 
            this.guardarComoMenu.Name = "guardarComoMenu";
            this.guardarComoMenu.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.S)));
            this.guardarComoMenu.Size = new System.Drawing.Size(284, 26);
            this.guardarComoMenu.Text = "Guardar como";
            this.guardarComoMenu.Click += new System.EventHandler(this.guardarComoMenu_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(281, 6);
            // 
            // Salir
            // 
            this.Salir.Name = "Salir";
            this.Salir.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Alt) 
            | System.Windows.Forms.Keys.X)));
            this.Salir.Size = new System.Drawing.Size(284, 26);
            this.Salir.Text = "Salir";
            this.Salir.Click += new System.EventHandler(this.Salir_Click_1);
            // 
            // edicionToolStripMenuItem
            // 
            this.edicionToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.copiar,
            this.cortar,
            this.pegar,
            this.toolStripSeparator3,
            this.deshacerMenu,
            this.rehacerMenu,
            this.toolStripSeparator5,
            this.limpiar});
            this.edicionToolStripMenuItem.Name = "edicionToolStripMenuItem";
            this.edicionToolStripMenuItem.Size = new System.Drawing.Size(70, 24);
            this.edicionToolStripMenuItem.Text = "Edición";
            // 
            // copiar
            // 
            this.copiar.Name = "copiar";
            this.copiar.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C)));
            this.copiar.Size = new System.Drawing.Size(196, 26);
            this.copiar.Text = "Copiar";
            this.copiar.Click += new System.EventHandler(this.copiar_Click_1);
            // 
            // cortar
            // 
            this.cortar.Name = "cortar";
            this.cortar.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X)));
            this.cortar.Size = new System.Drawing.Size(196, 26);
            this.cortar.Text = "Cortar";
            this.cortar.Click += new System.EventHandler(this.cortar_Click_1);
            // 
            // pegar
            // 
            this.pegar.Name = "pegar";
            this.pegar.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
            this.pegar.Size = new System.Drawing.Size(196, 26);
            this.pegar.Text = "Pegar";
            this.pegar.Click += new System.EventHandler(this.pegar_Click_1);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(193, 6);
            // 
            // deshacerMenu
            // 
            this.deshacerMenu.Name = "deshacerMenu";
            this.deshacerMenu.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
            this.deshacerMenu.Size = new System.Drawing.Size(196, 26);
            this.deshacerMenu.Text = "Deshacer";
            this.deshacerMenu.Click += new System.EventHandler(this.deshacerMenu_Click);
            // 
            // rehacerMenu
            // 
            this.rehacerMenu.Name = "rehacerMenu";
            this.rehacerMenu.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Y)));
            this.rehacerMenu.Size = new System.Drawing.Size(196, 26);
            this.rehacerMenu.Text = "Rehacer";
            this.rehacerMenu.Click += new System.EventHandler(this.rehacerMenu_Click);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(193, 6);
            // 
            // limpiar
            // 
            this.limpiar.Name = "limpiar";
            this.limpiar.Size = new System.Drawing.Size(196, 26);
            this.limpiar.Text = "Limpiar";
            this.limpiar.Click += new System.EventHandler(this.limpiar_Click_1);
            // 
            // color
            // 
            this.color.Name = "color";
            this.color.Size = new System.Drawing.Size(57, 24);
            this.color.Text = "Color";
            this.color.Click += new System.EventHandler(this.color_Click_1);
            // 
            // formato
            // 
            this.formato.Name = "formato";
            this.formato.Size = new System.Drawing.Size(77, 24);
            this.formato.Text = "Formato";
            this.formato.Click += new System.EventHandler(this.formato_Click_1);
            // 
            // ayudaToolStripMenuItem
            // 
            this.ayudaToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnAcerca});
            this.ayudaToolStripMenuItem.Name = "ayudaToolStripMenuItem";
            this.ayudaToolStripMenuItem.Size = new System.Drawing.Size(63, 24);
            this.ayudaToolStripMenuItem.Text = "Ayuda";
            // 
            // btnAcerca
            // 
            this.btnAcerca.Name = "btnAcerca";
            this.btnAcerca.Size = new System.Drawing.Size(181, 26);
            this.btnAcerca.Text = "Acerca";
            this.btnAcerca.Click += new System.EventHandler(this.btnAcerca_Click);
            // 
            // abrirVentana
            // 
            this.abrirVentana.FileName = "openFileDialog1";
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.botonAnalizar,
            this.toolStripSeparator2,
            this.botonAbrir,
            this.botonGuardar,
            this.botonGuardarComo,
            this.toolStripSeparator4,
            this.botonDeshacer,
            this.botonRehacer});
            this.toolStrip1.Location = new System.Drawing.Point(0, 28);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(1067, 27);
            this.toolStrip1.TabIndex = 3;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // botonAnalizar
            // 
            this.botonAnalizar.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.botonAnalizar.Image = ((System.Drawing.Image)(resources.GetObject("botonAnalizar.Image")));
            this.botonAnalizar.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.botonAnalizar.Name = "botonAnalizar";
            this.botonAnalizar.Size = new System.Drawing.Size(24, 24);
            this.botonAnalizar.Text = "Analizar Código";
            this.botonAnalizar.Click += new System.EventHandler(this.analizar_Click_1);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 27);
            // 
            // botonAbrir
            // 
            this.botonAbrir.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.botonAbrir.Image = ((System.Drawing.Image)(resources.GetObject("botonAbrir.Image")));
            this.botonAbrir.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.botonAbrir.Name = "botonAbrir";
            this.botonAbrir.Size = new System.Drawing.Size(24, 24);
            this.botonAbrir.Text = "Abrir";
            this.botonAbrir.Click += new System.EventHandler(this.botonAbrir_Click);
            // 
            // botonGuardar
            // 
            this.botonGuardar.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.botonGuardar.Image = ((System.Drawing.Image)(resources.GetObject("botonGuardar.Image")));
            this.botonGuardar.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.botonGuardar.Name = "botonGuardar";
            this.botonGuardar.Size = new System.Drawing.Size(24, 24);
            this.botonGuardar.Text = "Guardar (Ctrl + S)";
            this.botonGuardar.Click += new System.EventHandler(this.botonGuardar_Click);
            // 
            // botonGuardarComo
            // 
            this.botonGuardarComo.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.botonGuardarComo.Image = ((System.Drawing.Image)(resources.GetObject("botonGuardarComo.Image")));
            this.botonGuardarComo.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.botonGuardarComo.Name = "botonGuardarComo";
            this.botonGuardarComo.Size = new System.Drawing.Size(24, 24);
            this.botonGuardarComo.Text = "Guardar Como (Ctrl + Mayus + S)";
            this.botonGuardarComo.Click += new System.EventHandler(this.botonGuardarComo_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(6, 27);
            // 
            // botonDeshacer
            // 
            this.botonDeshacer.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.botonDeshacer.Image = ((System.Drawing.Image)(resources.GetObject("botonDeshacer.Image")));
            this.botonDeshacer.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.botonDeshacer.Name = "botonDeshacer";
            this.botonDeshacer.Size = new System.Drawing.Size(24, 24);
            this.botonDeshacer.Text = "Deshacer (Ctrl + Z)";
            this.botonDeshacer.Click += new System.EventHandler(this.botonDeshacer_Click);
            // 
            // botonRehacer
            // 
            this.botonRehacer.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.botonRehacer.Image = ((System.Drawing.Image)(resources.GetObject("botonRehacer.Image")));
            this.botonRehacer.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.botonRehacer.Name = "botonRehacer";
            this.botonRehacer.Size = new System.Drawing.Size(24, 24);
            this.botonRehacer.Text = "Rehacer (Ctrl + Y)";
            this.botonRehacer.Click += new System.EventHandler(this.rehacerBoton_Click);
            // 
            // codeText
            // 
            this.codeText.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.codeText.Dock = System.Windows.Forms.DockStyle.Fill;
            this.codeText.Font = new System.Drawing.Font("Consolas", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.codeText.Location = new System.Drawing.Point(54, 0);
            this.codeText.Name = "codeText";
            this.codeText.Size = new System.Drawing.Size(985, 353);
            this.codeText.TabIndex = 5;
            this.codeText.Text = "";
            // 
            // toolStrip2
            // 
            this.toolStrip2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.toolStrip2.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.etiquetaNomArch});
            this.toolStrip2.Location = new System.Drawing.Point(0, 736);
            this.toolStrip2.Name = "toolStrip2";
            this.toolStrip2.Size = new System.Drawing.Size(1067, 25);
            this.toolStrip2.TabIndex = 7;
            this.toolStrip2.Text = "toolStrip2";
            // 
            // etiquetaNomArch
            // 
            this.etiquetaNomArch.Name = "etiquetaNomArch";
            this.etiquetaNomArch.Size = new System.Drawing.Size(127, 22);
            this.etiquetaNomArch.Text = "etiquetaNomArch";
            // 
            // lineCode
            // 
            this.lineCode.BackColor = System.Drawing.Color.CornflowerBlue;
            this.lineCode.Dock = System.Windows.Forms.DockStyle.Left;
            this.lineCode.Location = new System.Drawing.Point(0, 0);
            this.lineCode.Name = "lineCode";
            this.lineCode.Size = new System.Drawing.Size(54, 353);
            this.lineCode.TabIndex = 8;
            this.lineCode.TabStop = false;
            this.lineCode.Paint += new System.Windows.Forms.PaintEventHandler(this.lineCode_Paint);
            // 
            // lineRefresh
            // 
            this.lineRefresh.Tick += new System.EventHandler(this.lineRefresh_Tick);
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.SystemColors.InactiveCaption;
            this.panel2.Controls.Add(this.codeText);
            this.panel2.Controls.Add(this.lineCode);
            this.panel2.Location = new System.Drawing.Point(16, 92);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1039, 353);
            this.panel2.TabIndex = 11;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(8, 64);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(124, 25);
            this.label1.TabIndex = 12;
            this.label1.Text = "Code editor";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.outResult);
            this.panel1.Location = new System.Drawing.Point(16, 476);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1039, 250);
            this.panel1.TabIndex = 13;
            // 
            // outResult
            // 
            this.outResult.BackColor = System.Drawing.SystemColors.InfoText;
            this.outResult.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.outResult.Dock = System.Windows.Forms.DockStyle.Fill;
            this.outResult.Font = new System.Drawing.Font("Consolas", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.outResult.ForeColor = System.Drawing.Color.Lime;
            this.outResult.Location = new System.Drawing.Point(0, 0);
            this.outResult.Name = "outResult";
            this.outResult.ReadOnly = true;
            this.outResult.Size = new System.Drawing.Size(1039, 250);
            this.outResult.TabIndex = 0;
            this.outResult.Text = "";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(11, 448);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 25);
            this.label2.TabIndex = 14;
            this.label2.Text = "Out";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // Form1
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.Color.Gainsboro;
            this.ClientSize = new System.Drawing.Size(1067, 761);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.toolStrip2);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Opacity = 0.9D;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Analizador Sintáctico";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.toolStrip2.ResumeLayout(false);
            this.toolStrip2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lineCode)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem archivoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem abrirMenu;
        private System.Windows.Forms.ToolStripMenuItem guardarComoMenu;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem edicionToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem copiar;
        private System.Windows.Forms.ToolStripMenuItem cortar;
        private System.Windows.Forms.ToolStripMenuItem pegar;
        private System.Windows.Forms.ToolStripMenuItem color;
        private System.Windows.Forms.ToolStripMenuItem formato;
        private System.Windows.Forms.ToolStripMenuItem Salir;
        private System.Windows.Forms.OpenFileDialog abrirVentana;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.SaveFileDialog guardarVentana;
        private System.Windows.Forms.FontDialog fontDialog1;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem limpiar;
        private System.Windows.Forms.ToolStripButton botonAnalizar;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.RichTextBox codeText;
        private System.Windows.Forms.ToolStrip toolStrip2;
        private System.Windows.Forms.ToolStripLabel etiquetaNomArch;
        private System.Windows.Forms.PictureBox lineCode;
        private System.Windows.Forms.Timer lineRefresh;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ToolStripMenuItem ayudaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem btnAcerca;
        private System.Windows.Forms.RichTextBox outResult;
        private System.Windows.Forms.ToolStripButton botonGuardar;
        private System.Windows.Forms.ToolStripButton botonGuardarComo;
        private System.Windows.Forms.ToolStripButton botonAbrir;
        private System.Windows.Forms.ToolStripMenuItem guardarMenu;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripMenuItem deshacerMenu;
        private System.Windows.Forms.ToolStripMenuItem rehacerMenu;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripButton botonRehacer;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripButton botonDeshacer;
    }
}

