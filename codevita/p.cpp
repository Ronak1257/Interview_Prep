#include <iostream>
using namespace std;
int main()
{
    int x, y;
    x = 2;
    y = ++x * ++x;
    cout << x << y;
    x = 2;
    y = x++ * ++x;
    cout << x << y;
    return 0;
}