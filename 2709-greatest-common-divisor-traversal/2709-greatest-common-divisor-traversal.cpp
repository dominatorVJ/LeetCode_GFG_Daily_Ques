class Solution {
public:
    class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
};

bool canTraverseAllPairs(vector<int>& nums1) {
    bool flag = 0;
    if(flag) return false;
   bool ansss1 = solve(nums1);
        return ansss1;
}
    bool solve(vector<int>& num1){
        bool anss1 = solve1(num1);
        return anss1;
    }
    bool solve1(vector<int>& num2){
        bool ans1 = solve2(num2);
        return ans1;
    }
    bool solve2(vector<int>& nums){
         int n = nums.size();
    UnionFind uf(n);

    unordered_map<int, vector<int>> factors;

    for (int i = 0; i < n; i++) {
        for (int j = 2; j * j <= nums[i]; j++) {
            if (nums[i] % j == 0) {
                factors[j].push_back(i);
                while (nums[i] % j == 0) {
                    nums[i] /= j;
                }
            }
        }
        if (nums[i] > 1) {
            factors[nums[i]].push_back(i);
        }
    }

    for (auto& factorPair : factors) {
        vector<int>& indices = factorPair.second;
        for (int i = 1; i < indices.size(); i++) {
            uf.unite(indices[i - 1], indices[i]);
        }
    }

    int root = uf.find(0);
    for (int i = 1; i < n; i++) {
        if (uf.find(i) != root) {
            return false;
        }
    }

    return true;
    }
};