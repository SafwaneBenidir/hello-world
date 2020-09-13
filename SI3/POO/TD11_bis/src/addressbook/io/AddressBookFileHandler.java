package addressbook.io;

import java.io.*;
import java.net.URISyntaxException;
import java.net.URL;

/**
 * Provide a range of file-handling operations on an AddressBook. These methods
 * demonstrate a range of basic features of the java.io package.
 * 
 * @author David J. Barnes and Michael Kölling.
 * @version 2016.02.29
 */
class AddressBookFileHandler {
    // The address book on which i/o operations are performed.
    private AddressBook book;
    // The name of a file used to store search results.
    private static final String RESULTS_FILE = "results.txt";

    /**
     * Constructor for objects of class FileHandler.
     * 
     * @param book
     *            The address book to use.
     */
    AddressBookFileHandler(AddressBook book) {
        this.book = book;
    }

    /**
     * Save the results of an address-book search to the file "results.txt" in
     * the project folder.
     * 
     * @param keyPrefix
     *            The key prefix to search on.
     */
    void saveSearchResults(String keyPrefix) throws IOException {
        File resultsFile = makeAbsoluteFilename(RESULTS_FILE);
        ContactDetails[] results = book.search(keyPrefix);
        FileWriter writer = new FileWriter(resultsFile);
        for (ContactDetails details : results) {
            writer.write(details.toString());
            writer.write('\n');
            writer.write('\n');
        }
        writer.close();
    }

    /**
     * Show the results from the most-recent call to saveSearchResults. As
     * output is to the console, any problems are reported directly by this
     * method.
     */
    void showSearchResults() {
        BufferedReader reader = null;
        try {
            File resultsFile = makeAbsoluteFilename(RESULTS_FILE);
            reader = new BufferedReader(new FileReader(resultsFile));
            System.out.println("Results ...");
            String line;
            line = reader.readLine();
            while (line != null) {
                System.out.println(line);
                line = reader.readLine();
            }
            System.out.println();
        } catch (FileNotFoundException e) {
            System.out.println("Unable to find the file: " + RESULTS_FILE);
        } catch (IOException e) {
            System.out.println("Error encountered reading the file: "
                    + RESULTS_FILE);
        } finally {
            if (reader != null) {
                // Catch any exception, but nothing can be done
                // about it.
                try {
                    reader.close();
                } catch (IOException e) {
                    System.out.println("Error on closing: " + RESULTS_FILE);
                }
            }
        }
    }

    /**
     * Add further entries to the address book, from a text file. The file is
     * assumed to contain one element per line, plus a blank line, for each
     * entry: name \n phone \n address \n \n A line may be blank if that part of
     * the details is missing.
     * 
     * @param filename
     *            The text file containing the details.
     * @throws IOException
     *             On input failure.
     */
    void addEntriesFromFile(String filename) throws IOException {
        // Make sure the file can be found.
        URL resource = getClass().getResource(filename);
        if (resource == null) {
            throw new FileNotFoundException(filename);
        }
        filename = resource.getFile();
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        String name;
        name = reader.readLine();
        while (name != null) {
            String phone = reader.readLine();
            String address = reader.readLine();
            // Discard the separating blank line.
            reader.readLine();
            book.addDetails(new ContactDetails(name, phone, address));
            name = reader.readLine();
        }
        reader.close();
    }

    /**
     * Read the binary version of an address book from the given file. If the
     * file name is not an absolute path, then it is assumed to be relative to
     * the current project folder.
     * 
     * @param sourceFile
     *            The file from where the details are to be read.
     * @return The address book object.
     * @throws IOException
     *             If the reading process fails for any reason.
     */
    AddressBook readFromFile(String sourceFile) throws IOException,
            ClassNotFoundException {
        // Make sure the file can be found.
        URL resource = getClass().getResource(sourceFile);
        if (resource == null) {
            throw new FileNotFoundException(sourceFile);
        }
        try {
            File source = new File(resource.toURI());
            ObjectInputStream is = new ObjectInputStream(new FileInputStream(
                    source));
            AddressBook savedBook = (AddressBook) is.readObject();
            is.close();
            return savedBook;
        } catch (URISyntaxException e) {
            throw new IOException("Unable to make a valid filename for "
                    + sourceFile);
        }
    }

    /**
     * Save a binary version of the address book to the given file. If the file
     * name is not an absolute path, then it is assumed to be relative to the
     * current project folder.
     * 
     * @param destinationFile
     *            The file where the details are to be saved.
     * @throws IOException
     *             If the saving process fails for any reason.
     */
    void saveToFile(String destinationFile) throws IOException {
        File destination = makeAbsoluteFilename(destinationFile);
        ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(
                destination));
        os.writeObject(book);
        os.close();
    }

    /**
     * Create an absolute file from the given file name. If the filename is an
     * absolute one already, then use it unchanged, otherwise assume it is
     * relative to the current project folder.
     */
    private File makeAbsoluteFilename(String filename) {
        File file = new File(filename);
        if (!file.isAbsolute()) {
            file = new File(getProjectFolder(), filename);
        }
        return file;
    }

    /**
     * In fact, this determines the classpath folder. Hopefully, there's only
     * one directory on the classpath :^) .
     * 
     * @return The classpath folder.
     */
    private File getProjectFolder() {
        return new File(System.getProperty("java.class.path"));
    }
}
