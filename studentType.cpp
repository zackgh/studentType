// Zack Ghalayini
// Homework 2 

/*
1.  Define a structure of type studentType to include a name, gpa and current credits begin taken.
Prompt the user first for a size, n, then for n students (and all of their information). 
Store all of this in a dynamic array (of studentTypes).
Write a function to display one student's information
Write a function to display a list of all of the students' names
Write a function to compute and display the average gpa of all of the students and the average number of credits being taken.
*/

#include<iostream>
#include<string>

using namespace std;


struct studentType
{
	string name;
	float gpa;
	int credits;
};

void displayOne(studentType students[],int n);
void display(studentType students[], int n);
void StudentAverage(studentType students[], int n);
void inputArray(int ** arr, int x, int y);
void displayArr(int ** arr, int x, int y);
int main()
{
	int n;
	cout << "Please enter number of students: ";
	cin >> n;
	cout << endl;
	
	studentType * students = new studentType[n];

	cout << "Please enter student info below\n\n" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter student " << i + 1 << " name: ";
		cin >> students[i].name;

		cout << "Enter student " << i + 1 << " gpa: ";
		cin >> students[i].gpa;

		cout << "Enter student " << i + 1 << " credits: ";
		cin >> students[i].credits;
	}

	displayOne(students, n);
	display(students, n);
	StudentAverage(students, n);

	//delete students;

	// Problem 2 -------------------------------------------------------------
	/*
	2.  Declare a dynamic 2D array of integers.Allow the user to input both the number of rows and columns.
		Write a function to allow the user to input the values.
		Write a display function which prints the array(in matrix form).
		*/
	
	int x, y;
	cout << "-------------------------------------------------------------\n\n\n\n\n" << endl;
	cout << "Please enter array dimensions" << endl;
	cout << "Collumns: ";
	cin >> x;
	cout << "Rows: ";
	cin >> y;
	cout << endl;

	int ** arr;
	arr = new int*[x];

	for (int i = 0; i < x; i++)
	{
		arr[i] = new int[y];
	}

	inputArray(arr, x, y);
	displayArr(arr, x, y);

	/*
	for (int i = 0; i < x; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
	return 0;
	*/
}





// Functions -------------------------------------------------------------------


void displayOne(studentType students[], int n)
{
	string b;
	cout << "Enter the name of the student to display info: ";
	cin.ignore();
	getline(cin, b);
	
	for (int i = 0; i < n; i++)
	{
		if (students[i].name == b)
		{
			cout <<"\n\n\nName: "<< students[i].name << endl;
			cout << "GPA: "<<students[i].gpa << endl;
			cout << "Credits: "<<students[i].credits << endl;

		}
	}
}


void display(studentType students[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\nStudent " << i + 1 << ")" << endl;
		cout << "\nName: " << students[i].name << endl;
		cout << "GPA: " << students[i].gpa << endl;
		cout << "Credits: " << students[i].credits << endl;
	}
}

void StudentAverage(studentType students[], int n)
{
	float gpaTotal = 0;
	float gpaAve = 0;
	int creditTotal = 0;
	int creditAve = 0;
	for (int i = 0; i < n; i++)
	{
		gpaTotal += students[i].gpa;
		creditTotal += students[i].credits;
	}

	gpaAve = gpaTotal / n;
	creditAve = creditTotal / n;

	cout << "\n\nStudent avegare GPA: " << gpaAve << endl;
	cout << "Student average credits: " << creditAve << endl;
}

void inputArray(int ** arr, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << "Row " << i + 1 << " Collumn " << j + 1 << " :";
			cin >> arr[i][j];
		}
	}
}

void displayArr(int ** arr, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
