#include <cmath>
#include "tickets.h"

using namespace std;

// Билет с 2N значным номером считается счастливым,
// если сумма N первых цифр равна сумме последних N цифр.
// Посчитать, сколько существует счастливых 2N-значных билетов.

// Начальные данные: число N от 1 до 10.
// Вывод результата: количество 2N-значных счастливых билетов.


size_t CalcSum(size_t num) // for SolveNaive
{
    size_t sum = 0;
    do
    {
        sum += num % 10;
        num /= 10;
    } while (num);

    return sum;
}

long long SolveNaive(size_t N)
{
    long long res = 0;
    size_t maxNum = pow(10, N);
    double Sum_i;
    for (size_t i = 0; i < maxNum; ++i)
    {
        Sum_i = CalcSum(i);
        for (size_t j = 0; j < maxNum; ++j)
            if ( Sum_i == CalcSum(j) )
                ++res;
    }
    return res;
}


vector<long long> CreateArr(const vector<long long> &_prevArr) // for SolveViaTable
{
    size_t newLen =  _prevArr.size() + 9;
    vector<long long> resArr;
    resArr.reserve(newLen);

    for (size_t i = 0; i < newLen; ++i)
    {
        int val = 0;
        for (size_t j = 0; j < 10; ++j)
            if ( fabs(i-j) >= 0 && fabs(i-j) < _prevArr.size() )
                val += _prevArr[i-j];

        resArr.emplace_back(val);
    }
    return resArr;
}

long long SolveViaTable(size_t n)
{
    vector<long long> a(10, 1);
    long long res = 0;

    for (size_t i = 0; i < n-1; ++i)
        a = CreateArr(a);

    for (const auto v : a)
        res += v*v;

    return res;
};


string Tickets::Run(vector<string> _data)
{
    if (_data.empty())
        return "_data is empty";

    size_t N = stol(_data.front());
    if (N < 1 || N > 10)
        return "Wrong N";

    return to_string(SolveViaTable(N));
//    return to_string(SolveNaive(N));
}

