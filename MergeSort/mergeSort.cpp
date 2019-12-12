#include<iostream>
using namespace std;

void mergeSort(int R[],int low,int high);
void merge(int R[],int low,int mid, int high);
void outPutArr(int arr[],int n);

void main(){
	int arr[] = {68,23,34,45,-33,41,999,-1,68};
	int length = 9;
	mergeSort(arr,0,length-1);
	outPutArr(arr,length);
}



/**
归并排序
*/
void mergeSort(int R[],int low,int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(R,low,mid);       //归并排序前半段
		mergeSort(R,mid+1,high);    //归并排序后半段
		merge(R,low,mid,high);    //将R数组中low~mid,mid~high两段序列归并为一个序列
	}
}



/**
将两个序列归并为一个有序序列
*/
void merge(int R[],int low,int mid, int high){
	int i,j,k;
	int n1 = mid - low +1;
	int n2 = high - mid;
	int left[n1],right[n2];
	for(i = 0;i<n1;i++){
		left[i] = R[low+i];
	}
	for(j = 0;j<n2;j++){
		right[j] = R[mid + 1 + j];
	}
	i = 0;j = 0;k = low;
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			R[k] = left[i++];
		}else{
			R[k] = right[j++];
		}
		k++;
	}
	while(i<n1){
		R[k++] = left[i++];
	}
	while(j<n2){
		R[k++] = right[j++];
	}
}

/**
对数组的输出方法
*/
void outPutArr(int arr[],int n){
	cout <<"<归并排序算法>\r\n"<<endl;
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