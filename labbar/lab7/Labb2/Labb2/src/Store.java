import java.util.LinkedList;
import java.util.Queue;

public class Store {
    Register[] registers = {new Register(), new Register()};

    public Store() {
        for (int i = 0; i < this.registers.length; i++) {
            this.registers[i] = new Register();
        }
    }

    public int getAverageQueueLength(){
        int counter = 0;
        for (int i = 0; i < this.registers.length; i++){
            counter += this.registers[i].queue.size();
        }
        return (counter/this.registers.length);
    }

    public void newCustomer(Customer c){
        int counter = 0;
        for (int i = 0; i < this.registers.length; i++){
            if(!(this.registers[counter].queue.size() == Math.min(this.registers[counter].queue.size(), this.registers[i].queue.size()))){
                counter = i;
            }
        }
        this.registers[counter].queue.add(c);
    }

    public void step(){
        for(int i = 0; i < this.registers.length; i++){

            this.registers[i].step();
        }
    }

    public void openNewRegister(){
        for(int i = 0; i < this.registers.length; i++){
            if(!this.registers[i].isOpen()){
                this.registers[i].open();
                break;
            }
        }
    }

    public Queue getDoneCustomers(){
        Queue<Customer> customersDone = new LinkedList<>();
        for (int i = 0; i < this.registers.length; i++){
            if(this.registers[i].currentCustomerIsDone()){
                customersDone.add(this.registers[i].queue.element());
            }
        }
        return customersDone;
    }

}
