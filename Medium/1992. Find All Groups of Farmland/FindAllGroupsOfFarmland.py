'''
LeetCode Medium: 1992. Find All Groups of Farmland
https://leetcode.com/problems/find-all-groups-of-farmland/

Check FindAllGroupsOfFarmland.cpp for brief solution explanation.
'''
class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        def check_bounds(r, c, M, N) -> bool:
            return 0<=r<M and 0<=c<N
        M, N = len(land), len(land[0])
        vis = [[False for i in range(N)]for i in range(M)]
        ans = []
        for i in range(M):
            for j in range(N):
                if vis[i][j]==True or land[i][j]==0:
                    continue
                mnr, mnc, mxr, mxc = i, j, i, j
                ti = i
                while check_bounds(ti, j, M, N)==True and land[ti][j]==1:
                    mxr = ti
                    ti+=1
                tj = j
                while check_bounds(i, tj, M, N)==True and land[i][tj]==1:
                    mxc = tj
                    tj+=1
                for r in range(mnr, mxr+1):
                    for c in range(mnc, mxc+1):
                        vis[r][c] = True
                ans.append([mnr, mnc, mxr, mxc])
        return ans