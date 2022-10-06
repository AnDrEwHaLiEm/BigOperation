#include <bits/stdc++.h>
using namespace std;
#define sz(v) (int)(v.size())
#define all(v) v.begin(), v.end()
class BigOperation
{

public:
    bool isSmaller(string a, string b)
    {
        int n1 = sz(a), n2 = sz(b);

        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;

        for (int i = 0; i < n1; i++)
            if (a[i] < b[i])
                return true;
            else if (a[i] > b[i])
                return false;

        return false;
    }

    string minusString(string a, string b)
    {
        string ans = "";
        bool negative = false;
        if (isSmaller(a, b))
        {
            negative = true;
            swap(a, b);
        }

        reverse(all(a));
        reverse(all(b));

        int rem = 0;
        int i = 0, j = 0;
        while (i < sz(a) && j < sz(b))
        {
            int x = (a[i] - '0');
            int y = (b[j] - '0');
            int sub = x - y - rem;

            if (sub < 0)
            {
                sub = sub + 10;
                rem = 1;
            }
            else
                rem = 0;
            char num = sub + '0';
            ans += num;
            i++;
            j++;
        }

        while (i < sz(a))
        {
            int x = a[i] - '0';
            int sub = x - rem;

            if (sub < 0)
            {
                sub = sub + 10;
                rem = 1;
            }
            else
                rem = 0;
            char num = sub + '0';
            ans += num;
        }
        if (negative)
            ans += '-';
        reverse(all(ans));
        bool ok = false;
        string returnans = "";
        for (int i = 0; i < sz(ans); i++)
        {
            if ((ans[i] >= '1' && ans[i] <= '9') && !ok)
            {
                ok = true;
            }
            if (ok)
            {
                returnans += ans[i];
            }
            if (ans[i] == '-')
                returnans += '-';
        }
        if (!ok)
            return "0";
        return returnans;
    }

    string plusString(string a, string b)
    {
        string ans = "";
        int rem = 0;
        reverse(all(a));
        reverse(all(b));
        if (sz(b) > sz(a))
            swap(a, b);
        int i = 0, j = 0;
        while (i < sz(a) && j < sz(b))
        {
            int x = a[i] - '0';
            int y = b[j] - '0';
            int sum = x + y + rem;
            rem = sum / 10;
            sum = sum % 10;
            char num = sum + '0';
            ans += num;
            i++;
            j++;
        }
        while (i < sz(a))
        {
            int x = a[i] - '0';
            int sum = x + rem;
            rem = sum / 10;
            sum = sum % 10;
            char num = sum + '0';
            ans += num;
            i++;
        }
        if (rem)
        {
            char num = rem + '0';
            ans += num;
        }
        reverse(all(ans));
        return ans;
    }
    string multiplyString(string a, string b)
    {

        if (sz(a) == 0 || sz(b) == 0 || a == "0" || b == "0")
            return "0";
        bool negative = false;
        if (a[0] == '-' ^ b[0] == '-')
        {
            negative = true;
        }
        vector<int> result(sz(a) + sz(b) + 1, 0);
        reverse(all(a));
        reverse(all(b));
        for (int i = 0; i < sz(a); i++)
        {
            if (a[i] == '-')
                continue;
            int x = a[i] - '0';
            for (int j = 0; j < sz(b); j++)
            {
                if (b[j] == '-')
                    continue;
                int y = b[j] - '0';
                int mul = (x * y) + result[i + j];
                result[i + j] = (mul % 10);
                result[i + j + 1] = (result[i + j + 1] + (mul / 10));
            }
        }
        string ans = "";
        reverse(all(result));
        if (negative)
            ans += '-';
        bool ok = false;

        for (int i = 0; i < sz(result); i++)
        {
            if ((result[i] >= 1 && result[i] <= 9) && ok == false)
            {
                ok = true;
            }
            if (ok)
            {
                char num = result[i] + '0';
                ans += num;
            }
            
        }
        return ans;
    }
};
