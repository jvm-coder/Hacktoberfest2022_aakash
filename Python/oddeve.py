
#importing the modules here
import random
import time

#list of items for choosing randomly
k=["Tails", "Heads"]
w=(1,2,3,4,5,6,7,8,9,10)

#function to make the user's input t or h in tails or head
def thy(f):
    if f=="t":
        return "Tails"
    elif f=="h":
        return "Heads"
    else:
        return "Abe Saaley!"

a=input("choose between heads(h) or tails(t)-")
b=thy(a)
print(f"you choose {b}")
print("---------------------------------")

#to show loading......
print("Tossing", end=" ")
for i in range(0,5):
    print(".", end=" ")
    time.sleep(1)
m=random.choice(k)
print(m)

#conditions start from winning the toss
#here if the user wins the toss then
if m==b:
    print("you won the toss")
    print("---------------------------------")
    c=input("what do you want to do batting(bt) or bowling(bw)-")
    print("---------------------------------")
    #this will count user's run
    d=0
    #this will count computer's run
    r=0
    #when user chooses to bat
    if c=="bt":
        while True:
            n=random.choice(w)
            s=int(input("enter a number- "))
            print("---------------------------------")
            #if the input is greater than 10 then the value will be rejected
            if s>10:
                print("Abbe Saaley!")
            else:
                #show the random value and the user's entered value
                print(f"computer's number-{n} // your number-{s}")
                print("---------------------------------")
                if n==s:
                    #if the user's value and random value coincides then user is out
                    print("you are out")
                    break
                else:
                    #score will add up
                    d+=s
                    print(f"your score is {d}")
                    print("---------------------------------")
                    if d==50:
                        #mark the runs till 50
                        print("you made a half century")
                        print("---------------------------------")
                    elif d==100:
                        #mark runs till 100
                        print("nice, you made century")
                        print("---------------------------------")
                    elif d==0:
                        print("bad luck")
                        print("---------------------------------")
            print("Calculating", end=" ")
            for i in range(0, 5):
                print(".", end=" ")
                time.sleep(1)
            print("\n")
            print("---------------------------------")
            print(f"you scored {d} runs")
            print("---------------------------------")
            print(f"computer has to score {d} runs")
            print("---------------------------------")
            time.sleep(2)
            #now batting of computer starts
            print("now it's computer's batting")
            print("---------------------------------")
        while True:
            o = random.choice(w)
            q=int(input("enter a number- "))
            print("---------------------------------")
            if q>10:
                print("Abbe Saaley!")
            else:
                print(f"computer's number-{o} // your number-{q}")
                print("---------------------------------")
                if o==q:
                    print("computer is out")
                    print("---------------------------------")
                    break
                else:
                    r+=o
                    print(f"computer's score is {r}")
                    print("---------------------------------")
                    if r==50:
                        print("computer made half century")
                        print("---------------------------------")
                    elif r==100:
                        print("computer made century")
                        print("---------------------------------")
                    elif r==0:
                        print("bad luck of computer")
                        print("---------------------------------")
                    if r>d:
                        #if computer's run gets above user's run it will break the loop
                        break
        print("Calculating", end=" ")
        for i in range(0, 5):
            print(".", end=" ")
            time.sleep(1)
        print("\n")
        print("---------------------------------")
        print(f"computer scored {r} runs")
        print("---------------------------------")
        if d>r:
            #if user's run is more than computer's run
            print("you won the game")
            print("---------------------------------")
        elif d<r:
            print("computer won the game")
            print("---------------------------------")
        elif d==r:
            #when user's and computer's run is same then
            print("match tied")
            print("---------------------------------")
            print("it's time for superover")
            print("---------------------------------")
            print("you will bat first")
            print("---------------------------------")
            #this is the counter
            ta=0
            #this is used to record the runs of user
            td=0
            #this is used to record the number of balls played
            te=0
            while ta<6:
                tb=random.choice(w)
                tc=int(input("enter your number- "))
                print("---------------------------------")
                if tc>10:
                    print("Abbe Saaley!")
                else:
                    if tb==tc:
                        print("you are out")
                        print("---------------------------------")
                    else:
                        td+=tc
                        print(f"your score is {td} runs")
                        print("---------------------------------")
                        te+=1
                        print(f"balls played-{te}")
                        print("---------------------------------")
                ta+=1
            print(f"your final score is{td}")
            print("---------------------------------")
            print(f"computer has to score {td} runs")
            print("---------------------------------")
            print("now it's computer's turn to bat")
            print("---------------------------------")
            tf=0
            ti=0
            tj=0
            while tf<6:
                tg=random.choice(w)
                th=int(input("enter your number- "))
                print("---------------------------------")
                if th>10:
                    print("Abbe Saaley!")
                else:
                    if tg==th:
                        print("you are out")
                        print("---------------------------------")
                    else:
                        ti+=tg
                        print(f"your score is {ti} runs")
                        print("---------------------------------")
                        tj+=1
                        print(f"balls played {tj}")
                        print("---------------------------------")
                    if ti>td:
                        break
                tf+=1
            print(f"computer's score is {ti}")
            print("---------------------------------")
            if ti>td:
                print("computer won this match")
                print("---------------------------------")
            elif ti<td:
                print("you won the match")
                print("---------------------------------")
            elif td==ti:
                #if match even ties at this point then it will be decided by toss
                tk=input("choose between heads(h) or tails(t)- ")
                print("---------------------------------")
                tl=thy(tk)
                print(f"your choice is {tl}")
                print("---------------------------------")
                tm=random.choice(k)
                print("calculating", end=" ")
                for i in range(0, 5):
                    print(".", end=" ")
                    time.sleep(1)
                print("\n")
                print("---------------------------------")
                if tm==tl:
                    print("you won the match")
                    print("---------------------------------")
                else:
                    print("computer wins the match")
                    print("---------------------------------")

    elif c=="bw":
        x=0
        y=0
        while True:
            l = random.choice(w)
            q=int(input("enter a number- "))
            print("---------------------------------")
            if q>10:
                print("Abbe Saaley!")
            else:
                print(f"computer's number-{l} // your number-{q}")
                print("---------------------------------")
                if l==q:
                    print("computer is out")
                    print("---------------------------------")
                    break
                else:
                    x+=l
                    print(f"computer's score is {x}")
                    print("---------------------------------")
                    if x==50:
                        print("computer made half century")
                        print("---------------------------------")
                    elif x==100:
                        print("computer made century")
                        print("---------------------------------")
                    elif x==0:
                        print("bad luck of computer")
                        print("---------------------------------")
        print("Calculating", end=" ")
        for i in range(0, 5):
            print(".", end=" ")
            time.sleep(1)
        print("\n")
        print("---------------------------------")
        print(f"computer scored {x} runs")
        print("---------------------------------")
        print(f"you need to score {x} runs")
        print("---------------------------------")
        time.sleep(2)
        print("now it's your batting")
        print("---------------------------------")
        while True:
            u=random.choice(w)
            z=int(input("enter a number- "))
            print("---------------------------------")
            if z>10:
                print("Abbe Saaley!")
            else:
                print(f"computer's number-{u} // your number-{z}")
                print("---------------------------------")
                if u==z:
                    print("you are out")
                    print("---------------------------------")
                    break
                else:
                    y+=z
                    print(f"your score is {y}")
                    print("---------------------------------")
                    if y==50:
                        print("you made a half century")
                        print("---------------------------------")
                    elif y==100:
                        print("nice, you made century")
                        print("---------------------------------")
                    elif y==0:
                        print("bad luck")
                        print("---------------------------------")
                    if y>x:
                        break
        print("Calculating", end=" ")
        for i in range(0, 5):
            print(".", end=" ")
            time.sleep(1)
        print("\n")
        print("---------------------------------")
        print(f"you scored {y} runs")
        print("---------------------------------")

        if x>y:
            print("computer won this match")
            print("---------------------------------")
        elif x<y:
            print("you won the match")
            print("---------------------------------")
        elif x==y:
            print("match is tied")
            print("---------------------------------")
            print("it's time for superover")
            print("---------------------------------")
            print("computer will bat first")
            print("---------------------------------")
            tf = 0
            ti = 0
            tj = 0
            while tf < 6:
                tg = random.choice(w)
                th = int(input("enter your number- "))
                print("---------------------------------")
                if th > 10:
                    print("Abbe Saaley!")
                else:
                    if tg == th:
                        print("you are out")
                        print("---------------------------------")
                    else:
                        ti += tg
                        print(f"your score is {ti} runs")
                        print("---------------------------------")
                        tj += 1
                        print(f"balls played {tj}")
                        print("---------------------------------")
                tf += 1
            print(f"computer's score is {ti}")
            print("---------------------------------")
            print(f"you have to score {ti} runs")
            print("---------------------------------")
            print("now it's your turn to bat")
            print("---------------------------------")
            ta = 0
            td = 0
            te = 0
            while ta < 6:
                tb = random.choice(w)
                tc = int(input("enter your number- "))
                print("---------------------------------")
                if tc > 10:
                    print("Abbe Saaley!")
                else:
                    if tb == tc:
                        print("you are out")
                        print("---------------------------------")
                    else:
                        td += tc
                        print(f"your score is {td} runs")
                        print("---------------------------------")
                        te += 1
                        print(f"balls played-{te}")
                        print("---------------------------------")
                        if td > ti:
                            break
                ta += 1
                print(f"your final score is {td}")
                print("---------------------------------")
                if ti > td:
                    print("computer won this match")
                    print("---------------------------------")
                elif ti < td:
                    print("you won the match")
                    print("---------------------------------")
                elif td == ti:
                    tk = input("choose between heads(h) or tails(t)- ")
                    print("---------------------------------")
                    tl = thy(tk)
                    print(f"your choice is {tl}")
                    print("---------------------------------")
                    tm = random.choice(k)
                    print("calculating", end=" ")
                    for i in range(0, 5):
                        print(".", end=" ")
                        time.sleep(1)
                    print("\n")
                    print("---------------------------------")
                    if tm == tl:
                        print("you won the match")
                        print("---------------------------------")
                    else:
                        print("computer wins the match")
                        print("---------------------------------")

