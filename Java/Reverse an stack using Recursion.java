/*
Problem Statement : Reverse an stack using Recursion 
TC : O(n^2)   SC : O(1)  but for Recursive call it uses Auxillary Recursion Stack --> O(2n)
*/
import java.util.*;
public class Main
{
    public static void ReverseStack(Stack<Integer> st){
        /// B   H   I 
        // Base Case 
        if(st.size()==1){
            return;
        }
        // Hypothesis
        int temp = st.pop();
        ReverseStack(st);
        //Induction 
        insert(st,temp);
        return;
        
    }
    public static void insert(Stack<Integer> st , int ele){
        /// B  H  I
        
        //Base
        if(st.size()==0){
            st.push(ele);
            return;
        }
        /// Hypothesis 
        int val = st.pop();
        insert(st,ele);
        //Induction
        st.push(val);
        return;
    }
	public static void main(String[] args) {
	    Stack<Integer> st = new Stack<>();
	    st.push(2);
	    st.push(5);
	    st.push(-3);
	    st.push(10);
	    
	    ReverseStack(st);
		System.out.println(st);
	}
}
