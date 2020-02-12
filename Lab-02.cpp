
#include<bits/stdc++.h>

using namespace std;

int Or(int a,int b) /// or sign used a*b
{
    if(a==1||b==1)
        return 1;
    else
        return 0;
}
int And(int a, int b) /// and sign used a^b
{
    if(a==1&&b==1)
        return 1;
    else
        return 0;
}
int Neg(int a)/// negation sign used -a
{
    if(a==0)
        return 1;
    else
        return 0;
}
int Imp(int a,int b)///implies sign used a%b
{
    if(a==1&&b==0)
        return 0;
    else
        return 1;
}
int Bicon(int a, int b)///biconditional sign used a@b
{
    int c=And(Imp(a,b),Imp(b,a));
    return c;
}

void Process(int& TopV, int& TopO, int* Value, char* Operator)
{
    while(Operator[TopO]!='(')
    {
        char temp=Operator[TopO];
        TopO=TopO-1;
        int a,b;
        a=Value[TopV];///pop 1 time
        Value[TopV]=0;
        TopV=TopV-1;
        b=Value[TopV];
        ///pop 2 times
        if(temp=='*')
        {
            Value[TopV]=Or(a,b);
        }
        if(temp=='^')
        {
            Value[TopV]=And(a,b);
        }
        if(temp=='%')
        {
            Value[TopV]=Imp(b,a);
        }
        if(temp=='@')
        {
            Value[TopV]=Bicon(b,a);
        }
        if(temp=='-')
        {
            TopV=TopV+1;
            Value[TopV]=Neg(a);
        }

        ///Push 1 time
    }///end of while
}

int main()
{
    int Value[20];
    char Operator[30];
    int TopV=-1;
    int TopO=0;
    int i;
    Operator[TopO]='(';
    cout<<"Enter your Proposition"<<endl;
    string s1;
    cin>>s1;
    cout<<"P\t|Q\t|R\t|"<<s1<<endl;
    for(int p=0; p<2; p++)
        for(int q=0; q<2; q++)
            for(int r=0; r<2; r++)
            {
                for(i=0; s1[i]; i++)
                {
                    if(s1[i]>='a'&&s1[i]<='z')
                    {
                        if(Operator[TopO]=='-')
                        {
                            if(s1[i]=='p')
                            {
                                TopV=TopV+1;
                                Value[TopV]=Neg(p);
                            }
                            if(s1[i]=='q')
                            {
                                TopV=TopV+1;
                                Value[TopV]=Neg(q);
                            }
                            if(s1[i]=='r')
                            {
                                TopV=TopV+1;
                                Value[TopV]=Neg(r);
                            }
                            TopO=TopO-1;
                        }
                        else
                        {
                            if(s1[i]=='p')
                            {
                                TopV=TopV+1;
                                Value[TopV]=p;
                            }
                            if(s1[i]=='q')
                            {
                                TopV=TopV+1;
                                Value[TopV]=q;
                            }
                            if(s1[i]=='r')
                            {
                                TopV=TopV+1;
                                Value[TopV]=r;
                            }
                        }
                    }///Value input
                    else
                    {
                        if(s1[i]!=')')
                        {
                            TopO=TopO+1;
                            Operator[TopO]=s1[i];
                        }
                        else if(s1[i]==')')
                        {
                            Process(TopV,TopO,Value,Operator);
                            TopO=TopO-1;
                        }

                    }///Operator input

                }///end of i loop

                Process(TopV,TopO,Value,Operator);///Empty Stack
                cout<<p<<"\t|"<<q<<"\t|"<<r<<"\t|"<<Value[TopV]<<endl;///printing result
                TopV=-1;///reseting Value stack
            }///end of nested 3 layer loop

}///end of main
