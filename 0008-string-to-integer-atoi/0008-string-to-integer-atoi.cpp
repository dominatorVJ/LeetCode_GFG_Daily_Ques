class Solution
{
    public:
        int myAtoi(string str)
        {
            int sign = 1, base = 0, i = 0;
           	//Skip spaces
            while (str[i] == ' ')
            {
                i++;
            }
            //Check the sign
            if (i < str.size() && (str[i] == '-' || str[i] == '+'))
            {
                sign = str[i++] == '-' ? -1 : 1;
            }
            // check for digit and build the number
            while (i < str.size() && isdigit(str[i]))
            {
                // Handle the special case for range in [INT_MIN,INT_MAX]
                if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
                {
                    if (sign == 1) return INT_MAX;
                    else return INT_MIN;
                }
                base = 10 * base + (str[i++] - '0');
            }
            return base * sign;
        }
};