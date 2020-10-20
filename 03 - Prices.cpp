#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float price1, price2, price3;
    float total;
    cout << "Enter the price1 = ";
    cin >> price1;
    cout << "\nEnter the price2 = ";
    cin >> price2;
    cout << "\nEnter the price3 = ";
    cin >> price3;
    total = price1 + price2 + price3;
    cout << setprecision(2)
         << setiosflags(ios::fixed);
    cout << "\nPrice 1"
         << setw(14) << price1
         << "\nPrice 2"
         << setw(14) << price2
         << "\nPrice 3"
         << setw(14) << price3
         << "\nTotal price:"
         << setw(10) << total
         << endl;
    return 0;
}
