#include <iostream>
#include <iomanip>
#include "caso.h"
void f(std::vector<double>& dydx, std::vector<double>& y, double x) {
    dydx[0] = y[1];
    dydx[1] = y[2];
    dydx[2] = -3 * y[2] - 3 * y[1] - y[0];
}

void f0(std::vector<double>& dydx, std::vector<double>& y, double x) {
    dydx[0] = -3 * y[0];
}

void f1(std::vector<double>& dydx, std::vector<double>& y, double x) {
    dydx[0] = 3 * x * x * y[0] + x * x * std::pow(M_E, std::pow(x, 3));
}

void f2(std::vector<double>& dydx, std::vector<double>& y, double x) {
    dydx[0] = -2 * x * y[0];
}

void f3(std::vector<double>& dydx, std::vector<double>& y, double x) {
    dydx[0] = -2 * y[0] + x;
}

void f4(std::vector<double>& dydx, std::vector<double>& y, double x) {
    dydx[0] = -2 * y[0];
}

int main() {
    std::vector<double> y = {2};
    double xl = 1, xr = 3, xs = 0.25;

    // caso::ODE a(f2, y, xl, xr, xs);
    // a.setButcherTableau(caso::RungeKutta4);
    // std::vector<double> ansa = a.rungeKutta();
    // for(auto i : ansa) {
    //     std::cout << std::fixed << std::setprecision(10) << i << ' ';
    // }
    
    // std::cout << std::endl;

    caso::ODE c(f3, y, 0, xr, xs);
    c.setButcherTableau(caso::DormanPrince8);
    std::vector<double> ansc = c.rungeKutta();
    for(auto i : ansc) {
        std::cout << std::fixed << std::setprecision(10) << i << ' ';
    }

    // std::cout << std::endl;

    // caso::ODE g(f4, y, 0, xr, xs);
    // std::vector<double> ansg = g.forwardEuler();
    // for(auto i : ansg) {
    //     std::cout << std::fixed << std::setprecision(10) << i << ' ';
    // }

    // std::cout << std::endl;

    // caso::ODE j(f4, y, 0, xr, xs);
    // std::vector<double> ansj = j.backwardEuler();
    // for(auto i : ansj) {
    //     std::cout << std::fixed << std::setprecision(10) << i << ' ';
    // }

    // std::cout << std::endl;

    // caso::ODE k(f3, y, 0, xr, xs);
    // std::vector<double> ansk = k.midpoint();
    // for(auto i : ansk) {
    //     std::cout << std::fixed << std::setprecision(10) << i << ' ';
    // }

    // std::cout << std::endl;

    // caso::ODE l(f3, y, 0, xr, xs);
    // std::vector<double> ansl = l.implicitMidpoint();
    // for(auto i : ansl) {
    //     std::cout << std::fixed << std::setprecision(10) << i << ' ';
    // }
    return 0;
}