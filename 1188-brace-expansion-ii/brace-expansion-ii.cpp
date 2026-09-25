class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        return dfs(expression, 0, (int)expression.length() - 1);
    }

private:
    vector<string> dfs(const string& expression, int s, int e) {
        set<string> ans;
        vector<vector<string>> groups{{}};
        int layer = 0;
        int left = 0;

        for (int i = s; i <= e; ++i) {
            char c = expression[i];

            if (c == '{') {
                layer++;
                if (layer == 1) {
                    left = i + 1;
                }
            }
            else if (c == '}') {
                layer--;
                if (layer == 0) {
                    vector<string> nested = dfs(expression, left, i - 1);
                    merge(groups, nested);
                }
            }
            else if (c == ',' && layer == 0) {
                groups.push_back({});
            }
            else if (layer == 0) {
                merge(groups, {string(1, c)});
            }
        }

        for (const auto& group : groups) {
            for (const string& word : group) {
                ans.insert(word);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }

    void merge(vector<vector<string>>& groups, const vector<string>& group) {
        if (groups.back().empty()) {
            groups.back() = group;
            return;
        }

        vector<string> merged;
        for (const string& a : groups.back()) {
            for (const string& b : group) {
                merged.push_back(a + b);
            }
        }
        groups.back() = merged;
    }
};