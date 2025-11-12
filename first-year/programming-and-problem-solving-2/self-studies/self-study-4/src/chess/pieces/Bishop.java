package chess.pieces;

import java.util.List;

import chess.BoardPosition;
import chess.ChessPiece;
import chess.PieceType;

public class Bishop extends ChessPiece {
    public Bishop(BoardPosition position) {
        super(position, PieceType.BISHOP);
    }

    @Override
    public boolean canMove(BoardPosition targetPosition, List<ChessPiece> pieces) {
        BoardPosition currentPosition = getPosition();
        if (currentPosition.isEqual(targetPosition))
            return false;

        double slope = Math.abs(targetPosition.getSlope(getPosition()));
        boolean isDiagonal = slope == 1;
        if (!isDiagonal)
            return false;

        if(currentPosition.isThereAnyPieceBetween(targetPosition, pieces))
            return false;

        return true;
    }
}
