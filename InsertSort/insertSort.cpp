/*
插入排序  算法思想
每趟将一个待排序的关键字按照其值的大小插入到已经排好的部分有序序列的适当位置上，
直到所有待排关键字都被插入到有序序列中为正。
*/

#include <iostream>
using namespace std;

void InsertSort(int R[],int n);
void outPutArr(int arr[],int n);

void main()
{
	int arr[] = {68,23,32,0,-33,23,41,999,-1,66};
	int len = sizeof(arr)/sizeof(arr[0]);
	InsertSort(arr,len);
}

/**
直接插入排序算法
*/
void InsertSort(int R[],int n){
	int i,j;
	int temp;
	for(i=1;i<n;i++){
		temp = R[i];  //将待插入关键字暂存在temp中
		j = i-1;
		/*下面这个循环完成了从待排关键字之前的关键字开始扫描，如果大于待排关键字，则后移一位*/
		while(j>=0&&temp<R[j]){
			R[j+1] = R[j];
			j--;
		}
		R[j+1] = temp;   //找到插入位置，将temp中暂存的待排关键字插入
	}
	//对排序了的数组输出
	outPutArr(R,n);
}


/**
对数组的输出方法
*/
void outPutArr(int arr[],int n){
	cout <<"<直接插入排序算法>\r\n"<<endl;
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

