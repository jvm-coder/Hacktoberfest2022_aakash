

def howSumRecur(arr, target) -> list or None:
    if target == 0:
        return []
    if target < 0:
        return None

    for i in range(len(arr)):
        remainder = target - arr[i]
        res = howSumRecur(arr, remainder)
        if res is not None:
            res.append(arr[i])
            return res
    return None


def howSumDP(arr, target, memo={}) -> list or None:

    if target in memo:
        return memo[target]
    if target == 0:
        return []
    if target < 0:
        return None

    for i in range(len(arr)):
        remainder = target - arr[i]
        res = howSumDP(arr, remainder)
        if res is not None:
            res.append(arr[i])
            memo[target] = res
            return memo[target]
    memo[target] = None
    return None


arr = [5, 2, 3]
print(howSumDP(arr, 7))

# [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
# [[15,13,2,5],[1,4,8,10],[9,3,6,7],[11,14,12,16]]
# [[15,13,2,5],[14,3,4,1],[12,6,8,9],[11,10,7,16]]


# [[15,13,2,5],[9,8,8,10],[1,3,6,7],[11,14,12,16]]
