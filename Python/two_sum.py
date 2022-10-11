#accepts a list and a target
#tries to return a pair of 2 integers present in the supplied list that sum up to target 
def twoSum(nums: list[int], target: int) -> tuple[int]:
        emptyDict = dict()
        myanswer = []

        for i, n in enumerate(nums):
            if n in emptyDict: # also add this number to the dict and find if target - n exists
                emptyDict[n].append(i) #appending the index    
 
            else: # add this number to the dict
                emptyDict[n] = [i]
                # print(f'{n} was added to the list')
                
            if target - n == n: # check if len(emptyDict[n]) >=2 
                if len(emptyDict[n]) >= 2:
                    # print(emptyDict)
                    return (emptyDict[n][0],emptyDict[n][1])
            else:
                if target - n in emptyDict: # target - n exists in empty dict
                    # print(emptyDict)
                    return (emptyDict[n][0], emptyDict[target - n][0])

        return (None,None) # nothing found
                

print(twoSum([1,2,3,4,5,6,7,8,9], 10))