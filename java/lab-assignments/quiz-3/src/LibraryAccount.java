public class LibraryAccount {
    private int accountId;
    private String holderName;
    private int borrowedBooks;
    private int maxBookAllowed;

    public LibraryAccount(int accountId, String holderName, int borrowedBooks, int maxBookAllowed) {
        this.accountId = accountId;
        this.holderName = holderName;
        this.borrowedBooks = borrowedBooks;
        this.maxBookAllowed = maxBookAllowed;
    }

    public int getAccountId() {
        return accountId;
    }

    public int getBorrowedBooks() {
        return borrowedBooks;
    }

    public String getHolderName() {
        return holderName;
    }

    public int getMaxBookAllowed() {
        return maxBookAllowed;
    }    

    public void borrowBook(int count) throws InvalidBookOperatorException, BookLimitException {
        if (count < 0)
            throw new InvalidBookOperatorException("You can't borrow negative(" + count + ") books.");

        if (borrowedBooks + count > maxBookAllowed)
            throw new BookLimitException("You cannot borrow " + count + " books and have total " + (count + borrowedBooks) + " books. \nYou can only borrow " + maxBookAllowed + " books at the same time, so you can borrow max " + (maxBookAllowed - borrowedBooks) + " now.");

        // if (borrowedBooks + count < 0)
        //     throw new InvalidBookOperatorException("You can't have negative borrowed books in total.");

        borrowedBooks += count;
        System.out.println("After borrow " + count + " book: " + this);
    }

    public void returnBook(int count) throws InvalidBookOperatorException {
        if (count < 0)
            throw new InvalidBookOperatorException("You cannot return negative count(" + count + ") books.");

        if (borrowedBooks - count < 0)
            throw new InvalidBookOperatorException("You cannot return " + count + " books, you have taken " + borrowedBooks + " before.");

        borrowedBooks -= count;
        System.out.println("After return " + count + " book: " + this);
    }

    public void transferBooks(LibraryAccount target, int count) throws InvalidBookOperatorException, BookLimitException, NullPointerException {
        if (target == null)
            throw new NullPointerException("Target library account cannot be null!");

        returnBook(count);
        target.borrowBook(count);
    }

    @Override
    public String toString() {
        return "[" + accountId + "] " + holderName + " " + borrowedBooks + "/" + maxBookAllowed;
    }
}
