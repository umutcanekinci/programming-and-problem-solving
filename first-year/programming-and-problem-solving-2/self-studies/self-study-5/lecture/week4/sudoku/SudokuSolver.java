package week4.sudoku;

import utils.ConsolUtils;

import java.util.ArrayList;

public class SudokuSolver {

    long branchCount;


    /**
     * TODO: Solves given sudoku board. Returns the solution as a new board object
     *       If there is no solution returns null
     * @param board
     * @return
     */
    public SudokuBoard solve(SudokuBoard board)
    {
        SudokuBoard copy = new SudokuBoard(board);
        branchCount =0;

        boolean solved =  trySolve(copy);

        System.out.println("Branch Count:" + branchCount);
        return solved ? copy:null;
    }

    private boolean trySolve(SudokuBoard board) {
        branchCount++;

        if (!board.isValid())
            return false;
        if (board.isComplete())
            return true;

        BoardPos empty = getFirstEmpty(board);
        if (empty== null)
            return true;

        ArrayList<Integer> candidates = getCandidates(board,empty);

        for (int i = 0; i < candidates.size(); i++) {
            board.put(empty.getRow(),empty.getCol(), candidates.get(i));

            //printBoard(board);
            if (trySolve( board))
                return true;

            board.erase(empty.getRow(),empty.getCol());


        }

        return false;
    }

    private ArrayList<Integer> getCandidates(SudokuBoard board, BoardPos empty) {
        ArrayList<Integer> candidates= new ArrayList<>();

        int[] row = board.getRow(empty.getRow());
        int[] col = board.getColumn(empty.getCol());
        int[] block = board.getBlock( board.getBlockIndex(empty));

        ArrayList<Integer> neighbors = new ArrayList<>();
        collectNeighbors(neighbors, row);
        collectNeighbors(neighbors, col);
        collectNeighbors(neighbors, block);

        for (int i = 1; i <= board.getBoardSize(); i++) {
            if (!neighbors.contains(i))
                candidates.add(i);
        }

        return candidates;
    }

    private void collectNeighbors(ArrayList<Integer> neighbors, int[] arr) {
        for (int i = 0; i < arr.length ; i++) {
            if (arr[i] != SudokuBoard.EMPTYCELL && !neighbors.contains(arr[i]))
                neighbors.add(arr[i]);
        }
    }

    private void printBoard(SudokuBoard board) {
        ConsolUtils.clearScreen();
        System.out.println(board);
        ConsolUtils.pause(200);
    }

    private BoardPos getFirstEmpty(SudokuBoard board) {
        for (int r = 0; r < board.getBoardSize(); r++) {
            for (int c = 0; c < board.getBoardSize(); c++) {
                if (board.isEmpty(r,c))
                    return new BoardPos(r,c);
            }
        }
        return null;
    }


    public static void main(String[] args) {
        SudokuBoard sb = new SudokuBoard(3);
        sb.put(2,6,7);
        sb.put(1,8,1);
        sb.put(1,7,6);
        sb.put(4,5,8);
        sb.put(8,0,9);
        System.out.println(sb);

        SudokuSolver solver = new SudokuSolver();

        SudokuBoard solution = solver.solve(sb);

        System.out.println(solution);





    }
}
