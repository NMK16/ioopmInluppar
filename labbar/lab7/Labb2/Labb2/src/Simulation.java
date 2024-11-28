public class Simulation {
    Store store = new Store();
    int time = 0;
    int intensity = 100;
    int maxGroceries = 100;
    int thresholdForNewRegister = 2;

    public void step(){

        this.store.step();
        
        int randomCustomerCreate = (int)Math.random()*100;
        if(randomCustomerCreate < this.intensity){
            Customer newCustomer = new Customer();
            newCustomer.groceries = (int)(Math.random()*this.maxGroceries)+1;
            this.store.newCustomer(newCustomer);
        }

        if(this.store.getAverageQueueLength() > this.thresholdForNewRegister){
            this.store.openNewRegister();
        }
        this.time++;

    }
}