public class Customer {
    int bornTime;
    int groceries;

    public void serve(){
        this.groceries--;
    }

    public boolean isDone(){
        return this.groceries == 0;
    }
}
