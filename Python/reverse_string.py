from typing import List


def reverseString(s: List[str]) -> None:
    l_idx = 0
    r_idx = len(s) - 1
    while l_idx < r_idx:
        s[l_idx], s[r_idx] = s[r_idx], s[l_idx]
        l_idx += 1
        r_idx -= 1
