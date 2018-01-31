package card;

import java.awt.*;
import java.util.ArrayList;

/**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

public class MoveCardPile {
    private ArrayList<Card> cardList ;
    private CardPile fromPile;
    private int startx;
    private int starty;
    private final static int separation  = 30;
    public MoveCardPile(){
        cardList = new ArrayList();
    }
    public int size(){
        return cardList.size();
    }
    public boolean isEmpty(){
        return cardList.isEmpty();
    }
    public void addCard(Card card){
        cardList.add(0, card);
    }
    public Card getCard(){
        if(cardList.size()>0) {
            return cardList.get(0);
        } else {
            return null;
        }
    }
    public Card removeCard(){
        if(cardList.size()>0) {
            return  cardList.remove(0);
        } else {
            return null;
        }
    }
    public ArrayList<Card> clear(){
        ArrayList<Card> list = cardList;
        cardList = new ArrayList();
        return list;
    }


    public void display(Graphics g, int tx, int ty, int oldx, int oldy){
        int dx = tx - oldx;
        int dy = ty - oldy;
        int x = startx + dx;
        int y = starty + dy;
        int localy = y;
        for (Card aCard : cardList) {
            aCard.setX(x);
            aCard.setY(localy);
            if (!(aCard.isFront())) {
                aCard.setFaceup(true);
            }
            aCard.draw(g);
            localy += separation;
        }
    }

    public CardPile getFromPile() {
        return fromPile;
    }

    public void setFromPile(CardPile fromPile, boolean flag) {
        this.fromPile = fromPile;
        this.startx = fromPile.x;
        if (flag) {
            this.starty = fromPile.y;
        } else {
            this.starty = fromPile.y + fromPile.getSize() * separation;
        }
    }

    public void setFromPile(CardPile fromPile, int i) {
        this.fromPile = fromPile;
        this.startx = fromPile.x;
        this.starty = fromPile.y + TablePile.unFlipCardSeparation * i + separation * (fromPile.getSize() - i);
    }

}
