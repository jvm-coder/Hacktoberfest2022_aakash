class Parent:
    counter=10
    def __init__(self):
        print("class initialized")
    def parentFunc(self):
        print("parentFunc being called")
    def setcounter(self,num):
        Parent.counter=num
    def showcounter(self):
        print(str(Parent.counter))

class Child:
    def __init__(self):
        print("child class being initialized")
    def childFunc(self):
        print("child func being called")

class Child(Parent):
    def __init__(self):
        print("child class being initialized")
    def childFunc(self):
        print("child func being called")

c = Child()
c.childFunc()


