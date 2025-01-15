
public class Queue<T>{
    private class Node {
        T element;
        Node next;
    }
    Node first;
    Node last;
    int length;
    
    public int length(){
        return this.length;
    }

    public void enqueue(T c) {
        Node newNode = new Node();
        newNode.element = c;
        if (this.length == 0) {
            this.first = newNode;
            this.last = newNode;
        } else {
            this.last.next = newNode;
            this.last = newNode;
        }
        this.length++;
    }

    public T dequeue(){
        if(this.length == 0){
            return null;
        }
        T returnCustomer = first.element;
        this.first = this.first.next;
        this.length--;
        if (this.length == 0) {
            this.last = null;
        }
        return returnCustomer;
    }

    public T first(){
        if(this.first != null){
            return this.first.element;
        }
        return null;
    }

}