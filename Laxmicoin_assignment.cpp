#include<bits/stdc++.h>
using namespace std;
struct node{
	int student_id;
	string student_name;
	float student_cgpa;
	node* next;
};
struct node* head;

void insert(int id,string name,float cgpa){
	node* tmp=new node();
	tmp->student_id=id;
	tmp->student_name=name;
	tmp->student_cgpa=cgpa;
	tmp->next=head;
	head=tmp;	
}

int deleteId(int id){
    node* tmp=head;
    node* prev=NULL;
    while(tmp->student_id!=id && tmp->next!=NULL){
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp->student_id==id){
        if(prev)
            prev->next=tmp->next;
        else
            head=tmp->next;
        free(tmp);
        return id;
    }
    return -1;
}

node* search(int id){
    node* tmp=head;
    while(tmp->student_id!=id && tmp->next!=NULL){
        tmp=tmp->next;
    }
    if(tmp->student_id==id){
        return tmp;
    }
    return NULL;
}

void print(){
 	node* tmp=head;
	if(tmp){
		cout<<"\n\n--List of students is: \n"<<endl;
		cout<<"ID\tName\t\tCGPA\n";
		while(tmp!=NULL){
			cout<<tmp->student_id<<"\t"<<tmp->student_name<<"\t\t"<<tmp->student_cgpa<<endl;
			tmp=tmp->next;
		}
		cout<<endl;	
	}
	else{
		cout<<"\nNo student found.\n";
	}
	
}

void insert_student(){
	int id;
	string name;
	float cgpa;

	cout<<"\n\nEnter Student Id :- ";
	cin>>id;
	cout<<endl;
	cout<<"Enter Student Name :- ";
	cin>>name;
	cout<<endl;
	cout<<"Enter Student CGPA :- ";
	cin>>cgpa;
	cout<<endl;
		
	insert(id,name,cgpa);
//	print();
}

void delete_student(){
	cout<<"\n--Deletion--\n";
	if(head){
		cout<<"\nEnter student id :-";
		int id;
		cin>>id;
		int result=deleteId(id);
		if(result==-1){
			cout<<"\nSorry, Id not present.\n";
		}
		else{
			cout<<"\nStudent Id "<<result<<" is deleted.\n";
		}	
	}
	else{
		cout<<"\nNo Student there (Please add data).\n";
	}
}

void search_student(){
	cout<<"\n--Searching--\n";
	if(head){
		cout<<"\nEnter student id :-";
		int id;
		cin>>id;
		node* result=search(id);
		if(result==NULL){
			cout<<"\nSorry, Id not present.\n";
		}
		else{
			cout<<"\n--Id fround\n";
			cout<<"\nStudent Id :- "<<result->student_id<<endl;
			cout<<"\nStudent Name :- "<<result->student_name<<endl;
			cout<<"\nStudent CGPA :- "<<result->student_cgpa<<endl;
		}	
	}
	else{
		cout<<"\nNo data is there(Please add data).\n";
	}	
}

void highest_cgpa(){
	node* tmp=head;
	if(tmp){
		node* maxNode=NULL;
		int max=-1;
		if(tmp->next==NULL){
			cout<<"here";
			maxNode=tmp;
		}
		else{
			 while(tmp!=NULL){
		    	cout<<tmp->student_cgpa<<endl;
		    	if(tmp->student_cgpa>max){
		    		max=tmp->student_cgpa;
		    		maxNode=tmp;
				}
		        tmp=tmp->next;
				//cout<<max<<tmp->student_cgpa<<endl;
	    	}
		}
	   
	    //cout<<tmp->student_cgpa<<endl;
		cout<<"\n\nHighest CGPA student\n";
		cout<<"\nStudent Id :- "<<maxNode->student_id<<endl;
		cout<<"\nStudent Name :- "<<maxNode->student_name<<endl;
		cout<<"\nStudent CGPA :- "<<maxNode->student_cgpa<<endl;
		cout<<endl;	
	}
	else{
		cout<<"\n\nNo student found.\n";
	}
}

void print_student(){
	print();
}

int main(){
	int op;
	while(1){
		cout<<"\n\n****** Student Register *******\n";
		cout<<"1. Add a student"<<endl;
		cout<<"2. Delete a student"<<endl;
		cout<<"3. Search a student"<<endl;
		cout<<"4. Print all student"<<endl;
		cout<<"5. Highest CGPA student"<<endl;
		cout<<"6. Exit."<<endl;
		cout<<"\nEnter your choice :- ";
		cin>>op;
		switch(op){
			case 1:
				insert_student();
				break;
			case 2:
				delete_student();
				break;
			case 3:
				search_student();
				break;
			case 4:
				print_student();
				break;
			case 5:
				highest_cgpa();
				break;
			case 6:
				exit(0);
			default:
				cout<<"\nWrong Choise.\n";
		}
	}
	return 0;
}
