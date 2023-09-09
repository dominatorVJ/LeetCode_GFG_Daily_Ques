class Solution
{
    public:
        bool isPalindrome(string s)
        {
            int n = s.size();
            int l = 0;
            int h = n - 1;

            while (l <= h)
            {
               	// isalnum check whether s[i] is digit or upper or lower case letter
                while (l < h && !isalnum(s[l])) l++;
                while (l < h && !isalnum(s[h])) h--;

                if (toupper(s[l]) != toupper(s[h])) return false;
                l++;
                h--;
            }
            return true;
        }
};