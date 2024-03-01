class Solution
{
    bool isSymetric(int i)
    {
        if (i < 10 || (i > 99 && i <= 999) || i == 10000) return false;
        if (i <= 99) return i % 10 == i / 10;
        else return i % 10 + (i / 10) % 10 == (i / 100) % 10 + (i / 1000);
    }
public:
    int countSymmetricIntegers(int low, int high)
    {
        int counter = 0;
        for (int i = low; i <= high; ++i)
            if (isSymetric(i)) ++counter;
        return counter;
    }
};