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

void back(node *head){
	if(!head) return;
	back(head->left);
	back(head->right);
	cout<<head->data<<"  ";
}
void frist_s(node *head){
	if(!head) return ;
	stack<node*> s;
	s.push(head);
	node *root=NULL;
	while (s.size())
	{
		root=s.top();
		s.pop();
		cout<<root->data<<"  ";
		if(root->right) s.push(root->right);
		if(root->left) s.push(root->left);
	}
}
void mid(node *head){
	if(!head) return;
	mid(head->left);
	cout<<head->data<<"  ";
	mid(head->right);
}
void mid_s(node *head){
	stack<node*> s;
	while (s.size()||head)
	{
		if (head!=NULL)
		{
			s.push(head);
			head=head->left;
		} 
		else
		{
			head=s.top();
			s.pop();
			cout<<head->data<<"  ";
			head=head->right;
		}
	}
}
int main(){
	stack<int> s;
	node* head=init();
	cout<<"前序遍历是：\n";	
	frist(head);
	cout<<endl;
	cout<<"非递归前序遍历是：\n";	
	frist_s(head);
	cout<<endl;
	cout<<"中序遍历是：\n";	
	mid(head);
	cout<<endl;
	cout<<"非递归中序遍历是：\n";	
	mid_s(head);
	cout<<endl;
	cout<<"后序遍历是：\n";	
	back(head);
	cout<<endl;
	return 0;
}
