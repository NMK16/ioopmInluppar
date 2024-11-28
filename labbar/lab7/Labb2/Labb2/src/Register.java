import java.util.Queue;

public class Register {
    boolean open = false;
    Queue<Customer> queue; 

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
        queue.element().serve();
    }
    public boolean hasCustomers(){
        return !queue.isEmpty();
    }

    public boolean currentCustomerIsDone(){
        return queue.element().isDone();
    }

    public void addToQueue(Customer c){
        queue.add(c);
    }
}
