#include<iostream>
#include<math.h>

class Polar{
public:
    float r;
    float p;
    Polar() {}
    Polar(float r, float p) {
        this->r = r;
        this->p = p;
    }
    void setPolar(Polar &q){
        std::cin >> q.r >> q.p;
    }
    void getPolar(){
        std::cout << r << " " << p << std::endl;
    }
    void get_toadocuc(float &x, float &y){
        x = r * cos(p);
        y = r * sin(p);
    }
    void get_toado(float a, float b){
        r = sqrt(a * a + b * b);
        p = atan(b / a);
    }
     friend Polar operator + (Polar p1, Polar p2){
        float a1, a2, b1, b2;
        p1.get_toadocuc(a1, b1);
        p2.get_toadocuc(a2, b2);
        Polar p;
        float a = a1 + a2;
        float b = b1 + b2;
        p.get_toado(a, b);
        return p;

    }

};
const float pi = 3.14159265359;
int main(){

    Polar p1(5, pi / 4);
    Polar p2(3, pi / 6);
    Polar p = p1 + p2;
    p.getPolar();

    return 0;

}
