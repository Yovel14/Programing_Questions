class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> cups (102, vector<double>(102,0));
        cups[0][0] = poured;
        for(int row = 0; row <= query_row; row++)
            for(int cup = 0; cup <=row;cup++)
            {
                double fill = (cups[row][cup]-1)/2;
                if(fill>0)
                {
                    cups[row+1][cup] +=fill;
                    cups[row+1][cup+1] +=fill;
                }
            }

        return min(1.0, cups[query_row][query_glass]);
    }
};