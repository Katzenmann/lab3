#include <iostream>
#include <complex>
#include <cmath>

using namespace std;
int main(){

  int N=40;
  complex<double> znull;
  complex<double> zeins,zsave;
  double bedingung=1e-8;
  //z0=complex<double>(1.0,1.0);
  for(double re=-2; re<=2; re+=0.01){
    for(double im=-2; im<=2; im+=0.01){
    znull = complex<double> (re,im);
    zsave = znull;
    int i;
      for(i=1; i<=N; i++){
      zeins=znull-(znull*znull*znull-1.0)/(3.0*znull*znull);
      if(abs(znull-zeins)<=bedingung){
	break;
      }
      znull=zeins;
      }
    cout<<real(zsave)<<"\t"<<imag(zsave)<<"\t"<<i<<endl;
    }
  }
  return 0;
}
