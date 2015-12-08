// Classic fourth order Runge-Kutta

# include<iostream>
# include<fstream>
# include<cmath>


using namespace std;


void function(double*);


int main(){
    const double dt=0.0001;
    const int tmin=0;
    const int tmax=100;
    const int Nit=(tmax-tmin)/dt +1; //iterations
    double t=tmin;
    
    const int N=3;
    double xyz[N];
    double temp[N];
    
    double k1[N];
    double k2[N];
    double k3[N];
    double k4[N];
    
    
    //initial values
    for(int i=0; i<N; i++)
        xyz[i]=1;
    //print initial values
    ofstream out("Lorenz_dt_0.0001.dat");
    out<<t<<"\t"<<xyz[0]<<"\t"<<xyz[1]<<"\t"<<xyz[2]<<endl;
        
      
    
    for (int i=0; i<Nit; i++){
        
        t+=dt;
        
        for(int i=0; i<N; i++)
        temp[i]=xyz[i];
     
        //k1 berechnen für x y z
        function(xyz);
    
        for(int i=0; i<N; i++){
            k1[i]=xyz[i];
            xyz[i]=temp[i]+k1[i]*dt/2;
            }
    
    //k2 berechnen für x y z
        
        function(xyz);
    
            
            for(int i=0; i<N; i++){
                k2[i]=xyz[i];
                xyz[i]=temp[i]+k2[i]*dt/2;
                
            }
        
        //k3 berechnen für x y z
        function(xyz);
    
            
            for(int i=0; i<N; i++){
                k3[i]=xyz[i];
                xyz[i]=temp[i]+k3[i]*dt/2;
                
            }
        
        //k4 berechen
       
        function(xyz);
    
            for(int i=0; i<N; i++)
                k4[i]=xyz[i];
            
            for(int i=0; i<N; i++)
                xyz[i]=temp[i]+dt/6 *(k1[i]+2*k2[i]+2*k3[i]+k4[i]);
    
    
    //print solution in file
    out<<t<<"\t"<<xyz[0]<<"\t"<<xyz[1]<<"\t"<<xyz[2]<<endl;
    
    }
    
    out.close();
            
    return 0;
}

void function(double* xyz){
    
    const double a=10;
    const double b= 28;
    const double c=8/3;
    
    double x=xyz[0];
    double y=xyz[1];
    double z=xyz[2];
    
    xyz[0]=a*(y-x);
    xyz[1]=x*(b-z)-y;
    xyz[2]=x*y-c*z;
}