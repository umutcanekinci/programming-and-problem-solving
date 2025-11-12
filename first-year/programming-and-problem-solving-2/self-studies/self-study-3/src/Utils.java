/**
 * Utility class for various helper methods.
 * This class contains methods that can be used across different parts of the application.
 * It is not intended to be instantiated.
 */
public class Utils {


    // Private constructor to prevent instantiation
    private Utils() {
        throw new UnsupportedOperationException("Utility class cannot be instantiated.");
    }
    
    /**
     * Checks if the given number is within the range of 0 (inclusive) to size (exclusive).
     * 
     * @param number The number to check.
     * @param size The upper limit of the range.
     * @return true if the number is within the range, false otherwise.
     */
    public static boolean isIndexInRange(int number, int size) {
        return number >= 0 && number < size;
    }

}
