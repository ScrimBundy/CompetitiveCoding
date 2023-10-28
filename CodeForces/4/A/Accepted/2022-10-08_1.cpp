#include <iostream>
int main() {
	int n;
	std::cin>>n;
	std::cout<<(char *)((n>2&&n%2==0)?"YES":"NO")<<"\n";
}