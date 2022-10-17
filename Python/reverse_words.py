from sys import stdin

#function to reverse a word
def revrseWord(string,start,end):

    reverse = ""                                    #empty string

    while start < end:
        reverse = string[start] + reverse           #adding element in empty string that will make it reverse (LIFO)
        start += 1
    return reverse

#function to reverse whole string
def reverseEachword(string):
    n = len(string)
    previousSpaceIndex = -1                         #assuming blank space position as -1
    ans = ""                                        #empty string
    i=0

    while i<n:
        if string[i] == " " :                       #finding space between word
            ans += (revrseWord(string,previousSpaceIndex + 1 , i) + " ") #revresing the word within spaces and adding in empty string
            previousSpaceIndex = i                  #updating space index
        
        i += 1

    #as we are checking words between spaces our last word will be left because at the end of string there is no blank space
    ans += (revrseWord(string , previousSpaceIndex + 1, i) + " ")

    return ans





#main
string = stdin.readline().strip()
ans = reverseEachword(string)
print(ans)