#include <iostream>

using namespace std;

void u_in(double* u,double x_min,double delta_x, int n){
  for (int i=0; i<n; i++){
    double x = x_min + i*delta_x;
    if(x > 0.75 && x <= 1.25){
      u[i] = 1.0;
    }
    else{
      u[i] = 0;
    }
  }
}

int main(){
  double *u;
  double delta_x = 0.1, delta_t = 0.1;
  double x_min = 0.0, x_max = 2.0;
  double T = 0.5, c =1;

  int nx = (x_max-x_min)/delta_x + 1;
  int nt = T/delta_t +1; 
  double *u_nuevo;
  double *u_viejo;
  double *u_ini;
  u_nuevo= new double[nx];
  u_viejo= new double[nx];
  u_ini = new double[nx];
  u_in(u_ini,x_min,delta_x, nx);
  u_in(u_viejo,x_min,delta_x, nx);
  double x=0;
  for(int j=1;j<nt;j++){
    u_nuevo[0]=0;
    u_nuevo[nx-1]=0;
    
    for(int i=1;i<nx-1;i++)
      {
	u_nuevo[i]=u_viejo[i]-c*delta_t*(u_viejo[i]-u_viejo[i-1])/delta_x;
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
  return 0;
  
}
