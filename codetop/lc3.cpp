int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int start=0;
    map<char, int> mp;
    int ans = 0;
    for(int end=0;end<n;end++){
        mp[s[end]]++;
        while(mp[s[end]]>1){
            mp[s[start]]--;
            start++;
        }
        ans=max(ans,end-start+1);
    }
    return ans;
}