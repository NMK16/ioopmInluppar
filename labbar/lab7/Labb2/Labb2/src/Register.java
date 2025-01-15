
public class Register {
    boolean open = false;
    Queue<Customer> queue = new Queue<>();
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
            this.queue.first().serve();
        }
    }
    public boolean hasCustomers(){
        return this.queue.length() != 0;
    }

    public boolean currentCustomerIsDone(){
        if(hasCustomers()){
            return this.queue.first().isDone();
        }
        return false;
    }

    public void addToQueue(Customer c){
        this.queue.enqueue(c);
    }
}