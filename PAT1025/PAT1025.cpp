#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
struct link {
	int address;
	int next;
	int data;
	struct link *nxt;//ָ����һ��
	struct link *last;//ָ����һ��
};
struct link l[100100],Lk[100100];
struct link *head;

int main() {
	head = (struct link*)malloc(sizeof(struct link));
	int n, k;
	int i, j;
	scanf_s("%d%d%d", &l[0].address, &n, &k);

	l[0].nxt = &l[n + 1];
	l[n + 1].nxt = NULL;
	
	for (i = 1; i <= n; i++) {
		scanf_s("%d%d%d", &l[i].address, &l[i].data, &l[i].next);
		//�ҳ���һ���ڵ�
		if (l[i].address == l[0].address) {
			l[i].nxt = l[0].nxt;
			l[0].nxt = &l[i];
			head = &l[i];
		}
	}

	//��������
	while (head->next != -1) {
		for (i = 1; i <= n; i++) {
			if (l[i].address == head->next) {
				l[i].nxt = head->nxt;
				head->nxt = &l[i];
				head = &l[i];
				break;
			}
		}
	}

	//������������
	head = &l[0];
	for (i = 0; head->nxt != NULL; i++) {

		//����������
		if (i != 0) {
			Lk[i].last = &Lk[i - 1];
			Lk[i - 1].nxt = &Lk[i];
		}
		
		//����������ת��
		Lk[i].address = head->address;
		Lk[i].data = head->data; 
		
		head = head->nxt;
	}

	int length = i - 1;
	Lk[length].nxt = &Lk[i];
	Lk[i].last = &Lk[length];
	Lk[i].data = i;
	//Lk[i].nxt = NULL;

	//������Ҫ��תֱ�����
	if (k == 1 || k > length) {
		
		head = Lk[0].nxt;
		printf("%05d %d", head->address, head->data);
		head = head->nxt;
		while (head->nxt != NULL) {
			printf(" %05d\n%05d %d", head->address, head->address, head->data);
			head = head->nxt;
		}
		printf(" -1\n");

		return 0;
	}

	bool islength = false;
	//��ת
	head = &Lk[length];	
	for (j = 1; j*k <= length; j++) {
		for (i = k*j; i > k*(j - 1); i--) {

			//ȫ��ת
			if (k == length&&!islength) {
				head = head->last;
				islength = true;
			}

			//��ԭ�����Ƴ�
			Lk[i].nxt->last = Lk[i].last;
			Lk[i].last->nxt = Lk[i].nxt;

			//��������β��
			Lk[i].last = head;
			head->nxt->last = &Lk[i];
			Lk[i].nxt = head->nxt;
			head->nxt = &Lk[i];

			head = &Lk[i];
		}
	}
	
	//ʣ�಻�÷�ת����
	for (i = (j - 1)*k + 1; i <= length; i++) {
		Lk[i].nxt->last = Lk[i].last;
		Lk[i].last->nxt = Lk[i].nxt;


		Lk[i].last = head;
		head->nxt->last = &Lk[i];
		Lk[i].nxt = head->nxt;
		head->nxt = &Lk[i];

		head = &Lk[i];
	}
	
	//���
	head = Lk[0].nxt;
	printf("%05d %d", head->address, head->data);
	head = head->nxt;
	while (head->nxt != NULL) {
		printf(" %05d\n%05d %d", head->address, head->address, head->data);
		head = head->nxt;
	}
	printf(" -1\n");
	
	return 0;
}