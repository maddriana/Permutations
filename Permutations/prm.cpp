#include "prm.h"

//PERMUTATIONS

int task1(int **p, unsigned n){
	//Create Table
	p[0] = new int[n];
	p[1] = new int[n];
	return 0;
}

int task2(int **p, unsigned n){
	//Fill Function Table
	cout << "Please insert " << n << " values for x:" << endl;
	for (unsigned i = 0; i < n; i++)cin >> p[0][i];

	bool a = ifMultitude(p[0], n);

	while (!a){
		cout << "The entered values do not represent a multitude. Please do not enter repetitive values." << endl;
		for (unsigned i = 0; i < n; i++)cin >> p[0][i];
		a = ifMultitude(p[0], n);
	}

	cout << "Please insert " << n << " values for f(x):" << endl;
	for (unsigned i = 0; i < n; i++)cin >> p[1][i];
	return 0;

}

bool task3(int **p, unsigned n){
	//Check if injective function
	for (unsigned i = 0; i < n; i++){
		for (unsigned j = i + 1; j < n; j++){
			if (p[0][i] != p[0][j] && p[1][i] != p[1][j])continue;
			if (p[0][i] == p[0][j] && p[1][i] == p[1][j])continue;
			return false;
		}
	}
	return true;
}

bool task4(int **p, unsigned n){
	return ifFunction(p, n);
}

bool task5(int **p, unsigned n){
	//Check if permutation
	for (unsigned i = 0; i < n; i++){
		bool flag = false;
		for (unsigned j = 0; j < n; j++){
			if (p[0][i] == p[1][j]){
				flag = true;
				break;
			}
		}
		if (!flag)return false;
	}
	return true;
}

long long task6(int **p, unsigned n){
	//Find number of possible permutations
	long long k = 1;
	for (unsigned i = 2; i <= n; i++){
		k *= i;
	}
	return k;
}


//CONSTANT POINTS

bool task7(int **p, unsigned n){
	//Find constant point
	for (unsigned i = 0; i < n; i++){
		if (p[0][i] == p[1][i])return true;
	}
	return false;
}

int task8(int **p, unsigned n){
	//Find number of constant points
	int count = 0;
	for (unsigned i = 0; i < n; i++){
		if (p[0][i] == p[1][i])count++;
	}
	return count;
}

bool task9(int **p, unsigned n){
	//If id
	if (task8(p, n) == n)return true;
	return false;
}

//INDEPENDENT CYCLES
int task10(int **p, unsigned n){
	//Cycles
	bool flag = false;

	bool *check = new bool[n];  //Array to mark status of an element

	for (unsigned i = 0; i < n; i++){
		check[i] = false;
	}

	for (unsigned i = 0; i < n; i++){
		if (check[i])continue;
		unsigned current = i;
		bool cflag = false;
		unsigned c = 0;
		int *curr = new int[n];
		while (c <= n){ //If there are no cycles in the function, the while cycle won't continue searching//
			curr[c] = p[0][current];
			check[current] = true;
			c++;
			int next = findnext(p, n, current);
			current = next;
			if (next == -1){
				break;
			}
			if (next == i){ 
				flag = true;//Marks if any cycle was detected overall
				cflag = true;//Marks if this in the current while has found a new cycle
				break; 
			}
		}
		if (cflag){ //Prints new cycle if found
			cout << "(";
			for (unsigned j = 0; j < c-1; j++)cout << curr[j] << " ";
			cout << curr[c-1]<<")";
		}
		if (curr != nullptr){
			delete[]curr;
			curr = nullptr;
		}
	}
	if (!flag)cout << "No independent cycles in function.";
	cout << endl;
	delete[]check;
	check = nullptr;

	return 0;

}



int task11(int **p, int *curr, unsigned n){
	//Save cycle lenghts in a dynamic array
	bool flag = false; 

	bool *check = new bool[n]; //Array to mark status of an element 

	for (unsigned i = 0; i < n; i++){
		check[i] = false;
		curr[i] = 0;
	}

	unsigned t = 0;
	for (unsigned i = 0; i < n; i++){

		if (check[i])continue; //Checked cycle
		unsigned current = i;
		bool cflag = false;
		unsigned c = 0;
		
		while (c <= n){ //If there are no cycles in the function, the while cycle won't continue searching//

			check[current] = true; 
			curr[t]++;
			c++;
			int next = findnext(p, n, current);
			current = next;

			if (next == -1){
				break;
			}

			if (next == i){
				flag = true; //Marks if any cycle was detected overall
				cflag = true;//Marks if this in the current while has found a new cycle
				break;
			}
		}
		if (cflag){  //Prints length if new cycle is found
			cout << curr[t] << " ";
			t++; 
		}
		else curr[t] = 0;
	}
	
	if(!flag)cout << "No independent cycles in function.";
	cout << endl;

	

	delete[]check;
	check = nullptr;

	return 0;

}


int task12(char *in, int **arr, unsigned n){
   //Prints permutation created from independent cycle notation//
	int **p = new int*[2];
	turner(in, arr, p, n);
	show(p, n);
	return 0;
}


