def longestCommonPrefix(self, strs: list[str]) -> str:
        res = min(strs, key = len)
        for i in strs:
            while res != i[:len(res)]:
                res = res[:-1]
        return res


# A function to find the longest common prefix string amongst an array of strings.

# If there is no common prefix, return an empty string "".
# Input: strs = ["flower","flow","flight"]
# Output: "fl"
# Input: strs = ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.