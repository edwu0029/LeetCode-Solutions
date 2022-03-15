/*
LeetCode Hard: 1044. Longest Duplicate Substring
https://leetcode.com/problems/longest-duplicate-substring/
 
Brief Solution Explanation:
N = Length of string s
- To do this, we can use a suffix array and longest common prefix(LCP) array to solve this problem
- We can first create a suffix array of the s in O(NlogNlogN) time
    - For details: https://web.stanford.edu/class/cs97si/suffix-array.pdf
    - We do this by sorting based on the first some power of two characters of all the suffixes
    - Ex. We sort by first character, first two characters, first four characters, ... first 2^k characters
    - From this, we can easily merge answers from the 2^m step to get 2^(m+1) step using a "sparse table-esque" approach
- It can then be seen that the longest duplicate substring is the maximum LCP of the suffix array
- We can then construct the LCP array from the suffix array using Kasai's algorithm
    - For details: https://cp-algorithms.web.app/string/suffix-array.html in the LCP section
    - This takes O(N) time
- When finding the maximum LCP, we can also keep track of which index it is to retrieve the substring which is our answer
- Note: My original idea was to use binary search + rolling hash, but it seems that a few testcases were recently added to break this solution

- The code below is a O(NlogNlogN) implementation, but this problem can be solved in O(NlogN)
- Instead of using the STL sort function when constructing the suffix array, we can use a Radix sort which runs in O(N) on pairs
    - This reduces the overall time complexity by a log factor, giving us O(NlogN) for the whole problem
Time Complexity: O(NlogNlogN)
Memory Complexity: O(NlogN)
*/
class Solution {
public:
    struct E{
        int f, s, i;
    };
    bool check_same(E a, E b){
        return a.f==b.f&&a.s==b.s;
    }
    string longestDupSubstring(string s) {
        int N = s.size();
        //Construct suffix and rank array
        vector<vector<int>>rank(log2(N)+2, vector<int>(N, 0));
        for(int i = 0;i<N;i++){
            rank[0][i] = s[i]-'a';
        }
        int t = 0;
        for(int k = 1, cnt = 1;(1<<(k-1))<N;k++, cnt<<=1){
            t = k;
            vector<E>p(N); //Rank for first 2^k characters for easch substring
            for(int i = 0;i<N;i++){
                p[i].f = rank[k-1][i];
                p[i].s = (i+cnt<N)?rank[k-1][i+cnt]:-1;
                p[i].i = i;
            }
            sort(p.begin(), p.end(), [](E a, E b){
                if(a.f==b.f){
                    if(a.s==b.s){
                        return a.i<b.i;
                    }else{
                        return a.s<b.s;
                    }
                }else{
                    return a.f<b.f;
                }
            });
            for(int i = 0;i<N;i++){
                //If certain substrings have the same lexographic order, we need to make sure thy have the same rank
                if(i>0&&check_same(p[i], p[i-1])){
                    rank[k][p[i].i] = rank[k][p[i-1].i];
                }else{
                    rank[k][p[i].i] = i;
                }
            }
        }
        vector<int>sa(N);
        for(int i = 0;i<N;i++){
            sa[rank[t][i]] = i;
        }
        //Construct lcp array(Kasai et al)
        vector<int>lcp(N);
        int k = 0;
        for(int i = 0;i<N;i++){
            if(rank[t][i]==N-1){
                k = 0;
                continue;
            }
            int j = sa[rank[t][i]+1];
            while(i+k<N&&j+k<N&&s[i+k]==s[j+k]){
                k++;
            }
            lcp[rank[t][i]] = k;
            k = max(0, k-1);
        }
        //Find the answer substring
        int len = 0, l = 0;
        for(int i = 0;i<N;i++){
            if(len<lcp[i]){
                l = sa[i];
                len = lcp[i];
            }
        }
        if(len==0){
            return "";
        }else{
            return s.substr(l, len);
        }
    }
};