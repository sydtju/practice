#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
struct node{
	int data;
	node *next;
	node(int data){
		this->data=data;
		this->next=NULL;
	}
};
node *init(int num){
	int  i=1;
	node *head=new node(0);
	while (i<=num)
	{
		head->next=new node(i++);
		head=head->next;
	}
	return head;
}
