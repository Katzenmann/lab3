#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>

using namespace std;

complex<double> katze(double);

int main(){
  ofstream out("complexedaten.dat");
  int N=200;
  double dphi=2*M_PI/N, phi;
  complex<double> fc[N];
  for(int i=1; i<=N; i++){
    
    phi   = i*dphi-M_PI;
    fc[i] = katze(phi);  
  }
  for(int i=1; i<=N; i++){
  
  out<< i*dphi-M_PI << " \t"<<real(fc[i])<< " \t"<<imag(fc[i])<<" \t"<<abs(fc[i])<<endl;

  cout<< i*dphi-M_PI << " \t"<<real(fc[i])<< " \t"<<imag(fc[i])<<" \t"<<abs(fc[i])<<endl;   
  }  
  out.close(); 
  
  
  return 0;
}

complex<double> katze(double phi){
  complex<double> ii = complex<double>(0.0,1.0);
  return tan(phi*(1.0+ii));
}