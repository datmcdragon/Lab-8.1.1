#include <iostream>

using namespace std;

int CountSim(const char* s, const char* cs)
{
    int count = 0;
    int j, k;
    for (int i = 0; s[i] != '\0'; i++)
    {
        j = 0;
        k = i;
        while (cs[j] != '\0')
        {
            if (s[k] == cs[j] && s[k] != '\0')
            {
                j++;
                k++;
            }
            else
                break;
        }
        if (cs[j] == '\0')
            count++;
    }
    return count;
}

bool SearchSim(const char* cs, int& i1, int& i2)
{
    for (int i = i2; cs[i] != '\0'; i++)
        if (cs[i] == '+' &&
            cs[i + 1] == '-' && cs[i + 1] != '\0' &&
            cs[i + 2] == '=' && cs[i + 2] != '\0')
        {
            i1 = i;
            i2 = i + 2;
            return true;
        }
    return false;
}

void ReplaceSim(char* cs)
{
    int i1 = 0, i2 = 0;

    while (SearchSim(cs, i1, i2))
    {
        cs[i1] = '*';
        cs[i1 + 1] = '*';
        for (int i = i2; cs[i] != '\0'; i++)
        {
            cs[i] = cs[i + 1];
        }
    }
}


int main()
{
    char cs[30] = "123+-=123+-=123+-=123";
    char s[] = "+-=";
    cout << CountSim(cs, s) << endl;

    ReplaceSim(cs);
    cout << cs << endl;

    return 0;
}