int task13(int **arr, int n){

	//Prints composition
   
	int **t1 = new int*[2];
	int **t2 = new int*[2];
	int **newt = new int*[2];

	task1(newt, n);
	toIntArray(t1, arr, n);
	toIntArray(t2, arr, n);

	composition(newt, t1, t2, arr, n);
	cout << endl << "Result is:" << endl;
	show(newt, n);

	clean(t1);
	clean(t2);

	return 0;
}


int task14(char *p, int **arr, unsigned n){

	//Prints ^-1 permutation
	int **t = new int*[2];
	turner(p, arr, t, n, true);
	task10(t, n);
	show(t, n);
	return 0;
}

bool task15(char *p, int **arr, unsigned n){
	//Checks if composition with ^-1 composition is id

	int **t = new int*[2];
	int **newp = new int*[2];
	turner(p, arr, t, n, true);
	turner(p, arr, newp, n);

	int **toCheck = new int *[2];
	task1(toCheck, n);

	composition(toCheck, newp, t, arr, n);

	cout << "The composition of the entered permutation whit its reverse is:" << endl;
	show(toCheck,n);
	bool a= task9(toCheck, n);

	clean(t);
	clean(newp);
	clean(toCheck);
	return a;
}

bool task16(int **arr, unsigned n){
	
	int **t1 = new int*[2];
	int **t2 = new int*[2];
	int **composition_t1 = new int*[2];
	int **composition_t2 = new int*[2];

	task1(composition_t1, n);
	task1(composition_t2, n);

	toIntArray(t1, arr, n);
	toIntArray(t2, arr, n);

	bool a = task9(t1, n);
	cout << endl<< "The function f is ";
	if (!a)cout << "not ";
	cout << "an ID." << endl;

	a = task9(t2, n);
	cout << endl << "The function g is ";
	if (!a)cout << "not ";
	cout << "an ID." << endl<<endl;


	composition(composition_t1, t1, t2, arr, n);
	composition(composition_t2, t2, t1, arr, n);

	cout << "Composition f o g:" << endl;
	show(composition_t1, n);

	cout << endl<< "Composition g o f:" << endl;
	show(composition_t2, n);

	cout << endl;
	return comparisson(composition_t1, composition_t2, n);

}


unsigned task17_1(int**arr, unsigned n){

	int **f = new int*[2];
	int **newf = new int*[2];
	task1(newf, n);
	task1(f, n);
	copy(newf, arr, n);
	copy(f, newf, n);
	unsigned i = 1;
	while (!task9(f, n)){
		int **curr= new int*[2];
		task1(curr, n);
		composition(curr,f, newf, arr, n);
		copy(f, curr, n);
		clean(curr);
		i++;
	}

	clean(f);
	clean(newf);

	return i;
}

int task17_2(int **arr, unsigned n){

	int *cycles = new int[n];
	cout << "Cycle lengths: ";
    task11(arr, cycles, n);
	if (cycles[0] == 0)return 1;
	int answer=cycles[0];
	int i = 1;
	while (cycles[i] != 0){
		answer = (answer*cycles[i])/evkAlg(answer, cycles[i]);
		i++;
	}

	if (cycles != nullptr){
		delete[]cycles;
		cycles = nullptr;
	}
	return answer;
}

//Helping functions

int clean(int **p){
	//Cleans Heap
	if (p != nullptr){
		delete[]p[0];
		delete[]p[1];
		delete[]p;
		p = nullptr;
	}

	return 0;
}

int findnext(int **p, unsigned n, int k){
	for (unsigned i = 0; i < n; i++){
		if (i == k)continue;
		if (p[0][i] == p[1][k])return i;
	}
	return -1;
}

int findDigit(char a){

	 //returns Digit from char;

	if (a>'9' || a < '0')return -1; //checks if Digit
	return int(a - '0'); 
}


int creator(int *p1, int *p2, int anf, int end){

	//Creates permutation elements from one cycle

	for (int i = anf; i < end; i++){

		p2[i] = p1[i+1];
	}
	p2[end] = p1[anf];  

	return 0;
}



int finder(int *p, int a, unsigned n){
	//Searches for element in a permutation and returns position

	for (unsigned i = 0; i < n; i++){
		if (p[i] == a)return i;
	}
	return -1;
}

int show(int **p, unsigned n){
	//Shows permutation
	for (unsigned j = 0; j < n; j++)cout << p[0][j] << "\t";
	cout << endl;
	for (unsigned j = 0; j <n; j++)cout << p[1][j] << "\t";
	cout << endl;
	return 0;
}


