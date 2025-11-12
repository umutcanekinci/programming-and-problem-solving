package chess.pieces;

import java.util.List;

import chess.BoardPosition;
import chess.ChessPiece;
import chess.PieceType;

public class Knight extends ChessPiece {
    public Knight(BoardPosition position) {
        super(position, PieceType.KNIGHT);
    }

    @Override
    public boolean canMove(BoardPosition targetPosition, List<ChessPiece> pieces) {
        BoardPosition currentPosition = getPosition();

        List<BoardPosition> knightMoves = currentPosition.getKnightMoves();
        for (BoardPosition move : knightMoves) {
            if (move.isEqual(targetPosition))
                return true;
        }
        return false;
    }
}
