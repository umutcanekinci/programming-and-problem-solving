package chess.pieces;

import java.util.List;

import chess.BoardPosition;
import chess.ChessPiece;
import chess.PieceType;

public class Queen extends ChessPiece {
    public Queen(BoardPosition position) {
        super(position, PieceType.QUEEN);
    }

    @Override
    public boolean canMove(BoardPosition targetPosition, List<ChessPiece> pieces) {
        BoardPosition currentPosition = getPosition();
        if (currentPosition.isEqual(targetPosition))
            return false;

        double slope = Math.abs(targetPosition.getSlope(getPosition()));
        boolean isDiagonal = slope == 1;
        boolean isVertical = slope == 0;
        boolean isHorizontal = Math.abs(slope) == Double.POSITIVE_INFINITY;
        if (!isDiagonal && !isVertical && !isHorizontal)
            return false;

        if(currentPosition.isThereAnyPieceBetween(targetPosition, pieces))
            return false;

        return true;
    }
}
