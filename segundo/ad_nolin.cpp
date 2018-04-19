#include <iostream>
#include <math.h>
using namespace std;

double gaussian(double sigma,double media,double x)
{
	return exp(-pow((x-media)/sigma,2)/2.0);
}

void u_in(double* u, double delta_x, int n,double sigma,double media,double x){
  for (int i=0; i<n; i++){
    x = i*delta_x;
    u[i] = gaussian(sigma, media, x);
    }
}
int main(){
  double delta_x = 0.1, delta_t = 0.1;
  double x_min = 0.0, x_max = 2.0;
  double T = 0.5, c =1;
  double sigma = 0.1;
  double media = 1;
  double x=0;
  int nx = (x_max-x_min)/delta_x + 1;
  int nt = T/delta_t +1; 
  double *u_nuevo;
  double *u_viejo;
  double *u_ini;
  u_nuevo= new double[nx];
  u_viejo= new double[nx];
  u_ini = new double[nx];
  u_in(u_ini,delta_x, nx,sigma,media,x);
  u_in(u_viejo,delta_x, nx, sigma,media,x);

 
  for(int j=1;j<nt;j++){
    u_nuevo[0]=0;
    u_nuevo[nx-1]=0;
    
  for(int i=1;i<nx-1;i++)
      {
	u_nuevo[i]=u_viejo[i]-u_viejo[i]*delta_t*(u_viejo[i]-u_viejo[i-1])/delta_x;
      }
  for(int i=0;i<nx;i++)
      {
	u_viejo[i]=u_nuevo[i];
      }
  }
  x=0;		
  for(int i=0;i<nx;i++)
    {
      x=i*delta_x;
      cout<<x<<" "<<  u_ini[i]<< " " <<u_nuevo[i]<<endl;
    }
return
0;
  
}
