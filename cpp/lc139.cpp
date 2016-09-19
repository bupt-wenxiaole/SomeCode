class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int slen = s.length();
        vector<bool> have(slen, false);
        return wordBreak(s, 0, wordDict, slen, have);
    }
    bool wordBreak(string s, int prelen, unordered_set<string>& wordDict, int slen, vector<bool>& have)
    {
        if(prelen >= slen)
            return true;
        if(have[prelen])
            return false;
        have[prelen] = true;
        string curprefix = s.substr(0, prelen);
        for(auto word : wordDict)
        {
            string nextprefix = curprefix + word;
            int nextlen = nextprefix.length();
            if(nextprefix == s.substr(0, nextprefix.length()) && wordBreak(s, nextlen, wordDict, slen, have))
            {
                return true;
            }
        }
        return false;
    }
};