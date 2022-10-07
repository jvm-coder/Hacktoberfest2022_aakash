
# to generate all paths from start to finsih 

m = []
r1 = [int(x) for x in input().split(" ")]
r2 = [int(x) for x in input().split(" ")]
r3 = [int(x) for x in input().split(" ")]

m.append(r1)
m.append(r2)
m.append(r3)

print(m)
path=[]

def allpath(m,path,i,j):
    r , c = len(m) , len(m[0])
    #path reached end
    if i == r-1 and j == c-1:
        print(path+[m[i][j]])
        return 

    path.append(m[i][j])
    #move down
    if 0<=i+1<=r-1 and 0<=j<=c-1:
        allpath(m,path,i+1,j)
    #move up
    if 0<=i<=r-1 and 0<=j+1<=c-1:
        allpath(m,path,i,j+1)
    #move diagonal
    #if 0<=i+1<=r-1 and 0<=j+1<=c-1:
    #   allpath(m,path,i+1,j+1)
    
    path.pop()


allpath(m,path,0,0)
