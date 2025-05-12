package chess.pieces;

import java.util.List;

import chess.BoardPosition;
import chess.ChessPiece;
import chess.PieceType;

public class King extends ChessPiece {
    public King(BoardPosition position) {
        super(position, PieceType.KING);
    }

    @Override
    public boolean canMove(BoardPosition position, List<ChessPiece> pieces) {
        // Check if the move is within one square in any direction
        int deltaX = Math.abs(position.getColumn() - this.getPosition().getColumn());
        int deltaY = Math.abs(position.getRow() - this.getPosition().getRow());

        if (deltaX <= 1 && deltaY <= 1) {
            // Check if the target position is occupied by a friendly piece
            for (ChessPiece piece : pieces) {
                if (piece.getPosition().equals(position) && piece.getColor() == this.getColor()) {
                    return false; // Cannot move to a position occupied by a friendly piece
                }
            }
            return true; // Valid move
        }
        return false; // Invalid move
    }
}
