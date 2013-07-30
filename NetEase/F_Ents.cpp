#include <stdio.h>
#define MAX_N 10000001
long result[MAX_N];
void F_Ents(long K, long P)
{
    result[0] = result[1] = 0;
    result[2] = 1%P;
    for(long i=3; i<=K; ++i)
    {
        if(i%2 == 0)
        {
            result[i] = result[i/2] + result[i-1];
        }
        else
        {
            result[i] = result[i-1];
        }
        if(result[i] >= P) result[i] -= P;
    }
}

int main()
{
    long K,P;

    scanf("%ld %ld", &K, &P);
    F_Ents(K, P);
    printf("%ld", result[K]);
    return 0;
}
