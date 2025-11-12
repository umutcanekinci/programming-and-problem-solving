package week4.sudoku;

/**
 * TODO: Represent a Sudoku Board with a class
 */
public class SudokuBoard {

    static final int DEFAULT_BOARD_SIZE = 9;
    public static final int EMPTYCELL = 0;

    private final int[][] board;
    private final int boardSize;
    private final int blockSize;

    SudokuBoard(int blockSize)
    {
        this.blockSize = blockSize;
        boardSize = blockSize*blockSize;

        board = new int[boardSize][boardSize];
    }


    SudokuBoard( SudokuBoard other)
    {
        this(other.blockSize);

        for (int r = 0; r < boardSize; r++) {
            for (int c = 0; c < boardSize; c++) {
                board[r][c] = other.board[r][c];
            }
        }
    }

    /**
     * !This is a dangerous getter
     * !as it returns the reference to your private data
     * @return
     */
    public int[][] getBoard() {
        return board;
    }

    public int getBlockIndex(BoardPos bp)
    {
        return getBlockIndex(bp.getRow(), bp.getCol());
    }
    public int getBlockIndex(int r, int c)
    {
        return (r/blockSize)*blockSize + (c/blockSize)%blockSize
;   }

    public int get(int row, int col)
    {
        return board[row][col];
    }

    public int getBoardSize() {
        return boardSize;
    }

    public int getBlockSize() {
        return blockSize;
    }

    public void put(int r, int c, int v)
    {
        board[r][c] = v;
    }

    public void erase(int r, int c)
    {
        put(r,c, EMPTYCELL);
    }

    public String toString()
    {
        String st = "";

        st  += drawBoardLine() + "\n";

        for (int r = 0; r < boardSize; r++) {

            st += rowToString(r);
            st += "\n";
            if (r % blockSize == blockSize-1)
                st += drawBoardLine() + "\n";
        }

        return st;

    }

    private String rowToString(int r) {
        String st = "| ";
        for (int c = 0; c < boardSize; c++) {
            st += cellToString(r,c);
            if (c % blockSize == blockSize-1)
                st += "| ";
        }

        return st;
    }

    private String cellToString(int r, int c) {
        return board[r][c] == EMPTYCELL ? ". ": ""+ board[r][c] + " ";
    }

    private String drawBoardLine() {
        String st= "";
        int width = 2* (boardSize + blockSize) + 1;
        for (int i = 0; i < width; i++) {
            st += "-";
        }
        return st;
    }

    public boolean isEmpty(int r, int c)
    {
        return board[r][c]== EMPTYCELL;

    }



        public boolean isEmpty()
    {
        for (int r = 0; r < boardSize; r++) {
            for (int c = 0; c < boardSize; c++) {
                if (!isEmpty(r,c))
                    return false;
            }
        }

        return true;
    }

    public boolean isComplete()
    {
        for (int r = 0; r < boardSize; r++) {
            for (int c = 0; c < boardSize; c++) {
                if (board[r][c]== EMPTYCELL)
                    return false;
            }
        }

        return true;
    }

    public boolean isValid()
    {
        return isValidRows() && isValidCols() && isValidBlocks();
    }

    private boolean isValidRows() {

        for (int r = 0; r < boardSize; r++) {
            if ( ! isValidRow(r))
                return false;
        }
        return true;
    }

    public int[] getRow(int r)
    {
        return board[r];
    }
    
    private boolean isValidRow(int r) {
        int[] arr = getRow(r);
        return isValidArray(arr);
    }

    private boolean isValidArray(int[] arr) {

        int[] counts = new int[boardSize+1];

        for (int i = 0; i < arr.length; i++) {
            if (arr[i]== EMPTYCELL)
                continue;

            if ( arr[i]<0 ||  arr[i]>boardSize)
                return false;

            counts[  arr[i] ]++;

            if (counts[arr[i]]>= 2)
                return false;
        }
        return true;
    }

    private boolean isValidCols() {

        for (int c = 0; c < boardSize; c++) {
            if ( ! isValidCol(c))
                return false;
        }
        return true;
    }

    private boolean isValidCol(int c) {

        int[] arr = getColumn(c);
        return isValidArray(arr);
    }

    public int[] getColumn(int c) {
        int[] arr = new int[boardSize];

        for (int r = 0; r < boardSize; r++) {
            arr[r] = board[r][c];
        }
        return arr;
    }

    private boolean isValidBlocks() {

        for (int b = 0; b < boardSize; b++) {
            if ( ! isValidBlock(b))
                return false;
        }
        return true;
    }

    private boolean isValidBlock(int b) {
        int[] arr = getBlock(b);

        return isValidArray(arr);
    }

    public int[] getBlock(int b) {
        int[] arr = new int[boardSize];
        int count =0;
        int sr = (b/blockSize) * blockSize;
        int sc = (b%blockSize) *blockSize;
        for (int r = 0; r < blockSize; r++) {
            for (int c = 0; c < blockSize; c++) {
                arr[count++] = board[sr + r] [ sc + c];
            }
        }
        return arr;
    }

    public boolean isSolved()
    {
        return isComplete() && isValid();
    }

    public static void main(String[] args) {
        SudokuBoard sb = new SudokuBoard(3);
        sb.put(2,6,7);
        sb.put(1,8,1);
        sb.put(1,7,1);
        sb.put(4,5,8);
        System.out.println(sb);

        System.out.println("Valid:" + sb.isValid());
    }

    /**
     * The string representation of the board is as follows:
     * -------------------------
     * | 0 1 0 | 0 0 0 | 0 5 0 |
     * | 0 0 0 | 0 3 0 | 0 0 0 |
     * | 2 0 0 | 0 0 0 | 0 0 0 |
     * -------------------------
     * | 0 0 0 | 0 0 0 | 0 0 0 |
     * | 0 5 0 | 0 0 0 | 0 0 0 |
     * | 0 0 0 | 0 0 0 | 0 0 0 |
     * -------------------------
     * | 0 0 0 | 0 0 9 | 0 0 0 |
     * | 0 0 0 | 0 0 0 | 0 1 0 |
     * | 0 0 7 | 0 8 0 | 0 0 0 |
     * -------------------------
     */

}
