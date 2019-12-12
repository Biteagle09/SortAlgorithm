## <center>排序算法<center/>
### 1. 直接插入
>算法思想：每趟将一个待排序的关键字按照其值的大小插入到已经排好的部分有序序列的适当位置上，
直到所有待排关键字都被插入到有序序列中为正。
~~~C++
void InsertSort(int R[], int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; i++) {
		temp = R[i];  //将待插入关键字暂存在temp中
		j = i - 1;
		/*下面这个循环完成了从待排关键字之前的关键字开始扫描，如果大于待排关键字，则后移一位*/
		while (j >= 0 && temp < R[j]) {
			R[j + 1] = R[j];
			j--;
		}
		R[j + 1] = temp;   //找到插入位置，将temp中暂存的待排关键字插入
	}
	//对排序了的数组输出
	outPutArr(R, n);
}
~~~
----
### 2.希尔排序
>算法思想：先将待排序的序列分割成若干个形如....

~~~C++
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
~~~
----
### 3.冒泡排序
>算法思想：。。。。

~~~C++
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
~~~
