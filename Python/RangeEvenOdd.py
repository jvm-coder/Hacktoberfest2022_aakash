#Python Program for printing even or odd numbers only by user's choice

choice = int(input("Press 1 for printing EVEN number or 2 for printing ODD number---> "))

mx = int(input("Enter maximum number---> "))

if choice == 1:
    for i in range(mx):
        cnt = 0
        print( i if i%2==0 else "-")
elif choice == 2:
    for i in range(mx):
        cnt = 0
        print(i if i%2!=0 else "-")
        
