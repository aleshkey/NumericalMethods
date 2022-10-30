#include <iostream>
#include <cmath>

using namespace std;

long long int getFacktorial(long int x){
    long long int res=1;
    for(long int i=1; i<=x; i++){
        res=res*i;
    }
    return res;
}

long double row(long x){
    long double res=0;
    long int n = 20;
    for(long int i=1; i<=n; i++){
        int p =pow(-1, i-1);
        long long int q = pow(x, 2*i-1);
        res=res+(p* ((double)q)/(double)getFacktorial(2*i-1));
    }
    return res;
}


int main() {
    std::cout <<row(2)- sin(2)<< std::endl;
    std::cout <<row(1)- sin(1)<< std::endl;
    return 0;
}
