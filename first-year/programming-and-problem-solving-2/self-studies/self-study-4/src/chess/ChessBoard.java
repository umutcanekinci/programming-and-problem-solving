package chess;
import java.util.ArrayList;
import java.util.List;

public class ChessBoard {
    private static final int SIZE = 8;
    
    enum ANSII {
        WHITE_BACKGROUND("\u001B[47m"),
        BLACK_BACKGROUND("\u001B[40m"),
        WHITE_TEXT("\u001B[37m"),
        BLACK_TEXT("\u001B[30m"),
        RESET("\u001B[0m");

        private final String string;

        ANSII(String string) {
            this.string = string;
        }

        @Override
        public String toString() {
            return string;
        }

        public static String blackOnWhite(String str) {
            return WHITE_BACKGROUND + "" + BLACK_TEXT + str + RESET;
        }

        public static String whiteOnBlack(String str) {
            return BLACK_BACKGROUND + "" + WHITE_TEXT + str + RESET;
        }

    }
    
    private static BoardPosition[] CENTRAL_SQUARES = {  new BoardPosition(3, 3),
                                                        new BoardPosition(4, 3),
                                                        new BoardPosition(3, 4),
                                                        new BoardPosition(4, 4)
    };

    private List<ChessPiece> chessPieces;

    public ChessBoard() {
        chessPieces = new ArrayList<>();
    }

    public void addPiece(ChessPiece piece) {
        if(chessPieces.contains(piece))
            return;
        
        chessPieces.add(piece);
    }

    public int materialAdvantage(Color color) {
        int advantage = 0;

        for (ChessPiece meterial : chessPieces) {
            Color meterialColor = meterial.getColor();

            if(meterialColor == null)
                continue;

            int value = meterial.getValue();
            advantage +=  meterialColor == color ? value : -value;
        }

        return advantage;
    }

    public int attackedBy(BoardPosition position, Color color) {
        int count = 0;
        for (ChessPiece piece : chessPieces) {
            Color pieceColor = piece.getColor();
            if(pieceColor == null || pieceColor != color || !piece.canMove(position, chessPieces))
                continue;

            count++;
        }
        return count;
    }

    public int safety(ChessPiece piece) {
        Color defendingColor = piece.getColor();

        if(defendingColor == null)
            return 0;

        BoardPosition position = piece.getPosition();

        if(position == null)
            return 0;
        
        int safetyPoint = attackedBy(position, defendingColor);

        for(Color color : Color.values()) {
            if(color == defendingColor)
                continue;

            safetyPoint -= attackedBy(position, color);
        }

        return safetyPoint;
    }

    public int centralControl(Color color) {
        int control = 0;
        for (BoardPosition boardPosition : CENTRAL_SQUARES) 
            control += attackedBy(boardPosition, color);
        return control;
    }

    //
    public String toString() {
        StringBuilder sb = new StringBuilder(getLetters());
        for(int row=0; row < SIZE; row++) {
            sb.append("\n");
            sb.append(ANSII.blackOnWhite(" " + (row + 1) + " "));
            for(int column=0; column < SIZE; column++) {
                BoardPosition position = new BoardPosition(row, column);
                Color color = position.getColor();
                ChessPiece piece = getPieceAt(position);
                String content = " " + (piece == null ? " " : piece.toString()) + " ";
                sb.append(color == Color.WHITE ? ANSII.blackOnWhite(content) : ANSII.whiteOnBlack(content));
            }
            sb.append(ANSII.blackOnWhite(" " + (row + 1) + " "));
        }
        
        return sb.append("\n").append(getLetters()).toString();
    }

    private String getLetters() {
        StringBuilder sb = new StringBuilder("   ");
        for(int i=0; i < SIZE; i++) {
            String letter = Character.toString('A' + i);
            sb.append(" ").append(letter).append(" ");
        }
        return ANSII.blackOnWhite(sb.append("   ").toString());
    }

    private ChessPiece getPieceAt(BoardPosition position) {
        for(ChessPiece piece : chessPieces) {
            if(piece == null)
                continue;

            BoardPosition piecePosition = piece.getPosition();
            if(piecePosition == null)
                continue;

            if(piecePosition.isEqual(position)) {
                return piece;
            }
                
        }
        return null;
    }
}
