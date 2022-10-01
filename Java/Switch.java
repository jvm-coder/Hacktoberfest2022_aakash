
import java.util.Scanner;

public class Switch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("enter fruit : ");
        String fruit = in.next();

        switch (fruit){
            case "Mango":
                System.out.println("King of fruits");
                break;
            case"Apple":
                System.out.println("A Sweet red fruit");
                break;
            case"Orange":
                System.out.println("A round fruit");
                break;
            case"Grapes":
                System.out.println("Small round Fruit");
                break;
            default:
                System.out.println("please enter a valid fruit");

        }

    }
}
