import java.util.Scanner;

public class App {
    public static void main(String [] args) {

        Scanner keyboardInput = new Scanner(System.in);

        System.out.print("Enter an adjective: ");
        String adjective = keyboardInput.nextLine();

        System.out.print("Enter another adjective: ");
        String anotherAdjective = keyboardInput.nextLine();

        System.out.print("Enter a noun: ");
        String noun = keyboardInput.nextLine();

        System.out.print("Enter a verb: ");
        String verb = keyboardInput.nextLine();

        System.out.print("Enter another noun: ");
        String noun = keyboardInput.nextLine();

        System.out.println("Did you have a " + adjective + " time? \n"
                         + "Because I definitely had a " + adjective2 + " time. \n"
                         + "Hopefully next " + noun + " it won't be too hard lol.\n"
                         + "You think next time you can " + verb + " me? *wink* *wink*\n"
                         + "We should be " + noun2 + " buddies!");

        keyboardInput.close();
       