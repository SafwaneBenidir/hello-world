package addressbook.io;

import java.io.IOException;

public class Main {

    /**
     * @param args
     * @throws IOException 
     */
    public static void main(String[] args) throws IOException {
        new AddressBookFileHandler(new AddressBookDemo().getBook()).saveSearchResults("d");
    }
}
