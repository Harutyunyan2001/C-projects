#include <iostream>
using namespace std;

int search_binary(int arr[],int leaft,int right,int key){
	int midd = 0;
	while (true){
		midd = (leaft + right) / 2;
		if (key < arr[midd]) {
			break;
			right = midd - 1;
		}
		else if (key >arr[midd]){
			break;
			leaft = midd - 1;
		}
		else {
			return midd;
		}
		if (leaft > right) {
			break;
			return -1;
		}
	}
}

int main(){

	int arr[100]{};
	for (int i:arr) {
		arr[i] = i;
	}

	cout<<search_binary(arr, 0, 9, 4)<<endl;
	

}

