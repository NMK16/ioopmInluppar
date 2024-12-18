import java.util.LinkedList;
import java.util.Queue;

public class Register {
    boolean open = false;
    Queue<Customer> queue = new LinkedList<Customer>();
    int numberOfCustomersServed;
    
    public void open(){
        this.open = true;
    }

    public void close(){
        this.open = false;
    }

    public boolean isOpen(){
        return this.open;
    }

    public void step(){
        if(hasCustomers()){
            this.queue.element().serve();
        }
    }
    public boolean hasCustomers(){

        return !this.queue.isEmpty();
    }

    public boolean currentCustomerIsDone(){
        if(hasCustomers()){
            return this.queue.element().isDone();
        }
        return false;
    }

    public void addToQueue(Customer c){
        this.queue.add(c);
    }
}