#include <iostream>
#include <iomanip>
using namespace std;
//This program stores data on student ID numbers and their respective grades. It sorts their grades and calculates the average.
//Author: Badtothebunny
//First I created the swap function that will be called in the bubblesort function.
void swap (int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
//Next is the bubblesort function.
void bubblesort (int grade[],int id[],int size)
{
	int i,j;
	for (j=0;j<=size-1;j++)
		for (i=0;i<size-j;i++)
			if (grade[i]>grade[i+1])
			{
				swap(grade[i],grade[i+1]);
				swap (id[i],id[i+1]);
			}
}
//This next function calculates what the average grade is for the class.
float average (int grade[],int size)
{
	int i;
	float sum=0,av;
	for (i=0;i<size;i++)
		sum+=grade[i];
	av=sum/size;
	return av;
}
//The last function we need is the search function. 
int search(int id[],int size,int srch)
{
	int i=0;
	while (i<size && id[i]!=srch)
		i++;
	if (i<size)
		return i;
	else
		return -1;
}
int main(int argc, char** argv)
{
	int id[30],grade[30],i=0,cnt=1,idnum,loc;
	float avrg;
	//Here I am collecting the data from the user using a while loop after getting our first pair.
	cout<<"Enter Student ID and their grade(0 terminates):"<<endl;
	cin>>id[i]>>grade[i];
	while(i<30 && id[i]!= 0 && grade[i]!=0)
	{
		cnt++;
		i++;
		if (i == 30)
			cout<<"Max data has been reached."<<endl;
		else
		{
			cout<<"Enter Student ID and their grade(0 terminates):"<<endl;
			cin>>id[i]>>grade[i];
		}
	}
	bubblesort(grade,id,cnt);
	//Now we can print out all the student's ID and grades.
	cout<<"Student ID"<<setw(6)<<"Grade"<<endl;
	for (i=0;i<=cnt;i++)
		cout<<id[i]<<setw(6)<<grade[i]<<endl;
	avrg=average(grade,cnt);
	//Now we print out all the students who have a higher than average grade.
	cout<<"Students that have above average:"<<endl<<"ID"<<setw(6)<<"Grade"<<endl;
	for(i=0;i<=cnt;i++)
		if(grade[i]>avrg)
			cout<<id[i]<<setw(6)<<grade[i]<<endl;
	//Lastly, we allow the user to search for any student's grade.
	cout<<"Search for any student's grade."<<endl<<"Enter student's ID:"<<endl;
	cin>>idnum;
	while (idnum != 00)
	{
		loc=search(id,cnt,idnum);
		if (loc == -1)
			cout<<"Student not found."<<endl;
		else
			cout<<"Student's grade is "<<grade[loc]<<endl;
		cout<<"Enter Student's ID(00 terminates):"<<endl;
		cin>>idnum;
	}
}



