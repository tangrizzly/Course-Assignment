package card;

import java.awt.*;
import java.util.ArrayList;
import java.util.Enumeration;

/**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

public class TablePile extends CardPile {
    private int notFlipNum;
    private int  cardNum;
    private final static int separation  = 30;
    final static int unFlipCardSeparation = 10;
    public TablePile(int x, int y,int notFlipNum){
        super(x, y);
        this.notFlipNum = notFlipNum;
        cardNum = notFlipNum+1;

    }
    @Override
    public boolean includes(int tx, int ty) {
        int beginX,beginY,endX,endY;
        beginX = x;
        beginY = y ;
        endX = x + Card.width;
        if(thePile.size() > 0) {
            endY =  beginY  + unFlipCardSeparation * notFlipNum + separation * (thePile.size() - 1 - notFlipNum) + Card.height ;
        } else {
            endY =  beginY  + Card.height;
        }
        return beginX <= tx && tx <= endX && beginY <= ty && ty <= endY;
    }

    @Override
    public int select(int tx, int ty) {
        if(!(isEmpty())){
            int beginX,beginY,endX,endY;
            beginX = x  ;
            beginY = y + unFlipCardSeparation * notFlipNum;
            endX = x + Card.width;
            endY =  beginY  + unFlipCardSeparation * notFlipNum + separation * (thePile.size() - 1 - notFlipNum) + Card.height;
            boolean flipInclude =  beginX <= tx && tx <= endX && beginY <= ty && ty <= endY;
            if(flipInclude){
                int c = (ty - beginY)/separation + notFlipNum;
                if(c >= thePile.size()){
                    c =  thePile.size() - 1;
                }
                return c;
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }

    @Override
    public void addCard(Object card) {
        ArrayList<Card> cardList = (ArrayList<Card>)card;
        cardNum += cardList.size();
        for(int i = 0;i < cardList.size();i++){
            thePile.push(cardList.get(i));
        }
    }

    @Override
    public Card pop() {
        cardNum--;
        return super.pop();
    }
    public boolean isCanAdd(Card card){
        if ( isEmpty()) {
            return card.getNum() == 12;
        }
        Card topCard = top();
        return (card.getColor() != topCard.getColor()) && (card.getNum() ==  topCard.getNum()-1 );
    }

    @Override
    public void display(Graphics g) {
        if (isEmpty()){
            g.drawImage(buttomPic.getBufferedImage(), this.x,this.y, Card.width, Card.height, null);
        }
        else{
            int localy = y;
            for (Enumeration e = thePile.elements(); e.hasMoreElements(); ) {

                Card aCard = (Card) e.nextElement();
                aCard.setX(x);
                aCard.setY(localy);
                aCard.draw(g);
                if(aCard.isFront()) {
                    localy += separation;
                } else {
                    localy += unFlipCardSeparation;
                }

            }
        }
    }
    public int getNotFlipNum() {
        return notFlipNum;
    }
    public void setNotFlipNum(int notFlipNum) {
        this.notFlipNum = notFlipNum;
    }
    public int getCardNum() {
        return cardNum;
    }
    public void setCardNum(int cardNum) {
        this.cardNum = cardNum;
    }
}