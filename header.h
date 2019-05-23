#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
	Node<T>* middle;
};

//------------ Класс тернарное дерево------------

template <class T>
class tree
{
private:
	Node<T>* root;

	void add(Node<T>*, T);
	void freetree(Node<T>* temp);
	void print(Node<T>* temp);
	bool search(Node<T>* temp, T elem);
	void map_quad(Node<T>*, tree &);
	void map_str(Node<T>*, tree &);
	void where(Node<T>*, tree&);
	void where_complex(Node<T>*, tree &, T, T);
	/*T int_to_string(T str);
	void where_str(Node<T>*, tree&);*/
	void merger(Node<T>*, tree&);
	void ejection_help(Node<T>*, tree&);
	Node<T>* search_ejection(Node<T>* temp, T elem); 
	void ejection(Node<T>*, tree&, T);
	//bool compare_tree(Node<T>* temp1, Node<T>* temp2);
	bool equal_tree(Node<T>*, Node<T>*);
	void filing(Node<T>*, ofstream &);
public:
	tree()
	{
		root = NULL;
	}
	~tree()
	{
		freetree(root);
	}
	void freetree_el();
	void add_el(T element);
	void print_el();
	void map_quad_el(tree &);
	void map_str_el(tree &); // Error
	void where_el(tree&);
	void where_complex_el(tree &);
	//void where_str_el(tree&);
	void merger_el(tree&);
	void ejection_el(tree&, T);
	bool search_tree(tree &A);
	bool search_el(T elem);
	bool equal_tree_el(tree&);
	void filing_el();
};

//---------- Класс комплексных чисел --------------------

class complex
{
private:
  double re;
  double im;
public:
  complex(){}
  complex(double r) { re = r; im = 0; } 
  complex(double r, double i) 
  { 
    re = r;
    im = i; 
  }
  complex (const complex &c)   // конструктор копирования
    {
      re = c.re;
      im = c.im;
    }
  ~complex(){}
  bool operator == (complex &c);  
  bool operator > (complex &c);
  bool operator < (complex &c);
  complex operator * (complex &c);
  complex operator = (complex &c);
  friend ostream& operator<< (ostream &, const complex &);
  friend istream& operator>> (istream &, complex &);
};

bool test_map();
bool test_where();
bool test_merger();
bool test_ejection_search_tree_and_search_elem();
bool test_map_c();
bool test_where_c();
bool test_merger_c();
bool test_ejection_search_tree_and_search_elem_c();
bool test_map_s();
bool test_merger_s();
bool test_ejection_search_tree_and_search_elem_s();
void test_general();


//*--------- Методы класса tree -------------

template <class T>
void tree<T>::freetree(Node<T>* temp)
{
	if (temp != NULL)
	{
		freetree(temp->left);
		freetree(temp->middle);
		freetree(temp->right);
		delete temp;	
	}
}

template <class T>
void tree<T>::freetree_el()
{
	freetree(root);
}

template <class T>
void tree<T>::add(Node<T>* temp, T elem)
{
	if (elem < temp->data)
  	{
    	if(temp->left != NULL)
     		add(temp->left, elem);
    	else
    	{
     	 	temp->left=new Node<T>;
      		temp->left->data = elem;
      		temp->left->left = NULL;    
      		temp->left->middle = NULL; 
      		temp->left->right = NULL;   
    	}  
  	}
  	else if (elem > temp->data)
  	{
   	 	if(temp->right!=NULL)
      		add(temp->right, elem);
    	else
    	{
      		temp->right=new Node<T>;
     	 	temp->right->data = elem;
      		temp->right->left = NULL;  
      		temp->right->middle = NULL; 
      		temp->right->right = NULL;
   	 	}
 	}
 	else if (elem == temp->data)
  	{
   	 	if(temp->middle != NULL)
      		add(temp->middle, elem);
    	else
    	{
      		temp->middle=new Node<T>;
     	 	temp->middle->data = elem;
      		temp->middle->left = NULL;  
      		temp->middle->middle = NULL; 
      		temp->middle->right = NULL;
    	}
 	}
}

template <class T>
void tree<T>::add_el(T element)
{
	if (root != NULL)
	{
		add(root, element);
	}
	else
	{
		root = new Node<T>;
		root->data = element;
		root->left = NULL;
		root->right = NULL;
		root->middle = NULL;
	}
}

