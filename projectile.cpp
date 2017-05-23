#include <iostream>
#include <cmath>

using namespace std;

struct projectile
{
    int t;
    double m;
    double x, y;
    double v_x, v_y;
};

projectile euler(projectile o, double g, double h)
{
    const double k = 0.1;

    o.x += o.v_x * h;
    o.y += o.v_y * h;

    o.v_x -= k * o.v_x * o.v_x * h;
    o.v_y -= (o.m * g + k * o.v_y * o.v_y) * h;

    o.t++;

    return o;
}

void update(projectile o, double g, double h)
{
    while(o.y >= 0)
    {
        cout << o.t << "\t" << o.x << "\t" << o.y << "\t" 
             << o.v_x << "\t" << o.v_y << "\t" 
             << sqrt(o.v_x * o.v_x + o.v_y * o.v_y) << endl;

        o = euler(o, g, h);
    }
}

void parabola(double theta, double g, double v_0)
{
    double y = 0;

    for(double x = 0; y >= 0; x += 0.1)
    {
        y = 0 + x * tan(theta) 
            - g * x * x / (2 * v_0 * v_0 * cos(theta) * cos(theta));

        if(y >= 0)
            cout << x << "\t" << y << endl;
    }
}

int main()
{
    const double g = 9.81;
    double h = 0.001;
    double v_0 = 10;
    double theta = M_PI / 4;

    projectile o;
    o.t   = 0;
    o.m   = 1;
    o.x   = 0;
    o.y   = 0;
    o.v_x = v_0 * cos(theta);
    o.v_y = v_0 * sin(theta);

    update(o, g, h);
    //parabola(theta, g, v_0);

    return 0;
}

