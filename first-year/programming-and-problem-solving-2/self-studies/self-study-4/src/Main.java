import chess.*;
import chess.pieces.Bishop;
import chess.pieces.King;
import chess.pieces.Knight;
import chess.pieces.Pawn;
import chess.pieces.Queen;
import chess.pieces.Rook;

public class Main {
    public static void main(String[] args) {
        ChessPiece[] pieces = new ChessPiece[] {
                new Rook(new BoardPosition(0, 0)),
                new Knight(new BoardPosition(0, 1)),
                new Bishop(new BoardPosition(0, 2)),
                new Queen(new BoardPosition(0, 3)),
                new King(new BoardPosition(0, 4)),
                new Bishop(new BoardPosition(0, 5)),
                new Knight(new BoardPosition(0, 6)),
                new Rook(new BoardPosition(0, 7)),
                new Pawn(new BoardPosition(1, 0)),
                new Pawn(new BoardPosition(1, 1)),
                new Pawn(new BoardPosition(1, 2)),
                new Pawn(new BoardPosition(1, 3)),
                new Pawn(new BoardPosition(1, 4)),
                new Pawn(new BoardPosition(1, 5)),
                new Pawn(new BoardPosition(1, 6)),
                new Pawn(new BoardPosition(1, 7)),
                new Rook(new BoardPosition(7, 0)),
                new Knight(new BoardPosition(7, 1)),
                new Bishop(new BoardPosition(7, 2)),
                new Queen(new BoardPosition(7, 3)),
                new King(new BoardPosition(7, 4)),
                new Bishop(new BoardPosition(7, 5)),
                new Knight(new BoardPosition(7, 6)),
                new Rook(new BoardPosition(7, 7)),
                new Pawn(new BoardPosition(6, 0)),
                new Pawn(new BoardPosition(6, 1)),
                new Pawn(new BoardPosition(6, 2)),
                new Pawn(new BoardPosition(6, 3)),
                new Pawn(new BoardPosition(6, 4)),
                new Pawn(new BoardPosition(6, 5)),
                new Pawn(new BoardPosition(6, 6)),
                new Pawn(new BoardPosition(6, 7)),
            };
        ChessBoard chessBoard = new ChessBoard();
        for (ChessPiece piece : pieces)
            chessBoard.addPiece(piece);

        System.out.println(chessBoard);
    }
}