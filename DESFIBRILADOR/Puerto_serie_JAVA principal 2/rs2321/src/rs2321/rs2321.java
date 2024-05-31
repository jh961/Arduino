package rs2321;

/*
 * rs2321.java
 *
 *
 */
import java.io.*;
import javax.swing.ImageIcon;

/**
 *
 * @author Administrador
 */
public class rs2321 extends javax.swing.JFrame {

    WriterPort emisor;
    ReaderPort reader;
    String a = "",datov,datot;
    int ed,posi1,t;
    double voltajeardu,voltajedescarga,energia;
    int voltajereferencia=5;
    String datoenviado="0";
    char r;

    /**
     * Creates new form rs2321
     */
    public rs2321() {

        initComponents();
        
        

        this.emisor = WriterPort.getInstance();
        this.reader = ReaderPort.getInstance();

        this.reader.addActionListener(new java.awt.event.ActionListener() {

            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ActionEventPort actionEventPort = (ActionEventPort) evt;
                evento_de_Lectura(actionEventPort);
            }
        });



    }

    public void evento_de_Lectura(ActionEventPort actionEventPort) {

        a = a + actionEventPort.getReaded();

        ed = a.length();

  for (int i = 0; i < ed; i++) {

            r = a.charAt(i);

            if (r == '@') {

                posi1=i;
                
            }else if (r == '#'){
                
                datov = a.substring(posi1 +1, i);
                
                voltajeardu=Float.parseFloat(datov);
                voltajedescarga=((voltajeardu*42.2499)-2);
                energia=(((0.08174)*((voltajedescarga)*(voltajedescarga)))/2);
                
                if(voltajedescarga<0){
                    voltajedescarga=0;
                    energia=0;
                }
                
                caja1.setText(a);
                caja2.setText(datov);
                caja3.setText(""+ voltajedescarga);
                caja4.setText(""+ energia + "MicroJulios");
                
                a= "";
            }
           
  }
  
  
         if((voltajedescarga)>=(voltajereferencia-4)){
                indicador1.setText("ˇˇˇCARGADO!!!");
                
                imgcalen.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagen/verde.png")));
            }else {
                indicador1.setText("ˇˇˇDESCARGADO!!!");
                
                imgcalen.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagen/rojo.png")));             
         }
         /*
         try {

            String datomandado = "$" + datoenvi1 + "%" + datoenvi2+ "#"; 
            emisor.escribir(datomandado);
           
        } catch (IOException iOException) {
        }
        */
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        caja1 = new javax.swing.JTextField();
        borrar = new javax.swing.JButton();
        jSeparator1 = new javax.swing.JSeparator();
        jLabel1 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        caja2 = new javax.swing.JTextField();
        caja3 = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        imgcalen = new javax.swing.JLabel();
        indicador1 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLabel11 = new javax.swing.JLabel();
        barra1 = new javax.swing.JScrollBar();
        jLabel12 = new javax.swing.JLabel();
        indicador3 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        caja4 = new javax.swing.JTextField();
        cargar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("DESFIBRILADOR RS-232");
        getContentPane().setLayout(null);
        getContentPane().add(caja1);
        caja1.setBounds(30, 30, 160, 30);

        borrar.setText("Borrar");
        borrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                borrarActionPerformed(evt);
            }
        });
        getContentPane().add(borrar);
        borrar.setBounds(260, 30, 80, 30);
        getContentPane().add(jSeparator1);
        jSeparator1.setBounds(30, 70, 590, 10);

        jLabel1.setFont(new java.awt.Font("Arial Black", 0, 12)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(0, 0, 153));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("DATOS RECIBIDOS");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(40, 10, 140, 18);

        jLabel3.setFont(new java.awt.Font("Arial Black", 0, 18)); // NOI18N
        jLabel3.setForeground(new java.awt.Color(0, 0, 153));
        jLabel3.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel3.setText("voltios");
        getContentPane().add(jLabel3);
        jLabel3.setBounds(310, 280, 100, 20);
        getContentPane().add(caja2);
        caja2.setBounds(60, 110, 160, 30);
        getContentPane().add(caja3);
        caja3.setBounds(250, 110, 160, 30);

        jLabel5.setFont(new java.awt.Font("Arial Black", 0, 12)); // NOI18N
        jLabel5.setForeground(new java.awt.Color(0, 0, 153));
        jLabel5.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel5.setText("CARGA COMPLETA");
        getContentPane().add(jLabel5);
        jLabel5.setBounds(150, 380, 140, 18);

        imgcalen.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagen/rojo.png"))); // NOI18N
        getContentPane().add(imgcalen);
        imgcalen.setBounds(200, 410, 40, 40);

        indicador1.setFont(new java.awt.Font("Gill Sans Ultra Bold", 0, 12)); // NOI18N
        indicador1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        getContentPane().add(indicador1);
        indicador1.setBounds(110, 460, 220, 30);

        jLabel7.setFont(new java.awt.Font("Arial Black", 0, 12)); // NOI18N
        jLabel7.setForeground(new java.awt.Color(0, 0, 153));
        jLabel7.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel7.setText("VOLTAJE ARDUINO");
        getContentPane().add(jLabel7);
        jLabel7.setBounds(70, 90, 140, 18);

        jLabel8.setFont(new java.awt.Font("Arial Black", 0, 12)); // NOI18N
        jLabel8.setForeground(new java.awt.Color(0, 0, 153));
        jLabel8.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel8.setText("VOLTAJE DESCARGA");
        getContentPane().add(jLabel8);
        jLabel8.setBounds(260, 90, 140, 18);

        jLabel9.setFont(new java.awt.Font("Arial Black", 0, 12)); // NOI18N
        jLabel9.setForeground(new java.awt.Color(0, 0, 153));
        jLabel9.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel9.setText("NIVEL DE CARGA DEL DESFIBRILADOR");
        getContentPane().add(jLabel9);
        jLabel9.setBounds(160, 190, 320, 18);

        jLabel11.setFont(new java.awt.Font("Arial Black", 0, 12)); // NOI18N
        jLabel11.setForeground(new java.awt.Color(0, 0, 153));
        jLabel11.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel11.setText("VOLTAJE");
        getContentPane().add(jLabel11);
        jLabel11.setBounds(260, 220, 140, 18);

        barra1.setMaximum(110);
        barra1.setOrientation(javax.swing.JScrollBar.HORIZONTAL);
        barra1.setUnitIncrement(10);
        barra1.addAdjustmentListener(new java.awt.event.AdjustmentListener() {
            public void adjustmentValueChanged(java.awt.event.AdjustmentEvent evt) {
                barra1AdjustmentValueChanged(evt);
            }
        });
        getContentPane().add(barra1);
        barra1.setBounds(90, 320, 470, 30);

        jLabel12.setFont(new java.awt.Font("Arial Black", 0, 12)); // NOI18N
        jLabel12.setForeground(new java.awt.Color(0, 0, 153));
        jLabel12.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel12.setText("IDEAL");
        getContentPane().add(jLabel12);
        jLabel12.setBounds(260, 240, 140, 18);

        indicador3.setFont(new java.awt.Font("Arial Black", 0, 18)); // NOI18N
        indicador3.setForeground(new java.awt.Color(0, 0, 153));
        indicador3.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        indicador3.setText("0");
        getContentPane().add(indicador3);
        indicador3.setBounds(250, 280, 60, 20);

        jLabel10.setFont(new java.awt.Font("Arial Black", 0, 12)); // NOI18N
        jLabel10.setForeground(new java.awt.Color(0, 0, 153));
        jLabel10.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel10.setText("ENERGIA");
        getContentPane().add(jLabel10);
        jLabel10.setBounds(450, 90, 140, 18);
        getContentPane().add(caja4);
        caja4.setBounds(440, 110, 160, 30);

        cargar.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        cargar.setForeground(new java.awt.Color(0, 153, 0));
        cargar.setText("CARGAR ");
        cargar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cargarActionPerformed(evt);
            }
        });
        getContentPane().add(cargar);
        cargar.setBounds(400, 400, 170, 80);

        java.awt.Dimension screenSize = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
        setBounds((screenSize.width-673)/2, (screenSize.height-549)/2, 673, 549);
    }// </editor-fold>//GEN-END:initComponents

    private void borrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_borrarActionPerformed

        a = "";
       caja1.setText("");
       caja2.setText("");
       caja3.setText("");
       caja4.setText("");



    }//GEN-LAST:event_borrarActionPerformed

    private void barra1AdjustmentValueChanged(java.awt.event.AdjustmentEvent evt) {//GEN-FIRST:event_barra1AdjustmentValueChanged
     
        int valor = barra1.getValue();

        
        voltajereferencia=valor;
        if((voltajereferencia>=3)&&(voltajereferencia<10)){
            datoenviado="X";
                    
        }else if((voltajereferencia>=10)&&(voltajereferencia<20)){
            datoenviado="A";
                    
        }else if((voltajereferencia>=20)&&(voltajereferencia<30)){
            datoenviado="B";
                    
        }else if((voltajereferencia>=30)&&(voltajereferencia<40)){
            datoenviado="C";
                    
        }else if((voltajereferencia>=40)&&(voltajereferencia<50)){
            datoenviado="D";
                    
        }else if((voltajereferencia>=50)&&(voltajereferencia<60)){
            datoenviado="E";
                    
        }else if((voltajereferencia>=60)&&(voltajereferencia<70)){
            datoenviado="F";
                    
        }else if((voltajereferencia>=70)&&(voltajereferencia<80)){
            datoenviado="G";
                    
        }else if((voltajereferencia>=80)&&(voltajereferencia<90)){
            datoenviado="H";
                    
        }else if((voltajereferencia>=90)&&(voltajereferencia<100)){
            datoenviado="I";
                    
        }else if((voltajereferencia>=100)&&(voltajereferencia<110)){
            datoenviado="J";
                    
        }
        
        indicador3.setText(""+ voltajereferencia);
      
        
    }//GEN-LAST:event_barra1AdjustmentValueChanged

    private void cargarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cargarActionPerformed
       try {

            String datoenviado1 = datoenviado ; 
            emisor.escribir(datoenviado1);
           
        } catch (IOException iOException) {
        }
    }//GEN-LAST:event_cargarActionPerformed

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
    private javax.swing.JScrollBar barra1;
    private javax.swing.JButton borrar;
    private javax.swing.JTextField caja1;
    private javax.swing.JTextField caja2;
    private javax.swing.JTextField caja3;
    private javax.swing.JTextField caja4;
    private javax.swing.JButton cargar;
    private javax.swing.JLabel imgcalen;
    private javax.swing.JLabel indicador1;
    private javax.swing.JLabel indicador3;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JSeparator jSeparator1;
    // End of variables declaration//GEN-END:variables
}
