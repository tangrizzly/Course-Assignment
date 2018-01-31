package card;

/**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

public class DiscardPile extends CardPile {

    public DiscardPile (int x, int y) {
        super (x, y);
    }

    public void addCard (Object card){
        Card cards = (Card)card;
        if (!(cards.isFront())) {
            cards.setFaceup(true);
        }
        thePile.push(cards);
    }

}