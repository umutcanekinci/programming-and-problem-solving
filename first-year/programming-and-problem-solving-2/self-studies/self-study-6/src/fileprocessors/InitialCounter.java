package fileprocessors;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;

import utils.FileSystemUtils;

/*
 * InitialCounter   
A file processor that counts the words starting with each letter. 
Reads the input file and writes the number of words starting with each letter to an output file. 
The path f the output file is given in the constructor. You will omit the letters of zero occurrences.   
Example: If the input file contains only the the sentence ”This is a sample input file for testing” 
then the output file must be the following:  
A:1 
F:2 
I:2 
S:1 T:2
 */
public class InitialCounter implements FileProcessor {

    private static final char[] ALPHABET = "abcdefghijklmnopqrstuvwxyz".toCharArray();

    private final String outputPath;

    public InitialCounter(String outputPath) {
        this.outputPath = outputPath;
    }

    @Override
    public void process(String inputFilePath) {
        try {
            List<String> words = FileSystemUtils.readLines(inputFilePath);
            StringBuilder counts = new StringBuilder();
            for (int i = 0; i < ALPHABET.length; i++) {
                String letter = Character.toString(ALPHABET[i]);
                List<String> filteredWords = new ArrayList<>(words);
                filteredWords.removeIf(word -> !word.startsWith(letter));
                counts.append(letter).append(": ").append(filteredWords.size());
            }
        
            FileSystemUtils.newFile(outputPath);
            FileSystemUtils.writeLine(outputPath, counts.toString());
        } catch (IOException e) {
            FileSystemUtils.LOGGER.log(Level.SEVERE, "IOException\nThe file with path {0} is corrupted or file connection is broken.", inputFilePath);
        }
    }

}
