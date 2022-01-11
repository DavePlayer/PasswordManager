#include "crypto.h"

std::string Crypto::createKey()
{
    long long int p, q, euler, n, d, e;

    p = this->generatePrime(7);
    q = this->generatePrime(p + 2);
    n = p * q;
    euler = (p - 1) * (q - 1);
    e = this->coPrime(n, euler); // public
    d = this->CalculateDecryptionKey(e, euler);
    // std::cout << "\n\np: " << this->p << "\nq: " << this->q << "\neuler: " << euler << "\nn=" << this->n << "\ne: " << this->e << "\nd: " << this->d << "\n\n";

    // std::string Benc = this->encrypt("test");
    // std::cout << "encrypted = " << Benc << "\n\n";
    // std::string Bdec = this->decrypt(Benc);
    // std::cout << "decrypted = " << Bdec << "\n\n";

    return std::to_string(p) + "\n" + std::to_string(q) + "\n" + std::to_string(n) + "\n" + std::to_string(euler) + "\n" + std::to_string(e) + "\n" + std::to_string(d);
}

long long unsigned int Crypto::power(long long x, long long y)
{
    long long unsigned int res = x;
    for (int i = 0; i < y; i++)
    {
        res *= x;
    }
    return res;
}

char Crypto::enc(char c, long long int d, int n)
{
    int value = 1;
    while (d > 0)
    {
        value *= c;
        value %= n;
        d--;
    }
    return value;
}
std::string Crypto::encrypt(std::string message)
{
    for (auto &a : message)
    {
        a = this->enc(a - 97, this->e, this->n);
    }
    return message;
}

std::string Crypto::decrypt(std::string message)
{
    for (auto &a : message)
    {
        a = 97 + this->enc(a, this->d, n);
    }
    return message;
}

int Crypto::CalculateDecryptionKey(int e, int phi)
{
    int x, y;
    this->__xgcd(e, phi, x, y);
    if (x >= 0)
        return x;
    else
        return phi + x;
}

int Crypto::__xgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1, gcd = __xgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int Crypto::coPrime(int a, int b)
{
    std::vector<int> coprimes;
    for (int i = 2; i < b; i++)
    {
        if (__gcd(i, a) && __gcd(i, b))
            coprimes.push_back(i);
    }
    return coprimes[rand() % coprimes.size()];
}

bool Crypto::__gcd(int a, int b)
{
    if (a == 0)
    {
        if (b > 1)
            return false;
        else
            return true;
    }
    return __gcd(b % a, a);
}

int Crypto::generatePrime(int n)
{
    do
    {
        if (this->isPrime(n))
            return n;
        if (n < std::numeric_limits<int>::max() / 100000)
            n++;
        else
            n = 1;
    } while (true);
}

bool Crypto::isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}