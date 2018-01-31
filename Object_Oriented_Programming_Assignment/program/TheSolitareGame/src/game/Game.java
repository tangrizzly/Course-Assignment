package game; /**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

import card.*;

import java.util.ArrayList;
import java.util.Random;

class Game {
    private static final ArrayList<Card> allCard;
    static final CardPile[] allPiles;
    private static final DeckPile deckPile;
    private static final DiscardPile discardPile;
    private static final TablePile[] tablePile;
    private static final SuitPile[] suitPile;
    static final MoveCardPile moveCard;

    static {
        allCard = new ArrayList<Card>();
        for (int i = 0; i < 4; i++) {
            Card.CardShape type = Card.CardShape.fromInteger(i);
            for (int j = 0; j <= 12; j++) {
                allCard.add(new Card(j, type));
            }
        }
        Random generator = new Random();
        for (int i = 0; i < 52; i++) {
            int j = Math.abs(generator.nextInt() % 52);
            // swap the two card values
            Card temp = allCard.get(i);
            allCard.set(i, allCard.get(j));
            allCard.set(j, temp);
        }

        allPiles = new CardPile[13];
        suitPile = new SuitPile[4];
        tablePile = new TablePile[7];

        allPiles[0] = deckPile = new DeckPile(50, 40);
        allPiles[1] = discardPile = new DiscardPile(50 + Card.width + 30, 40);
        for (int i = 0; i < 4; i++) {
            allPiles[2 + i] = suitPile[i] =
                    new SuitPile(50 + Card.width + 30 + Card.width + 100 + (30 + Card.width) * i, 40);
        }
        for (int i = 0; i < 7; i++) {
            allPiles[6 + i] = tablePile[i] =
                    new TablePile(38 + (25 + Card.width) * i, 40 + Card.height + 40, i);
        }
        for (int i = 0; i < 7; i++) {
            ArrayList<Card> al = new ArrayList<Card>();
            for (int j = 0; j < tablePile[i].getCardNum(); j++) {
                al.add(allCard.remove(allCard.size() - 1));
            }
            tablePile[i].addCard(al);
            tablePile[i].setCardNum(tablePile[i].getNotFlipNum() + 1);
            tablePile[i].top().setFaceup(true);
        }
        int rest = allCard.size();
        for (int i = 0; i < rest; i++) {
            deckPile.addCard(allCard.remove(allCard.size() - 1));
        }
        moveCard = new MoveCardPile();
    }

    private static void transferFromDiscardToDeck() {
        while (!(discardPile.isEmpty())) {
            Card card = discardPile.pop();
            card.setFaceup(false);
            deckPile.addCard(card);

        }
    }

    static boolean testDeckPile(int x, int y) {
        int selectNum = deckPile.select(x, y);
        if (selectNum >= 0) {
            discardPile.addCard(deckPile.pop());
            return true;
        } else if (selectNum == -2) {
            Game.transferFromDiscardToDeck();
            return true;
        } else {
            return false;
        }
    }

    static boolean testDisCardPile(int x, int y) {
        int selectNum = discardPile.select(x, y);
        if (selectNum >= 0) {
            moveCard.clear();
            moveCard.addCard(discardPile.pop());
            moveCard.setFromPile(discardPile, true);
            return true;
        } else if (selectNum == -2) {
        } else {
        }
        return false;
    }

    static boolean testTablePile(int x, int y) {
        boolean isDrag = false;
        for (int i = 0; i < tablePile.length; i++) {
            int selectNum = tablePile[i].select(x, y);
            if (selectNum >= 0) {
                moveCard.clear();
                int num = tablePile[i].getCardNum();
                for (int j = selectNum; j < num; j++) {
                    moveCard.addCard(tablePile[i].pop());
                }
                moveCard.setFromPile(tablePile[i], tablePile[i].getNotFlipNum());
                return true;
            }
        }
        return isDrag;
    }

    static boolean isCanAddToSuitPile(int x, int y) {
        if (moveCard.size() == 1) {
            for (int i = 0; i < 4; i++) {
                if (suitPile[i].includes(x, y)) {
                    if (suitPile[i].isCanAdd(moveCard.getCard())) {
                        suitPile[i].addCard(moveCard.removeCard());
                        return true;
                    }
                }
            }
        }
        return false;
    }

    static boolean isWin() {
        for (int i = 0; i < 4; i++) {
            if (suitPile[i].getSize() != 13) {
                return false;
            }
        }
        return true;
    }


    static boolean isCanAddToSuitPile() {
        if (moveCard.size() == 1) {
            for (int i = 0; i < 4; i++) {
                if (suitPile[i].isCanAdd(moveCard.getCard())) {
                    suitPile[i].addCard(moveCard.removeCard());
                    return true;
                }
            }
        }
        return false;
    }

    static boolean isCanAddtoTablePile(int x, int y) {
        for (int i = 0; i < 7; i++) {
            if (tablePile[i].includes(x, y)) {
                if (tablePile[i].hashCode() != moveCard.getFromPile().hashCode()) {
                    if (tablePile[i].isCanAdd(moveCard.getCard())) {
                        tablePile[i].addCard(moveCard.clear());
                        return true;
                    }
                }

            }
        }
        return false;
    }

    static void refreshTablePile() {
        for (int i = 0; i < 7; i++) {
            if (tablePile[i].top() != null) {
                if (!(tablePile[i].top().isFront())) {
                    tablePile[i].top().setFaceup(true);
                    tablePile[i].setNotFlipNum(tablePile[i].getNotFlipNum() - 1);
                }
            }
        }
    }

    static void returnToFromPile() {
        if (moveCard.getFromPile() != null) {
            if (moveCard.getFromPile().hashCode() == discardPile.hashCode()) {
                while (!(moveCard.isEmpty())) {
                    moveCard.getFromPile().addCard(moveCard.removeCard());
                }
            } else {
                moveCard.getFromPile().addCard(moveCard.clear());
            }
        }
    }
}
