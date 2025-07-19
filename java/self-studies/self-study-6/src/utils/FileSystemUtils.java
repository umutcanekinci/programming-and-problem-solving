package utils;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JFileChooser;

import exceptions.FilePathNotFoundException;

public  class FileSystemUtils {
    public static final String EXTENSION = ".str";
    public static final Logger LOGGER = Logger.getLogger(FileSystemUtils.class.getName());
    private static final String WORD_DELIMITER = " ";

    private FileSystemUtils() {}

    public static File newFile(String path) {
        File file = null;
        try {
            file = new File(path);
            if (file.createNewFile())
                LOGGER.log(Level.SEVERE, "File created: {0}", file.getAbsolutePath());
            else
                LOGGER.log(Level.SEVERE, "File already exists: {0}", file.getAbsolutePath());
        } catch (IOException e) {
            LOGGER.log(Level.SEVERE, "An error occurred while creating the file: {0}", e.getMessage());
        }
        return file;
    }

    public static List<String> readLines(String path) throws IOException {
        /*
            The useage of try-with-resources saves us from closing the resources.
         */
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(path))) {
            return readLinesFromReader(bufferedReader);
        }
    }

    private static List<String> readLinesFromReader(BufferedReader reader) throws IOException {
        List<String> result = new ArrayList<>();
        String line;
        while((line = reader.readLine()) != null)
            result.add(line);
        return result;
    }

    public static void writeLine(String path, String line) throws IOException {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(path))) {
            bufferedWriter.write(line);
        }
    }

    public static void writeLines(String path, List<String> words) throws IOException {
        StringBuilder sb = new StringBuilder();
        words.forEach(word -> sb.append(word).append(WORD_DELIMITER));

        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(path))) {
            bufferedWriter.write(sb.toString());
        }
    }

    public static File chooseFile() throws FilePathNotFoundException {
        JFileChooser chooser = new JFileChooser();
        chooser.setDialogTitle("Choose an .str file.");
        int state = chooser.showOpenDialog(chooser);
        
        switch (state) {
            case JFileChooser.CANCEL_OPTION:
                return null;
        
            case JFileChooser.APPROVE_OPTION:
                return chooser.getSelectedFile();

            case JFileChooser.ERROR_OPTION:
                throw new FilePathNotFoundException();

            default:
                throw new FilePathNotFoundException();
        }

    }

}
