#include<iostream>

using namespace std;
typedef int status;
typedef int ElementType;
#define ERROR 1;
#define OK 0;
typedef struct BinaryTreeNode {
    ElementType data;
    struct BinaryTreeNode *lchild, *rchild;
} BinaryTreeNode, *BinaryTree;

status createBinaryTree(BinaryTree &T, ElementType data) {
    T = new BinaryTreeNode;
    if (!T)return ERROR;
    T->lchild = NULL;
    T->rchild = NULL;
    T->data = data;
    return 0;
}

status createFullTree(BinaryTree &T) {
    BinaryTree temp = new BinaryTreeNode;//F2L
    BinaryTree temp2 = new BinaryTreeNode;//F2R
    BinaryTree temp3 = new BinaryTreeNode;//F31L
    temp->data = 3;
    temp2->data = 2;
    temp3->data = 1;
    temp3->lchild = NULL;
    temp3->rchild = NULL;
    T->lchild = temp;
    T->rchild = temp2;
    temp->lchild = temp3;//F31L
    temp3 = new BinaryTreeNode;//F31R
    temp3->data = 4;
    temp3->lchild = NULL;
    temp3->rchild = NULL;
    temp->rchild = temp3;
    temp3 = new BinaryTreeNode;//F32L
    temp3->data = 7;
    temp3->lchild = NULL;
    temp3->rchild = NULL;
    temp2->lchild = temp3;
    temp3 = new BinaryTreeNode;//F32R
    temp3->data = 8;
    temp3->lchild = NULL;
    temp3->rchild = NULL;
    temp2->rchild = temp3;

    return OK;

}

status InOrderTraverse(BinaryTree &T) { //中序遍历
    if (!T)return ERROR;
    InOrderTraverse(T->lchild);
    cout << T->data << "  ";
    InOrderTraverse(T->rchild);
    return OK;
}

status PreOrderTraverse(BinaryTree &T) { //前序遍历
    if (!T)return ERROR;
    cout << T->data << "  ";
    InOrderTraverse(T->lchild);
    InOrderTraverse(T->rchild);
    return OK;
}

status PostOrderTraverse(BinaryTree &T) { //后序遍历
    if (!T)return ERROR;
    InOrderTraverse(T->lchild);
    InOrderTraverse(T->rchild);
    cout << T->data << "  ";
    return OK;
}

int Depth(BinaryTree &T) {
    if (T == NULL)return 0;
    int m = Depth(T->lchild);
    int n = Depth(T->rchild);
    if (m > n) return m + 1;
    else return n + 1;
}

int Count(BinaryTree &T) {
    if (T == NULL) return 0;
    else return Count(T->lchild) + Count(T->rchild) + 1;
}

int LeafCount(BinaryTree &T) {
    if (T == NULL) return 1;
    if (T->rchild == NULL && T->rchild == NULL) {
        return 1;
    } else return LeafCount(T->lchild) + LeafCount(T->rchild);
}

int DegreeWithOne(BinaryTree &T) {
    if(T==NULL)return 0;
    if((T->lchild!=NULL&&T->rchild==NULL)||(T->lchild==NULL&&T->rchild!=NULL)){
        return 1;
    }
    else return DegreeWithOne(T->lchild)+DegreeWithOne(T->rchild);
}

int main() {
    BinaryTree node;

    createBinaryTree(node, 12); //创建如Markdown文件下二叉树形式
    createFullTree(node);
    printf("InOrderTraverse:\n");
    InOrderTraverse(node);
    printf("\nPreorderTraverse:\n");
    PreOrderTraverse(node);
    printf("\nPostorderTraverse:\n");
    PostOrderTraverse(node);
    printf("\n");
    printf("Depth:%d\n", Depth(node));
    printf("count:%d\n", Count(node));
    printf("DegreeWithOne:%d\n",DegreeWithOne(node));

    return OK;
}
