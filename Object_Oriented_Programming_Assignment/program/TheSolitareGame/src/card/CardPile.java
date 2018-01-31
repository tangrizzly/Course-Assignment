package card;

import java.awt.*;
import java.util.EmptyStackException;
import java.util.Stack;

/**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

public class CardPile {

    protected final int x;
    protected final int y;
    public final Stack<Card> thePile;
    public static Image buttomPic;

    public CardPile (int xl, int yl) {
        x = xl;
        y = yl;
        thePile = new Stack();
        if (buttomPic == null) {
            String picture = "/PNG-cards/empty.png";
            buttomPic = new Image(picture);
        }
    }
    public  Card top() {
        if(!(thePile.empty())) {
            return thePile.peek();
        } else {
            return null;
        }
    }
    public  boolean isEmpty() {
        return thePile.empty();
    }

    public  Card pop() {
        try {
            return thePile.pop();
        } catch (EmptyStackException e) { return null; }
    }

    public boolean includes (int tx, int ty) {
        return this.x <= tx && tx <= this.x + Card.width &&
                this.y <= ty && ty <= this.y + Card.height;
    }

    public int select (int tx, int ty) {
        if(includes(tx,ty)){
            if(isEmpty()) {
                return -2;
            } else {
                return thePile.size() - 1;
            }
        }
        else {
            return -1;
        }
    }

    public void addCard (Object card){
        thePile.push((Card)card);
    }

    public void display (Graphics g){
        if (isEmpty()){
            g.drawImage(buttomPic.getBufferedImage(), this.x,this.y, Card.width, Card.height, null);
        }
        else{
            top().setX(x);
            top().setY(y);
            top().draw(g);
        }
    }

    public int getSize() {
        return this.thePile.size();
    }
}

