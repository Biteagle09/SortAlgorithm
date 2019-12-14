#include<iostream>
using namespace std;

void outPutArr(int arr[],int n);
void sift(int R[] ,int low,int high);
void heapSort(int R[], int n);

void main(){
	int arr[] = { 68,23,32,0,-33,23,41,999,-1,66 };
	int length = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr,length);
}


/**
堆排序算法主方法
*/
void heapSort(int R[], int n){
	int i;
	int temp;
	for(i = n/2 - 1; i >= 0; i--){      //建立初始堆
		sift(R, i, n-1);
	}
	for(i = n-1; i > 0; i--){        //进行n-1次循环，完成堆排序
		temp = R[0];             //一下3句换出根节点的关键字，将其放入最终位置
		R[0] = R[i];
		R[i] = temp;
		sift(R, 0, i-1);           //在减少了一个关键字的无序序列中调整
	}
	outPutArr(R, n);
}



/**
堆的局部调整方法
*/
void sift(int R[] ,int low, int high){      //关键字设定下表从0开始
	int i = low,j = 2*i + 1;                 //R[j]是R[i]的左孩子节点
	int temp = R[i];
	while(j <= high){
		if(j < high && R[j] < R[j+1]){         //若右孩子较大，则j指向右孩子
			j++;                           //j变为2*i+2
		}
		if(temp < R[j]){
			R[i] = R[j];                  //将R[j]调整到双亲节点的位置
			i = j;                        //修改i和j的值，继续向下调整
			j = 2*i + 1;
		}else{
			break;                       //调整结束
		}
	}
	R[i] = temp;                         //被调整节点放入最终位置
}




/**
对数组的输出方法
*/
void outPutArr(int arr[],int n){
	cout <<"<堆排序算法>\r\n"<<endl;
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