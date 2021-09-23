'''
LeetCode Medium: 1239. Maximum Length of a Concatenated String with Unique Characters
https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

Check MaximumLengthOfAConcatenatedStringWithUniqueCharacters.cpp for brief solution explanation.
'''
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        N = len(arr)
        used = []
        for i in range(N):
            cur = 0
            for j in range(len(arr[i])):
                if cur&(1<<(ord(arr[i][j])-ord('a'))):
                    cur = 0
                    break
                else:
                    cur|=(1<<(ord(arr[i][j])-ord('a')))
            used.append(cur)
        ans = 0
        for mask in range(1<<N):
            cur, cnt_len = 0, 0
            check = True
            for i in range(N):
                if mask&(1<<i):
                    if used[i]==0 or cur&used[i]:
                        check = False
                        break
                    else:
                        cur|=used[i]
                        cnt_len+=len(arr[i])
            if check:
                ans = max(ans, cnt_len)
        return ans