template <class T>
void tree<T>::print(Node<T>* temp)
{
	if (temp != NULL)
	{
		if (temp->left != NULL) cout << " (";
		print(temp->left);
		if (temp->left != NULL) cout << ") ";
		cout << temp->data;
        if (temp->middle != NULL) cout << " [";
		print(temp->middle);
		if (temp->middle != NULL) cout << "] ";
		if (temp->right != NULL) cout << " [";
		print(temp->right);
		if (temp->right != NULL) cout << "} ";
	}	
}

template <class T>
void tree<T>::print_el()
{
	print(root);
}

template <class T>
bool tree<T>::search(Node<T>* temp, T elem) 
{  	while (temp != NULL)
	{
	    if (elem == temp->data)
	        return true;
	   	else
	    {
	        if (elem < temp->data) 
	        	return search(temp->left, elem);
	       	else if (elem > temp->data)
	       		return search(temp->right, elem);
	    }
    }
    return false;
}

template <class T>
bool tree<T>::search_el(T elem) 
{
	if (search(root, elem) == true)
		return true;
	else
		return false;
}

template <class T>
void tree<T>::map_quad(Node<T>* temp, tree &A)
{
	if (temp != NULL)
	{
		A.add_el(temp->data*temp->data);		
		map_quad(temp->left, A);		
		map_quad(temp->right, A);		
		map_quad(temp->middle, A);
	}
}  

template <class T>
void tree<T>::map_quad_el(tree &A)
{
	map_quad(root, A);
}

template <class T>
void tree<T>::map_str(Node<T>* temp, tree &A)
{
	if (temp != NULL)
	{
		A.add_el(temp->data.substr(1, 3));		
		map_str(temp->left, A);		
		map_str(temp->right, A);		
		map_str(temp->middle, A);
	}
}  

template <class T>
void tree<T>::map_str_el(tree &A)
{
	map_str(root, A);
}


template <class T>
void tree<T>::where(Node<T>* temp, tree &A)
{
	if (temp != NULL)
	{	
		if ((temp->data >= 5)&&(temp->data <= 50))
			A.add_el(temp->data);		
		where(temp->left, A);
		where(temp->middle, A);
		where(temp->right, A);
	}
}    

template <class T>
void tree<T>::where_el(tree &A)
{
	where(root, A); 
	if (A.root == NULL)
	{
		cout << "New Tree is absent" << endl;
	}
}

template <class T>
void tree<T>::where_complex(Node<T>* temp, tree &A, T c1, T c2)
{

	if (temp != NULL)
	{	
		if ((temp->data > c1)&&(temp->data < c2))
			A.add_el(temp->data);		
		where_complex(temp->left, A, c1, c2);
		where_complex(temp->right, A, c1, c2);
		where_complex(temp->middle, A, c1, c2);
	}
}   

template <class T>
void tree<T>::where_complex_el(tree &A)
{
	T c1(4, 15);
	T c2(51, 63);
	where_complex(root, A, c1, c2);
	if (A.root == NULL)
	{
		cout << "New Tree is absent" << endl;
	}
}

/*template <class T>
T tree<T>::int_to_string(T str)
{
	int length = str.length();
	ostringstream ss;
	ss << length;
	return ss.str();
}

template <class T>
void tree<T>::where_str(Node<T>* temp, tree &A)
{
	T a = int_to_string(temp->data);
	A.add_el(a);
	where_str(temp->left, A);
	where_str(temp->middle, A);
	where_str(temp->right, A);
}

template <class T>
void tree<T>::where_str_el(tree &A)
{
	where_str(root, A);
}*/


template <class T>
void tree<T>::merger(Node<T>* temp, tree &A)
{
	if (temp != NULL)
	{
		A.add_el(temp->data);
		merger(temp->left, A);
		merger(temp->right, A);
		merger(temp->middle, A);
	}
}

template <class T>
void tree<T>::merger_el(tree &A)
{
	merger(root, A);
	freetree(root);
}

template <class T>
void tree<T>::ejection_help(Node<T>* temp, tree &A)
{
	if (temp != NULL)
	{
		A.add_el(temp->data);
		ejection_help(temp->left, A);
		ejection_help(temp->middle, A);
		ejection_help(temp->right, A);
	}
}

template <class T>
Node<T>* tree<T>::search_ejection(Node<T>* temp, T elem) 
{  	while (temp != NULL)
	{
	    if (elem == temp->data)
	        return temp;
	    else if (elem < temp->data) 
	        return search_ejection(temp->left, elem);
	    else
	       	return search_ejection(temp->right, elem);
    }
    return NULL;
}

