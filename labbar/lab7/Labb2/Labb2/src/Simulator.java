public class Simulator {
    public static void main(String[] args) throws Exception {
        Customer customer = new Customer();
        customer.groceries = (int)(Math.random()*10)+1;
        while(!customer.isDone()){
            customer.serve();
        }
        System.out.println("Done");
    }
}

