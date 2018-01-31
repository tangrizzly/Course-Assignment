package card;

import java.awt.*;

/**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

public class Card {

    final public static int width = 96;
    final public static int height = 130;

    public enum CardShape {
        HEARTS("hearts"), SPADES("spades"), DIAMONDS("diamonds"), CLUBS("clubs");

        private String name;

        CardShape(String name) {
            this.name = name;
        }
        public String getName() {
            return name;
        }
        public static CardShape fromInteger(int x) {
            switch(x) {
                case 0:
                    return HEARTS;
                case 1:
                    return SPADES;
                case 2:
                    return DIAMONDS;
                case 3:
                    return CLUBS;
            }
            return null;
        }
    }

    private boolean front;
    private int num;
    private CardShape type;
    private int x;
    private int y;
    private Image imageFront;
    private static Image imageBack;

    public Card (int num, CardShape type) {
        this.num = num;
        this.type = type;
        this.front = false;
        String front = "/PNG-cards/" + (this.num + 1) +"_of_"+ this.type.getName() + ".png";
        imageFront = new Image(front);

        String back = "/PNG-cards/back.png";
            imageBack = new Image(back);
    }

    Color getColor() {
        if (isFront()){
            if (getType() == CardShape.HEARTS || getType() == CardShape.DIAMONDS) {
                return Color.red;
            } else {
                return Color.black;
            }
        }
        return Color.yellow;
    }

    void draw (Graphics g) {
        if (isFront()) {
            g.drawImage(imageFront.getBufferedImage(), getX(), getY(), Card.width, Card.height, null);
        }
        else {
            g.drawImage(imageBack.getBufferedImage(), getX(), getY(), Card.width, Card.height, null);
        }
    }

    public boolean isFront() {
        return front;
    }
    public void setFaceup(boolean front) {
        this.front = front;
    }
    int getNum() {
        return num;
    }

    CardShape getType() {
        return type;
    }

    public int getX() {
        return x;
    }
    public void setX(int x) {
        this.x = x;
    }
    public int getY() {
        return y;
    }
    public void setY(int y) {
        this.y = y;
    }
}