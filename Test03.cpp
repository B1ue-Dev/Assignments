// ======================================================================================
// NOTICE:
// 1) DO NOT MODIFIND ANY FUNCTION PROTOTYPE.
// ======================================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Monomial // don thuc mot bien (x): m = a.x^p
{
    float a; // Coefficient, he so (a) cua don thuc trong m = ax^p
    int p;   // Power of x, so mu (p) cua bien x trong m = ax^p
    public:
    Monomial(int a=0, int n=0) {  this->a = a; this->p = n; }
    string txt() {  return to_string(a)+"x^"+to_string(p); }

    int getPower() const { return p; }
    float getCoefficient() const { return a; }
    void setCoefficient(float new_a) { a = new_a; }
};
//-----------------------------------------------------------------------
class CubicFunction // hàm bậc 3: f(x) = m0 + m1 + m2 + m3, mi=ai.x^pi
{
    bool  FoundCriticalPoint = false;
    float CX1=0;  float CY1=0;
    float CX2=0;  float CY2=0;
    public:
    vector <Monomial> p; //  f is a set of monomials: m[0]+m[1]+m[2]+m[3]
    CubicFunction(Monomial m ={0,0}) // Constructor
    {   p = {}; p.push_back(m);
        FoundCriticalPoint = false;
    }
    void Add (Monomial m)
    {   // add a monomial u to the object data member p
        // notice: 2x^2 + 3x^2 = 5x^2
        // write your code here

        bool exists = false;
        for (auto &monomial : p) {
            if (monomial.getPower() == m.getPower()) {
                monomial.setCoefficient(monomial.getCoefficient() + m.getCoefficient());
                exists = true;
                break;
            }
        }
        if (!exists) {
            p.push_back(m);
        }
    }
    //-----------------------------------------------------------------------
    bool FindCriticalPoints()
    {
        // find critical points (cực đại (CX1,CY1) và cực tiểu(CX2,CY2))
        // update CX1,CX2,CY1,CY2 if found (hence: FoundCriticalPoint = true)
        // https://www.cuemath.com/calculus/cubic-function/
        // write your code here.

        if (p.size() < 4) {
            return false;
        }
        float a = 0, b = 0, c = 0;
        for (const auto &monomial : p) {
            if (monomial.getPower() == 3) {
                a = monomial.getCoefficient();
            } else if (monomial.getPower() == 2) {
                b = monomial.getCoefficient();
            } else if (monomial.getPower() == 1) {
                c = monomial.getCoefficient();
            }
        }

        float discriminant = pow(2*b, 2) - 4*3*a*c;
        if (discriminant < 0) return false;

        CX1 = (-2*b + sqrt(discriminant)) / (2*3*a);
        CX2 = (-2*b - sqrt(discriminant)) / (2*3*a);
        CY1 = a*pow(CX1, 3) + b*pow(CX1, 2) + c*CX1;
        CY2 = a*pow(CX2, 3) + b*pow(CX2, 2) + c*CX2;
        FoundCriticalPoint = true;
        return true;
    }
    // add friends
    friend string ShowFunction(CubicFunction &c);
    friend void ShowCriticalpoints(CubicFunction &c);
};

string ShowFunction(CubicFunction &c)
{   string sf="";
    for (int i=0; i<c.p.size(); i++)
        sf += (c.p[i].txt()+" ");
    return sf;
}

void ShowCriticalpoints(CubicFunction &c)
{
    if(c.FoundCriticalPoint)
    {   cout << "CX1= " << c.CX1 <<" CY1=" << c.CY1 <<endl;
        cout << "CX2= " << c.CX2 <<" CY2=" << c.CY2 <<endl;
    } else
        cout << "This function has not critical points" << endl;
}

int main()
{
    // you can write some tests here. Freely modify.
    CubicFunction u({1,0});
    u.Add({1,1}); u.Add({2,2});   u.Add({1,3}); // u(x) = 1 + x + 2x^2 + x^3
    //
    cout << ShowFunction(u);
    //
    u.FindCriticalPoints();  ShowCriticalpoints(u);
    //
    return 0;
}
