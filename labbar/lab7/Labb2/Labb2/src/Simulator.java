public class Simulator{

    public static void main(String[] args) throws InterruptedException{
        int steps = 50;
        Simulation s = new Simulation(); // TODO: Add parameters!

        for(int i = 0; i < steps; i++){
            System.out.print("\033[2J\033[;H");
            s.step();
            System.out.println("Customers Served: " + s.store.numberOfCustomersServed);
            System.out.println("Currently Open Registers: " + s.store.numberOfOpenRegisters);
            System.out.println("Amount Of Current Customers: " + s.store.amountOfCurrentCustomers);
            System.out.print("\nAmount Of Current Customers R1: " + "[" + s.store.amountOfCurrentCustomersR1 + "]" + " ");
            for(int j = 0; j < s.store.amountOfCurrentCustomersR1; j++){
                System.out.print("@");
            }
            System.out.print("\nAmount Of Current Customers R2: " + "[" + s.store.amountOfCurrentCustomersR2 + "]" + " ");
            for(int j = 0; j < s.store.amountOfCurrentCustomersR2; j++){
                System.out.print("@");
            }
            System.out.print("\nAmount Of Current Customers R3: " + "[" + s.store.amountOfCurrentCustomersR3 + "]" + " ");
            for(int j = 0; j < s.store.amountOfCurrentCustomersR3; j++){
                System.out.print("@");
            }
            System.out.print("\nAmount Of Current Customers R4: " + "[" + s.store.amountOfCurrentCustomersR4 + "]" + " ");
            for(int j = 0; j < s.store.amountOfCurrentCustomersR4; j++){
                System.out.print("@");
            }
            System.out.print("\nAmount Of Current Customers R5: " + "[" + s.store.amountOfCurrentCustomersR5 + "]" + " ");
            for(int j = 0; j < s.store.amountOfCurrentCustomersR5; j++){
                System.out.print("@");
            }

            Thread.sleep(500);
        }
        System.out.println("");
        System.out.println("Simulation finished!");
    }
}