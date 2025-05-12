package chess.pieces;

import java.util.List;

import chess.BoardPosition;
import chess.ChessPiece;
import chess.PieceType;

public class Pawn extends ChessPiece {
    public Pawn(BoardPosition position) {
        super(position, PieceType.PAWN);
    }

    @Override
    public boolean canMove(BoardPosition targetPosition, List<ChessPiece> pieces) {
        BoardPosition currentPosition = getPosition();
        if (currentPosition.isEqual(targetPosition))
            return false;

        double slope = Math.abs(targetPosition.getSlope(currentPosition));
        boolean isDiagonalMove = slope == 1;
        boolean isStraightMove = slope == 0;

        if (!isDiagonalMove && !isStraightMove)
            return false;

        if (isStraightMove && currentPosition.isThereAnyPieceBetween(currentPosition, pieces))
            return false;

        return true;
    }
}
