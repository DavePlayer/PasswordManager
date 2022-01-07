#include <iostream>
#include <random>
#include <vector>
#include <cmath>

class Crypto
{
public:
    std::string key = NULL;
    long long int p, q, euler, n, d, e;

    std::string createKey();
    bool isPrime(int n);
    int generatePrime(int n);
    int coPrime(int n, int euler);
    bool __gcd(int a, int b);
    int CalculateDecryptionKey(int e, int phi);
    int __xgcd(int a, int b, int &x, int &y);
    char enc(char l, long long int d, int n);
    long long unsigned int power(long long a, long long b);
    std::string decrypt(std::string message);
    std::string encrypt(std::string message);
};