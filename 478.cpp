#include "util.h"

class Solution {
public:

    double r;
    double x;
    double y;

    Solution(double radius, double x_center, double y_center) : r(radius), x(x_center), y(y_center) {

    }

    uniform_real_distribution<double> d1{ 0, 1 };
    default_random_engine             r1;

    vector<double> randPoint() {

        


        pair<double, double> pos(sqrt(d1(r1)) * r, d1(r1) * 2 * M_PI);
        
        auto x_pos = pos.first * cos(pos.second);
        auto y_pos = pos.first * sin(pos.second);
        return { x_pos + x , y_pos + y };
    }

};

double x0 = -73839.1;
double yy0 = -3289891.3;
double r0 = 0.01;

bool check(double x, double y) {
    if ((x - x0) * (x - x0) + (y - yy0) * (y - yy0) > r0 * r0)
        return false;
    return true;
}

int main() {
    Solution s(r0, x0, yy0);
    for(int i = 0; i < 1000000; ++i) {
        auto result = s.randPoint();
        if (!check(result[0], result[1]))
            test::print_vector(result);
    }
    
}