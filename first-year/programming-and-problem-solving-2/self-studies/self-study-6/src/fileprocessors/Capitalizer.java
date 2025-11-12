package fileprocessors;

import java.io.IOException;
import java.util.List;
import java.util.logging.Level;


import exceptions.FilePathNotFoundException;
import utils.FileSystemUtils;
import utils.StringUtils;

/*
• Capitalizer 
A file processor that copies the content of the inputfile to the output file capitalizing the initial 
letters of each word. The path of the output file will be the same as that of input file and the name of the output file 
is the name of the input file concatenated by “_capitalized”.  
Example: If the input file contains only the the sentence ”This is a sample input file for testing” 
then the content of the output file must be the following: 
This Is A Sample Input File For Testing 

 */
public class Capitalizer implements FileProcessor {

    private static final String OFFSET = "_capitalized";

    @Override
    public void process(String inputFilePath) {
        try {
            List<String> words = FileSystemUtils.readLines(inputFilePath);
            StringUtils.capitalizeAll(words);

            String outputPath = StringUtils.replaceExtension(inputFilePath, OFFSET + FileSystemUtils.EXTENSION);
            FileSystemUtils.newFile(outputPath);
            FileSystemUtils.writeLines(inputFilePath, words);
        }
        catch(IOException exception) {
            FileSystemUtils.LOGGER.log(Level.SEVERE, "IOException\nThe file with path {0} is corrupted or file connection is broken.", inputFilePath);
        }
        catch (FilePathNotFoundException exception) {
            FileSystemUtils.LOGGER.log(Level.SEVERE, "Invalid file path: {0}", inputFilePath);
        }
    }
}
