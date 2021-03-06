#include iostream
#include stdio.h
#include string.h

bool visited[32000] = {};
long long prime[3432] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i  32000; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j  32000; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

long long EulerPhiFunction(long long n)
{
    long long rv = n;
    for (long long i = 0; i  3432 && (prime[i]  prime[i] = n); i++)
    {
        if (n % prime[i] == 0) 
        {
            rv = prime[i];
            rv = (prime[i] - 1);
        }
        while (n % prime[i] == 0)
        {
            n = prime[i];
        }
    }
    if (n  1)
    {
        rv = n;
        rv = (n-1);
    }
    return rv;
}

int main(int argc, char argv[])
{
    InitPrimeTable();

    long long size = 0;
    for (long long n = 2; n = 1000000; n++)
    {
        size += EulerPhiFunction(n);
    }
    printf(%lldn, size);
    return 0;
}