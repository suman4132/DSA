class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int s) {
        visited[s] = true;
        for (int key : rooms[s]) {
            if (!visited[key]) {
                dfs(rooms, visited, key);  
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();  
        vector<bool> visited(n, false);
        dfs(rooms, visited, 0); 

        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};
