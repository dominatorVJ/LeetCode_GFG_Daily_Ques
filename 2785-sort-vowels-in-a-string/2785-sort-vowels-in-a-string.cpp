class Solution
{
    public:
        string sortVowels(string s)
        {
            int n = s.size();
            string vo = "";
            for (auto c: s)
            {
                if (isVowel(c))
                {
                    vo += c;
                }
            }
            sort(vo.begin(), vo.end());

            for (int i = 0, j = 0; i < n; i++)
            {
                if (isVowel(s[i]))
                {
                    s[i] = vo[j++];
                }
            }
            return s;
        }
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;

        return false;
    }
};