template <class T>
void tree<T>::ejection(Node<T>* temp, tree &A, T elem)
{
	if (search_ejection(root, elem) != NULL)
	{	
		temp = search_ejection(root, elem);
		ejection_help(temp, A);
	}
}

template <class T>
void tree<T>::ejection_el(tree &A, T elem)
{
	ejection(root, A, elem);
}

// Поиск на вхождение поддерева
template <class T>
bool tree<T>::search_tree(tree &A)
{
	tree B;
	T elem = A.root->data;
	ejection_el(B, elem);
	if (equal_tree(A.root, B.root) == true)
		return true;
	else
		return false;
}

/*template <class T>
bool tree<T>::compare_tree(Node<T>* temp1, Node<T>* temp2)
{
	if ((temp1 != NULL)&&(temp2 != NULL))
	{
		if (temp1->data == temp2->data)
			return true && compare_tree(temp1->left, temp2->left)&&compare_tree(temp1->middle, temp2->middle)&&compare_tree(temp1->right, temp2->right);
		else return false;
	}
	else
		return false;
}*/

template <class T>
bool tree<T>::equal_tree(Node<T>* temp1, Node<T>* temp2)
{
  if (temp1 == temp2)  return true;
  if ((temp1 == NULL) || (temp2 == NULL)) return false;
  return ((temp1->data == temp2->data) && equal_tree(temp1->left, temp2->left) && equal_tree(temp1->middle, temp2->middle) && equal_tree(temp1->right, temp2->right));
}

template <class T>
bool tree<T>::equal_tree_el(tree &A)
{
	return equal_tree(root, A.root);
}


template <class T>
void tree<T>::filing(Node<T>* temp, ofstream &fout)
{	
	if (temp != NULL)
	{	
		if (temp->left != NULL) fout << " (";
		filing(temp->left, fout);
		if (temp->left != NULL) fout << ") ";
		fout << temp->data;
        if (temp->middle != NULL) fout << " [";
		filing(temp->middle, fout);
		if (temp->middle != NULL) fout << "] ";
		if (temp->right != NULL) fout << " [";
		filing(temp->right, fout);
		if (temp->right != NULL) fout << "} ";
	}
		
}

template <class T>
void tree<T>::filing_el()
{	
	string FILE;
	cout << "Enter Name of the file: ";
	cin >> FILE;
	cout << endl; 
	ofstream fout;
	fout.open(FILE, ofstream::app);
	filing(root, fout);
	fout.close();
}





//*--------- Методы класса complex ----------------------------------------

bool complex::operator == (complex &c)   
{
   if (re == c.re)
   		return true;
   	else
   		return false;
}

bool complex::operator > (complex &c)   
{
	if (re > c.re)
   		return true;
   	else
   		return false;
}

bool complex::operator < (complex &c)   
{
   if (re < c.re)
   		return true;
   	else
   		return false;
}


complex complex::operator * (complex &c)
{
	complex temp;
	temp.re = (re * c.re) - (im * c.im);
	temp.im = (re * c.im) + (im * c.re);
	return temp;
}

complex complex::operator = (complex &c)
{
	re = c.re;
	im = c.im;
	return (*this);
}

ostream& operator<< (ostream &out, const complex &c)
{
  out << "|" << c.re << ", " << c.im << "|";
  return out;
}

istream& operator>> (istream &in, complex &c)
{
  in >> c.re >> c.im;
  return in;
}


//-----------------tests//------------------------------------------------------------------------------------

bool test_map()
{
	tree<double> A;
	tree<double> A1;
	A.add_el(0);
	A.add_el(11);
	A.add_el(1);
	A.add_el(-156);
	A.add_el(2);
	A.map_quad_el(A1);
	tree<double> B;
	B.add_el(0);
	B.add_el(24336);
	B.add_el(121);
	B.add_el(1);
	B.add_el(4);
	return A1.equal_tree_el(B);
}

bool test_where()
{
	tree<double> A;
	tree<double> B;
	A.add_el(0);
	A.add_el(5);
	A.add_el(50);
	A.add_el(25);
	A.add_el(156.53);
	A.add_el(-567.453);
	B.add_el(5);
	B.add_el(50);
	B.add_el(25);
	tree<double> A1;
	A.where_el(A1);
	return A1.equal_tree_el(B);
}	

