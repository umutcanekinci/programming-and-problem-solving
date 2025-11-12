package fileprocessors;


/*
    Assume that the input text file will only contain letters of the alphabet and space(‘ ‘) character.   
    
    The process function of the interface does not throw any exception. So the classes above, must handle 
    exceptions themselves and not throw out.  

    Write a Main class for testing your code. Create a text file “sample.txt” and fill the with an arbitrary text 
    data. Use this file as your input file.
    Write a main function create instances of all classes and call process 
    methods of all file processors.
*/
public interface FileProcessor {
    void process(String inputFilePath);
}
