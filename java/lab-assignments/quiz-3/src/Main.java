import java.util.logging.Level;
import java.util.logging.Logger;

public class Main {

    private static Logger logger = Logger.getLogger(Main.class.getName());

    private static LibraryAccount[] accounts = new LibraryAccount[] {
        new LibraryAccount(0, "Fikret", 2, 4),
        new LibraryAccount(1, "İfret ", 3, 5),
        new LibraryAccount(2, "Nimet ", 6, 7),
    };

    public static void main(String[] args) {
        System.out.println("ACCOUNTS");
        for (LibraryAccount account : accounts)
            System.out.println(account);
        System.out.println();

        try {
            // Working part
            accounts[0].borrowBook(1);
            accounts[1].returnBook(2);
            accounts[2].transferBooks(accounts[1], 1);
            
            // Negative count exceptions
            //accounts[0].borrowBook(-3);
            //accounts[0].returnBook(-3);

            // Max Limit exception
            //accounts[2].borrowBook(10);

            // Returning more than borrowed books exception
            //accounts[0].returnBook(20);

            // NullException
            //accounts[0].transferBooks(null, 10);
        }
        catch (Exception e) {
            System.out.println("");
            logger.log(Level.SEVERE, e.getMessage());
        }
    }

}
