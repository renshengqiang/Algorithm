#include <stdio.h>
void _Swap(char *str, int i, int j)
{
    char temp;
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}
//Desc: 打印所有的排列组合
//str:待排列的字符串，n字符串的长度
//return:组合数目
int PermGen(char *str, int n)
{
    int i;
    static nSolutions = 0;
    if(n == 1)
    {
        printf("%s\n", str);
        ++nSolutions;
    }
    for(i=0; i<n; ++i)
    {
        _Swap(str, i, n-1);
        PermGen(str, n-1);
        _Swap(str, i, n-1);
    }

    return nSolutions;
}

int main()
{
    char str[]="abcde";

    printf("\n %d solutions\n", PermGen(str, 5));

    return 0;
}
