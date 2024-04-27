class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long m=grid.length();
        long long n=grid[0].length();
        for(long long i=0;i<m;i++){
            for(long long j=0;j<n;j++){
                if(grid[i][j]){
                    long long sum_m=-1;
                    long long sum_n=-1;

                    for(long long p=0;p<m;p++){
                        if(grid[p][j]){
                            sum_n++;
                        }
                    }
                    for(long long p=0;p<n;p++){
                        if(grid[i][p]){
                            sum_m++;
                        }
                    }                    
                    ans+=sum_m*sum_n;
                }

            }

        }
        return ans;
    }
};