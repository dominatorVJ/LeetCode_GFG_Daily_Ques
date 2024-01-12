class Solution
{
    public:
        bool halvesAreAlike(string s)
        {
            int n = s.size();
            string a = "", b = "";
            for (int i = 0; i < n / 2; i++)
            {
                a += s[i];
            }
            for (int i = n / 2 ; i < n; i++)
            {
                b += s[i];
            }
            return countVowels(a) == countVowels(b);
        }
    int countVowels(string s)
    {
        int cnt = 0;
       
        for (auto c: s)
        {
            c =  tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                cnt++;
            }
        }
        return cnt;
    }
};