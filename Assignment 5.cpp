#include <iostream>
#include <cstring>
using namespace std;

string longest_common_substring(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    int max_length = 0;
    int end_pos = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_length)
                {
                    max_length = dp[i][j];
                    end_pos = i - 1;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    string result = "";
    for (int i = end_pos - max_length + 1; i <= end_pos; i++)
    {
        result += s1[i];
    }
    return result;
}

int main()
{
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;
    string lcs = longest_common_substring(s1, s2);
    cout << "Longest Common Substring: " << lcs << endl;
    return 0;
}
