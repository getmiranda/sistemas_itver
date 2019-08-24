package interfaz;

import java.awt.event.KeyListener;

public class Ventana extends javax.swing.JFrame {
    
    public Ventana() {
        initComponents();
    }
    
   public void addEventos(Oyente oyente){
       this.opcionCompilar.addActionListener(oyente);
       this.opcionLimpiar.addActionListener(oyente);
       this.opcionAbrir.addActionListener(oyente);
       this.opcionGuardar.addActionListener(oyente);
       this.opcionSalir.addActionListener(oyente);
       this.areaTexto.addKeyListener(oyente);
       this.getAreaTextoP().addMouseWheelListener(oyente);
   }

    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jPanel2 = new javax.swing.JPanel();
        panelCentro = new javax.swing.JPanel();
        areaTextoP = new javax.swing.JScrollPane();
        areaTexto = new javax.swing.JTextArea();
        panelNorte = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        txtNumLineasP = new javax.swing.JScrollPane();
        txtNumLineas = new javax.swing.JTextArea();
        panelSur = new javax.swing.JPanel();
        panelSurN = new javax.swing.JPanel();
        etiquetaLexico = new javax.swing.JLabel();
        etiquetaSintactico = new javax.swing.JLabel();
        etiquetaSemantico = new javax.swing.JLabel();
        panelSurC = new javax.swing.JPanel();
        areaLexicoP = new javax.swing.JScrollPane();
        areaLexico = new javax.swing.JTextArea();
        areaSintacticoP = new javax.swing.JScrollPane();
        areaSintactico = new javax.swing.JTextArea();
        areaSemanticoP = new javax.swing.JScrollPane();
        areaSemantico = new javax.swing.JTextArea();
        barraDeMenu = new javax.swing.JMenuBar();
        menuArchivo = new javax.swing.JMenu();
        opcionAbrir = new javax.swing.JMenuItem();
        opcionGuardar = new javax.swing.JMenuItem();
        separador = new javax.swing.JPopupMenu.Separator();
        opcionSalir = new javax.swing.JMenuItem();
        menuAcciones = new javax.swing.JMenu();
        opcionCompilar = new javax.swing.JMenuItem();
        opcionLimpiar = new javax.swing.JMenuItem();
        separador2 = new javax.swing.JPopupMenu.Separator();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        panelCentro.setBorder(javax.swing.BorderFactory.createLineBorder(getBackground(), 10));

