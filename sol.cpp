class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        vector<vector<int>> vec;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            int index = i + 1;
            while (index < n && s[index] == s[i])
                index++;
            if (index - i >= 3) {
                temp.push_back(i);
                temp.push_back(index - 1);
                vec.push_back(temp);
                temp.clear();
            }
            i = index - 1;
        }
        sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[0] < b[0]; 
        });
        return vec;
    }
};
