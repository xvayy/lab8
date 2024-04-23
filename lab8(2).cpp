#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

// Structure to represent a point
struct pt {
	double x, y;
};

// Comparator function to sort points based on x-coordinate
bool cmp(pt a, pt b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// Function to check if three points are in clockwise order
bool cw(pt a, pt b, pt c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

// Function to check if three points are in counterclockwise order
bool ccw(pt a, pt b, pt c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

// Function to find the convex hull of a set of points
void convex_hull(vector<pt>& a) {
	if (a.size() == 1) return; // If there is only one point, there is no convex hull
	sort(a.begin(), a.end(), &cmp); // Sort points by x-coordinate
	pt p1 = a[0], p2 = a.back();
	vector<pt> up, down;
	up.push_back(p1);
	down.push_back(p1);
	for (size_t i = 1; i < a.size(); ++i) {
		if (i == a.size() - 1 || cw(p1, a[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
				up.pop_back();
			up.push_back(a[i]);
		}
		if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
				down.pop_back();
			down.push_back(a[i]);
		}
	}
	a.clear();
	for (size_t i = 0; i < up.size(); ++i)
		a.push_back(up[i]);
	for (size_t i = down.size() - 2; i > 0; --i)
		a.push_back(down[i]);
}

int main() {
	SetConsoleOutputCP(1251); // Set console output code page to support Cyrillic characters
	int n;
	cout << "Enter the number of points: ";
	cin >> n;
	if (n == 1) {
		cout << "Convex hull does not exist" << endl;
		return 0;
	}
	vector<pt> a(n);
	for (int i = 0; i < n; ++i) {
		cout << "Enter the coordinates of point " << i + 1 << " (x, y): ";
		cin >> a[i].x >> a[i].y;
	}
	convex_hull(a);
	cout << "Coordinates of the points of the convex hull:" << endl;
	for (const auto& point : a) {
		cout << "(" << point.x << ", " << point.y << ")" << endl;
	}
	return 0;
}