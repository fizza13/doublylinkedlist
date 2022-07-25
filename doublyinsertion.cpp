#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node*prev;
};


   struct node *head=NULL;
  // struct node *tail=NULL;

 void add_node(int value)
    {
         struct node *s, *temp;
    temp = new node; 
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        s = head;
        while (s->next != NULL)
           {
			 s = s->next;}
        s->next = temp;
        temp->prev = s;
    }
    }
    void deleteatpos(int pos)
    {
    struct node *p=head;
	struct node *q=p->next;
	if(pos==1) 
	{
		cout<<"first index";
	 } 
	 else
	 {
	 	for(int i=1;i<pos-1;i++)
	 	{
	 		p=p->next;
	 		q=q->next;
		 }
		 p->next=q->next;
		 q->next->prev=q->prev;
		 delete q;
	 }
	}
	void deletelastnode( )
	{
		struct node *p,*q;
		if (head==NULL)
		{
		cout<<"empty"	;
		}
		else
		{
			p=head;
			q=head->next;
			while(q->next!=NULL)
			{
				p=p->next;
				q=q->next;
			}
			p->next=NULL;
			delete q;
			
		}
	}

    void displaydata()
{
struct node *ptr=head;
	do	{
			cout<<ptr->data<<" ";
		ptr=ptr->next;
		}while(ptr!=head);
	}


int main()
{
  int n,i,value,a,opt,b,pos;
 
   cout<<"how many nodes you want to enter";
   cin>>n;
   for(int i=0;i<n;i++)
   {
   	cout<<"enter value for "<<i+1<<" node";
   	cin>>value;
   	add_node(value);
   }
   // displaydata();
    while(true){
	
    cout<<"press 1 to delete by giving index.\n";
    cout<<"press 2 to deletelast node\n";
	cout<<"select your option\n";
	cin>>opt;
	switch(opt)
	{
		case 1:
		//	cout<<"enter value\n";
		//	cin>>a;
			cout<<"enter pos\n";
			cin>>pos;
			deleteatpos(pos);
			displaydata();
			break;
		case 2:
		//	cout<<"enter value\n";
		//	cin>>b;
		//	cout<<"enter position\n";
		//	cin>>pos;
			deletelastnode();
			displaydata();
			break;
							
	}}
    
    return 0;
}
