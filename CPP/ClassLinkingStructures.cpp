#include<iostream>
using namespace std;

struct Student{
	int reg_no;
	float gpa;
	
	Student* p;
};

int main()
{
	Student s1,s2,s3;
	cout<<"\n Enter registration number of Student 1 ";
	cin>>s1.reg_no;
	cout<<"\n Enter gpa number of Student 1 ";
	cin>>s1.gpa;
	
	cout<<"\n Enter registration number of Student 2 ";
	cin>>s2.reg_no;
	cout<<"\n Enter gpa number of Student 2 ";
	cin>>s2.gpa;
	
	cout<<"\n Enter registration number of Student 3 ";
	cin>>s3.reg_no;
	cout<<"\n Enter gpa number of Student 3 ";
	cin>>s3.gpa;
	
	s1.p=&s2;
	s2.p=&s3;
	s3.p=NULL;
	
	Student *start;
	start=&s1;
	
	//compiler forgets the names s1 s2 s3 "somehow" but we know the name start
	// and we want to print each Student data
	// how can we do it???
	
	Student *temp=start;
	while(temp!=NULL)
	{
		cout<<"\n registration number is "<<temp->reg_no;
		cout<<" \n gpa is "<<temp->gpa;
		
		temp=temp->p;
		}	
	
	
	
}
