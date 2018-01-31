package game; /**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

import card.Image;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;

import javax.swing.JPanel;

public class Solitaire extends JPanel implements MouseListener, ActionListener,MouseMotionListener {

    private boolean isDrag = false;

    private int x;
    private int y;

    private int oldx;
    private int oldy;

    private boolean win = false;
    private card.Image winBanner;


    public Solitaire() {
        setSize(900, 700);
        setLayout(null);
        addMouseListener (this);
        addMouseMotionListener(this);
    }

    @Override
    protected void paintComponent(Graphics g) {
        BufferedImage bi = new BufferedImage(900, 700, 1);
        Graphics2D G = bi.createGraphics();
        G.clearRect(0, 0, 900, 700);
        G.setColor(new Color(0x04817F));
        G.fillRect(0, 0, 900, 700);
        for (int i = 0; i < 13; i++) {
            Game.allPiles[i].display(G);
        }
        Game.moveCard.display(G, x, y, oldx, oldy);
        if (win) {
            if (winBanner == null) {
                winBanner = new Image("/PNG-cards/win.png");
            }
            G.drawImage(winBanner.getBufferedImage(),450 - winBanner.getWidth() / 2, 350 - winBanner.getHeight() / 2, null);
        }
        g.drawImage(bi, 0, 0, null);
    }

    @Override
    public void actionPerformed(ActionEvent e) {}

    @Override
    public void mouseClicked(MouseEvent e) {
        // 双击
        if (e.getClickCount() == 2) {
            int x = e.getX();
            int y = e.getY();
            Game.testDeckPile(x,y);
            Game.testDisCardPile(x, y);
            Game.testTablePile(x, y);

            if(Game.isCanAddToSuitPile()) {
                Game.refreshTablePile();
            } else {
                Game.returnToFromPile();
            }
            isDrag = false;
        }
        repaint();
    }

    @Override
    public void mousePressed(MouseEvent e) {
        x = e.getX();
        y = e.getY();
        oldx = x;
        oldy = y;
        isDrag = false;
        boolean isSelect = Game.testDeckPile(x,y);
        if(!isSelect){
            isSelect = Game.testDisCardPile(x, y);
            if(isSelect) {
                isDrag = true;
            } else {
                isSelect = Game.testTablePile(x, y);
                if(isSelect) {
                    isDrag = true;
                }
            }
        }
        isDrag = false;
        repaint();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        if(isDrag &&  Game.moveCard.size() > 0 ){
            boolean isCanAdd = Game.isCanAddToSuitPile(x,y);
            if(!isCanAdd) {
                isCanAdd = Game.isCanAddtoTablePile(x, y);
            }
            if(!isCanAdd) {
                Game.returnToFromPile();
            } else {
                Game.refreshTablePile();
            }
            isDrag = false;
        } else {
            if(Game.moveCard.size() > 0) {
                Game.returnToFromPile();
            }
        }
        if (Game.isWin()) {
            win = true;
        }
        repaint();
    }

    @Override
    public void mouseEntered(MouseEvent e) {}

    @Override
    public void mouseExited(MouseEvent e) {}

    @Override
    public void mouseDragged(MouseEvent e) {
        isDrag = true;
        x = e.getX();
        y = e.getY();
        repaint();
    }

    @Override
    public void mouseMoved(MouseEvent e) {}

}
