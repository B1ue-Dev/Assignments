#include<iostream>
#include<string>
using namespace std;
class date{
    public:
        int day;
        int month;
        int year;
        void getdate(date &d){
            cin >> d.month;
            cin >> d.day;
            cin >> d.year;
        }
        void showdate(date d){
            int day;
            switch(d.month){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if(d.day > 31){
                        return;
                    } else {
                        day = d.day;
                    }
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    if(d.day > 30){
                        return;
                    } else {
                        day = d.day;
                    }
                    break;
                case 2:
                    if(d.year % 4 == 0){
                        if(d.day <= 29){
                            day = d.day;
                        } else {
                            return;
                        }
                    } else {
                        if(d.day <=28){
                            day = d.day;
                        } else {
                            return;
                        }
                    }
                    break;
                    default:
                        return;
            }
            string c = to_string(day);
            string d = to_string(month);
            string e = to_string(year);
            if(e.length() < 2){
                e = "0" + e;
            }
            string f = c + "/" + d + "/" + e;
            if(f[2] != '/'){
                f = "0" + f;
            }
            if(f[5] != '/'){
                f.insert(3, "0");
            }
            cout << f;
        }
};
int main(){
    date a;
    a.getdate(a);
    a.showdate(a);
}
