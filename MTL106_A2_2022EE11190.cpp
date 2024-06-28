#include <cmath>
#include <iomanip>
#include<iostream>
using namespace std;


int main(){
    long double transm[7][7];
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cin>>transm[i][j];
            
    }
  }
  long double tzero,t1,t2; 
  cin>>tzero>>t1>>t2;
  long double a,g,p,e; 
  cin>>a>>g>>p>>e;
  long double T; 
  cin>>T;
  long double state[7];
  for(int i=1;i<7;i++){
    state[i]=0.00;
  }
  state[0]=1.00;
  long double peb=transm[1][3]*g;

  long double peis=transm[1][3];
  
  long double peia=transm[1][2];
  
  long double pei;
  long double pea=transm[1][2]*g;
  for(long double t=0;t<T;t++){

    if(t>=tzero){
        transm[0][5]=a*(t-tzero);
        double term=transm[0][0]+transm[0][1];
        transm[0][1]=((1.00-transm[0][5])*transm[0][1])/(term);
        transm[0][0]=((1.00-transm[0][5])*transm[0][0])/(term);
       
        
    }else{
        transm[0][5]=0;
    }
    
    if(t<t1||t>t2){
        pei=peia+peis;
    }else{
        pei=pea+peb;
       
    }

    transm[0][1]=transm[0][1]+e*sin((2*M_PI*t)/(365));


    transm[0][0]=transm[0][0]-e*sin((2*M_PI*t)/(365));

    long double temp[7];
    for(int i=0;i<7;i++){
        temp[i]=state[i];
    }
    state[0]=temp[0]-transm[0][1]*temp[0]-(transm[0][5])*temp[0]+transm[5][0]*temp[5];
    state[1]=temp[1]-pei*temp[1]+transm[0][1]*temp[0];
    state[2]=temp[2]-transm[2][4]*temp[2]-transm[2][6]*temp[2]+p*pei*temp[1];
    state[3]=temp[3]-transm[3][4]*temp[3]-transm[3][6]*temp[3]+(1.00-p)*pei*temp[1];
    state[4]=temp[4]+transm[2][4]*temp[2]+transm[3][4]*temp[3];
    state[5]=temp[5]-transm[5][0]*temp[5]+transm[0][5]*temp[0];
    state[6]=state[6]+transm[2][6]*temp[2]+transm[3][6]*temp[3];
  }
  for(int i=0;i<7;i++){
    cout<<setprecision(17)<<state[i]<<" ";
  }

  cout<<endl;
    
    return 0;
}