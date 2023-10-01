class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int sz = s.size();
        while(i < sz){
            int j = i;
            while(j < s.size() && s[j] != ' '){
                j++;
            }
            int k = j-1;
            while(i < k){
                swap(s[i++], s[k--]);
            }
            i = j+1;
        }
        return s;
    }
};
