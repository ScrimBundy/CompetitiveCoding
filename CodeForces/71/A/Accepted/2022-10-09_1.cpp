#include<iostream>
int l,t;
int main() {
	std::cin>>t;
	for(;t>0;t--){
		l=0;
		char *s=new char[110],*c,*n=new char[2];
		std::cin>>s;
		c=s;
		for(;;){if(*c!='\0')l++;else break;c++;}
		std::sprintf(n,"%d%c",l-2,*--c);
		std::printf("%c%s\n",*s,(char*)(l>10)?n:s+1);
	}
}