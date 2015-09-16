#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct tree_node {
            char data;
            struct tree_node *left_child, *right_child;
} tnode_str;
tnode_str *root;
void inorder( tnode_str *ptr ){
    if ( ptr ){
            inorder( ptr->left_child );       // ���� ���� Ʈ�� �˻�
            printf("%c ", ptr->data );     // ��� �湮
            inorder( ptr->right_child );      // ���� ���� Ʈ�� �˻�
    }
}
void preorder( tnode_str *ptr ){
    if ( ptr ){
        printf("%c ", ptr->data );        // ��� �湮
             preorder( ptr->left_child );      // ���� ���� Ʈ�� �˻�
             preorder( ptr->right_child );     // ���� ���� Ʈ�� �˻�
    }
}
void postorder( tnode_str *ptr ){
    if ( ptr ){
            postorder( ptr->left_child );       // ���� ���� Ʈ�� �˻�
            postorder( ptr->right_child );     // ���� ���� Ʈ�� �˻�
            printf("%c ", ptr->data );         // ��� �湮
    }
}
void main()
{
            //��Ƽ�̵����а� 1091055 �����
            tnode_str *n1, *n2, *n3, *n4, *n5, *n6, *n7;
            n1 = (tnode_str *)malloc(sizeof(tnode_str));
            n2 = (tnode_str *)malloc(sizeof(tnode_str));
            n3 = (tnode_str *)malloc(sizeof(tnode_str));
            n4 = (tnode_str *)malloc(sizeof(tnode_str));
            n5 = (tnode_str *)malloc(sizeof(tnode_str));
            n6 = (tnode_str *)malloc(sizeof(tnode_str));
 
            n7 = (tnode_str *)malloc(sizeof(tnode_str));
            n1->data = '+';  n1->left_child = n2;  n1->right_child = n3;
            n2->data = '*';  n2->left_child = n4;  n2->right_child = n5;
            n3->data = '/';  n3->left_child = n6;  n3->right_child = n7;
            n4->data = 'a'; n4->left_child = NULL; n4->right_child = NULL;
            n5->data = 'b'; n5->left_child = NULL; n5->right_child = NULL;
            n6->data = 'c'; n6->left_child = NULL; n6->right_child = NULL;
            n7->data = 'd'; n7->left_child = NULL; n7->right_child = NULL;
 
            root = n1;
            printf("\ninorder\n"); inorder(root);
            printf("\npreorder\n"); preorder(root);
            printf("\npostorder\n"); postorder(root);
}
 