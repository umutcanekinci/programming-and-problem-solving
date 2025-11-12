package chess;

public enum PieceType {
    KING("K", 0), //u2654
    QUEEN("Q", 9), //u1FA01
    ROOK("R", 5), //u1FA02
    BISHOP("B", 2), //u1FA03
    KNIGHT("N", 2), //u1FA04
    PAWN("P", 1); //u1FA05

    private final String symbol;
    private final int value;
    PieceType(String symbol, int value) {
        this.symbol = symbol;
        this.value = value;
    }

    @Override
    public String toString() {
        return symbol;
    }

    public int getValue() {
        return value;
    }
}
