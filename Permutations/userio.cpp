#include "prm.h"
#include "userio.h"

int launch(){
	cout << "PERMUTATIONS" << endl << "Created by Adriana Raykova" << endl;
	menu();
	cout << "Goodbye." << endl;
	return 0;
}

int menu(){
	int n;
	int**p = new int*[2];

	int k;
	bool flag = true;
	cout << endl << "Please enter number of preferred option:" << endl;
	cout << "1 -> Create function" << endl << "2 -> Exit" << endl;
	cin >> k;
	if (k == 2)return 0;

	cout << "Please insert number of elements in function:" << endl;
	cin >> n;
	task1(p, n);
	task2(p, n);
	
	cout << endl;

	while (flag){
		k = mainMenu();
		switch (k)
		{
		case 1:
			permutationsMenu(p, n);
			break;
		case 2:
			fPnMenu(p, n);
			break;
		case 3:
			inCyclesMenu(p, n);
			break;
		case 4:
			compositionMenu(p, n);
			break;
		case 5:
			reversePmtMenu(p, n);
			break;
		case 6:
			iterationMenu(p, n);
			break;
		default:
			flag = false;
			break;
		}
		
	}
	clean(p);
	return 0;
}



int mainMenu(){
	int t;

	cout << "***MAIN MENU***" << endl;
	cout << endl << "Please enter number of preferred option:" << endl;
	cout << "1 -> Part ONE -> Permutations" << endl;
	cout << "2 -> Part TWO -> Fixed points" << endl;
	cout << "3 -> Part THREE -> Independent cycles"<< endl;
	cout << "4 -> Part FOUR -> Composition" << endl;
	cout << "5 -> Part FIVE -> Reverse permutation" << endl;
	cout << "6 -> Part SIX -> Iteration" << endl;
	cout << "Enter any other NUMBER to EXIT" << endl;

	cin >> t;
	return t;
}

int permutationsMenu(int **p, int n){
	int t;
	
	cout << endl << "***PART ONE: PERMUTATIONS***" << endl;
	cout << "1 -> Check if injective fuction" << endl;
	cout << "2 -> Check if surjective function" << endl;
	cout << "3 -> Check if permutation" << endl;
	cout << "4 -> Calculate number of possible permutations " << endl;
	cout << "Enter any other NUMBER to go back to Main Menu" << endl;
	bool flag = true;
	bool a;
	while (flag){
		cout << endl << "Please enter number of preferred option:" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			a = task3(p, n);
			cout << "The entered function is ";
			if (!a)cout << "not ";
			cout << "an injective function." << endl;
			break;
		case 2:
			a = task4(p, n);
			cout << "The entered function is ";
			if (!a)cout << "not ";
			cout << "a surjective function." << endl;
			break;
		case 3:
			a = task5(p, n);
			cout << "The entered function is ";
			if (!a)cout << "not ";
			cout << "a permutation." << endl;
			break;
		case 4:
			cout << "The number of possible permutaitons is: ";
			cout << task6(p, n) << endl;
			break;
		default:
			flag = false;
			break;
		}
	}
	return 0;
}

int fPnMenu(int **p, int n){

	cout << endl << "***PART TWO: FIXED POINTS***" << endl;
	int t;
	cout << "1 -> Check if there are any fixed points in function" << endl;
	cout << "2 -> Count number of fixed points" << endl;
	cout << "3 -> Check if entered function is ID" << endl;
	cout << "Enter any other NUMBER to go back to Main Menu" << endl;
	int number;
	bool flag = true;
	bool a;
	while (flag){
		cout << endl << "Please enter number of preferred option:" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			a = task7(p, n);
			
			if (a)cout << "There is at least one fixed point in the entered function." << endl;
			else cout << "There are no fixed points in the entered function." << endl;

			break;
		case 2:
			number = task8(p, n);
			if (number == 1)cout << "There is ";
			else cout << "There are ";
				
				cout << number << " fixed points in the entered function " << endl;
			break;
		case 3:
			a = task9(p, n);
			cout << "The entered function is ";
			if (!a)cout << "not ";
			cout << "an ID." << endl;
			break;
		default:
			flag = false;
			break;
		}
	}
	return 0;
}

