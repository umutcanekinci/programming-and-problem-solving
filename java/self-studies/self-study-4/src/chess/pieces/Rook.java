package chess.pieces;

import java.util.List;

import chess.BoardPosition;
import chess.ChessPiece;
import chess.PieceType;

public class Rook extends ChessPiece {
    public Rook(BoardPosition position) {
        super(position, PieceType.ROOK);
    }

    @Override
    public boolean canMove(BoardPosition targetPosition, List<ChessPiece> pieces) {
        BoardPosition currentPosition = getPosition();
        if (currentPosition.isEqual(targetPosition))
            return false;

        double slope = targetPosition.getSlope(currentPosition);
        boolean isVertical = slope == 0;
        boolean isHorizontal = Math.abs(slope) == Double.POSITIVE_INFINITY;
        
        if (!isVertical && !isHorizontal)
            return false;
        
        if(currentPosition.isThereAnyPieceBetween(currentPosition, pieces))
            return false;
        
        return true;   
    }
}
