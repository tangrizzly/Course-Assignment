package game;

import javax.swing.*;

/**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

public class SolitaireGame extends JFrame {

    public SolitaireGame(){
        setSize(900, 700);
        setTitle("Solitaire");
        setLayout(null);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setVisible(true);
        Solitaire sp = new Solitaire();
        add(sp);
    }
    public static void main(String[] args) {
        new SolitaireGame();
    }

}
