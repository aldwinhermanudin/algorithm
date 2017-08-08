#include <iostream>

using namespace std;

int factorial(int n);
int main(){
	
	int max_itter;
	
	cout << "Enter number : " << endl;
	cin >> max_itter;
	cout << "Number is " << max_itter << endl;
	for (int i = 0; i <= max_itter; i++){
		
		cout << " " << factorial(i) << " ";
		
	}	
	cout << endl;
	
	return 0;
}


int factorial(int n){
	
	if(n == 0) return 1;
	return factorial(n-1) * n;
}
