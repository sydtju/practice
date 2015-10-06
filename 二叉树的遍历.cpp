#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
node *init(){
	int  i=0;
	node *head=new node(i++);
	head->left=new node(i++);
	head->right=new node(i++);
	head->left->left=new node(i++);
	head->left->right=new node(i++);
	head->right->left=new node(i++);
	head->right->right=new node(i++);
	return head;
}
void frist(node *head){
	if(!head) return;
	cout<<head->data<<"  ";
	frist(head->left);
	frist(head->right);
}
void mid(node *head){
	if(!head) return;
	frist(head->left);
	cout<<head->data<<"  ";
	frist(head->right);
}
void back(node *head){
	if(!head) return;
	frist(head->left);
	frist(head->right);
	cout<<head->data<<"  ";
}
int main(){
	stack<int> s;
	node* head=init();
	cout<<"前序遍历是：";	
	frist(head);
	cout<<endl;
	cout<<"中序遍历是：";	
	mid(head);
	cout<<endl;
	cout<<"后序遍历是：";	
	back(head);
	cout<<endl;
	return 0;
}
