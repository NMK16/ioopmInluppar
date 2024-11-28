public class Store {
    Register registers[];

    public int getAverageQueueLength(){
        int counter = 0;
        for (int i = 0; i < registers.length; i++){
            counter += registers[i].queue.size();
        }
        return (counter/registers.length);
    }

    public void newCustomer(Customer c){
        int counter = 0;
        for (int i = 0; i < registers.length; i++){
            if(!(registers[counter].queue.size() == Math.min(registers[counter].queue.size(), registers[i].queue.size()))){
                counter = i;
            }
        }
        registers[counter].queue.add(c);
    }

    public void step(){
        
    }

    public void openNewRegister(){
        registers[registers.length].open();
    }
}
