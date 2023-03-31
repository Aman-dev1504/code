#include <string>
#include <iostream>
#include <algorithm>

unsigned long long str2num(const std::string &x)
{
    unsigned long long result = 0;
    for (auto c : x)
    {
        result *= 10;
        result += c - '0';
    }
    return result;
}

int main()
{
    std::string pan = "0123456789";

    unsigned int maxDigit;
    std::cin >> maxDigit;
    pan.erase(maxDigit + 1);

    // all divisors
    const unsigned int primes[] = {2, 3, 5, 7, 11, 13, 17};

    unsigned long long sum = 0;

    do
    {
        bool ok = true;

        for (unsigned int i = 0; i + 2 < maxDigit; i++)
        {
            std::string check = pan.substr(i + 1, 3);
            if (str2num(check) % primes[i] != 0)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            sum += str2num(pan);
    } while (std::next_permutation(pan.begin(), pan.end()));

    std::cout << sum << std::endl;
    return 0;
}
