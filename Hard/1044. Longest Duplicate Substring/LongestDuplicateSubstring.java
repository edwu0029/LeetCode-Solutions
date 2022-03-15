/*
LeetCode Hard: 1044. Longest Duplicate Substring
https://leetcode.com/problems/longest-duplicate-substring/

Check LongestDuplicateSubstring.cpp for brief solution explanation.
*/
class Solution {
    public class E{
        public int f, s, i;
    }
    public boolean check_same(E a, E b){
        return a.f==b.f&&a.s==b.s;
    }
    public String longestDupSubstring(String s) {
        int N = s.length();
        //Build Suffix array
        int[][]rank = new int[(int)Math.floor(Math.log(N)/Math.log(2))+2][N];
        for(int i = 0;i<N;i++){
            rank[0][i] = s.charAt(i)-'a';
        }
        int t = 0;
        for(int k = 1, cnt = 1;(1<<(k-1))<N;k++, cnt<<=1){
            t = k;
            E[]p = new E[N];
            for(int i = 0;i<N;i++){
                p[i] = new E();
                p[i].f = rank[k-1][i];
                p[i].s = (i+cnt<N)?rank[k-1][i+cnt]:-1;
                p[i].i = i;
            }
            Arrays.sort(p, new Comparator<E>() {
                public int compare(E a, E b) {
                    if(a.f==b.f){
                        if(a.s==b.s){
                            return Integer.compare(a.i, b.i);
                        }else{
                            return Integer.compare(a.s, b.s);
                        }
                    }else{
                        return Integer.compare(a.f, b.f);
                    }
                }
            });
            for(int i = 0;i<N;i++){
                if(i>0&&check_same(p[i], p[i-1])){
                    rank[k][p[i].i] = rank[k][p[i-1].i];
                }else{
                    rank[k][p[i].i] = i;
                }
            }
        }
        int[]sa = new int[N];
        for(int i = 0;i<N;i++){
            sa[rank[t][i]] = i;
        }
        //Kasai Algorithm
        int[]lcp = new int[N];
        int k = 0;
        for(int i = 0;i<N;i++){
            if(rank[t][i]==N-1){
                k = 0;
                continue;
            }
            int j = sa[rank[t][i]+1];
            while(i+k<N&&j+k<N&&s.charAt(i+k)==s.charAt(j+k)){
                k++;
            }
            lcp[rank[t][i]] = k;
            k = Math.max(0, k-1);
        }
        //Find answer substring
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
            return s.substring(l, l+len);
        }
    }
}