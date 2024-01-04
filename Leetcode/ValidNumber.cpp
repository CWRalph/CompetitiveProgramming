#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool verifyInt(string s)
    {
        if (s.length() == 0) return false;
        int i = 0;
        if (s[0] == '-' || s[0] == '+') ++i;
        if (i == s.length()) return false;
        for (;i < s.length(); i++){if (!isdigit(s[i])) return false;}
        return true;
    }

    bool isNumber(string s) {
        //Check alphabetical
        int i = 0;
        for (auto& i : s) i = tolower(i);
        for (auto i : s) if (isalpha(i) && i != 'e') return false;


        //Check for too many dots or es
        int count = 0,count2 = 0;
        for (int i = 0; (i = s.find('.', i)) != std::string::npos; i++) {count++;}
        for (int i = 0; (i = s.find('e', i)) != std::string::npos; i++) {count2++;}
        if (count > 1 || count2 > 1) return false;


        //Check for a first e
        if (s[0] == 'e') return false;

        //Now on to the fun stuff
        if (s[0] == '-' || s[0] == '+')
        {
            if (s.length() > 1) i++;
            else return false;
        }


        for (; i < s.length(); i++)
        {
            if (s[i] == '.')
            {
                if (i == s.length() - 1)
                {
                    if (i > 0 && isdigit(s[i - 1])) continue;
                    else return false;
                }
                else
                {
                    if (i > 0 && isdigit(s[i - 1])) continue;
                    else if (s.length() > 1 && (isdigit(s[i + 1]) || s[i + 1] == '-' || s[i + 1] == '+')) continue;
                    else return false;
                }
            }
            else if (s[i] == 'e' && i > 0 && (isdigit(s[i-1]) || s[i - 1] == '.')) return verifyInt(s.substr(i + 1, s.length() - i));
            else if (!isdigit(s[i])) return false;
        }
        return true;
    }
};