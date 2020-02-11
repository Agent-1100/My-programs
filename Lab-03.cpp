
#include<bits/stdc++.h>

using namespace std;

int countr=0;

double av=0;

void menu()
{
    cout<<"Enter Your choice"<<endl;
    cout<<"1. Iteration Method"<<endl;
    cout<<"2. Newton-Raphson Method"<<endl;
    cout<<"3. Comparison"<<endl;
    cout<<"4. Exit"<<endl;
}

double f(double x)
{
    double value=0.5*(3+cos(x));
    return value;
}

double f1(double x)
{
    double value= 2*x-3-cos(x);
    return value;
}
double f2(double x)
{
    double value= 2+sin(x);
    return value;
}

double Iteration()
{
    double x,xr,check;
    x=av;
    cout<<"No. of iteration = "<<countr;
    cout<<"\t Value of approximate root = "<<x<<endl;
    while(1){
    xr=f(x);
    check = abs(xr-x);
    if(check<=0.001)
    {
        countr=countr+1;
        return xr;
    }
    x=xr;
    countr=countr+1;
    cout<<"No. of iteration = "<<countr;
    cout<<"\t Value of approximate root = "<<fixed<<setprecision(6)<<x<<endl;
    }

}

double NR()
{
    double x,xr,check;
    x=av;
    cout<<"No. of iteration = "<<countr;
    cout<<"\t Value of approximate root = "<<x<<endl;
    while(1)
    {
        xr=x-(f1(x)/f2(x));
        check=abs(xr-x);
        if(check<=0.001)
        {
            countr=countr+1;
            return xr;
        }
        x=xr;
        countr=countr+1;
        cout<<"No. of iteration = "<<countr;
        cout<<"\t Value of approximate root = "<<fixed<<setprecision(6)<<x<<endl;
    }
}

int main()
{
    double result1=0,result2=0;
    int count1=0,count2=0;
    int m, i=1;
    while(i==1){
    menu();
    cin>>m;
    switch (m)
    {
        case 1: {   if(av==0){
                    cout<<"Enter your approximate value between[3/2, pi/2]"<<endl;;
                    cin>>av;}
                    countr = 0;
                    result1=Iteration();
                    count1=countr;
                    countr=0;
                    cout<<"No. of iteration = "<<count1;
                    cout<<"\t Value of approximate root = "<<fixed<<setprecision(6)<<result1<<endl;
                    cout<<"Root = "<<fixed<<setprecision(3)<<result1<<endl;
                    cout<<"No. of iteration = "<<count1<<endl;;
                    break;}


        case 2: {   if(av==0){
                    cout<<"Enter your approximate value between[3/2, pi/2]"<<endl; ;
                    cin>>av;}
                    countr = 0;
                    result2=NR();
                    count2=countr;
                    countr=0;
                    cout<<"No. of iteration = "<<count2;
                    cout<<"\t Value of approximate root = "<<fixed<<setprecision(6)<<result2<<endl;
                    cout<<"Root = "<<fixed<<setprecision(3)<<result1<<endl;
                    break;}

        case 3:{    if(result1==0)
                        cout<<"Please Find Iteration Value first"<<endl;
                    if(result2==0)
                        cout<<"Please Find Newton-Raphson Value first"<<endl;
                    if(result1!=0 && result2!=0){
                        cout<<"Root from Iteration =  "<<result1<<endl;
                        cout<<"No. of iteration = "<<count1<<endl;
                        cout<<"Root from Newton-Raphson =  "<<result2<<endl;
                        cout<<"No. of iteration = "<<count2<<endl;
                        if(count1<count2)
                            cout<<"Iteration is better\n\n"<<endl;
                        else
                            cout<<"Newton-Raphson is better\n\n"<<endl;
                    }
                    break;}

        case 4: {i=0;break;}

        default: {cout<<"This is not a valid choice"<<endl;}
    }
     }
}
