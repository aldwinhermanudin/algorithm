#include <iostream>

using namespace std;

int fibb_recrv(int n);
int main(){
	
	int max_number;
	
	cout << "Enter max number : " << endl;
	cin >> max_number;
	cout << "Max number is " << max_number << endl;
	for (int i = 0; i < max_number; i++){
		
		cout << " " << fibb_recrv(i) << " ";
		
	}	
	cout << endl;
	
	return 0;
}


int fibb_recrv(int n){
	
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	return fibb_recrv(n-1) + fibb_recrv(n-2);
}
