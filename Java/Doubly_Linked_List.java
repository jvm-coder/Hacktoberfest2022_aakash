class Node{
	int data;
	Node next;
    Node prev;
	Node()
	{
		data = 0;
		next = null;
        prev = null;
	}
    Node(int d){
        data = d;
    } 
}
class LL{
    Node head=null;
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
        n.prev = null;
        n.next = head;
        head  = n;
        System.out.println("Inserting at beginning.");
        printSLL();
    }
    void insertEnd(int d){
        Node n = new Node(d);
        Node temp = head;
        while(temp.next!=null){
            temp = temp.next;
        }
        n.prev = temp.prev;
        n.next = temp.next;
        temp.next = n;
        System.out.println("Inserting at End: ");
        printSLL();
    }
    void insertPos(int d,int pos){
        if (pos>0){
            Node n = new Node(d);
            Node temp = head;
            for(int i = 0;i<pos-1;i++){
                temp = temp.next;
            }
            n.prev = temp.prev;
            n.next = temp.next;
            temp.next = n;
            System.out.println("Inserting at given position.");
            printSLL();
        } 
    }
    void deleteBeg(){
        head = head.next;
        System.out.println("Deleting at beginning.");
        printSLL();
    }
    void deleteEnd(){
        Node temp = head;
        Node t = temp;
        while(temp.next != null){
            t = temp;
            temp = temp.next;
        }
        t.next = null;
        System.out.println("Deleting at end.");
        printSLL();
    }
    void deletePos(int pos){
        Node temp = head;
        Node t = temp;
        for(int i = 0;i<pos-1;i++){
            temp = temp.next;
            t = temp.next.next;
        }
        t.prev = temp;
        temp.next = temp.next.next;
        System.out.println("Deleting at given position.");
        printSLL();
    }
}

public class DLL_Doubly_List {
    public static void main(String[] args) {
        LL ab = new LL();
        
        ab.printSLL();
        ab.insertBeg(12);
        ab.insertBeg(24);
        ab.insertBeg(36);
        ab.insertBeg(48);
        ab.insertEnd(20);
        ab.insertPos(30,2);
        ab.deleteBeg();
        ab.deleteEnd();
        ab.deletePos(2);
    }   
}
