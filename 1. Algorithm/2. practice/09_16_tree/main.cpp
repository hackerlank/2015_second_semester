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
            inorder( ptr->left_child );       // 좌측 서브 트리 검사
            printf("%c ", ptr->data );     // 노드 방문
            inorder( ptr->right_child );      // 우측 서브 트리 검사
    }
}
void preorder( tnode_str *ptr ){
    if ( ptr ){
        printf("%c ", ptr->data );        // 노드 방문
             preorder( ptr->left_child );      // 좌측 서브 트리 검사
             preorder( ptr->right_child );     // 우측 서브 트리 검사
    }
}
void postorder( tnode_str *ptr ){
    if ( ptr ){
            postorder( ptr->left_child );       // 좌측 서브 트리 검사
            postorder( ptr->right_child );     // 우측 서브 트리 검사
            printf("%c ", ptr->data );         // 노드 방문
    }
}
void main()
{
            //멀티미디어공학과 1091055 김웅빈
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
 