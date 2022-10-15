#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    int data;
    Stack *next; //  Structure of the node (Self Referencial Structure).
};
class Stack_Operation
{
    Stack *top;
    Stack *ptr;

protected:
    void position_reset();
    bool isEmpty();

public:
    void insertion();
    void display();
    void push();
    void pop();
    void peek_in_Stack_LinkedList(); // for retreaving the data according to the given position in the stack.
    void Stack_top();
    void Stack_bottom();
};

void Stack_Operation::peek_in_Stack_LinkedList()
{
    int Position;
    cout << "Enter the position from the top for which you want the data of that element:- ";
    cin >> Position;
    Stack *ptr = top; // Ptr is the supplimentary pointer which is points out to the node where the top pointer is present.
    for (int i = 0; (i < Position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next; // for moving the ptr pointer.
    }

    if (ptr != NULL)
    {
        cout << "The Value at this position " << Position << " is :- " << ptr->data<<endl;
    }
    else
    {
        cout << "Wrong Position is Given Please try again !!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    }
}

void Stack_Operation::Stack_top()
{
    if (isEmpty())
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "The Value of the top most position is: " << top->data << endl;
    }
}

void Stack_Operation::Stack_bottom()
{

    if (isEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }
    else
    {
        position_reset();
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        cout << "The Bottom Most Value of the Stack is: " << ptr->data;
        cout << endl;
    }
}

bool Stack_Operation::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Stack_Operation::position_reset()
{
    ptr = top;
}

void Stack_Operation::insertion()
{
    int size;
    int data;
    cout << "Enter the size of the stack: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        Stack *new_node = new Stack;
        cout << "Enter the data which you want to insert in the stack: ";
        cin >> data;
        new_node->data = data;
        new_node->next = NULL;
        if (i == 0)
        {
            top = new_node;
        }
        else
        {
            new_node->next = top;
            top = new_node;
        }
    }
}
// void Stack_Operation::insertion()
// {
//     int size;
//     int data;
//     cout << "Enter the size of the stack: ";
//     cin >> size;
//     for (int i = 0; i < size; i++)
//     {
//         Stack *new_node = new Stack;
//         cout << "Enter the data which you want to insert in the stack: ";
//         cin >> data;
//         new_node->data = data;
//         new_node->next = NULL;
//         if (i == 0)
//         {
//             top = new_node;
//         }
//         else
//         {
//             new_node->next = top = ptr;
//             top = new_node;
//         }
//     }
// }

void Stack_Operation::display()
{
    position_reset();
    while (ptr != NULL)
    {
        cout << ptr->data;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            cout << "";
        }
        else
        {
            cout << ",";
        }
    }
    cout << endl;
}

void Stack_Operation::push()
{
    Stack *pushNode = new Stack;
    int data;
    cout << "Enter the data you want to push in the Stack: ";
    cin >> data;
    pushNode->data = data;
    pushNode->next = top;
    top = pushNode;
}

void Stack_Operation::pop()
{
    if (isEmpty())
    {
        cout << "The UnderFlow !!!!!!!!!!!!!" << endl;
    }
    else
    {
        Stack *delete_node = top;
        top = top->next;
        delete delete_node;
    } // Agar top pointer ki value change ho rhi function me to uska main() se koi lena dena nhi hain (call by value is implemented implictly) . In this case we have to send the address of that value so that it would reflect changes in the actual parameters (function called Parameter) etc.
}

int main()
{
    int choice;
    do
    {
        Stack_Operation operations;
        cout << "1. Insert the values in the Stack" << endl;
        cout << "2. display the stack" << endl;
        cout << "3. push the element in the stack" << endl;
        cout << "4. pop the element in the stack" << endl;
        cout << "5. Stack Top Value" << endl;
        cout << "6. Stack bottom Value" << endl;
        cout << "7. Data of that element which is retreaved According given Position" << endl;
        cout << "8. Exit" << endl;
        cout << endl;
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.insertion();
            break;
        }
        case 2:
        {
            operations.display();
            break;
        }
        case 3:
        {
            operations.push();
            break;
        }
        case 4:
        {
            operations.pop();
            break;
        }
        case 5:
        {
            operations.Stack_top();
            break;
        }
        case 6:
        {
            operations.Stack_bottom();
            break;
        }
        case 7:
        {
            operations.peek_in_Stack_LinkedList();
            break;
        }
        case 8:
        {
            break;
        }

        default:
        {
            cout << "Wrong Choice!!!!!!!!!!!!!!!";
            break;
        }
        }

    } while (choice != 8);
    return 0;
}