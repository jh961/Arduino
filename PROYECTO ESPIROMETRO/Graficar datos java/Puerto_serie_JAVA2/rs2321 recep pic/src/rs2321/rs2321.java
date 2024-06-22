package rs2321;

/*
 * rs2321.java
 *
 *
 */
import java.awt.event.ActionEvent;
import java.io.*;
import javax.swing.Timer;

/**
 *
 * @author Administrador
 */
public class rs2321 extends javax.swing.JFrame {

    pincel lienzo;
    WriterPort emisor;
    ReaderPort reader;
    String a = "", dato3, datomandado,dt1;
    int tiempo,ed, t, y,z,sc1=300, sc = 300, ac = 0, dx, dy, di;
    int h=300;
    char r;
    Timer reloj;
    boolean flag = true;

    /**
     * Creates new form rs2321
     */
    public rs2321() {



        initComponents();

        reloj = new Timer(70, (new java.awt.event.ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // throw new UnsupportedOperationException("Not supported yet.");
                evento_reloj(e);
            }
        }));


        this.emisor = WriterPort.getInstance();
        this.reader = ReaderPort.getInstance();

        this.reader.addActionListener(new java.awt.event.ActionListener() {

            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ActionEventPort actionEventPort = (ActionEventPort) evt;
                evento_de_Lectura(actionEventPort);
            }
        });

        lienzo = new pincel(this);                          //enlace a la clase pincel que es la que pinta
        lienzo.setBackground(new java.awt.Color(0, 0, 0));  //definicion de color de fondo
        panel1.add(lienzo);                                 //Agrega el canvas a un panel
        lienzo.setBounds(60, 20, 400, 301);


    }

    public void evento_de_Lectura(ActionEventPort actionEventPort) {

        a = a + actionEventPort.getReaded();

        ed = a.length();

        for (int i = 0; i < ed; i++) {

            r = a.charAt(i);
            if (r == '@') {
                z = i;

            } else if (r == '#') {
                
                caja1.setText(a);
                
                dato3 = a.substring(z + 1, i);
               
                sc1=sc = Integer.parseInt(dato3);
                caja4.setText(String.valueOf(sc));
                sc= 300 - sc;
                lienzo.trans(sc);
                a = "";
            }else if(r == '%'){
         
        if (flag == true) {

            t = 1;
            reloj.start();
            flag = false;
        } else {

            flag = true;

            t = 0;
            reloj.stop();

        }

        lienzo.transferencia(t);

        lienzo.repaint();
              a = "";  
              r=' ';
            }
               
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        caja1 = new javax.swing.JTextField();
        caja4 = new javax.swing.JTextField();
        caja5 = new javax.swing.JTextField();
        borrardato = new javax.swing.JButton();
        jSeparator1 = new javax.swing.JSeparator();
        jLabel1 = new javax.swing.JLabel();
        panel1 = new javax.swing.JPanel();
        borrar = new javax.swing.JButton();
        visualizar = new javax.swing.JButton();
        pintar = new javax.swing.JButton();
        star = new javax.swing.JButton();
        pintarlimite = new javax.swing.JButton();
        jLabel7 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        jLabel13 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Plantilla Comunicaci�n RS-232");
        getContentPane().setLayout(null);
        getContentPane().add(caja1);
        caja1.setBounds(50, 50, 160, 30);
        getContentPane().add(caja4);
        caja4.setBounds(140, 130, 100, 30);

        caja5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                caja5ActionPerformed(evt);
            }
        });
        getContentPane().add(caja5);
        caja5.setBounds(580, 100, 100, 30);

        borrardato.setText("Borrar");
        borrardato.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                borrardatoActionPerformed(evt);
            }
        });
        getContentPane().add(borrardato);
        borrardato.setBounds(150, 170, 80, 30);
        getContentPane().add(jSeparator1);
        jSeparator1.setBounds(30, 90, 340, 10);

        jLabel1.setFont(new java.awt.Font("Arial Black", 0, 12)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(0, 0, 153));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("Recepcion  de Datos Puerto Serie");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(-10, 10, 330, 40);

        panel1.setBorder(javax.swing.BorderFactory.createEtchedBorder());
        panel1.setLayout(null);
        getContentPane().add(panel1);
        panel1.setBounds(40, 230, 550, 340);

        borrar.setText("Borrar");
        borrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                borrarActionPerformed(evt);
            }
        });
        getContentPane().add(borrar);
        borrar.setBounds(620, 240, 70, 30);

        visualizar.setText("Visualizar");
        visualizar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                visualizarActionPerformed(evt);
            }
        });
        getContentPane().add(visualizar);
        visualizar.setBounds(600, 280, 110, 30);

        pintar.setText("Pintar Esfera");
        pintar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                pintarActionPerformed(evt);
            }
        });
        getContentPane().add(pintar);
        pintar.setBounds(600, 320, 120, 23);

        star.setText("strar/stop");
        star.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                starActionPerformed(evt);
            }
        });
        getContentPane().add(star);
        star.setBounds(550, 20, 150, 60);

        pintarlimite.setText("Pintar Limite");
        pintarlimite.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                pintarlimiteActionPerformed(evt);
            }
        });
        getContentPane().add(pintarlimite);
        pintarlimite.setBounds(570, 140, 120, 23);

        jLabel7.setFont(new java.awt.Font("Tahoma", 1, 11)); // NOI18N
        jLabel7.setForeground(new java.awt.Color(153, 0, 0));
        jLabel7.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel7.setText("Recepci�n Datos");
        getContentPane().add(jLabel7);
        jLabel7.setBounds(120, 100, 140, 20);

        jLabel2.setText("8");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(20, 370, 10, 30);

        jLabel3.setText("0                    1                    2                    3                    4                    5                    6                    7                    8");
        getContentPane().add(jLabel3);
        jLabel3.setBounds(40, 570, 550, 20);

        jLabel4.setText("0");
        getContentPane().add(jLabel4);
        jLabel4.setBounds(20, 540, 10, 30);

        jLabel5.setText("2");
        getContentPane().add(jLabel5);
        jLabel5.setBounds(20, 490, 10, 30);

        jLabel6.setText("4");
        getContentPane().add(jLabel6);
        jLabel6.setBounds(20, 450, 10, 30);

        jLabel8.setText("6");
        getContentPane().add(jLabel8);
        jLabel8.setBounds(20, 410, 10, 30);

        jLabel10.setText("10");
        getContentPane().add(jLabel10);
        jLabel10.setBounds(20, 330, 20, 30);

        jLabel12.setText("12");
        getContentPane().add(jLabel12);
        jLabel12.setBounds(20, 280, 20, 30);

        jLabel13.setText("14");
        getContentPane().add(jLabel13);
        jLabel13.setBounds(20, 240, 20, 30);

        java.awt.Dimension screenSize = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
        setBounds((screenSize.width-743)/2, (screenSize.height-631)/2, 743, 631);
    }// </editor-fold>//GEN-END:initComponents

    private void borrardatoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_borrardatoActionPerformed


        caja1.setText("");
        caja4.setText("");
       

    }//GEN-LAST:event_borrardatoActionPerformed

    private void borrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_borrarActionPerformed

        lienzo.borrar(1);
        lienzo.repaint();
    }//GEN-LAST:event_borrarActionPerformed

    private void visualizarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_visualizarActionPerformed

        int f = 0;

        if (f == 0) {
            panel1.setVisible(true);
            f = 1;
        } else {
            panel1.setVisible(false);
            f = 0;
        }

    }//GEN-LAST:event_visualizarActionPerformed

    private void pintarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_pintarActionPerformed

       

        dx = 0; //Integer.parseInt(cajax.getText());
        dy = 300; // Integer.parseInt(cajay.getText());
        di = 2; //Integer.parseInt(caja1.getText());

        
        h = Integer.parseInt(caja5.getText());
        

        lienzo.transferencia(dx, dy, di);
        lienzo.transfer(h);
        lienzo.repaint();

    }//GEN-LAST:event_pintarActionPerformed

    private void starActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_starActionPerformed

        if (flag == true) {

            t = 1;
            reloj.start();
            flag = false;
        } else {

            flag = true;

            t = 0;
            reloj.stop();

        }

        lienzo.transferencia(t);

        lienzo.repaint();

        // TODO add your handling code here:
    }//GEN-LAST:event_starActionPerformed

    private void pintarlimiteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_pintarlimiteActionPerformed
        h = Integer.parseInt(caja5.getText());
        lienzo.transfer(h);
        lienzo.repaint();
    }//GEN-LAST:event_pintarlimiteActionPerformed

    private void caja5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_caja5ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_caja5ActionPerformed
    private void evento_reloj(java.awt.event.ActionEvent evt) {
  
 lienzo.transferencia(t);
       lienzo.repaint();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {

            public void run() {
                new rs2321().setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton borrar;
    private javax.swing.JButton borrardato;
    private javax.swing.JTextField caja1;
    private javax.swing.JTextField caja4;
    private javax.swing.JTextField caja5;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JPanel panel1;
    private javax.swing.JButton pintar;
    private javax.swing.JButton pintarlimite;
    private javax.swing.JButton star;
    private javax.swing.JButton visualizar;
    // End of variables declaration//GEN-END:variables
}