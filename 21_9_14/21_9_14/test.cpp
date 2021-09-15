//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        if (s.empty())
//            return 0;
//        unordered_map<char, int> m1;
//        int res = 0;
//        int pos = 0;
//        for (int i = 0; i < s.size(); ++i) {
//            if (m1.find(s[i]) == m1.end()) {
//                m1[s[i]]++;
//                res = max(res, (int)m1.size());
//            }
//            else {
//                while (pos < s.size() && m1.find(s[i]) != m1.end()) {
//                    m1.erase(s[pos++]);
//                }
//                m1[s[i]]++;
//                res = max(res, (int)m1.size());
//            }
//        }
//        return res;
//    }
//};