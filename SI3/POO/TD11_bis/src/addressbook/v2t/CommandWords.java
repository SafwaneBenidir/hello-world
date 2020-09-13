package addressbook.v2t;

import java.util.Arrays;

/**
 * This class holds an enumeration of all command words known to the program.
 * 
 * @author David J. Barnes and Michael Kölling.
 * @version 2016.02.29
 */
class CommandWords {
    // a constant array that holds all valid command words
    private static final String validCommands[] = { "add", "get", "search",
            "list", "help", "quit", };

    /**
     * Constructor for CommandWords
     */
    CommandWords() {
    }

    /**
     * Check whether a given String is a valid command word.
     * 
     * @param aString
     *            The string to be checked.
     * @return true if it is valid, false if it isn't.
     */
    boolean isCommand(String aString) {
        if (aString != null) {
            return Arrays.stream(validCommands)
                    .filter(c -> c.equals(aString))
                    .findFirst()
                    .isPresent();
        }
        // if we get here, the string was not found in the commands
        return false;
    }

    /**
     * Print all valid commands to System.out.
     */
    void showAll() {
        for (String command : validCommands) {
            System.out.print(command + "  ");
        }
        System.out.println();
    }
}
