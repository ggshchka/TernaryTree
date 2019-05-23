#include "header.h"
#include <string>

int main(int argc, char const *argv[])
{
	while (true)
	{
		Back1:
		cout << endl <<"			Welcome to MAJOR OAK!" << endl;
		 	//----------------------------back1
		cout << "1 - Double" << endl << "2 - Complex" << endl << "3 - String" << endl << "4 - Test the program"  << endl << "5 - About the program" << endl << "6 - Exit" << endl;
		char key;
		cin >> key;
			if (key == '1')
			{
				tree<double> A;
				cout << endl << endl << "You should create a tree" << endl;
				cout << "Add N elements. Enter N: ";
				int N;
				cin >> N;
				for (int i = 0; i < N; ++i)
				{
					double elem;
					cin >> elem;
					A.add_el(elem);
				}
				cout << endl;
				A.print_el();
				cout << endl;
				getch();
				Repeat1:
				cout << endl << endl << "1 - map (quad)" << endl << "2 - where (5 <= element <= 50)" << endl << "3 - merger" << endl << "4 - ejection" << endl << "5 - search tree" << endl  << "6 - search element" << endl << "7 - Show a tree" << endl << "8 - Filing" << endl  << "9 - Back" << endl << "0 - Exit" << endl;
				char key1;
				cin >> key1;
				if (key1 == '1')
				{
					tree<double> B;
					A.map_quad_el(B);
					B.print_el();
					//B.freetree_el();
					getch();
					goto Repeat1;
				}
				else if (key1 == '2')
				{
					tree<double> B;
					A.where_el(B);
					getch();
					B.print_el();
					//B.freetree_el();
					getch();
					goto Repeat1;
				}
				else if (key1 == '3')
				{
					cout << endl << "You should create a second tree" << endl;
					cout << "Add N elements. Enter N: ";
					tree<double> B;
					int N;
					cin >> N;
					for (int i = 0; i < N; ++i)
					{
						double elem;
						cin >> elem;
						B.add_el(elem);
					}
					B.merger_el(A);
					//B.freetree_el();
					cout << endl;
					A.print_el();
					getch();
					goto Repeat1;
				}	
				else if (key1 == '4')
				{
					tree<double> B;
					cout << "Enter the element" << endl;
					double elem;
					cin >> elem;
					A.ejection_el(B, elem);
					B.print_el();
					//B.freetree_el();
					getch();
					goto Repeat1;
				}
				else if (key1 == '5')
				{
					cout << "You should create a second tree" << endl;
					cout << "Add N elements. Enter N: ";
					tree<double> B;
					int N;
					cin >> N;
					for (int i = 0; i < N; ++i)
					{
						double elem;
						cin >> elem;
						B.add_el(elem);
					}
					if (A.search_tree(B) == true)
						cout << "YES!" << endl;
					else
						cout << "NO!" << endl;
					//B.freetree_el();
					getch();
					goto Repeat1;
				}
				else if (key1 == '6')
				{
					tree<double> B;
					cout << "Enter the element" << endl;
					double elem;
					cin >> elem;
					if (A.search_el(elem) == true)
						cout << "YES!" << endl;
					else
						cout << "NO!" << endl;
					getch();
					goto Repeat1;
				}
				else if (key1 == '7')
				{
					cout << "		Tree" << endl << endl << "       ";
					A.print_el();
					cout << endl << endl;
					getch();
					goto Repeat1;
				}
				else if (key1 == '8')
				{
					A.filing_el();
					goto Repeat1;
				}
				else if (key1 == '9')
				{
					//A.freetree_el();
					cout << endl;
					goto Back1;
				}
				else if (key1 == '0')
				{
					return false;
				}
				else
				{
					cout << "Try again" << endl;
					goto Repeat1;
				}
			}	
			else if (key == '2')
			{
				tree<complex> A;
				cout << endl << endl << "You should create a tree" << endl;
				cout << "Add N elements. Enter N: ";
				int N;
				cin >> N;
				for (int i = 0; i < N; ++i)
				{
					complex elem;
					cin >> elem;
					A.add_el(elem);
				}
				cout << endl;
				A.print_el();
				cout << endl;
				getch();
				Repeat2:
				cout << endl << "1 - map (quad)" << endl << "2 - where" << endl << "3 - merger" << endl << "4 - ejection" << endl << "5 - search tree" << endl  << "6 - search element" << endl << "7 - Show a tree" << endl  << "8 - Filing" << endl  << "9 - Back" << endl << "0 - Exit" << endl;
				char key1;
				cin >> key1;
				if (key1 == '1')
				{
					tree<complex> B;
					A.map_quad_el(B);
					B.print_el();
					B.freetree_el();
					getch();
					goto Repeat2;
				}
				else if (key1 == '2')
				{
					tree<complex> B1;
					A.where_complex_el(B1);
					getch();
					B1.print_el();
					B1.freetree_el();
					getch();
					goto Repeat2;
				}
				else if (key1 == '3')
				{
					cout << endl << "You should create a second tree" << endl;
					cout << "Add N elements. Enter N: ";
					tree<complex> B;
					int N;
					cin >> N;
					for (int i = 0; i < N; ++i)
					{
						complex elem;
						cin >> elem;
						B.add_el(elem);
					}
					B.merger_el(A);
					B.freetree_el();
					cout << endl;
					A.print_el();
					getch();
					goto Repeat2;
				}	
				else if (key1 == '4')
				{
					tree<complex> B;
					cout << "Enter the element" << endl;
					complex elem;
					cin >> elem;
					A.ejection_el(B, elem);
					B.print_el();
					B.freetree_el();
					getch();
					goto Repeat2;
				}
				else if (key1 == '5')
				{
					cout << "You should create a second tree" << endl;
					cout << "Add N elements. Enter N: ";
					tree<complex> B;
					int N;
					cin >> N;
					for (int i = 0; i < N; ++i)
					{
						complex elem;
						cin >> elem;
						B.add_el(elem);
					}
					if (A.search_tree(B) == true)
						cout << "YES!" << endl;
					else
						cout << "NO!" << endl;
					B.freetree_el();
					getch();
					goto Repeat2;
				}
				else if (key1 == '6')
				{
					tree<complex> B;
					cout << "Enter the element" << endl;
					complex elem;
					cin >> elem;
					if (A.search_el(elem) == true)
						cout << "YES!" << endl;
					else
						cout << "NO!" << endl;
					getch();
					goto Repeat2;
				}
				else if (key1 == '7')
				{
					cout << "		Tree" << endl << endl << "       ";
					A.print_el();
					cout << endl << endl;
					getch();
					goto Repeat2;
				}
				else if (key1 == '8')
				{
					A.filing_el();
					getch();
					goto Repeat2;
				}
				else if (key1 == '9')
				{
					A.freetree_el();
					cout << endl;
					goto Back1;
				}
				else if (key1 == '0')
				{
					return false;
				}
				else
				{
					cout << "Try again" << endl;
					goto Repeat2;
				}
			}
			else if (key == '3')
			{
				tree<string> A;
				cout << endl << endl << "You should create a tree" << endl;
				cout << "Add N elements. Enter N: ";
				int N;
				cin >> N;
				for (int i = 0; i < N; ++i)
				{
					string elem;
					cin >> elem;
					A.add_el(elem);
				}
				cout << endl;
				A.print_el();
				cout << endl;
				getch();
				Repeat3:
				cout << endl << "1 - map (F(str) = str.substr(1, 3))" << endl << "2 - merger" << endl << "3 - ejection" << endl << "4 - search tree" << endl  << "5 - search element" << endl << "6 - Show a tree" << endl  << "7 - Filing" << endl << "8 - Back" << endl << "9 - Exit" << endl;
				char key1;
				cin >> key1;
				if (key1 == '1')
				{
					tree<string> B;
					A.map_str_el(B);
					B.print_el();
					B.freetree_el();
					getch();
					goto Repeat3;
				}
				else if (key1 == '2')
				{
					cout << endl << "You should create a second tree" << endl;
					cout << "Add N elements. Enter N: ";
					tree<string> B;
					int N;
					cin >> N;
					for (int i = 0; i < N; ++i)
					{
						string elem;
						cin >> elem;
						B.add_el(elem);
					}
					B.merger_el(A);
					B.freetree_el();
					cout << endl;
					A.print_el();
					getch();
					goto Repeat3;
				}	
				else if (key1 == '3')
				{
					tree<string> B;
					cout << "Enter the element" << endl;
					string elem;
					cin >> elem;
					A.ejection_el(B, elem);
					B.print_el();
					B.freetree_el();
					getch();
					goto Repeat3;
				}
				else if (key1 == '4')
				{
					cout << "You should create a second tree" << endl;
					cout << "Add N elements. Enter N: ";
					tree<string> B;
					int N;
					cin >> N;
					for (int i = 0; i < N; ++i)
					{
						string elem;
						cin >> elem;
						B.add_el(elem);
					}
					if (A.search_tree(B) == true)
						cout << "YES!" << endl;
					else
						cout << "NO!" << endl;
					B.freetree_el();
					getch();
					goto Repeat3;

				}
				else if (key1 == '5')
				{
					tree<string> B;
					cout << "Enter the element" << endl;
					string elem;
					cin >> elem;
					if (A.search_el(elem) == true)
						cout << "YES!" << endl;
					else
						cout << "NO!" << endl;
					getch();
					goto Repeat3;
				}
				else if (key1 == '6')
				{
					cout << "		Tree" << endl << endl << "       ";
					A.print_el();
					cout << endl << endl;
					getch();
					goto Repeat3;
				}
				else if (key1 == '7')
				{
					A.filing_el();
					getch();
					goto Repeat3;
				}
				else if (key1 == '8')
				{
					A.freetree_el();
					cout << endl;
					goto Back1;
				}
				else if (key1 == '9')
				{
					return false;
				}
				else
				{
					cout << "Try again" << endl;
					goto Repeat3;
				}
			}
			else if (key == '4')
			{
				test_general();
				getch();
				cout << endl;
			}
			else if (key == '5')
			{
				cout << endl << " 			  MAJOR OAK v1.0 " << endl << "The program is a demonstration of a ternary tree" << endl << "About a ternary tree." << endl;
				cout << "In computer science, a ternary tree is a tree data structure in which each node has at most three child nodes, usually distinguished as left, mid and right. ";
				cout << "Nodes with children are parent nodes, and child nodes may contain references to their parents. ";
				cout << "Outside the tree, there is often a reference to the root node (the ancestor of all nodes), if it exists. ";
				cout << "Any node in the data structure can be reached by starting at root node and repeatedly following references to either the left, mid or right child." << endl;
				cout << endl << "								24.05.2018";
				cout << endl << "											Saparbekov Sultan";
				getch();
			}
			else if (key == '6')
			{
				return false;
			}
			else 
			{
				cout << "Try again" << endl;
				goto Back1;
			}
		
	}//*/
	return 0;
}