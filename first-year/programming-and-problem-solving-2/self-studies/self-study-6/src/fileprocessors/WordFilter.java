package fileprocessors;

import java.io.IOException;
import java.util.List;
import java.util.logging.Level;

import exceptions.FilePathNotFoundException;
import utils.FileSystemUtils;
import utils.StringUtils;

/*
 * WordFilter 
A file processor that copies the content of the inputfile to the output file except the 
occurrences of the given key. All occurrences of the key must be removed in the output file. The path of the output file will be the same as that of input file and the name of the output file 
is the name of the input file concatenated by “_filetered”. The key is given in constructor 
Example: If the input file contains only the the sentence ”This is a sample input file for testing” 
and the key is “file” then the content of the output file must be the following: 
This is a sample input for testing 
 
 */
public class WordFilter implements FileProcessor {
    private static final String OFFSET = "_filtered";

    private final String key;

    public WordFilter(String key) {
        this.key = key;
    }

    @Override
    public void process(String inputFilePath) {
        try {
            List<String> filteredWords = FileSystemUtils.readLines(inputFilePath);
            filteredWords.removeIf(word -> word.equals(key));
            
            String outputPath = StringUtils.replaceExtension(inputFilePath, OFFSET + FileSystemUtils.EXTENSION);
            FileSystemUtils.newFile(outputPath);

            FileSystemUtils.writeLine(outputPath, "key: " + filteredWords.size());
        } catch (IOException e) {
            FileSystemUtils.LOGGER.log(Level.SEVERE, "IOException\nThe file with path {0} is corrupted or file connection is broken.", inputFilePath);
        } catch (FilePathNotFoundException e) {
            FileSystemUtils.LOGGER.log(Level.SEVERE, "Invalid file path: {0}", inputFilePath);
        }        
    }

}
