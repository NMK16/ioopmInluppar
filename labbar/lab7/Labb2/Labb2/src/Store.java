import java.util.LinkedList;
import java.util.Queue;

public class Store {
    Register[] registers;
    int numberOfOpenRegisters;
    int numberOfCustomersServed;
    int amountOfCurrentCustomers;
    int amountOfCurrentCustomersR1;
    int amountOfCurrentCustomersR2;
    int amountOfCurrentCustomersR3;
    int amountOfCurrentCustomersR4;
    int amountOfCurrentCustomersR5;


    public Store() {
        this.registers = new Register[5]; // Initial size
        for (int i = 0; i < registers.length; i++) {
            registers[i] = new Register();
        }
    }

    public int getAverageQueueLength(){
        int counter = 0;
        for (int i = 0; i < registers.length; i++){
            counter += this.registers[i].queue.size();
        }
        return numberOfOpenRegisters == 0 ? 0 : (counter/numberOfOpenRegisters);
    }

    public void newCustomer(Customer c){
        if(numberOfOpenRegisters == 0){
            openNewRegister();
        }
        int counter = 0;
        for (int i = 0; i < numberOfOpenRegisters; i++){
            if(!(this.registers[counter].queue.size() == Math.min(this.registers[counter].queue.size(), this.registers[i].queue.size()))){
                counter = i;
            }
        }
        this.registers[counter].queue.add(c);
        amountOfCurrentCustomers++;
    }


    public void step(){
        for(int i = 0; i < numberOfOpenRegisters && this.registers[i].isOpen(); i++){
            this.registers[i].step();

            if(registers[i].currentCustomerIsDone()){
                registers[i].queue.remove();
                amountOfCurrentCustomers--;
                numberOfCustomersServed++;
            }

            if (!this.registers[i].hasCustomers()) {
                this.registers[i].close();
                numberOfOpenRegisters--;
            }
        }
        
        amountOfCurrentCustomersR1 = registers[0].queue.size();
        amountOfCurrentCustomersR2 = registers[1].queue.size();
        amountOfCurrentCustomersR3 = registers[2].queue.size();
        amountOfCurrentCustomersR4 = registers[3].queue.size();
        amountOfCurrentCustomersR5 = registers[4].queue.size();
    }

    public void openNewRegister(){
        for(int i = 0; i < this.registers.length; i++){
            if(!this.registers[i].isOpen()){
                this.registers[i].open();
                numberOfOpenRegisters++;
                return;
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