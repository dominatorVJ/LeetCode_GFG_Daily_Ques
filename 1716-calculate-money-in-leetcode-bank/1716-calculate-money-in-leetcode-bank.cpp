class Solution
{
    public:
        int totalMoney(int n)
        {
            int money = 0;
            int i = 1;
            while (i != n + 1)
            {
                if (i < 8)
                {
                    money += i;
                }
                else if (i > 7 && i % 7 == 0)
                {
                    money += 1 + ((i - 1) % 7) + (i - 1) / 7;
                }
                else
                {
                    money += (i % 7) + i / 7;
                }
                i++;
            }
            return money;
        }
};