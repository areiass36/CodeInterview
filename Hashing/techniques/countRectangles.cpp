#include<bits/stdc++.h>

using namespace std;

// Chat GPT made this
class PairHash {
public:
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

//Ryan's Solution - DOESN'T WORK (TRY TO FIX AFTER)
int countRectangles(vector<pair<int,int>> points){
    unordered_set<pair<int,int>,PairHash> indexedPoints(points.begin(),points.end());

    auto areDiagonalPoint = [&](pair<int,int> pointA, pair<int,int> pointB) -> bool {
        return pointA.first != pointB.first and pointA.second != pointB.second;
    };

    int count = 0;
    for(auto pointA : points){ // FIX: Probaly the mistake is here
        for(auto pointB : points){
            if (areDiagonalPoint(pointA,pointB)){
                auto pointC = make_pair(pointA.first, pointB.second);
                auto pointD = make_pair(pointB.first, pointA.second);

                if (
                    indexedPoints.find(pointC) != indexedPoints.end() and 
                    indexedPoints.find(pointD) != indexedPoints.end()) {
                        count++;
                }
            }
        }
    }
    return count/2;
}


// CourseSolution
class Point {
public:
    int x,y;
    Point() {}
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
};

class Compare {
public:
    bool operator()(const Point p1, const Point p2) const{
        if (p1.x == p2.x){
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }
};

// Time - O(n² log n)
// Space - O(n)
int count_rectangles(vector<Point> points){
    set<Point, Compare> s;

    for(Point p : points){
        s.insert(p);
    }

    int ans = 0;
    for(auto it = s.begin(); it != prev(s.end()); it++){
        for(auto jt = next(it); jt != s.end(); jt++){
            Point p1 = *it;
            Point p2 = *jt;

            if (p1.x == p2.x or p1.y == p2.y){
                continue;
            }

            Point p3(p1.x,p2.y);
            Point p4(p2.x,p1.y);

            if (s.find(p3) != s.end() and s.find(p4) != s.end()){
                ans++;
            }
        }
    }
    return ans/2;
}


int main(){
    vector<pair<int,int>> points = {
        {0,0},
        {0,1},
        {1,1},
        {1,0},
        {2,1},
        {2,0},
        {3,1},
        {3,0}
    };

    cout << countRectangles(points) << endl;

    vector<Point> points2 = {
        {0,0},
        {0,1},
        {1,1},
        {1,0},
        {2,1},
        {2,0},
        {3,1},
        {3,0}
    };

    cout << count_rectangles(points2) << endl;
}