#include <iostream>

using namespace std;

const double PI = 3.14159265;
const float ERODE = 50;

int eroYear(float x, float y){
    float space = (x * x + y * y) * PI * 0.5;
    int year = 0;
    while(space > 0){
        space -= ERODE;
        year += 1;
    }
    return year;
}


int main(){
    int n; // # test cases
    scanf("%d", &n);;
    float cur_x, cur_y;
    for(int i = 0; i < n; i++){
        scanf("%f %f", &cur_x, &cur_y);
        cout << "Property " << i + 1 << ": " << "This property will begin eroding in year " << eroYear(cur_x, cur_y) << ".\n";
    }
    cout << "END OF OUTPUT." << endl;
}
