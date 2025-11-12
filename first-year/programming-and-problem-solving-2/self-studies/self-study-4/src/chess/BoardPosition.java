package chess;

import java.util.List;

public class BoardPosition {
    private int row;
    private int column;

    public BoardPosition(int row, int column) {
        this.row = row;
        this.column = column;
    }

    public Color getColor() {
        return (row + column) % 2 == 0 ? Color.WHITE : Color.BLACK;
    }

    public String toString() {
        return "(" + row + ", " + column + ")";
    }

    public boolean isEqual(BoardPosition position) {
        return this.row == position.row && this.column == position.column;
    }

    public double getSlope(BoardPosition position) {
        return (double) (this.row - position.row) / (this.column - position.column);
    }

    public boolean isBetween(BoardPosition start, BoardPosition end) {
        return (this.row > Math.min(start.row, end.row) && this.row < Math.max(start.row, end.row)) &&
               (this.column > Math.min(start.column, end.column) && this.column < Math.max(start.column, end.column));
    }

    public boolean isThereAnyPieceBetween(BoardPosition target, List<ChessPiece> pieces) {
        if(this.isEqual(target))
            return true;
        
        double slope = target.getSlope(this);

        for (ChessPiece piece : pieces) {
            BoardPosition piecePosition = piece.getPosition();

            if (piecePosition.isEqual(target) || piecePosition.isEqual(this))
                continue;

            if (getSlope(piecePosition) == slope && piecePosition.isBetween(this, target))
                return true;
        }
        return false;
    }

    public List<BoardPosition> getKnightMoves() {
        return List.of(
            new BoardPosition(row + 2, column + 1),
            new BoardPosition(row + 2, column - 1),
            new BoardPosition(row - 2, column + 1),
            new BoardPosition(row - 2, column - 1),
            new BoardPosition(row + 1, column + 2),
            new BoardPosition(row + 1, column - 2),
            new BoardPosition(row - 1, column + 2),
            new BoardPosition(row - 1, column - 2)
        );
    }

    public int getRow() {
        return row;
    }

    public int getColumn() {
        return column;
    }
}
