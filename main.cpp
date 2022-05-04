#include <iostream>
#include <bits/stdc++.h>
/*
 * z(x)=sqrt(sin(x+0.74))*sh(0.8x^2+0.1)
 * eps=10^(-6)
 * x=0.1(0.01)0.2
 */
using namespace std;
void calc(float start,float end, float step){
    float x=start;
    cout<<"  x"<<"     sin" << "  sqrt(sin)"<<"   sh"<< "   result"<< endl;
    while (x<=end){
        cout<< x << " " << sin(x+0.74)
        << " " << sqrt(sin(x+0.74))
        << " " << sinh(0.8*x*x+0.1)
        << " " << sqrt(sin(x+0.74))*sinh(0.8*x*x+0.1)<< endl;
        x+=step;
    }
};

int factorial(int deg){
    int res=1;
    for (int i=1; i<=deg; i++){
        res*=i;
    }
    return res;
};

float sin_calc(float eps1, float x){
    float sin = 0;
    int k=0;
    while (pow(x + 0.74, 2*k+1)/ factorial(2*k+1)>=eps1){
        k++;
    }
    for (int i=0; i<=k; i++){
        sin+=pow(x + 0.74, 2*i+1)/ factorial(2*i+1)*pow(-1,i);
    }
    return sin;
};
float sinh_calc(float eps2, float x){
    float sinh = 0;
    int k=0;
    while (pow(0.8*x*x+0.1, 2*k+1)/ factorial(2*k+1)>=eps2){
        k++;
    }
    for (int i=0; i<=k; i++){
        sinh+=pow(0.8*x*x+0.1, 2*i+1)/ factorial(2*i+1);
    }
    return sinh;
};
float sqrt_calc(float eps3, float x){
    float sqrt = 1;
    while (abs(sqrt-0.5*(sqrt+x/sqrt))>=eps3){
        sqrt=0.5*(sqrt+x/sqrt);
    }
    return sqrt;
};

void table(float eps1,float eps2,float eps3,float start,float end,float step){
    cout<<"  x"<<"     sin" << "  sqrt(sin)"<<"   sh"<< "   result"<< endl;
    for (float x=start; x<=end; x+=step){
        cout<< x << " " << sin_calc(eps1,x)
            << " " << sqrt_calc(eps3, sin_calc(eps1, x))
            << " " << sinh_calc(eps2, x)
            << " " << sqrt_calc(eps3, sin_calc(eps1, x))* sinh_calc(eps2, x) << endl;
    }
}

int main() {
    float start, end, step, eps1, eps2, eps3 ,E;
    E=1E-6;
    start=0.1;
    end=0.4;
    step=0.01;
    eps1=E/0.3;
    eps2=E/0.9;
    eps3=E/3;
    calc(start, end, step);
    std::cout << "<----------------------------->" << std::endl;
    table(eps1,eps2,eps3,start,end, step);


    std::cout << "<----------------------------->" << std::endl;

    return 0;
}
