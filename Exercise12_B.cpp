/* Here is the Point class. It is almost similar same that in the program memleakharj.cpp.
    The difference is that it now has a member function distance, that calculates 
    distance between two points.
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;


//Definition for exception class
class Exception {
	public:
		Exception(const char *explanation0) {explanation = explanation0;}
		const char *what() const {return explanation;}
	private:
		const char *explanation;
};


#define N 100
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

//Class definition for Point
class Point {
	friend ostream& operator<<(ostream &out, const Point &point);
	public:
		Point(float x0 = 0.0, float y0 = 0.0);
		~Point();
		bool operator<(const Point& p2) { return distance(Point(0, 0)) < p2.distance(Point(0, 0)); }
		
        float distance(const Point& p2) const;
        static int count;
	private:
		float x;
		float y;
};
int Point::count = 0;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	try {
		const Point origin(0.0, 0.0);

		vector<unique_ptr<Point>> points;
		points.emplace_back(make_unique<Point>(2.5, 4.5));
		points.emplace_back(make_unique<Point>(3.8, 7.1));
		points.emplace_back(make_unique<Point>(9.3, 0.7));
		sort(points.begin(), points.end(), [&origin](unique_ptr<Point>& p1, unique_ptr<Point>& p2) {
			return p1->distance(origin) < p2->distance(origin); });
	}
	catch (Exception e) {
		cout << "Exception explanation is: " << e.what() << endl;
	}
	_CrtDumpMemoryLeaks();
	return 0;

}
//-----------------------------------------------------------------
//Implementation of class Point
Point:: Point(float x0, float y0): x(x0), y(y0) {
    count++;
    if (count >= N)
        throw Exception ("Does not succeed to create the last apex");
    cout << "Point constructor is done " << (void*)this << endl;
}

Point::~Point() {
    cout << "\nDestructor for Point " << (void*)this << " : ("
            << x << "," << y << ")" << endl;
}

float Point::distance(const Point& p2) const {
    float deltax = p2.x - x;
    float deltay = p2.y - y;   
    return sqrt(deltax*deltax + deltay*deltay);
}


// Friend functions of Point
ostream &operator<<(ostream & out, const Point &point) {
	out << "(" << point.x << "," << point.y << ")";
	return out;
}