int turner(char *in, int**arr, int**p, unsigned n, bool a){ 
	//Turns char cycle description into int array permutation
	p[0] = new int[n];
	p[1] = new int[n];

	for (unsigned i = 0; i < n; i++){
		p[0][i] = 0;
	}

	int i = 0;
	int beg = 0;
	bool inNumber = false;
	bool negative = false;
	char *t = in;

	while (*t != '\0'){

		while (*t != ')' && *t != '\0'){

			if (*t == '-')negative = true;
			int digit = findDigit(*t);
			if (digit != -1){
				p[0][i] = p[0][i] * 10 + digit;
				t++;
				inNumber = true;
				continue;
			}
			
			if (inNumber == true){ 
				if (p[0][i]>0)if (negative)p[0][i] = 0 - p[0][i];
				negative = false;
				i++; 
			}
			if (*t == '-')negative = true;
			inNumber = false;
			t++;
		}
		t++;
		if (inNumber == true){ 
				if(p[0][i]>0)if (negative)p[0][i] = 0 - p[0][i];
		}
		if (a)reverse(p[0], beg, i);
		creator(p[0], p[1], beg, i);
		beg = i + 1;
	}

	unsigned newi = i;

	if (newi != n - 1){    //If not all elements were part of described independent cycle//
		for (unsigned j = 0; j < n; j++){
			if (finder(p[0], arr[0][j], n) == -1){
				newi++;
				p[0][newi] = arr[0][j];
				p[1][newi] = arr[0][j];
			}
		}
	}
	return 0;
}

int reverse(int *p, int anf, int end){

	//Reverse cycle in int array
	int len = end - anf+1;
	len /= 2;
	for (int i = 0; i < len; i++){
		int buf = p[anf+i];
		p[anf+i] = p[end - i];
		p[end - i] = buf;
	}
	return 0;
}

int toIntArray(int **t, int **arr, unsigned n){
	char *p = new char[1000];  

	cout << "Please insert permutation in cycle notation:" << endl;
	cout << "Cycle notation example: (1 2 3)(4 5)" << endl;
	cin.ignore();
	cin.getline(p, 999);
	entrySecure(p, arr[0], n);
	int*a = new int[n];
	int len = cycleNumbers(p, a, n);
	if (ifPrm(arr[0], a, len, n))turner(p, arr, t, n);
	delete[]a;
	a = nullptr;
	return 0;
}

int composition(int **newt, int**t1, int **t2, int**arr, unsigned n){

	//finds composition of two permutations//

	for (unsigned i = 0; i < n; i++){
		newt[0][i] = arr[0][i];
	}
	for (unsigned i = 0; i < n; i++){
		int a;
		a = finder(t2[0], arr[0][i], n);
		a = t2[1][a];
		a = finder(t1[0], a, n);
		newt[1][i] = t1[1][a];
	}

	return 0;
}

bool comparisson(int **c1, int**c2, unsigned n){
	for (unsigned i = 0; i < n; i++){
		int k = finder(c2[0], c1[0][i], n);
		if (c2[1][k] != c1[1][i])return false;
	}
	return true;
}

int copy(int **a, int **b, unsigned n){
	for (unsigned i = 0; i < n; i++){
		a[0][i] = b[0][i];
		a[1][i] = b[1][i];
	}
	return 0;
}

int evkAlg(int a, int b){
	if (b == 0)return a;
	return evkAlg(b, a%b);
}

int cycleNumbers(char*p, int *a, unsigned n){
	char *t = p;
	int r;
	bool inNumber = false;
    bool negative = false;
	unsigned i = 0;
	while (*t != '\0'){
		a[i] = 0;
		if (*t == '-')negative = true;
		while (findDigit(*t) != -1){
			a[i] = a[i] * 10 + findDigit(*t);
			inNumber = true;
			t++;
		}
		if (inNumber){
			if (negative)a[i] = 0 - a[i];
			inNumber = false;
			i++;
		    negative = false;
		}
		t++;
		if (i > n){ cout << "Too many numbers entered" << endl; 
		return 0;
		}
	}
	return i;
}

int  ifFunction(int **arr, unsigned n){
	for (unsigned i = 0; i < n-1; i++){
		for (unsigned j = i + 1; j < n; j++){
			if (arr[0][i] == arr[0][j]){
				if (arr[1][i] != arr[1][j])return 0;
			}
		}
	}
	return n;
}

bool  ifMultitude(int *p, unsigned n){
	for (unsigned i = 0; i < n - 1; i++){
		for (unsigned j = i + 1; j < n; j++){
		    if (p[i] == p[j])return false;
		}
	}
	return true;
}

bool ifPrm(int *p, int*newp, unsigned len, unsigned n){
	for (unsigned i = 0; i < len; i++){
		if (finder(p, newp[i], n) == -1)return false;
	}
	return true;
}

int entrySecure(char* newp, int *p, unsigned n){
	int *a = new int[n];
	int len;
	bool c=false;
	len = cycleNumbers(newp, a,n);
	if (len != 0){
		c = ifPrm(p, a, len, n);
	}
	while (!c){
		
		cout << "The entered notation is incorrect. Please enter ONLY numbers contained in function." << endl;
		cin.getline(newp, 99);
		len = cycleNumbers(newp, a,n);
		if (len != 0){
			c = ifPrm(p, a, len, n);
		}
	}

	if (a != nullptr){
		delete[]a;
		a = nullptr;
	}

	return 0;
}