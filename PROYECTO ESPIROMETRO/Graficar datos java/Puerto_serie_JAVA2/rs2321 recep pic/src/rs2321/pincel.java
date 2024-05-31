package rs2321;

/*
 * pincel.java
 *
 *
 *
 * To change this template, choose Tools | Template Manager and open the
 * template in the editor.
 */
import java.awt.*;
import javax.swing.Timer;
import java.awt.event.ActionEvent;

/**
 *
 * @author MARY
 */
public class pincel extends Canvas {

    rs2321 form1;
    int px = 0, py = 300, ancho = 300, alto = 0, pa = 0, pe = 0, pi = 0, po = 0, pos = 300, poi = 0,y;
    int acceso = 0, g=300, f, e;
    Timer reloj;

    /**
     * Creates a new instance of pincel
     */
    public pincel(rs2321 R) {
        this.form1 = R;

        reloj = new Timer(25, (new java.awt.event.ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // throw new UnsupportedOperationException("Not supported yet.");
                evento_reloj(e);
            }
        }));


    }

    public void transferencia(int vx, int vy, int diam) {


        pa = px = vx;
        g = pe = py = vy;
        // pi = ancho = diam;
        // po = alto = diam;

    }

    public void transferencia(int r) {


        if (r == 0) {

            reloj.stop();

        } else {
            reloj.start();

        }
    }

    public void trans(int v) {

        g = v;
    }

    public void transfer(int v) {

        pos = v;
        

    }

    public void borrar(int f) {
        acceso = f;
    }

    private void evento_reloj(java.awt.event.ActionEvent evt) {


        px = px + 1;
        py = g;


        // y++;
        //form1.caja7.setText(String.valueOf(y));


    }

    @Override
    public void paint(Graphics lapiz) { // METODOS PARA PINTAR SIN DEJAR RASTRO


     
        lapiz.setColor(new Color(255, 0, 0));
        lapiz.drawLine(0, 0, 0, 300);
        lapiz.drawLine(0, 300, 400, 300);

    }

    @Override
    public void update(Graphics lapiz) {// METODOS PARA PINTAR DEJANDO RASTRO


        if (acceso == 1) {

            lapiz.clearRect(0, 0, 400, 301);
            lapiz.setColor(new Color(255, 0, 0));
            lapiz.drawLine(0, 0, 0, 300);
            lapiz.drawLine(0, 300, 400, 300);



            acceso = 0;
            
        } else {
           
            e = 300 - pos;

            lapiz.setColor(new Color(0, 240, 185));
            lapiz.drawLine(alto, ancho, px, py);

            lapiz.setColor(new Color(255, 255, 255));
            lapiz.drawLine(0, e, 400, e);
            

            alto = px;
            ancho = py;

            if (px >= 400) {

                reloj.restart();
                acceso = 2;
                alto = px - px;
                ancho = py;

            lapiz.clearRect(0, 0, 400, 301);
            lapiz.setColor(new Color(255, 0, 0));
            lapiz.drawLine(0, 0, 0, 300);
            lapiz.drawLine(0, 300, 400, 300);
            }

            if (acceso == 2) {


            lapiz.clearRect(0, 0, 400, 301);
            lapiz.setColor(new Color(255, 0, 0));
            lapiz.drawLine(0, 0, 0, 300);
            lapiz.drawLine(0, 300, 400, 300);



                lapiz.setColor(new Color(0, 240, 185));
                lapiz.fillOval(0, pe, pi, po);

                px = alto;
                py = ancho;


                acceso = 0;
            }

        }
   
     
   }
}
