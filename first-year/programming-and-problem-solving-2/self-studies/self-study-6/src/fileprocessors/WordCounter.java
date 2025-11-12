package fileprocessors;

import java.io.IOException;
import java.util.List;
import java.util.logging.Level;

import utils.FileSystemUtils;

/*
 * WordCounter 
A file processor that counts the key in the input file and prints out the number to the output 
file. The key and the path of the outputfile is given in the constructor. 
Example: If the input file contains only the the sentence ”This is a sample input file for testing” 
and the key is “file” then the output file must be the following: 
file:1
 */
public class WordCounter implements FileProcessor{
    private final String key;
    private final String outputPath;

    public WordCounter(String key, String outputPath) {
        this.key = key;
        this.outputPath = outputPath;
    }

    @Override
    public void process(String inputFilePath) {
        
        try {
            List<String> filteredWords = FileSystemUtils.readLines(inputFilePath);
            filteredWords.removeIf(word -> !word.equals(key));
            
            FileSystemUtils.newFile(outputPath);
            FileSystemUtils.writeLine(outputPath, "key: " + filteredWords.size());
        } catch (IOException e) {
            FileSystemUtils.LOGGER.log(Level.SEVERE, "IOException\nThe file with path {0} is corrupted or file connection is broken.", inputFilePath);
        }
    }



}
