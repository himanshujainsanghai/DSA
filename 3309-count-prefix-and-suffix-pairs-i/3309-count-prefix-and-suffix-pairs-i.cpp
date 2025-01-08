

#include <string>
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string test = words[i];
                string subject = words[j];
                if (test.size() > subject.size())
                    continue;
                // if((subject.rfind(test) == subject.size()-test.size()) &&
                // (subject.rfind(test) == 0)){
                //     count++;
                // }
                bool isPrefix = subject.compare(0, test.size(), test) == 0;
                bool isSuffix = subject.compare(subject.size() - test.size(),
                                                test.size(), test) == 0;

                if (isPrefix && isSuffix) {
                    count++;
                }
            }
        }

        // string test = "ba";
        // string subject = "cvbnnnba";
        // cout<<subject.rfind(test);

        return count;
    }
};