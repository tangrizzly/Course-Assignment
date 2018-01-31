package card;

/**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

public class SuitPile extends CardPile {

    public SuitPile (int x, int y) { super(x, y); }

    public boolean isCanAdd(Card card) {
        if (isEmpty()) {
            return card.getNum() == 0;
        }
        Card topCard = top();
        return (card.getType() == topCard.getType()) && (card.getNum() ==  topCard.getNum() + 1);
    }

}