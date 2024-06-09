// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin>>n;
//     int a[n];
//     for(int &i:a){
//         cin>>i;
//     }
//     cout<<a[0]<<" ";
//     for(int i = 1 ; i < n ; i++){
//         if(a[i]==a[i-1]){
//             continue;
//         }else{
//             cout<<a[i]<<" ";
//         }
//     }
//     return 0;
// }

//

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
            string h = to_string(month);
            string e = to_string(year);
            if(e.length() < 2){
                e = "0" + e;
            }
            string f = c + "/" + h + "/" + e;
            if(f[2] != '/'){
                f = "0" + f;
            }
            if(f[5] != '/'){
                f.insert(3, "0");
            }
            cout << f;
        }
};
class employee{
    public:
        int ms;
        string ten;
        float money;
        date d;
        int etype;



        void gettemploy(){
            cout << "Nhap ms: ";
            cin >> ms;
            cout << "Nhap ten: ";
            cin >> ten;
            cout << "Money: ";
            cin >> money;
            cout << "Nhap ngay thang nam: ";
            d.getdate(d);
            cout << "Nghe nghiep: ";
            cin >> etype;
        }
        void puttemploy(){
            cout << "MS: " << ms << endl;
            cout << "TEN: " << ten << endl;
            cout << "MONEY: " << money << "$" << endl;
            cout << "Ngay nhap viec: ";
            d.showdate(d);
            cout << endl;
            cout << "Nghe Nghiep: ";
            switch(etype){
                case 1:
                    cout << "Lao dong." << endl;
                    break;
                case 2:
                    cout << "Thu ky." << endl;
                    break;
                case 3:
                    cout << "Quan ly." << endl;
                    break;
                default:
                    cout << "Khong hop le." << endl;
                    break;
            }

        }
};
int main(){
    employee a;
    a.gettemploy();
    a.puttemploy();
}
