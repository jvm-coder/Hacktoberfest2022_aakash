class Node{
	int data;
	Node next;
	Node()
	{
		data = 0;
		next = null;
	}
    Node(int d){
        data = d;
    }
}

class LL{
    Node head = null;
    void printSLL(){
        Node move = head;
        while(move != null){
            System.out.print(move.data+" ");
            move = move.next;
        }
        System.out.println("");
    }
    void insertBeg(int d){
        Node n = new Node(d);
        n.next = head;
        head = n;
        System.out.println("Inserting at Beginning: ");
        printSLL();
    }
    void insertEnd(int d){
        Node n = new Node(d);
        Node temp = head;
        while(temp.next!=null){
            temp = temp.next;
        }
        n.next = temp.next;
        temp.next = n;
        System.out.println("Inserting at End: ");
        printSLL();
    }
    void insertPos(int d,int pos){
        if(pos>0){
            Node n = new Node(d);
            Node temp = head;
            for(int i = 0;i<pos-1;i++){
                temp = temp.next;
            }
            n.next = temp.next;
            temp.next = n;
            System.out.println("Inserting at given position: ");
            printSLL();
        }
    }
    void deleteBeg(){
        head = head.next;
        System.out.println("Deleting at Beginning: ");
        printSLL();
    }
    void deleteEnd(){
        Node temp = head;
        Node c = temp;
        while(temp.next != null){
            c = temp;
            temp = temp.next;
        }
        c.next = null;
        System.out.println("Deleting at End: ");
        printSLL();
    }
    void deletePos(int pos){
        Node temp = head;
        for(int i = 0;i<pos-1;i++){
            temp = temp.next;
        }
        temp.next = temp.next.next;
        System.out.println("Deleting at given position: ");
        printSLL();
    }
}

public class SLL_Linked_List {
    public static void main(String args[]){
        LL ab = new LL();
        ab.printSLL();
        ab.insertBeg(10);
        ab.insertBeg(30);
        ab.insertBeg(40);
        ab.insertBeg(50);
        ab.insertPos(15,2);
        ab.insertEnd(60);
        ab.deleteBeg();
        ab.deleteEnd();
        ab.deletePos(2);
    }
}