else:
    print("computer wins the toss")
    print("---------------------------------")
    aa=["bt", "bw"]
    ab=random.choice(aa)

    if ab=="bt":
        print("computer chooses to bat")
        print("---------------------------------")
        x = 0
        y = 0
        while True:
            l = random.choice(w)
            q = int(input("enter a number- "))
            print("---------------------------------")
            if q>10:
                print("Abbe Saaley!")
            else:
                print(f"computer's number-{l} // your number-{q}")
                print("---------------------------------")
                if l == q:
                    print("computer is out")
                    print("---------------------------------")
                    break
                else:
                    x += l
                    print(f"computer's score is {x}")
                    print("---------------------------------")
                    if x == 50:
                        print("computer made half century")
                        print("---------------------------------")
                    elif x == 100:
                        print("computer made century")
                        print("---------------------------------")
                    elif x == 0:
                        print("bad luck of computer")
                        print("---------------------------------")
        print("Calculating", end=" ")
        for i in range(0, 5):
            print(".", end=" ")
            time.sleep(1)
        print("\n")
        print("---------------------------------")
        print(f"computer scored {x} runs")
        print("---------------------------------")
        print(f"you need to score {x} runs")
        print("---------------------------------")
        time.sleep(2)
        print("now it's your batting")
        print("---------------------------------")
        while True:
            u = random.choice(w)
            z = int(input("enter a number- "))
            print("---------------------------------")
            if z>10:
                print("Abbe Saaley!")
            else:
                print(f"computer's number-{u} // your number-{z}")
                print("---------------------------------")
                if u == z:
                    print("you are out")
                    print("---------------------------------")
                    break
                else:
                    y += z
                    print(f"your score is {y}")
                    print("---------------------------------")
                    if y == 50:
                        print("you made a half century")
                        print("---------------------------------")
                    elif y == 100:
                        print("nice, you made century")
                        print("---------------------------------")
                    elif y == 0:
                        print("bad luck")
                        print("---------------------------------")
                    if y>x:
                        break
        print("Calculating", end=" ")
        for i in range(0, 5):
            print(".", end=" ")
            time.sleep(1)
        print("\n")
        print("---------------------------------")
        print(f"you scored {y} runs")
        print("---------------------------------")

        if x > y:
            print("computer won this match")
            print("---------------------------------")
        elif x < y:
            print("you won the match")
            print("---------------------------------")
        elif x == y:
            print("match is tied")
            print("---------------------------------")
            print("it's time for superover")
            print("---------------------------------")
            print("computer will bat first")
            print("---------------------------------")
            tf = 0
            ti = 0
            tj = 0
            while tf < 6:
                tg = random.choice(w)
                th = int(input("enter your number- "))
                print("---------------------------------")
                if th > 10:
                    print("Abbe Saaley!")
                else:
                    if tg == th:
                        print("you are out")
                        print("---------------------------------")
                    else:
                        ti += tg
                        print(f"your score is {ti} runs")
                        print("---------------------------------")
                        tj += 1
                        print(f"balls played {tj}")
                        print("---------------------------------")
                tf += 1
            print(f"computer's score is {ti}")
            print("---------------------------------")
            print(f"you have to score {ti} runs")
            print("---------------------------------")
            print("now it's your turn to bat")
            print("---------------------------------")
            ta = 0
            td = 0
            te = 0
            while ta < 6:
                tb = random.choice(w)
                tc = int(input("enter your number- "))
                print("---------------------------------")
                if tc > 10:
                    print("Abbe Saaley!")
                else:
                    if tb == tc:
                        print("you are out")
                        print("---------------------------------")
                    else:
                        td += tc
                        print(f"your score is {td} runs")
                        print("---------------------------------")
                        te += 1
                        print(f"balls played-{te}")
                        print("---------------------------------")
                        if td > ti:
                            break
                ta += 1
                print(f"your final score is {td}")
                print("---------------------------------")
                if ti > td:
                    print("computer won this match")
                    print("---------------------------------")
                elif ti < td:
                    print("you won the match")
                    print("---------------------------------")
                elif td == ti:
                    tk = input("choose between heads(h) or tails(t)- ")
                    print("---------------------------------")
                    tl = thy(tk)
                    print(f"your choice is {tl}")
                    print("---------------------------------")
                    tm = random.choice(k)
                    print("calculating", end=" ")
                    for i in range(0, 5):
                        print(".", end=" ")
                        time.sleep(1)
                    print("\n")
                    print("---------------------------------")
                    if tm == tl:
                        print("you won the match")
                        print("---------------------------------")
                    else:
                        print("computer wins the match")
                        print("---------------------------------")
    if ab=="bw":
        print("computer chooses to bowl")
        print("---------------------------------")
        d=0
        r=0
        while True:
            n=random.choice(w)
            s=int(input("enter a number- "))
            print("---------------------------------")
            if s>10:
                print("Abbe Saaley!")
            else:
                print(f"computer's number-{n} // your number-{s}")
                print("---------------------------------")
                if n==s:
                    print("you are out")
                    print("---------------------------------")
                    break
                else:
                    d+=s
                    print(f"your score is {d}")
                    print("---------------------------------")
                    if d==50:
                        print("you made a half century")
                        print("---------------------------------")
                    elif d==100:
                        print("nice, you made century")
                        print("---------------------------------")
                    elif d==0:
                        print("bad luck")
                        print("---------------------------------")
        print("Calculating", end=" ")
        for i in range(0, 5):
            print(".", end=" ")
            time.sleep(1)
        print("\n")
        print("---------------------------------")
        print(f"you scored {d} runs")
        print("---------------------------------")
        print(f"computer needs to score {d} runs")
        print("---------------------------------")
        time.sleep(2)
        print("now it's computer's batting")
        print("---------------------------------")
        while True:
            o = random.choice(w)
            q=int(input("enter a number- "))
            print("---------------------------------")
            if q>10:
                print("Abbe Saaley!")
            else:
                print(f"computer's number-{o} // your number-{q}")
                print("---------------------------------")
                if o==q:
                    print("computer is out")
                    print("---------------------------------")
                    break
                else:
                    r+=o
                    print(f"computer's score is {r}")
                    print("---------------------------------")
                    if r==50:
                        print("computer made half century")
                        print("---------------------------------")
                    elif r==100:
                        print("computer made century")
                        print("---------------------------------")
                    elif r==0:
                        print("bad luck of computer")
                        print("---------------------------------")
                    if r>d:
                        break
        print("Calculating", end=" ")
        for i in range(0, 5):
            print(".", end=" ")
            time.sleep(1)
        print("\n")
        print("---------------------------------")
        print(f"computer scored {r} runs")
        print("---------------------------------")
        if d>r:
            print("you won the game")
            print("---------------------------------")
        elif d<r:
            print("computer won the game")
            print("---------------------------------")
        elif d==r:
            print("match tied")
            print("---------------------------------")
            print("it's time for superover")
            print("---------------------------------")
            print("you will bat first")
            print("---------------------------------")
            ta = 0
            td = 0
            te = 0
            while ta < 6:
                tb = random.choice(w)
                tc = int(input("enter your number- "))
                print("---------------------------------")
                if tc > 10:
                    print("Abbe Saaley!")
                else:
                    if tb == tc:
                        print("you are out")
                        print("---------------------------------")
                    else:
                        td += tc
                        print(f"your score is {td} runs")
                        print("---------------------------------")
                        te += 1
                        print(f"balls played-{te}")
                        print("---------------------------------")
                ta += 1
            print(f"your final score is{td}")
            print("---------------------------------")
            print(f"computer has to score {td} runs")
            print("---------------------------------")
            print("now it's computer's turn to bat")
            print("---------------------------------")
            tf = 0
            ti = 0
            tj = 0
            while tf < 6:
                tg = random.choice(w)
                th = int(input("enter your number- "))
                print("---------------------------------")
                if th > 10:
                    print("Abbe Saaley!")
                else:
                    if tg == th:
                        print("you are out")
                        print("---------------------------------")
                    else:
                        ti += tg
                        print(f"your score is {ti} runs")
                        print("---------------------------------")
                        tj += 1
                        print(f"balls played {tj}")
                        print("---------------------------------")
                    if ti > td:
                        break
                tf += 1
            print(f"computer's score is {ti}")
            print("---------------------------------")
            if ti > td:
                print("computer won this match")
                print("---------------------------------")
            elif ti < td:
                print("you won the match")
                print("---------------------------------")
            elif td == ti:
                tk = input("choose between heads(h) or tails(t)- ")
                print("---------------------------------")
                tl = thy(tk)
                print(f"your choice is {tl}")
                print("---------------------------------")
                tm = random.choice(k)
                print("calculating", end=" ")
                for i in range(0, 5):
                    print(".", end=" ")
                    time.sleep(1)
                print("\n")
                print("---------------------------------")
                if tm == tl:
                    print("you won the match")
                    print("---------------------------------")
                else:
                    print("computer wins the match")
                    print("---------------------------------")