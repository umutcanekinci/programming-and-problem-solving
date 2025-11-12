package fileprocessors;

import java.util.List;

/*
 * FilePipeline 
A file processor that contains a list of file processors representing the pipeline of those 
processors. When process(..) method is called with a given input file, it makes the inputfile 
processed with all processors in the list one by one.
 */
public class FilePipeline implements FileProcessor{
    private List<FileProcessor> processors;

    public FilePipeline(List<FileProcessor> processors) {
        this.processors = processors;
    }

    @Override
    public void process(String inputFilePath) {
        processors.forEach(processor -> processor.process(inputFilePath));
    }
}
