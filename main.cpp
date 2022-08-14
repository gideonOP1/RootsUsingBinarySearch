#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <initializer_list>
#include <cctype>
#include<bits/stdc++.h>
using namespace std;


//=====================================================================


template <typename T> class polynomial                                                        // Polynomial over field of type T
{
   vector<T> coeff;
public:
   // Various constructors
   polynomial() { coeff = { T{} }; }                                                          // Construct as "zero"
   polynomial( const vector<T> &V ) { coeff = V; }                                            // Construct from a vector
   polynomial( const initializer_list<T> &V ) { coeff = vector<T>( V.begin(), V.end() ); }    // Construct from initialiser list
   polynomial( const string str, char X = 'x' );                                              // Construct from string

   T eval( T x );
};

//----------------------------

template <typename T> polynomial<T>::polynomial( const string str, char X )         // Construct from string
{
   // First strip blanks
   string s;
   for ( char c : str ) if ( !isspace( c ) ) s += c;

   // Break into units at every '+' or '-'; the limits will be [p,q)
   int p = 0, q = p;
   while ( q < s.size() )
   {
      for ( q = p + 1; q < s.size() && s[q] != '+' && s[q] != '-'; q++ );
      string unit = s.substr( p, q - p );                                           // should be of form "cxn", meaning c times x^n

      // Pick out coefficient and exponent
      T c = 1;
      int n = 0;

      int pos = unit.find( X );                                                     // position of char X
      if ( pos == string::npos )                                                    // X not found; pure number
      {
         stringstream( unit ) >> c;
      }
      else                                                                          // identify coefficient (c) and exponent (n)
      {
         if ( pos != 0 )                                                            // pos == 0 would mean default c = 1
         {
            string first = unit.substr( 0, pos );
                 if ( first == "+" ) c = 1;                                         // just "+" means +1
            else if ( first == "-" ) c = -1;                                        // just "-" means -1
            else                     stringstream( first ) >> c;
         }

         if ( pos == unit.size() - 1 )
         {
            n = 1;
         }
         else
         {
            stringstream( unit.substr( pos + 1 ) ) >> n;
         }
      }

      if ( n + 1 > coeff.size() ) coeff.resize( n + 1 );
      coeff[n] += c;
      p = q;
   }
}

//----------------------------

template <typename T> T polynomial<T>::eval( T x )                                  // Evaluate polynomial at x
{
   T result = 0;
   for ( int r = coeff.size() - 1; r >= 0; r-- ) result = coeff[r] + result * x;
   return result;
}


//=====================================================================
float posPT=0,negPT=0;
bool exactRoot=false;

void SignChange (polynomial<double> p)
{
    for(int i=-1000;i<=1000;i++){
        //cout<<p.eval(i)<<" "<<i<<endl;

        if(p.eval(i)==0 && i!=0){negPT=i;posPT=i;exactRoot=true;break;}

        else if(p.eval(i)<0&&p.eval(i+1)>0||p.eval(i)>0&&p.eval(i+1)<0){
          negPT=i;
          posPT=i+1;
        }
    }

}


void BinomialRoot(polynomial<double> p,double strt,double end,int x)
{
    int it=0;
    double prev=0;

    while(true){
        double mid=(strt+end)/2;
        it++;
        //cout<<setprecision(x)<<mid<<" "<<p.eval(mid)<<" iteration "<<it<<endl;
        if(mid==prev){cout<<setprecision(x+1)<<"Approximate Root Is "<<mid<<endl;break;}
        if(p.eval(mid)<0){strt=mid;}
        if(p.eval(mid)>0){end=mid;}
        prev=mid;

    }

    cout<<"Total Iterations " <<it<<endl;
}




int main()
{

   string str;
   int n;
   cout<<"Enter Polynomial"<<endl;
   cin>>str;
   cout<<"Enter Precision"<<endl;
   cin>>n;
   polynomial<double> p(str);
   SignChange(p);


   if(exactRoot==true){cout<<negPT<<endl;}
   else if(exactRoot==false && negPT==0&&posPT==0){cout<<"No Root"<<endl;}
   else
   {
       //cout<<negPT<<" "<<p.eval(negPT)<<'\n'<<posPT<<" "<<p.eval(posPT)<<endl;
       cout<<endl;
       BinomialRoot(p,negPT,posPT,n);



   }









}
