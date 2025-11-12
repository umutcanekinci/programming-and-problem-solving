import java.util.Random;

/**
 * The TentsPuzzle class represents a puzzle game where tents must be placed adjacent to trees
 * on a grid while adhering to specific rules. The puzzle ensures that no two tents are adjacent
 * and that each tree has at most one tent adjacent to it.
 * 
 * @version 1.0
 */
public class TentsPuzzle {

    public static final Random random = new Random();
    private final int puzzleSize;
    private final int[][] board;

    /**
     * Enum representing the different types of tiles in the puzzle.
     * Each tile has a value and a string representation.
     */
    private enum Tile {
        EMPTY(0, "."),
        TREE(1, "Y"),
        TENT(2, "*");

        int value;
        String string;

        Tile(int value, String string) {
            this.value = value;
            this.string = string;
        }

        public static Tile intToTile(int value) {
            for(Tile tile : Tile.values()) {
                if(tile.value == value)
                    return tile;
            }
            return null;
        }

        public int getValue() {
            return value;
        }

        @Override
        public String toString() {
            return string;
        }
    }

    /**
     * Constructs a TentsPuzzle with the specified puzzle size.
     * 
     * @param puzzleSize The size of the puzzle grid. Must be greater than 1.
     * @throws IllegalArgumentException if the puzzle size is less than or equal to 1.
    */
    public TentsPuzzle(int puzzleSize) {
        if(puzzleSize <= 1)
            throw new IllegalArgumentException("N can't be smaller than 2.");

        this.puzzleSize = puzzleSize;
        board = new int[puzzleSize+1][puzzleSize+1];
    }

    /**
     * Places a the given value at the specified row and column in the puzzle.
     * 
     * @param value The value to place in the puzzle.
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     */
    private void put(int row, int col, int value) {
        if(!Utils.isIndexInRange(row, puzzleSize + 1) && !Utils.isIndexInRange(col, puzzleSize + 1))
            throw new IndexOutOfBoundsException("row and col values should be in the puzzle.");

        board[row][col] = value;
    }

    /**
     * Places a tree at the specified row and column in the puzzle.
     * 
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     */
    public void putTree(int row, int col) {
        put(row+1, col+1, Tile.TREE.getValue());
    }

    /**
     * Places a tent at the specified row and column in the puzzle.
     * 
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     */
    public void putTent(int row, int col) {
        put(row+1, col+1, Tile.TENT.getValue());
        board[0][col+1] += 1;
        board[row+1][0] += 1;
    }

    /**
     * Clears the tile at the specified row and column in the puzzle.
     * 
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     */
    public void clear(int row, int col) {
        put(row, col, Tile.EMPTY.getValue());
    }

    /**
     * Gets the tile at the specified row and column in the puzzle.
     * 
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     * @return The tile at the specified position, or null if out of bounds.
     */
    private Tile get(int row, int col) {
        if(!Utils.isIndexInRange(row, puzzleSize) || !Utils.isIndexInRange(col, puzzleSize))
            return null;

        return Tile.intToTile(board[row+1][col+1]);
    }
    
    /**
     * @return a string representation of the puzzle grid.
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for(int r = 0; r < puzzleSize + 1; r++)
            sb.append(getRow(r)).append("\n");
        return sb.toString();
    }

    /**
     * Gets the row string representation of the puzzle grid.
     * 
     * @param r The row index (0-based).
     * @return The string representation of the row.
     */
    private String getRow(int r) {
        int[] row = board[r];
        StringBuilder sb = new StringBuilder("");

        if(r == 0) { // Horizontal Line
            sb.append("  |"); // Vertical line
            for(int c = 1; c < puzzleSize + 1; c++) {
                int value = row[c];
                sb.append(" ").append(value);
            }
            sb.append("\n").append("───").append("──".repeat(puzzleSize));
            return sb.toString();
        }
        
        sb.append(row[0]).append(" |"); // Vertical line
        for(int c = 1; c < puzzleSize + 1; c++) {
            int value = row[c];
            sb.append(" ").append(Tile.intToTile(value));
        }

        return sb.toString();
    }
    
    /**
     * Checks if the puzzle is valid according to the game rules.
     * 
     * @return true if the puzzle is valid, false otherwise.
     */
    private boolean isValid() {
        // Check if tends are touching or not
        for(int r=0; r<puzzleSize; r++) {
            for(int c=0; c<puzzleSize; c++) {
                Tile tile = get(r, c);
                boolean isNotValidTent = tile == Tile.TENT && hasTentNeighbour(r, c);
                boolean isNotValidTree = tile == Tile.TREE && hasTwoTendNeighbours(r, c);

                if(isNotValidTent || isNotValidTree)
                    return false;
            }
        }
        return true;
    }

    /**
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     * @return true if there are two tents adjacent to the tile, false otherwise.
     */
    private boolean hasTentNeighbour(int row, int col) {
        for(Tile tile : getNeighbours(row, col)) {
            if(tile == Tile.TENT)
                return true;
        }
        return false;
    }

    /**
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     * @return true if there are two tents adjacent to the tile, false otherwise.
     */
    private boolean hasTwoTendNeighbours(int row, int col) {
        boolean hasFirstTendNeighbourFound = false;
        for(Tile tile : getNeighbours(row, col)) {
            if(tile == Tile.TENT) {
                if(hasFirstTendNeighbourFound)
                    return true;
                hasFirstTendNeighbourFound = true;
            }
        }
        return false;
    }

    /**
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     * @return An array of neighbouring tiles.
     */
    private Tile[] getNeighbours(int row, int col) {
        return new Tile[] {
            get(row-1, col)  , // top
            get(row-1, col-1), // topleft
            get(row-1, col+1), // topright
            get(row+1, col)  , // bot
            get(row+1, col-1), // botleft
            get(row+1, col+1), // botright
            get(row  , col-1), // left
            get(row  , col+1), // right
        };
    }

    /**
     * Fills the puzzle with random tents.
     * 
     * @param n The number of tents to fill.
     */
    private void fillRandom(int n) {
        for(int i=0; i<n; i++) {
            int r = random.nextInt(puzzleSize);
            int c = random.nextInt(puzzleSize);
            
            if(get(r, c) != Tile.EMPTY) 
                fillRandom(1);
            else
                putTent(r, c);
        }
    }

    /**
     * Main method for testing the TentsPuzzle class.
     *  
     * @param args Command-line arguments (not used).
     */
    public static void main(String[] args) {
        TentsPuzzle puzzle = new TentsPuzzle(5);
        puzzle.fillRandom(3);
        System.out.println(puzzle);
        System.out.println("The puzzle is " + (puzzle.isValid() ? "Valid" : "Invalid"));

        puzzle.putTree(3, 1);
        puzzle.putTree(3, 2);
        System.out.println(puzzle);
        System.out.println("The puzzle is " + (puzzle.isValid() ? "Valid" : "Invalid"));


    }

}
