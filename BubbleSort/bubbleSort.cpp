#include <iostream>
using namespace std;
void bubbleSort(int R[],int n);
void outPutArr(int arr[],int n);


void main(){
	int arr[] = { 68,23,32,0,-33,23,41,999,-1,66 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr,len);
}


/**
冒泡排序算法
*/
void bubbleSort(int R[], int n){
	int i,j;
	bool flag;
	int temp;
	for(i = n-1; i > 0; i--){
		flag = false;        //flag用来标记此趟排序是否发生了交换
		for(j = 1; j <= i; j++){
			if(R[j-1] > R[j]){
				temp = R[j];
				R[j] = R[j-1];
				R[j-1] = temp;
				flag = true;  //如果没发生交换，则flag为0
			}
		}
		if(!flag){      //一趟排序过程中没有发生排序，则证明剩余序列有序，不在冒泡
			outPutArr(R,n);
			return;
		}
	}
}


/**
对数组的输出方法
*/
void outPutArr(int arr[],int n){
	cout <<"<起泡排序算法>\r\n"<<endl;
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
