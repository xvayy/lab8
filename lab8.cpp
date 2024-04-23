#include <iostream>
#include <Windows.h>
using namespace std;

// Structure to represent a point
struct pt {
	int x, y;
};

// Function to calculate the area of a triangle
inline int area(pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Function to check if two line segments intersect on the x-axis
inline bool intersect_1(int a, int b, int c, int d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a, c) <= min(b, d);
}

// Function to check if two line segments intersect
bool intersect(pt a, pt b, pt c, pt d) {
	return intersect_1(a.x, b.x, c.x, d.x)
		&& intersect_1(a.y, b.y, c.y, d.y)
		&& area(a, b, c) * area(a, b, d) <= 0
		&& area(c, d, a) * area(c, d, b) <= 0;
}

int main() {
	SetConsoleOutputCP(1251); // Set console output code page to support Cyrillic characters
	pt a, b, c, d;

	cout << "Check for intersection of two line segments by the first method\n" << endl;
	cout << "Enter the coordinates of point a (x, y): ";
	cin >> a.x >> a.y;
	cout << "Enter the coordinates of point b (x, y): ";
	cin >> b.x >> b.y;
	cout << "Enter the coordinates of point c (x, y): ";
	cin >> c.x >> c.y;
	cout << "Enter the coordinates of point d (x, y): ";
	cin >> d.x >> d.y;

	cout << (intersect(a, b, c, d) ? "Yes, the line segments intersect" : "No, the line segments do not intersect") << endl;
	return 0;
}