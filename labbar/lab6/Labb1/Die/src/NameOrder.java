
import java.util.Scanner;

public class NameOrder {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Input first string: ");
        String name1 = input.nextLine();
        System.out.print("Input first string: ");
        String name2 = input.nextLine();
        if(name1.compareTo(name2) < 0){
            System.out.println(name1);
            System.out.println(name2);
        }
        else if (name1.compareTo(name2) > 0){
            System.out.println(name2);
            System.out.println(name1);
        }
        else {
            System.out.println(name1);
            System.out.println(name2);
        }
    }
}
