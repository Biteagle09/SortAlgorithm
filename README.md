## <center>�����㷨<center/>
### 1. ֱ�Ӳ���
>�㷨˼�룺ÿ�˽�һ��������Ĺؼ��ְ�����ֵ�Ĵ�С���뵽�Ѿ��źõĲ����������е��ʵ�λ���ϣ�
ֱ�����д��Źؼ��ֶ������뵽����������Ϊ����
~~~C++
void InsertSort(int R[], int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; i++) {
		temp = R[i];  //��������ؼ����ݴ���temp��
		j = i - 1;
		/*�������ѭ������˴Ӵ��Źؼ���֮ǰ�Ĺؼ��ֿ�ʼɨ�裬������ڴ��Źؼ��֣������һλ*/
		while (j >= 0 && temp < R[j]) {
			R[j + 1] = R[j];
			j--;
		}
		R[j + 1] = temp;   //�ҵ�����λ�ã���temp���ݴ�Ĵ��Źؼ��ֲ���
	}
	//�������˵��������
	outPutArr(R, n);
}
~~~
----
### 2.ϣ������
>�㷨˼�룺�Ƚ�����������зָ�����ɸ�����....

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
### 3.ð������
>�㷨˼�룺��������

~~~C++
void bubbleSort(int R[], int n){
	int i,j;
	bool flag;
	int temp;
	for(i = n-1; i > 0; i--){
		flag = false;        //flag������Ǵ��������Ƿ����˽���
		for(j = 1; j <= i; j++){
			if(R[j-1] > R[j]){
				temp = R[j];
				R[j] = R[j-1];
				R[j-1] = temp;
				flag = true;  //���û������������flagΪ0
			}
		}
		if(!flag){      //һ�����������û�з���������֤��ʣ���������򣬲���ð��
			outPutArr(R,n);
			return;
		}
	}
}
~~~
