class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int>mrow;
        unordered_set<int>mcol;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    mrow.insert(i);
                    mcol.insert(j);

                }
            }
        }
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(mrow.count(i)>0 || mcol.count(j)>0)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};