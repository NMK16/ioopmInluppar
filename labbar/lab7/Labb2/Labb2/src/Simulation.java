
public class Simulation {
    Store store = new Store();
    int time;
    int intensity = 70;
    int maxGroceries = 10;
    int thresholdForNewRegister = 3;


    private boolean nonFullRegisterExists(){
        for(int i = 0; i < this.store.registers.length; i++){
            if(this.store.registers[i].queue.size() < thresholdForNewRegister){
                return true;
            }
        }
        return false;
    }

    public void step(){
        this.store.step();

        if(this.store.getAverageQueueLength() >= this.thresholdForNewRegister){
            this.store.openNewRegister();
        }

        int randomCustomerCreate = (int)((Math.random()*100)+1);
        if(randomCustomerCreate < this.intensity && nonFullRegisterExists()){
            Customer newCustomer = new Customer();
            newCustomer.groceries = (int)((Math.random()*maxGroceries)+1);
            this.store.newCustomer(newCustomer);
        }


        this.time++;

    }
}