#include <iostream>
#include <random>
#include <iostream>
#include <string>
#include <random>

class Crypto
{
public:
    long long int p, q, euler, n, d, e;
    bool isKeyLoaded = false;

    std::string createKey();
    std::string loadKey(int p, int q, int n, int euler, int e, int d);
    std::string generateSafePassword(int length);
    char GenRand();
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