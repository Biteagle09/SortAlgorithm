## <center>排序算法<center/>
### 1. 直接插入
>算法思想：每趟将一个待排序的关键字按照其值的大小插入到已经排好的部分有序序列的适当位置上，
>直到所有待排关键字都被插入到有序序列中为止。
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
>算法思想：希尔排序又称之为缩小增量排序，其本质还是插入排序，
>只不过是将待排序列按照某种规则分成几个子序列，分别对这几个子序列进行直接插入排序。
>这个规则的体现就是增量的选取，希尔排序的时间复杂度为：&emsp;O(n*logn)。

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
>算法思想：假设待排序表长为n，从后往前（或从前往后）两两比较相邻元素的值，
>若为逆序（即A[i-1]>A[i]），则交换它们，直到序列比较完。我们称它为一.趟冒泡，
>结果将最小的元素交换到待排序列的第一一个位置（关键字最小的元素如气泡一般逐渐
>往上“漂浮”直至“水面”，这就是冒泡排序名字的由来）。下一趟冒泡时，前一趟确定的
>最小元素不再参与比较，待排序列减少-一个元素，每趟冒泡的结果把序列中的最小元素
>放到了序列的最终位置，.....  这样最多做n-1趟冒泡就能把所有元素排好序。

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
----
## 4.快速排序
>算法思想：也是交换类的排序，它通过多次划分操作实现排序。以升序为例，
>其执行流程可以概括为：每一趟选择当前所有子序列中的一个关键字（通常是第一个）作为枢轴，
>将子序列中比枢轴小的移到枢轴的前边，比枢轴大的移动到枢轴的后边；
>当本趟所有的子序列都被枢轴以上述规则划分完毕后会的到新的一组更短的子序列，
>它们成为下一趟划分的初始序列集。快速排序的算法思想基于分治思想的，
>其平均时间复杂度为O(n*logn)，最坏时间复杂度为O(n^2)。
~~~C++
void quickSort(int R[], int low, int high){
	int temp;
	int i = low, j = high;
	if(low < high){
		temp = R[low];
		while(i < j){   //将数组中小于temp的放在左边，大于temp的放在右边
			while(j > i && R[j] >= temp){   //从右往左扫描，找到一个小于temp的关键字
				j--;
			}
			if(i < j){
				R[i] = R[j];         //放在temp左边
				i++;                 //右移一位
			}
			while(i < j && R[i] < temp){    //从左往右扫描，找到一个大于temp的关键字
				i++;
			}
			if(i < j){
				R[j] = R[i];        //放在temp右边
				j--;                //左移一位
			}
		}
		R[i] = temp;                //将temp放在最终位置
		quickSort(R,low,i-1);       //递归的对temp左边的关键字排序
		quickSort(R,i+1,high);      //递归的对temp右边的关键字排序
	}
}
~~~
### 5.简单选择排序
>算法思想：选择类排序的主要动作是“选择”。简单选择采用最简单的选择方式，从头至尾扫描序列，
>选出最小的一个关键字，和第一个关键字交换，接着从剩下的关键字中继续这种选择和交换，
>最终使序列有序。
~~~C++
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
~~~
----
### 6.堆排序