        areaTextoP.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);

        areaTexto.setColumns(20);
        areaTexto.setFont(new java.awt.Font("Consolas", 1, 18)); // NOI18N
        areaTexto.setForeground(new java.awt.Color(0, 51, 102));
        areaTexto.setRows(5);
        areaTexto.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED, java.awt.Color.darkGray, java.awt.Color.lightGray, null, null));
        areaTexto.setCursor(new java.awt.Cursor(java.awt.Cursor.TEXT_CURSOR));
        areaTextoP.setViewportView(areaTexto);

        panelNorte.setBackground(new java.awt.Color(0, 0, 51));
        panelNorte.setAlignmentX(1.0F);

        jLabel1.setForeground(new java.awt.Color(0, 204, 204));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/mcencabe.jpg"))); // NOI18N
        jLabel1.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);

        javax.swing.GroupLayout panelNorteLayout = new javax.swing.GroupLayout(panelNorte);
        panelNorte.setLayout(panelNorteLayout);
        panelNorteLayout.setHorizontalGroup(
            panelNorteLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, 1138, Short.MAX_VALUE)
        );
        panelNorteLayout.setVerticalGroup(
            panelNorteLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, 172, Short.MAX_VALUE)
        );

        txtNumLineas.setEditable(false);
        txtNumLineas.setBackground(new java.awt.Color(0, 51, 102));
        txtNumLineas.setColumns(1);
        txtNumLineas.setFont(new java.awt.Font("Consolas", 1, 18)); // NOI18N
        txtNumLineas.setForeground(new java.awt.Color(255, 255, 255));
        txtNumLineas.setRows(5);
        txtNumLineas.setToolTipText("");
        txtNumLineas.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED, java.awt.Color.darkGray, new java.awt.Color(0, 51, 102), null, null));
        txtNumLineasP.setViewportView(txtNumLineas);

        javax.swing.GroupLayout panelCentroLayout = new javax.swing.GroupLayout(panelCentro);
        panelCentro.setLayout(panelCentroLayout);
        panelCentroLayout.setHorizontalGroup(
            panelCentroLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
            .addGroup(panelCentroLayout.createSequentialGroup()
                .addComponent(txtNumLineasP, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(areaTextoP))
            .addComponent(panelNorte, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        panelCentroLayout.setVerticalGroup(
            panelCentroLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelCentroLayout.createSequentialGroup()
                .addComponent(panelNorte, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(panelCentroLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(txtNumLineasP)
                    .addComponent(areaTextoP, javax.swing.GroupLayout.DEFAULT_SIZE, 402, Short.MAX_VALUE)))
        );

        panelSur.setBorder(javax.swing.BorderFactory.createLineBorder(getBackground(), 10));
        panelSur.setLayout(new java.awt.BorderLayout());

        panelSurN.setLayout(new java.awt.GridLayout(1, 0));

        etiquetaLexico.setFont(new java.awt.Font("Segoe UI Semilight", 1, 14)); // NOI18N
        etiquetaLexico.setForeground(new java.awt.Color(0, 102, 102));
        etiquetaLexico.setText(" Análisis Léxico");
        etiquetaLexico.setToolTipText("");
        etiquetaLexico.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        etiquetaLexico.setMaximumSize(new java.awt.Dimension(34, 3));
        etiquetaLexico.setMinimumSize(new java.awt.Dimension(34, 3));
        panelSurN.add(etiquetaLexico);

        etiquetaSintactico.setFont(new java.awt.Font("Segoe UI Semilight", 1, 14)); // NOI18N
        etiquetaSintactico.setForeground(new java.awt.Color(0, 102, 102));
        etiquetaSintactico.setText(" Análisis sintáctico");
        etiquetaSintactico.setMaximumSize(new java.awt.Dimension(34, 3));
        etiquetaSintactico.setMinimumSize(new java.awt.Dimension(34, 3));
        panelSurN.add(etiquetaSintactico);

        etiquetaSemantico.setFont(new java.awt.Font("Segoe UI Semilight", 1, 14)); // NOI18N
        etiquetaSemantico.setForeground(new java.awt.Color(0, 102, 102));
        etiquetaSemantico.setText(" Analisis Semántico");
        etiquetaSemantico.setMaximumSize(new java.awt.Dimension(34, 3));
        etiquetaSemantico.setMinimumSize(new java.awt.Dimension(34, 3));
        panelSurN.add(etiquetaSemantico);

        panelSur.add(panelSurN, java.awt.BorderLayout.NORTH);

        panelSurC.setBackground(new java.awt.Color(255, 255, 255));
        panelSurC.setLayout(new java.awt.GridLayout(1, 0, 5, 0));

        areaLexicoP.setBackground(new java.awt.Color(51, 51, 51));

        areaLexico.setEditable(false);
        areaLexico.setBackground(new java.awt.Color(0, 0, 0));
        areaLexico.setColumns(20);
        areaLexico.setFont(new java.awt.Font("MS Gothic", 3, 14)); // NOI18N
        areaLexico.setForeground(new java.awt.Color(0, 255, 0));
        areaLexico.setRows(5);
        areaLexico.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.LOWERED, java.awt.Color.darkGray, java.awt.Color.lightGray, null, null));
        areaLexico.setCaretColor(new java.awt.Color(102, 102, 102));
        areaLexico.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        areaLexicoP.setViewportView(areaLexico);

        panelSurC.add(areaLexicoP);

        areaSintactico.setEditable(false);
        areaSintactico.setBackground(new java.awt.Color(0, 0, 0));
        areaSintactico.setColumns(20);
        areaSintactico.setFont(new java.awt.Font("MS Gothic", 3, 14)); // NOI18N
        areaSintactico.setForeground(new java.awt.Color(255, 0, 204));
        areaSintactico.setRows(5);
        areaSintactico.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.LOWERED, java.awt.Color.darkGray, java.awt.Color.lightGray, null, null));
        areaSintactico.setCursor(new java.awt.Cursor(java.awt.Cursor.WAIT_CURSOR));
        areaSintacticoP.setViewportView(areaSintactico);

        panelSurC.add(areaSintacticoP);

        areaSemantico.setEditable(false);
        areaSemantico.setBackground(new java.awt.Color(0, 0, 0));
        areaSemantico.setColumns(20);
        areaSemantico.setFont(new java.awt.Font("MS Gothic", 3, 14)); // NOI18N
        areaSemantico.setForeground(new java.awt.Color(0, 255, 204));
        areaSemantico.setRows(5);
        areaSemantico.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.LOWERED, java.awt.Color.darkGray, java.awt.Color.lightGray, null, null));
        areaSemantico.setCursor(new java.awt.Cursor(java.awt.Cursor.WAIT_CURSOR));
        areaSemanticoP.setViewportView(areaSemantico);

        panelSurC.add(areaSemanticoP);

        panelSur.add(panelSurC, java.awt.BorderLayout.CENTER);

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(panelCentro, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(panelSur, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(panelCentro, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(panelSur, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        menuArchivo.setForeground(new java.awt.Color(0, 51, 153));
        menuArchivo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/windows_7_rocketdock_exe_by_asilaydyingdl.png"))); // NOI18N
        menuArchivo.setText("  Archivo  ");
        menuArchivo.setToolTipText("");
        menuArchivo.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        menuArchivo.setFont(new java.awt.Font("Segoe UI", 1, 18)); // NOI18N

        opcionAbrir.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_A, java.awt.event.InputEvent.CTRL_MASK));
        opcionAbrir.setFont(new java.awt.Font("Rockwell", 0, 13)); // NOI18N
        opcionAbrir.setForeground(new java.awt.Color(102, 0, 51));
        opcionAbrir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/ab.png"))); // NOI18N
        opcionAbrir.setText("  Abrir");
        opcionAbrir.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        opcionAbrir.setName("abrir"); // NOI18N
        menuArchivo.add(opcionAbrir);

        opcionGuardar.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_S, java.awt.event.InputEvent.CTRL_MASK));
        opcionGuardar.setFont(new java.awt.Font("Rockwell", 0, 13)); // NOI18N
        opcionGuardar.setForeground(new java.awt.Color(102, 0, 51));
        opcionGuardar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/diskette_save_saveas_1514.png"))); // NOI18N
        opcionGuardar.setText("  Guardar    ");
        opcionGuardar.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        opcionGuardar.setName("guardar"); // NOI18N
        menuArchivo.add(opcionGuardar);
        menuArchivo.add(separador);

        opcionSalir.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_F4, java.awt.event.InputEvent.ALT_MASK));
        opcionSalir.setFont(new java.awt.Font("Rockwell", 0, 13)); // NOI18N
        opcionSalir.setForeground(new java.awt.Color(102, 0, 51));
        opcionSalir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/cross-31176_640.png"))); // NOI18N
        opcionSalir.setText("  Salir");
        opcionSalir.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        opcionSalir.setName("salir"); // NOI18N
        menuArchivo.add(opcionSalir);

        barraDeMenu.add(menuArchivo);

        menuAcciones.setForeground(new java.awt.Color(0, 51, 153));
        menuAcciones.setText(" Acciones");
        menuAcciones.setToolTipText("");
        menuAcciones.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        menuAcciones.setFont(new java.awt.Font("Segoe UI", 1, 18)); // NOI18N

        opcionCompilar.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_C, java.awt.event.InputEvent.CTRL_MASK));
        opcionCompilar.setFont(new java.awt.Font("Rockwell", 0, 13)); // NOI18N
        opcionCompilar.setForeground(new java.awt.Color(102, 0, 51));
        opcionCompilar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/FXOERTEGOHMAMZP.png"))); // NOI18N
        opcionCompilar.setText("Compilar   ");
        opcionCompilar.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        opcionCompilar.setName("compilar"); // NOI18N
        menuAcciones.add(opcionCompilar);

        opcionLimpiar.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_L, java.awt.event.InputEvent.CTRL_MASK));
        opcionLimpiar.setFont(new java.awt.Font("Rockwell", 0, 13)); // NOI18N
        opcionLimpiar.setForeground(new java.awt.Color(102, 0, 51));
        opcionLimpiar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/419660.png"))); // NOI18N
        opcionLimpiar.setText("Limpiar  ");
        opcionLimpiar.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        opcionLimpiar.setName("limpiar"); // NOI18N
        menuAcciones.add(opcionLimpiar);
        menuAcciones.add(separador2);

        barraDeMenu.add(menuAcciones);

        setJMenuBar(barraDeMenu);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel2, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextArea areaLexico;
    private javax.swing.JScrollPane areaLexicoP;
    private javax.swing.JTextArea areaSemantico;
    private javax.swing.JScrollPane areaSemanticoP;
    private javax.swing.JTextArea areaSintactico;
    private javax.swing.JScrollPane areaSintacticoP;
    private javax.swing.JTextArea areaTexto;
    private javax.swing.JScrollPane areaTextoP;
    private javax.swing.JMenuBar barraDeMenu;
    private javax.swing.JLabel etiquetaLexico;
    private javax.swing.JLabel etiquetaSemantico;
    private javax.swing.JLabel etiquetaSintactico;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JMenu menuAcciones;
    private javax.swing.JMenu menuArchivo;
    private javax.swing.JMenuItem opcionAbrir;
    private javax.swing.JMenuItem opcionCompilar;
    private javax.swing.JMenuItem opcionGuardar;
    private javax.swing.JMenuItem opcionLimpiar;
    private javax.swing.JMenuItem opcionSalir;
    private javax.swing.JPanel panelCentro;
    private javax.swing.JPanel panelNorte;
    private javax.swing.JPanel panelSur;
    private javax.swing.JPanel panelSurC;
    private javax.swing.JPanel panelSurN;
    private javax.swing.JPopupMenu.Separator separador;
    private javax.swing.JPopupMenu.Separator separador2;
    private javax.swing.JTextArea txtNumLineas;
    private javax.swing.JScrollPane txtNumLineasP;
    // End of variables declaration//GEN-END:variables

    /**
     * @return the areaLexico
     */
    public javax.swing.JTextArea getAreaLexico() {
        return areaLexico;
    }

    /**
     * @param areaLexico the areaLexico to set
     */
    public void setAreaLexico(javax.swing.JTextArea areaLexico) {
        this.areaLexico = areaLexico;
    }

    /**
     * @return the areaSemantico
     */
    public javax.swing.JTextArea getAreaSemantico() {
        return areaSemantico;
    }

    /**
     * @param areaSemantico the areaSemantico to set
     */
    public void setAreaSemantico(javax.swing.JTextArea areaSemantico) {
        this.areaSemantico = areaSemantico;
    }

    /**
     * @return the areaSintactico
     */
    public javax.swing.JTextArea getAreaSintactico() {
        return areaSintactico;
    }

    /**
     * @param areaSintactico the areaSintactico to set
     */
    public void setAreaSintactico(javax.swing.JTextArea areaSintactico) {
        this.areaSintactico = areaSintactico;
    }

    /**
     * @return the areaTexto
     */
    public javax.swing.JTextArea getAreaTexto() {
        return areaTexto;
    }

    /**
     * @param areaTexto the areaTexto to set
     */
    public void setAreaTexto(javax.swing.JTextArea areaTexto) {
        this.areaTexto = areaTexto;
    }

    /**
     * @return the txtNumLineas
     */
    public javax.swing.JTextArea getTxtNumLineas() {
        return txtNumLineas;
    }

    /**
     * @param txtNumLineas the txtNumLineas to set
     */
    public void setTxtNumLineas(javax.swing.JTextArea txtNumLineas) {
        this.txtNumLineas = txtNumLineas;
    }

    /**
     * @return the areaTextoP
     */
    public javax.swing.JScrollPane getAreaTextoP() {
        return areaTextoP;
    }

    /**
     * @param areaTextoP the areaTextoP to set
     */
    public void setAreaTextoP(javax.swing.JScrollPane areaTextoP) {
        this.areaTextoP = areaTextoP;
    }

    /**
     * @return the txtNumLineasP
     */
    public javax.swing.JScrollPane getTxtNumLineasP() {
        return txtNumLineasP;
    }

    /**
     * @param txtNumLineasP the txtNumLineasP to set
     */
    public void setTxtNumLineasP(javax.swing.JScrollPane txtNumLineasP) {
        this.txtNumLineasP = txtNumLineasP;
    }
}
