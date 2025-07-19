package week11.utils;

import java.io.Console;
import java.io.IOException;

public class ConsolUtils {

    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLACK = "\u001B[30m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_WHITE = "\u001B[37m";

    public static final String BLACK_BOLD_BRIGHT = "\033[1;90m"; // BLACK
    public static final String RED_BOLD_BRIGHT = "\033[1;91m";   // RED
    public static final String GREEN_BOLD_BRIGHT = "\033[1;92m"; // GREEN
    public static final String YELLOW_BOLD_BRIGHT = "\033[1;93m";// YELLOW
    public static final String BLUE_BOLD_BRIGHT = "\033[1;94m";  // BLUE
    public static final String PURPLE_BOLD_BRIGHT = "\033[1;95m";// PURPLE
    public static final String CYAN_BOLD_BRIGHT = "\033[1;96m";  // CYAN
    public static final String WHITE_BOLD_BRIGHT = "\033[1;97m"; // WHITE

    /**
     * pause the program for a given amount of time
     * @param millisecond
     */
    public static void pause(long millisecond)
    {
        try {
            Thread.sleep(millisecond);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * clears the screen
     */
    public static void clearScreen()
    {
        try {
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public  static String colorize(String text, String color)
    {
        return color + text + ANSI_RESET;
    }

    public static void print(String text, Color color)
    {
        System.out.print(colorize(text,color.toString()));
    }
    public static void println(String text, Color color)
    {
        System.out.println(colorize(text,color.toString()));
    }


    public static void waitForEnter() {
        Console c = System.console();
        if (c != null) {
            c.format("\n\n\nPress ENTER to proceed.\n");
            c.readLine();
        }
    }

    public static String line(int len) {
        String line ="";
        for (int i = 0; i < len; i++) {
            line += "-";
        }
        return line;
    }
}
