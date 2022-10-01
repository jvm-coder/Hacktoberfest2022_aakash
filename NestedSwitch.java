package shubham;

import java.util.Scanner;

public class NestedSwitch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int EmpID = in.nextInt();
        String department = in.next();

        switch(EmpID){
            case 1:
                System.out.println("Shubham Singh");
                break;
            case 2:
                System.out.println("Tejas Thete");
                break;
            case 3:
                System.out.println("EmpNumber3");
                switch (department){
                    case "IT":
                        System.out.println("IT department");
                        break;
                    case "Management":
                        System.out.println("Management");
                        break;
                    default:
                        System.out.println("no department entered");
                }
                break;
            default:
                System.out.println("Enter EmpID");
        }

          // Better way (Enhanced one):
        switch (EmpID) {
            case 1 -> System.out.println("Shubham Singh");
            case 2 -> System.out.println("Tejas Thete");
            case 3 -> {
                System.out.println("EmpNumber3");
                switch (department) {
                    case "IT" -> System.out.println("IT department");
                    case "Management" -> System.out.println("Management");
                    default -> System.out.println("no department entered");
                }
            }
            default -> System.out.println("Enter EmpID");
        }
    }
}



