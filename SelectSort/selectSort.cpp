#include <iostream>
using namespace std;
void selectSort(int R[],int n);
void outPutArr(int arr[],int n);

void main(){
	int arr[] = { 68,23,32,0,-33,23,41,999,-1,66 };
	int len = sizeof(arr) / sizeof(arr[0]);
	selectSort(arr,len);
}

/**
简单选择排序算法
*/
void selectSort(int R[], int n){
	int i, j, k;
	int temp;
	for(i = 0; i < n; i++){
		k = i;
		/*下面这个循环是算法的关键，它从无序序列中挑出一个最小的关键字*/
		for(j = i + 1; j < n; j++){
			if(R[k] > R[j]){
				k = j;
			}
		}
		/*下面这三句完成最小关键字与无序序列第一个关键字的交换*/
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	}
	outPutArr(R,n);
}


/**
对数组的输出
*/
void outPutArr(int arr[],int n){
	cout <<"<简单选择排序算法>\r\n"<<endl;
	cout <<"数组长度："<<n<<"\r\n"<<endl;
	cout <<"升序序列：";
	for(int i=0;i<n;i++){
		if(i<n-1){
			cout << arr[i] << " , ";
		}else{
			cout << arr[i] <<";\r\n"<<endl;
		}
	}
}

