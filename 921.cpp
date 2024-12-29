class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int sum[n + 5], res = 0;
        s = ' ' + s;
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i ++)
        {
            sum[i] = sum[i - 1];
            if (s[i] == '(') sum[i] ++;
            else sum[i] --;
        }
        bool cnt[n + 5];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i ++)
            if (sum[i] < 0 && !cnt[-sum[i]]) cnt[-sum[i]] = 1, res ++;
        return sum[n] + 2 * res;
    }
};