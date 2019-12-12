#include<iostream>
using namespace std;

void outPutArr(int arr[],int n);
void quickSort(int R[] ,int low,int high);

void main(){
	int arr[] = {68,23,34,45,-33,41,999,-1,68};
	int length = 9;
	quickSort(arr,0,length-1);
	outPutArr(arr,length);
}



void quickSort(int R[] ,int low,int high){
	int temp;
	int i = low, j = high;
	if(low<high){
		temp = R[low];
		while(i<j){   //将数组中小于temp的放在左边，大于temp的放在右边
			while(j>i && R[j]>=temp){   //从右往左扫描，找到一个小于temp的关键字
				j--;
			}
			if(i<j){
				R[i] = R[j];         //放在temp左边
				i++;                 //右移一位
			}
			while(i<j && R[i]<temp){    //从左往右扫描，找到一个大于temp的关键字
				i++;
			}
			if(i<j){
				R[j] = R[i];        //放在temp右边
				j--;                //左移一位
			}
		}
		R[i] = temp;                //将temp放在最终位置
		quickSort(R,low,i-1);       //递归的对temp左边的关键字排序
		quickSort(R,i+1,high);      //递归的对temp右边的关键字排序
	}
}



/**
对数组的输出方法
*/
void outPutArr(int arr[],int n){
	cout <<"<快速排序算法>\r\n"<<endl;
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