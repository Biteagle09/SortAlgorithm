#include<iostream>
using namespace std;

void shellSort(int R[],int n);
void outPutArr(int arr[],int n);

void main(){
	int arr[] = { 68,23,32,0,-33,23,41,999,-1,66 };
	int len = sizeof(arr) / sizeof(arr[0]);
	shellSort(arr,len);
}


/**
希尔排序算法
*/
void shellSort(int R[], int n){
	int temp;
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i++){
			temp = R[i];
			int j;
			for(j = i; j >= gap && R[j-gap] > temp; j -= gap){
				R[j] = R[j-gap];
			}
			R[j] = temp;
		}
	}
	outPutArr(R,n);
}




/**
对数组的输出方法
*/
void outPutArr(int arr[],int n){
	cout <<"<希尔排序算法>\r\n"<<endl;
	cout <<"数组长度："<<n<<"\r\n"<<endl;
	cout <<"升序序列：{";
	for(int i=0;i<n;i++){
		if(i<n-1){
			cout << arr[i] << " , ";
		}else{
			cout << arr[i] <<"};\r\n"<<endl;
		}
	}
}