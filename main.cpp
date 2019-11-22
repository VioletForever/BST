#include"BST.h"

int main() 
{
	int i = 20, n = 0;
	ElemType a[15] = { 19, 38, 12, 40, 41, 39, 54, 76, 35, 47, 80, 14, 9, 44, 60 };
	ElemType data;
	BST T = NULL;

	for (int i = 0; i < 15; i++) {			//�������Ա�������������
		InsertBST(T, a[i]);
	}

	cout << "���������Ա�������������" << endl;

	while (i != 0) {
		switch (i)
		{
		case 1:			//����ڵ�
			cout << "���������Ľڵ�����:";
			cin >> n;
			cout << "����������:";
			for (int k = 0; k < n; k++) {
				cin >> data;
				InsertBST(T, data);
			}
			break;

		case 2:			//��������������
			if (T)
				VisitBST(T);
			else
				cout << "BSTΪ�ա�";
			cout << endl;
			break;

		case 3:			//ɾ���ڵ�
			cout << "������Ҫɾ���Ľڵ����ݣ�";
			cin >> n;
			DeleteBST(T, n);
			break;

		case 4:			//���ٶ���������
			DestroyBST(T);
			break;
		}
		

		menu();
		cin >> i;
	}
	return 0;
}