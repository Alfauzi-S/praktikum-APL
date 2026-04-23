#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

double hitungJarak(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void cariPasanganTerdekat(vector<Point> &points) {
    int n = points.size();
    if (n < 2) {
        cout << "Minimal harus ada 2 titik." << endl; // Fixed: << instead of <
        return;
    }
    double minJarak = numeric_limits<double>::max(); // Fixed: :: instead of :
    Point pA, pB;
    
    for (int i = 0; i < n; i++) { // Fixed: i++ instead of +i
        for (int j = i + 1; j < n; j++) { // Fixed: j++ instead of +j
            double jarak = hitungJarak(points[i], points[j]);
            if (jarak < minJarak) {
                minJarak = jarak;
                pA = points[i];
                pB = points[j];
            }
        }
    }
    
    cout << "Pasangan titik terdekat ditemukan:" << endl; // Fixed: << operators
    cout << "Titik 1: (" << pA.x << ", " << pA.y << ")" << endl;
    cout << "Titik 2: (" << pB.x << ", " << pB.y << ")" << endl;
    cout << "Jarak : " << minJarak << endl;
}

int main() {
    vector<Point> points = {
        {2, 3},
        {12, 30},
        {40, 50},
        {5, 1},
        {12, 10},
        {3, 4}
    };
    cout << "Menghitung pasangan titik terdekat." << endl << endl; // Fixed: << operators
    cariPasanganTerdekat(points);
    return 0;
}