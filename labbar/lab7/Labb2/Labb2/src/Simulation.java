

public class Simulation {
    Store store = new Store();
    int time;
    int intensity = 50;
    int maxGroceries = 5;
    int thresholdForNewRegister = 3;

    public void step(){

        if(this.store.getAverageQueueLength() >= this.thresholdForNewRegister){
            this.store.openNewRegister();
        }
        
        int randomCustomerCreate = (int)(Math.random()*100);
        if(randomCustomerCreate < this.intensity){
            Customer newCustomer = new Customer();
            newCustomer.groceries = 3; //(int)((Math.random()*maxGroceries)+1);
            this.store.newCustomer(newCustomer);
        }
        
        this.store.step();


        this.time++;

    }
}