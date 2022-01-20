#include <iostream>
#include <cstdio>
using namespace std;

int arr[100];
int n;


void merge(int left_start, int left_end, int right_start, int right_end) {
	// ����һ���ڴ棬�����ݴ�ϲ��õ�˳���
	int *tmp = (int*)malloc(sizeof(int)*(right_end - left_start + 1));
	int i = left_start, j = right_start;
	int tmp_pos = 0;
	printf("[%d,%d]+[%d,%d]",left_start, left_end, right_start, right_end);
	// ��С������������˭С˭�ȷ�
	while (i<=left_end && j<=right_end) {
		cout<<"tmp_pos: "<<tmp_pos<<endl;
		if (arr[i]<arr[j]) {
			tmp[tmp_pos++] = arr[i++];   // i++ ����ԭֵ��++i����+1���ֵ
		} else {
			tmp[tmp_pos++] = arr[j++];
		}
	}
	// ���iû���ߵ���˳���ͷ������˳����ʣ�ಿ�ַ���tmp
	if (i<=left_end) {
		for (int t = i; t<=left_end; t++) {
			tmp[tmp_pos++] = arr[t];
		}
	}
	// ����jͬ��
	if (j<=right_end) {
		for (int t = j; t<=right_end; t++) {
			tmp[tmp_pos++] = arr[t];
		}
	}
	printf("tmp: ");
	// �Ѻϲ��õ�˳���tmp�ŵ�arr��
	for (int index = 0; index<=right_end - left_start; index++) {
		printf("%d ", tmp[index]);
		arr[index + left_start] = tmp[index];
	}
	printf("\n");
	// �ͷ�tmp���ڴ�
	free(tmp);
}

void merge_sort(int start, int end) {
	//�ж��Ƿ�ɷ�
	if (start>=end) return;
	//�ȷ�,mid����ȡ��,��mid,�Ҳ���mid
	int mid = (start+end) / 2;
	int left_start = start;
	int left_end = mid;
	int right_start = mid+1;
	int right_end = end;
	merge_sort(left_start, left_end);
	merge_sort(right_start, right_end);
	//���
	merge(left_start, left_end, right_start, right_end);
}



int main() {
	cout<<"���������ֵĸ���:";
	cin>>n;
	cout<<"����������������:";
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	merge_sort(0,n-1);
	cout<<"�����:";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
}