bool test_merger()
{
	tree<double> A;
	tree<double> B;
	A.add_el(5.54);
	A.add_el(0);
	A.add_el(65535.324);
	A.add_el(-54.5);
	A.add_el(10000);
	B.add_el(2147483647);
	B.add_el(-32768);
	B.add_el(0);
	B.add_el(-423.45);
	B.add_el(2147483647);
	tree<double> C;
	C.add_el(5.54);
	C.add_el(0);
	C.add_el(65535.324);
	C.add_el(-54.5);
	C.add_el(10000);
	C.add_el(2147483647);
	C.add_el(-32768);
	C.add_el(0);
	C.add_el(-423.45);
	C.add_el(2147483647);
	B.merger_el(A);
	return C.equal_tree_el(A);
}

bool test_ejection_search_tree_and_search_elem()
{
	tree<double> A;
	tree<double> A1;
	tree<double> A2;
	tree<double> A3;
		A.add_el(5.5);
		A.add_el(0);
		A.add_el(5.5);
		A.add_el(15.432);
		A.add_el(8);
		A.add_el(154);
		A.add_el(86);
		A.add_el(-23);
		A.add_el(453);
		A.add_el(-12.43);
		A.add_el(-2147483647);
		A.add_el(2147483647);
		A.add_el(10000);
		A.add_el(-128);
		A.add_el(432.432);
	tree<double> B;
		B.add_el(154);
		B.add_el(86);
		B.add_el(453);
		B.add_el(432.432);
		B.add_el(2147483647);
		B.add_el(10000);
	A.ejection_el(A1, 154);
	tree<double> C;
		C.add_el(-128);
	A.ejection_el(A2, -128);
	tree<double> D;
		D.add_el(5.5);
		D.add_el(0);
		D.add_el(5.5);
		D.add_el(15.432);
		D.add_el(8);
		D.add_el(154);
		D.add_el(86);
		D.add_el(-23);
		D.add_el(453);
		D.add_el(-12.43);
		D.add_el(-2147483647);
		D.add_el(2147483647);
		D.add_el(10000);
		D.add_el(-128);
		D.add_el(432.432);
	A.ejection_el(A3, 5.5);
	tree<double> E;
		E.add_el(-23);
		E.add_el(-12.43);
		E.add_el(-2147483647);
		E.add_el(-128);
	return (B.equal_tree_el(A1) && C.equal_tree_el(A2) && D.equal_tree_el(A3) && A.search_tree(E) && A.search_el(2147483647) && A.search_el(0));
}

bool test_map_c()
{
	tree<complex> A;
	tree<complex> A1;
	tree<complex> B;
	complex a0(0, 0);
	complex a1(11, 5);
	complex a2(-14, 4);
	complex a3(50, -42);
	complex b0(0, 0);
	complex b1(180, -112);
	complex b2(96, 110);
	complex b3(736, -4200);
	A.add_el(a0);
	A.add_el(a1);
	A.add_el(a2);
	A.add_el(a3);
	B.add_el(b0);
	B.add_el(b1);
	B.add_el(b2);
	B.add_el(b3);	
	A.map_quad_el(A1);
	return A1.equal_tree_el(B);
}  

bool test_where_c()
{
	tree<complex> A;
	tree<complex> A1;
	tree<complex> B;
	complex a0(0, 0);
	complex a1(11, 5);
	complex a2(50, 4);
	complex a3(5, -4);
	complex b0(11, 5);
	complex b1(50, 4);
	complex b2(5, -4);
	A.add_el(a0);
	A.add_el(a1);
	A.add_el(a2);
	A.add_el(a3);
	B.add_el(b0);
	B.add_el(b1);
	B.add_el(b2);
	A.where_complex_el(A1);
	return A1.equal_tree_el(B);
}	


bool test_merger_c()
{
	tree<complex> A;
	tree<complex> B;
	complex a0(50, 4);
	complex a1(0, 0);
	complex a2(2147483647, 2147483647);
	complex a3(-2147483647, 2147483647);
	complex b0(50, 4);
	complex b1(4, 50);
	complex b2(-50, -4);
	A.add_el(a0);
	A.add_el(a1);
	A.add_el(a2);
	A.add_el(a3);
	B.add_el(b0);
	B.add_el(b1);
	B.add_el(b2);
	complex c0(50, 4);
	complex c1(0, 0);
	complex c2(2147483647, 2147483647);
	complex c3(-2147483647, 2147483647);
	complex c4(50, 4);
	complex c5(4, 50);
	complex c6(-50, -4);
	tree<complex> C;
	C.add_el(c0);
	C.add_el(c1);
	C.add_el(c2);
	C.add_el(c3);
	C.add_el(c4);
	C.add_el(c5);
	C.add_el(c6);
	B.merger_el(A);
	return C.equal_tree_el(A);
}

