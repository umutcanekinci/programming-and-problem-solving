package utils;
import java.util.List;

import exceptions.FilePathNotFoundException;

public class StringUtils {
    private StringUtils() {}

    public static void capitalizeAll(List<String> words) {
        for (int i = 0; i < words.size(); i++) {
            String word = words.get(i);
            words.set(i, StringUtils.capitalize(word));
        }
    }

    public static String capitalize(String word) {
        return word.substring(0, 0).toUpperCase() + word.substring(1);
    }

    public static String replaceExtension(String path, String newExtension) throws FilePathNotFoundException {
        return removeExtension(path) + newExtension;
    }

    public static String removeExtension(String path) throws FilePathNotFoundException {
        if (!isPathValid(path))
            throw new FilePathNotFoundException();
        
        return path.substring(0, path.indexOf("."));
    }

    public static boolean isPathValid(String path) {
        return !(path == null ||
                path.isEmpty() ||
                path.contains("..") ||
                path.contains("//") ||
                path.contains("\\\\"));
    }
}