int inCyclesMenu(int **p, int n){
	int t;
	cout << endl << "***PART THREE: INDEPENDET CYCLES***" << endl;
	cout << "1 -> Show permutation in cycle notation" << endl;
	cout << "2 -> Show cycle lengths" << endl;
	cout << "3 -> Enter cycle notation to be shown as function" << endl;
	cout << "Enter any other NUMBER to go back to Main Menu" << endl;
	bool flag = true;
	char *newp = new char[100];

	int *a = new int[n];
	while (flag){
		cout << endl << "Please enter number of preferred option:" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			task10(p, n);
			break;
		case 2:
			cout << "Cycle lengths in order are:" << endl;
			task11(p, a, n);
			cout << endl;
			break;
		case 3:
			cout << "Please insert permutation in cycle notation:" << endl;
			cout << "Cycle notation example: (1 2 3)(4 5)" << endl;

			cin.ignore();
			cin.getline(newp, 99);

			entrySecure(newp, p[0], n);
			
			task12(newp,p,n);
			break;
		default:
			flag = false;
			break;
		}
	}

	if (a != nullptr){
		delete[]a;
		a = nullptr;
	}
	return 0;
}

int compositionMenu(int **p, int n){
	int t;
	cout << endl << "***PART THREE: COMPOSITION***" << endl;
	cout << endl << "1 -> Find composition of two permutations entered in cycle notation" << endl;
	cout << "Enter any other NUMBER to go back to Main Menu" << endl;

	bool flag = true;
	while (flag){
		cout << endl << "Please enter number of preferred option:" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			task13(p, n);
			break;
		default:
			flag = false;
			break;
		}
	}
	return t;
}

int reversePmtMenu(int **p, int n){
	int t;
	cout << endl << "***PART FIVE: REVERSE PERMUTATIONS***" << endl;
	cout << "1 -> Find reverse permutation" << endl;
	cout << "2 -> Find composition of a permutation entered in cycle notation and its reverse. Check if result is ID" << endl;
	cout << "3 -> Proof that if two permutations are both not ID, then composition is not a commutative operation" << endl;
	cout << "Enter any other NUMBER to go back to Main Menu" << endl;
	bool flag = true;
	bool a;
	char *newp = new char[100];
	while (flag){
		cout << endl << "Please enter number of preferred option:" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			cout << "Please insert permutation in cycle notation:" << endl;
			cout << "Cycle notation example: (1 2 3)(4 5)" << endl;

			cin.ignore();
			cin.getline(newp, 99);

			entrySecure(newp, p[0], n);
			task14(newp, p, n);
			break;
		case 2:
			cout << "Please insert permutation in cycle notation:" << endl;
			cout << "Cycle notation example: (1 2 3)(4 5)" << endl;

			cin.ignore();
			cin.getline(newp, 99);

			entrySecure(newp, p[0], n);

			a = task15(newp, p, n);
			cout << "The composition is ";
		
			if (!a)cout << "not ";
			cout << "an ID." << endl;
			break;
		case 3:
			task16(p, n);
			cout << "Therefore if two functions are not IDs, composition is not a commutative operation." << endl;
			break;
		default:
			flag = false;
			break;
		}
	}
	return 0;
}

int iterationMenu(int **p,int n){
	int t;

	char *newp = new char[100];


	cout << endl << "1 -> Find number of iterations needed to result in ID of function" << endl;
	cout << "Enter any other NUMBER to go back to Main Menu" << endl;
	bool flag = true;
	int **perm = new int*[2];
	while (flag){
		cout << endl << "Please enter number of preferred option:" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
		
			task1(perm, n);

			toIntArray(perm, p, n);

			cout << "Needed iterrations to result in ID function:" << endl;
			cout<<"Result A -> Creating next iterration until result is ID function: "<<task17_1(perm, n)<<endl;
			cout << "Result B - > Calculating needed iterrations using cycle lengths: " << task17_2(perm, n) << endl;
			break;
		default:
			flag = false;
			break;
		}
	}
	clean(perm);
	return t;
}