bool test_ejection_search_tree_and_search_elem_c()
{
	tree<complex> A1;
	tree<complex> A2;
	tree<complex> A;
	complex a0(50, 4); A.add_el(a0);
	complex a1(0, 0); A.add_el(a1);
	complex a2(2147483647, 2147483647); A.add_el(a2); 
	complex a3(-2147483647, 2147483647); A.add_el(a3);
	complex a4(50, 4); A.add_el(a4);
	complex a5(15, 132); A.add_el(a5);
	complex a6(156, 2); A.add_el(a6);
	complex a7(-21, 7); A.add_el(a7);
	complex a8(51, 5); A.add_el(a8);
	complex a9(-51, 3); A.add_el(a9);
	complex a10(23, 76); A.add_el(a10);
	complex a11(86, 27); A.add_el(a11);
	tree<complex> B;
	complex b0(156, 2); B.add_el(b0);
	complex b1(51, 5); B.add_el(b1);
	complex b2(86, 27); B.add_el(b2);
		A.ejection_el(A1, b0);
	tree<complex> C;
	complex c(-51, 3); C.add_el(c);
		A.ejection_el(A2, c);
	tree<complex> D;
	complex d0(-2147483647, 2147483647); D.add_el(d0);
	complex d1(-21, 7); D.add_el(d1);
	complex d2(-51, 3); D.add_el(d2);
	complex s1(2147483647, 2147483647);
	complex s2(51, 5);
	return (B.equal_tree_el(A1) && C.equal_tree_el(A2) && A.search_tree(D) && A.search_el(s1) && A.search_el(s2));
}

bool test_map_s()
{
	tree<string> A;
	tree<string> A1;
	A.add_el("Audi");
	A.add_el("Buick");
	A.add_el("BMW");
	A.add_el("Citroen");
	A.add_el("Ferrari");
	A.add_el("Mercedes");
	tree<string> B;
	B.add_el("udi");
	B.add_el("uic");
	B.add_el("MW");
	B.add_el("itr");
	B.add_el("err");
	B.add_el("erc");
	A.map_str_el(A1);
	return A1.equal_tree_el(B);
}

bool test_merger_s()
{
	tree<string> A;
	tree<string> B;
	A.add_el("Citroen");
	A.add_el("Ferrari");
	A.add_el("Audi");
	A.add_el("Buick");
	B.add_el("Volkswagen");
	B.add_el("Infinity");
	B.add_el("Lexus");
	B.add_el("Mazda");
	B.merger_el(A);
	tree<string> C;
	C.add_el("Citroen");
	C.add_el("Ferrari");
	C.add_el("Audi");
	C.add_el("Buick");
	C.add_el("Volkswagen");
	C.add_el("Infinity");
	C.add_el("Lexus");
	C.add_el("Mazda");
	return C.equal_tree_el(A);
}

bool test_ejection_search_tree_and_search_elem_s()
{
	tree<string> A;
	tree<string> A1;
	tree<string> A2;
	tree<string> A3;
	A.add_el("Mercedes");
	A.add_el("Citroen");
	A.add_el("Ferrari");
	A.add_el("Audi");
	A.add_el("Buick");
	A.add_el("BMW");
	A.add_el("Volkswagen");
	A.add_el("Infinity");
	A.add_el("Lexus");
	A.add_el("Mazda");
	A.add_el("Mitsubishi");
	A.add_el("Toyota");
	A.add_el("Nissan");
	A.add_el("Honda");
	A.add_el("Lada");
	A.add_el("ZAZ");
	tree<string> B;
	B.add_el("Lexus");
	B.add_el("Lada");
	B.add_el("Mazda");
	A.ejection_el(A1, "Lexus");
	tree<string> C;
	C.add_el("Audi");
	C.add_el("Buick");
	C.add_el("BMW");
	return (B.equal_tree_el(A1) && A.search_tree(C) && A.search_el("Infinity") && A.search_el("ZAZ"));
}

void test_general()
{
	if (test_map() && test_where() && test_merger() && test_ejection_search_tree_and_search_elem() && test_map_c() && test_where_c() && test_merger_c() && test_ejection_search_tree_and_search_elem_c() && test_map_s() && test_merger_s() && test_ejection_search_tree_and_search_elem_s())
		cout << "Test is completed successfully" << endl;
	else
		cout << "Fail" << endl;
}
//-----------------------------------------------------------------//-----------------------------------------------------------------
