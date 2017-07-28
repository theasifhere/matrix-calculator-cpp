#include<iostream>
#include<fstream>
using namespace std;
int process_no();
bool sizecheck(int, int);
int** arr_input(int, int);
void print_array(int**, int, int);
int** diagonal(int**, int, int, int);
void transpose(int**, int, int);
int** product(int**, int**, int, int, int, int);
void file(int**, int, int);
int** diagonalSum(int**, int** ,int);
// Programmed by Asif Iqbal (twitter.com/TheAsifHere)
void main() {
	int process,col,row,row2, col2,**ptr1,**ptr2,**ptr3,func;
	process = process_no();
	while (process)
	{  switch (process)
		{
		case 1: cout << "\n\t\tMultiplication";
			cout << "\nEnter number of Rows of 1st matrix: ";    cin >> row;	//input of array
			cout << "Enter number of Columns of 1st matrix: ";   cin >> col;
			cout << "\tEnter the Elements of MAtrix 1\n";
			ptr1 = arr_input(row, col);
			cout << "Enter number of Rows of 2nd matrix: ";    cin >> row2;
			cout << "Enter number of Columns of 2nd matrix: ";   cin >> col2;
			cout << "\n\tEnter the Elements of MAtrix 2\n";
			ptr2 = arr_input(row2, col2);
			if (sizecheck(col, row2) == true) //calling function to check either matrix can be multiplied or not
			{
			 ptr3 = product(ptr1, ptr2, row, col, col2, row2);
			 cout << "\tPRODUCT";
			 print_array(ptr3, row, col2);
			 file(ptr3, row, col2);
			}
			else
				cerr << "\n\tORDER of MATRICES NOT OPERATABLE\n";
			system("pause"); system("cls");
			process = process_no();		//process value update
			break;
		case 2: cout << "\tUpper/Lower Diagonal \n";
			cout << "Enter size of Square Matrix: ";	cin >> row;
			col = row;
			cout << "\t Enter the Elements of Matrix\n";
			ptr1 = arr_input(row, col);
			cout << "\t0:LOWER DIAGONAL\n\t1:UPPER DIAGONAL\n";cin >> func;
			ptr2 = diagonal(ptr1, row, col, func);	//function call for diagonal matrix
			print_array(ptr2, row, col);
			file(ptr2, row, col);		//calling function for saving result in file
			system("pause"); system("cls");
			process = process_no();
			break;
		case 3: cout << "\n\n\t\tTranspose\n";
			cout << "Enter size of Square Matrix: ";	cin >> row; col = row;
			cout << "\n\tEnter the elements of Matrix\n";
			ptr1 = arr_input(row, col);
			cout << "\nAdress of pointer is " << ptr1<<endl;
			transpose(ptr1, row, col);	//calling transpose function
			system("pause"); system("cls");
			process = process_no(); 
			break;
		case 4: cout << "\tUpper / Lower Diagonal Sum \n"; 
			cout << "Enter size of Matrices:";	cin >> row; 
			col = row;
			cout << "\t Enter the Elements of 1st Matrix\n";
			ptr1 = arr_input(row, col);		//array input function
			cout << "\t Enter the Elements of 2nd Matrix\n";
			ptr2 = arr_input(row, col);
			cout << "\t0:LOWER DIAGONAL SUM\n\t1:UPPER DIAGONAL SUM\n"; cin >> func;
	print_array(diagonalSum(diagonal(ptr1, row, row, func) , diagonal(ptr2, row, row, func), row),  row,  row);	//Printing diagonalising and Sum up array  
	file(diagonalSum(diagonal(ptr1, row, row, func), diagonal(ptr2, row, row, func), row), row, row);	//file out
			system("pause"); system("cls");
			process = process_no(); 
			break;
		case 5: cout << "\tExiting\n";
			ptr1 = NULL; ptr2 = NULL; ptr3 = NULL;  //Pointing pointers to null
			return;break;
		default:  cerr << "\tWrong Input Select suitable Menu\n";
			system("pause"); system("cls");
			process = process_no(); 
			break;
		}
	}
}
int process_no()
{
	int processno;
	cout << "\t1: \tMatrix Multiplication \n";   cout << "\t2: \tUpper/Lower Diagonal Half \n";  
	cout << "\t3: \tTranspose\n";   cout << "\t4: \tUpper / Lower Diagonal Sum \n";    
	cout << "\t5: \tExit\n";
	cout << "\nSelect required Operation : ";
	cin >> processno;
	return processno;
}
int **arr_input(int row, int col)
	{
		int **arr;
		arr = new int*[row];
		for (int i = 0; i < row; i++)        //array size
		{
			*(arr + i) = new int[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> *(*(arr + i) + j);
			}
		}   //input array
		return arr;
	}
void transpose(int**arr, int row, int col)
	{
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				cout << *(*(arr + j) + i) << "  ";		//pointer notation//
			}	
			cout << endl;
		}
		cout << "\nAdress after transpose is " << arr << endl;
	}
void print_array(int** arr, int row, int col)
{
	cout << endl << " \t ";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << *(*(arr + i) + j) << "    ";
		}
		cout << endl << " \t ";
	}
	cout << endl;
}
bool sizecheck(int col, int row)
{
	return (col == row) ? true : false;		//check & rturn throught ternary operator
}
int** product(int**arr, int**arr2, int row, int col, int col2, int row2)
{
	int**result;
	result = new int*[row];
	for (int i = 0; i < row; i++)     //array size declaration of size ===> row1 * col2 ===> m1 * n2
		*(result + i) = new int[col2];	

	for (size_t i = 0; i < row; i++)     //initialising product array to zero
		for (size_t j = 0; j < col2; j++)
			(*(*(result + i) + j)) = 0;

	for (size_t i = 0; i < row; i++)         //MULTIPLYING THE ELEMENTS AND STORING
		for (size_t j = 0; j < col2; j++)
			for (size_t k = 0; k < col; k++)
				*(*(result + i) + j) += *(*(arr + i) + k) * *(*(arr2 + k) + j);

	cout << endl;
	return result;
}
void file(int** arr, int row, int col){
	ofstream objectFile;
	objectFile.open("Result.txt", ios::app);
	objectFile << endl << "\t";
	for (int i = 0; i < row; i++)
	{	for (int j = 0; j < col; j++)
		{
			objectFile << *(*(arr + i) + j) << "    ";
		}
		objectFile << endl << "\t";
	}
	objectFile << endl<<endl;
}
int**diagonal(int**arr, int row, int col, int func) {
	switch (func)
	{
	case 1:
		for (size_t i = 0; i < row; i++)
			for (size_t j = 0; j < col; j++)
				*(*(arr + i) + j) = (j < i) ? 0 : *(*(arr + i) + j);
		break;
	case 0:
		for (size_t i = 0; i < row; i++)
			for (size_t j = 0; j < col; j++)
				*(*(arr + i) + j) = (i >= j) ? *(*(arr + i) + j) : 0;
		break;
	}
	return arr;
}
int**diagonalSum(int**arr,int**arr2 , int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			*(*(arr + i) + j) = *(*(arr + i) + j) + *(*(arr2 + i) + j);		//pointer notation//
		}
	}
	return arr;
}
//extra line to complete 200 lines. THANK YOU!