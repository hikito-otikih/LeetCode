class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        int ans = 0;
        for (int i = 0; i < points.size(); i ++)
        {
            vector<vector<int> > vi;
            for (int j = i + 1; j < points.size(); j ++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int k = __gcd(x, y);
                if (k == 0) k = x ? x : y;
                x /= k;
                y /= k;
                if (x < 0 || (x == 0 && y < 0)) 
                {
                    x = - x;
                    y = - y;
                }
                vi.push_back({x, y});
            }
            sort(vi.begin(), vi.end());
            for (int i = 0; i < vi.size(); i ++)
            {
                int j = i;
                while (j + 1 < vi.size() && vi[j + 1] == vi[j]) j ++;
                ans = max(ans, j - i + 1);
                i = j;
            }
        }
        return ans + 1;
    }
};