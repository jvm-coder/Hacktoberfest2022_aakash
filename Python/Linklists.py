
# singly linklist

class node:
    def __init__(self,value):
        self.value=value
        self.next=None
        
class linkedList:
    def __init__(self):
        self.head=None
        self.tail=None
        
    def InsertAtFirst(self,value):
        newnode=node(value)
        if self.head is None:
            self.head=newnode
            self.tail=newnode
        else:
            newnode.next=self.head
            self.head=newnode
    
    def InsertAtEnd(self,value):
        newnode=node(value)
        if self.head is None:
            self.head=newnode
            self.tail=newnode
        else:
            self.tail.next=newnode
            self.tail=newnode
            
    def InsertAfter(self,item,value):
        x=self.head
        while (x != None):
            if x.value == item:
                break 
            x=x.next
        if x is None:
            print("Item not found")
        else:
            newnode=node(value)
            newnode.next = x.next
            x.next=newnode        
            
    def DeleteAtFirst(self):
        if self.head is None:
            print("Link List is empty")
        else:
            self.head=self.head.next
            
    def DeleteAtEnd(self):
        if self.head is None:
            raise Exception ("Link list is emoty")
        else:
            p=self.head
            q=p.next
            while (q.next is not None):
                p=p.next
                q=q.next
            p.next= None
            
    def DeleteByValue(self,value):
        x=self.head
        if x!=None:
            while x!=None:
                if x.value==value:
                    break
                y=x                
                x=x.next
            if x==None:
                return
            y.next=x.next
            x=None
    
    def Print(self):
        a=self.head
        while(a):
            print(a.value, end=" ")
            a=a.next
                
# driver code

print('Single Link List')
ob=linkedList()

ob.InsertAtFirst(1)
ob.InsertAtFirst(2)
ob.InsertAtFirst(3)
ob.InsertAtFirst(4)
ob.InsertAtFirst(5)

print("\nWhen inserted first:")
ob.Print()
ob.InsertAtEnd(7)

print("\nWhen inserted last:")
ob.Print()

print("\nWhen inserted after:")
ob.InsertAfter(4,6)
ob.Print()

print("\nWhen deleted from first:")
ob.DeleteAtFirst()
ob.Print()

print("\nWhen deleted from end:")
ob.DeleteAtEnd()
ob.Print()

print("\nWhen deleted by value:")
ob.DeleteByValue(2)
ob.Print()




# In[12]:


# Doubly linklist

class Node:
    def __init__(self,value):
        self.value=value
        self.next=None
        self.previous=None
        
class DLL:
    def __init__(self):
        self.head=None
        self.tail=None
        
    def insertatfirst(self,value):
        newNode=Node(value)
        if self.head==None:
            self.head=newNode
            self.tail=newNode
        else:
            newNode.next=self.head
            self.head.previous=newNode
            self.head=newNode
            
    def insertatlast(self,value):        
        newNode=Node(value)
        if self.head==None:
            self.head=newNode
            self.tail=newNode
        else:
            self.tail.next=newNode
            newNode.previous=self.tail
            self.tail=newNode
            
    def insertafter(self,after, val):
        newNode=Node(val)
        x=self.head
        while x.value!=after and x!=None:
            x=x.next
        newNode.next=x.next
        x.next.previous=newNode
        x.next=newNode
        newNode.previous=x
        
    def deleteatfirst(self):
        self.head=self.head.next
        self.head.previous=None
        
    def deleteatlast(self):
        self.tail=self.tail.previous
        self.tail.next=None
    
    def deletebyvalue(self,value):        
        if self.head is None:
            raise Exception("LIST IS EMPTY")
        else:
            x=self.head
            while x.value!=value and x!=None:
                x=x.next
            n = x.next
            x =x.previous
            n.prev = x
            x.next = n
            del(x)


    def Print(self):
        x = self.head
        if x is None:
            raise Exception("LIST IS EMPTY")
        else:
            while (x):
                print(x.value, end=" ")
                x = x.next
            print("\n")
            
ob=DLL()
print("Inserting at Start:")
ob.insertatfirst(1)
ob.Print()

print("Inserting at End")

ob.insertatlast(3)
ob.insertatlast(2)
ob.insertatlast(3)
ob.insertatlast(4)
ob.insertatlast(5)
ob.insertatlast(6)
ob.Print()

print("Inserting after a specific Value: ")
ob.insertafter(2,0)
ob.Print()

print("Deleting from Start:")
ob.deleteatfirst()
ob.Print()

print("Deleting from end: ")
ob.deleteatlast()
ob.Print()

print("Deleting a specific Value: ")
ob.deletebyvalue(4)
ob.Print()