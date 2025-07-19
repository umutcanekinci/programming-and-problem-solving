package week4.sudoku;

public class BoardPos {

    private final int row;
    private final int col;

    public BoardPos(int row, int col) {
        this.row = row;
        this.col = col;
    }

    public int getRow() {
        return row;
    }

    public int getCol() {
        return col;
    }

    @Override
    public String toString() {
        return "("+row+"-"+col+")";
    }

    public static void main(String[] args) {
        BoardPos bp = new BoardPos(1,3);

        System.out.println(bp);
    }
}
