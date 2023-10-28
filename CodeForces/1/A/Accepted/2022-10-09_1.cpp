#include<iostream>
int t,f,a,b,c;
int main() {
	std::cin>>t;
	for(;t>0;t--){
		std::cin>>a>>b>>c;
		if(a+b+c>1)f++;
	}
	std::cout<<f<<"\n";
}