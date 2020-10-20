/* Quadratic equation solving
	using if .. else
	and math function sqrt();
	may be I can use pow(); too
*/
#include <iostream>
#include <math.h>
using namespace std;

int main ()
	{
	    float a, b, c; // inputs
	    float d;       // discriminant
	    float x1, x2;  // outputs
		cout << "Enter the coeff. values, be carefool a<>0" << endl;
		cout << "a=";
		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "c=";
		cin >> c;
		d = b * b - 4 * a * c; // calculating the discriminant
	if (d > 0) {
		         x1 = (-b - sqrt(d)) / (2 * a);
		         x2 = (-b + sqrt(d)) / (2 * a);
		         cout << "Equation has two root:" << endl;
		         cout << "Root x1=" << x1 << endl;
				 cout << "Root x2=" << x2 << endl;
	         }
	else
	    if (d == 0) {
	             x1 = (-b) / (2 * a);
	             cout << "Equation has a single root:" << endl;
	             cout << "Root x1=" << x1 << endl;
	             }
	else cout << "Equation does not have real roots" << endl;

	return 0;
	}
