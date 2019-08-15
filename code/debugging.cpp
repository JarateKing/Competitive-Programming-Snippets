#define DEBUG(v) cout<<"DEBUG: "<<#v<<" = "<<v<<"\n"

#define DEBUGARR(a,l) cout<<"DEBUG ARRAY: "<<#a<<" = ";for(int ZQ=0;ZQ<l;ZQ++)cout<<a[ZQ]<<" ";cout<<"\n"

#define DEBUGMAT(a,x,y) cout<<"DEBUG 2D: "<<#a<<"\n";for(int XQ=0;XQ<x;XQ++){for(int YQ=0;YQ<y;YQ++)cout<<a[XQ][YQ]<<" ";cout<<"\n";}
