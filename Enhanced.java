
import java.util.Scanner;

public class Enhanced {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
//            System.out.println("enter fruit : ");
//            String fruit = in.next();

//            switch (fruit) {
//                case "Mango" -> System.out.println("King of fruits");
//                case "Apple" -> System.out.println("A Sweet red fruit");
//                case "Orange" -> System.out.println("A round fruit");
//                case "Grapes" -> System.out.println("Small round Fruit");
//                default -> System.out.println("please enter a valid fruit");
//            }
            int day = in.nextInt();
            switch (day) {
                case 1 -> System.out.println("Monday");
                case 2 -> System.out.println("Tuesday");
                case 3 -> System.out.println("Wednesday");
                case 4 -> System.out.println("Thursday");
                case 5 -> System.out.println("Friday");
                case 6 -> System.out.println("Saturday");
                case 7 -> System.out.println("Sunday");
            }
//            switch (day){
//                case 1 ,2 , 3 ,4 , 5 -> System.out.println("Weekday");
//                case 6 , 7 -> System.out.println("Weekend");
//            }
        }

    }
