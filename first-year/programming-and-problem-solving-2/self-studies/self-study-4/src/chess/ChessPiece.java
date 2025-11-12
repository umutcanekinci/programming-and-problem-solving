package chess;

import java.util.List;

public abstract class ChessPiece {

    private BoardPosition position;
    private Color color;
    private PieceType type;

    protected ChessPiece(BoardPosition position, PieceType type) {
        this.position = position;
        this.color = position.getColor();
        this.type = type;
    }

    public abstract boolean canMove(BoardPosition target, List<ChessPiece> pieces);

    //#region Getters

    public BoardPosition getPosition() {
        return position;
    }

    public Color getColor() {
        return color;
    }

    public int getValue() {
        return type.getValue();
    }

    public String toString() {
        return type.toString();
    }

    //endregion
}
