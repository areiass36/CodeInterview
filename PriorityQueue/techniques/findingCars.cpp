#include<bits/stdc++.h>

using namespace std;

class Car {
public:
    string id;
    int x,y;
    Car(string id, int x, int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist() const{
        return x*x + y*y;
    }
};

class CarCompare{
public:
    bool operator()(const Car a, const Car b){
        return a.dist() < b.dist();
    }
};

// Time - O(n + (n-k) log k)
// Space - O(k)
void findingCars(vector<Car> cars, int k){
    priority_queue<Car,vector<Car>,CarCompare> maxHeap(cars.begin(),cars.begin() + k);

    for (int i = k; i < cars.size(); i++){
        Car car = cars[i];
        int dist = car.dist();

        if(dist < maxHeap.top().dist()){
            maxHeap.pop();
            maxHeap.push(car);
        }
    }

    while(!maxHeap.empty()){
        cout<<maxHeap.top().id<<" ";
        maxHeap.pop();
    }
    cout << endl;
}

int main(){

    vector<Car> arr = {
        Car("C1",1,1),
        Car("C2",2,1),
        Car("C3",3,2),
        Car("C4",0,1),
        Car("C5",2,3)
    };
    findingCars(arr,3);
}