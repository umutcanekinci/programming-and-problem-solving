package main;

import java.util.List;

import exceptions.FilePathNotFoundException;
import fileprocessors.Capitalizer;
import fileprocessors.FilePipeline;
import fileprocessors.FileProcessor;
import fileprocessors.InitialCounter;
import fileprocessors.WordCounter;
import fileprocessors.WordFilter;
import utils.FileSystemUtils;


/*
 * I have done this self-study in last hours, because of that I have not been able to
 * write JUnit tests for the classes, add exceptions, and fix bugs. It can be improved
 * in many ways, but I have tried to implement the requirements as much as possible.
 */
public class Main {
    public static void main(String[] args) {

        try {
            String inputFilePath = FileSystemUtils.chooseFile().getAbsolutePath();
            String outputFilePath = FileSystemUtils.chooseFile().getAbsolutePath();

            List<FileProcessor> processors = List.of(
                new Capitalizer(),
                new InitialCounter(outputFilePath),
                new WordCounter(inputFilePath, outputFilePath),
                new WordFilter(outputFilePath)
            );

            FilePipeline filePipeline = new FilePipeline(processors);
            filePipeline.process(inputFilePath);

        } catch (FilePathNotFoundException e) {
            System.out.println(e);
        }
    }
}
