 # include <iostream>
using namespace std;

double convert_knots(int knot)
{
    return 6076.0/5280.0/60.0*knot;
}


double convert_knots(int knot);

int main()
{
    int i;
    cin >> i;
    cout << convert_knots(i);
    return 0;
}
