class Solution {
public:
    vector<int> parent, rankv;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rankv[px] < rankv[py])
            parent[px] = py;
        else if (rankv[px] > rankv[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rankv[px]++;
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        // Step 1: Sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        // Step 2: Initialize DSU
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Step 3: Initially connect 0 and firstPerson
        unite(0, firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> people;

            // Step 4: Union all meetings at the same time
            int j = i;
            while (j < meetings.size() && meetings[j][2] == time) {
                unite(meetings[j][0], meetings[j][1]);
                people.push_back(meetings[j][0]);
                people.push_back(meetings[j][1]);
                j++;
            }

            // Step 5: Rollback invalid unions
            for (int p : people) {
                if (find(p) != find(0)) {
                    parent[p] = p;  // break connection
                }
            }

            i = j;
        }

        // Step 6: Collect all who know the secret
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0))
                result.push_back(i);
        }

        return result;
    }
};
