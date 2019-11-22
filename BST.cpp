#include"BST.h"


void menu()														//�˵�
{
	cout << "=======================================================================" << endl;
	cout << "��-------------------------------���˵�------------------------------��" << endl;
	cout << "|    1������ڵ�(����������)           2�����������б���������        |" << endl;
	cout << "|    3��ɾ���ڵ�                       4�����ٶ�����                  |" << endl;
	cout << "��-------------------------------0���˳�-----------------------------��" << endl;
	cout << "������Ҫִ�еĲ�����ţ�";
}


void InsertBST(BST& T,ElemType n)	//����ڵ�
{
	if (!T) {									//���TΪ�գ����½��ڵ㲢����
		T = new BSTNode;
		T->data = n;
		T->Lchild = T->Rchild = NULL;
	}
	else if (n > T->data)						//n>T->data�����T����������
		InsertBST(T->Rchild, n);
	else if (n < T->data)						//n<T->data�����T����������
		InsertBST(T->Lchild, n);
}

void VisitBST(BST T)				//��������������
{
	if (T) {									//��T����
		VisitBST(T->Lchild);					//����������
		cout << setw(6) << T->data;				//���T
		VisitBST(T->Rchild);					//����������
	}
}

void DeleteBST(BST& T, ElemType n)	//ɾ���ڵ�
{
	if (!T)										//��TΪ��
		cout << "δ�ҵ��ýڵ㡣" << endl;
	else {
		if (T->data == n) {
			if (!T->Lchild && !T->Rchild) {		//��ɾ���ڵ���Ҷ�ӽڵ�
				BST p = T;
				T = NULL;
				delete p;
			}
			else if (T->Lchild && !T->Rchild) {	//��ɾ���ڵ�ֻ��������
				BST p = T;
				T = T->Lchild;
				delete p;
			}
			else if (!T->Lchild && T->Rchild) {	//��ɾ���ڵ�ֻ��������
				BST p = T;
				T = T->Rchild;
				delete p;
			}
			else {								//��ɾ���ڵ�����������
				BST p = T, S = T->Lchild;		//S����T��������pָ��Sǰ��
				while (S->Rchild) {				//S��T����������Ѱ��Tǰ���ڵ�
					p = S;
					S = S->Rchild;
				}
				T->data = S->data;				//��S�ڵ����ݸ���T
				if (p == T)						//pָ��T����T����ָ��S����
					p->Lchild = S->Lchild;
				else							//p��ָ��T����p���Һ���ָ��S������
					p->Rchild = S->Lchild;
			}
		}
		else if (n > T->data)					//��n>T->data������������Ѱ��
			DeleteBST(T->Rchild, n);
		else if (n < T->data)					//��n<T->data������������Ѱ��
			DeleteBST(T->Lchild, n);
	}
}

void DestroyBST(BST& T)				//���ٶ���������
{
	if (T) {
		DestroyBST(T->Lchild);					//����������
		DestroyBST(T->Rchild);					//����������
		delete T;								//���ٵ�ǰ�ڵ�
		T = NULL;
	}
}
