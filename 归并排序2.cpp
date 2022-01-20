#include <iostream>
#include <cstdio>
using namespace std;

int arr[100];
int n;


void merge(int left_start, int left_end, int right_start, int right_end) {
	// 申请一块内存，用来暂存合并好的顺序表
	int *tmp = (int*)malloc(sizeof(int)*(right_end - left_start + 1));
	int i = left_start, j = right_start;
	int tmp_pos = 0;
	printf("[%d,%d]+[%d,%d]",left_start, left_end, right_start, right_end);
	// 从小到大排序，所以谁小谁先放
	while (i<=left_end && j<=right_end) {
		cout<<"tmp_pos: "<<tmp_pos<<endl;
		if (arr[i]<arr[j]) {
			tmp[tmp_pos++] = arr[i++];   // i++ 返回原值，++i返回+1后的值
		} else {
			tmp[tmp_pos++] = arr[j++];
		}
	}
	// 如果i没有走到左顺序表尽头，把左顺序表的剩余部分放入tmp
	if (i<=left_end) {
		for (int t = i; t<=left_end; t++) {
			tmp[tmp_pos++] = arr[t];
		}
	}
	// 对于j同理
	if (j<=right_end) {
		for (int t = j; t<=right_end; t++) {
			tmp[tmp_pos++] = arr[t];
		}
	}
	printf("tmp: ");
	// 把合并好的顺序表tmp放到arr中
	for (int index = 0; index<=right_end - left_start; index++) {
		printf("%d ", tmp[index]);
		arr[index + left_start] = tmp[index];
	}
	printf("\n");
	// 释放tmp的内存
	free(tmp);
}

void merge_sort(int start, int end) {
	//判断是否可分
	if (start>=end) return;
	//先分,mid向下取整,左含mid,右不含mid
	int mid = (start+end) / 2;
	int left_start = start;
	int left_end = mid;
	int right_start = mid+1;
	int right_end = end;
	merge_sort(left_start, left_end);
	merge_sort(right_start, right_end);
	//后合
	merge(left_start, left_end, right_start, right_end);
}



int main() {
	cout<<"请输入数字的个数:";
	cin>>n;
	cout<<"请输入待排序的数组:";
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	merge_sort(0,n-1);
	cout<<"排序后:";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
}
