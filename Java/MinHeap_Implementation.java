
import java.util.*;
public class MinHeap_Implementation
{
	public static void main(String[] args) {
		Heap mhp=new Heap();
		mhp.add(21);
		mhp.add(5);
		mhp.add(6);
		mhp.printHeap();
		mhp.add(7);
		mhp.add(23);
		mhp.printHeap();
		System.out.println(mhp.top());
		System.out.println("Value removed:- "+ mhp.remove());
		mhp.printHeap();
		System.out.println("Value removed:- "+ mhp.remove());
		mhp.printHeap();
		System.out.println("Value removed:- "+ mhp.remove());
		mhp.printHeap();
		mhp.add(2);
		mhp.add(13);
		mhp.printHeap();
		
	}
}
class Heap{
    ArrayList<Integer> list;
    int size;
    
    public Heap(){
        list=new ArrayList<>();
        size=0;
    }
    public void add(int val){
        //add to list -> upheapify
        list.add(val);
        size++;
        upheapify(list.size()-1);  // recursive function
    }
    public void upheapify(int ci){ // ci -> child index
        if(ci==0)
        return;
        
        int pi=(ci-1)/2; //parent index
        if(list.get(ci)<list.get(pi)){
            swap(ci, pi);
            upheapify(pi);
        }
    }
    public void swap(int idx1, int idx2){
        int val1=list.get(idx1);
        int val2=list.get(idx2);
        list.set(idx1, val2);
        list.set(idx2, val1);
    }
    
    public int remove(){  // remove top (min value for minheap)
        if(size==0){
            System.out.println("Underflow! Heap is Empty");
            return -1;
        }
        // swap top and last value -> remove last from list -> downheapify
        int val=list.get(0);
        swap(0, list.size()-1);
        list.remove(list.size()-1);
        downheapify(0);
        return val;
        
    }
    
    public void downheapify(int pi)  //pi-> parent index
    {
        if(pi>=list.size())
            return;
        //compare parent , left and right values and get min out of it -> swap -> recursive call
        int minVal=list.get(pi);
        
        int li=2*pi+1;
        int ri=2*pi+2;
        int minIdx=pi;
        
        if(li<list.size() && list.get(li)<minVal){
            minVal=list.get(li);
            minIdx=li;
        }
            
        
        if(ri<list.size() && list.get(ri)<minVal){
            minVal=list.get(ri);
            minIdx=ri;
        }
        
        if(minIdx!=pi)
        {
            swap(minIdx, pi);
            downheapify(minIdx);
        }
    
    }
    
    public int top(){
        if(size==0){
            System.out.println("Underflow! Heap is Empty");
            return -1;
        }
        return list.get(0);
    }
    public int size(){
        if(size==0)
        {
            System.out.println("Heap is Empty");
            return 0;
        }
        return size;
    }
    
    public void printHeap(){
        for(int val:list)
        System.out.print(val + " ");
        System.out.println();
    }
}
