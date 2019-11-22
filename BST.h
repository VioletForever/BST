#ifndef BST_H

#define BST_H

#include<iostream>
#include<iomanip>

using namespace std;

typedef int ElemType;

typedef struct BSTNode {
	ElemType data;
	BSTNode* Lchild, * Rchild;
}*BST;

void menu();						//�˵�
void InsertBST(BST& T, ElemType n);	//����ڵ�
void VisitBST(BST T);				//��������������
void DeleteBST(BST& T,ElemType n);	//ɾ���ڵ�
void DestroyBST(BST& T);			//���ٶ���������


#endif 

