#include <bits/stdc++.h>

using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    int hour = (minutes / 60) % 24;

    if (hour == 0)
        hour = 24;

    int min = minutes % 60;
    
    string digitalTime = to_string(hour) + ":";
    
    digitalTime += (min < 10) ? "0" + to_string(min) : to_string(min);
    
    return digitalTime;
    
}

int main(){
    cout << convert_to_digital_time(1180) << endl; //19:40
    cout << convert_to_digital_time(1024) << endl; //17:04
    cout << convert_to_digital_time(1440) << endl; //24:00
    cout << convert_to_digital_time(2301) << endl; //14:21
    cout << convert_to_digital_time(1754) << endl; //5:14
}