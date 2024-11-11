//DAA_1 
////Iterative and Non - recursive  implementation of Fibonacci numbers.

#include <iostream>
using namespace std;

int fibo_iterative(int n) {
	// Time Complexity: O(n)
	// Space Complexity: O(1)
	int a = 0, b = 1, c;
	for (int i = 1; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return a;
}

int fibo_recursive(int n) {
	// Time Complexity: O(2^n)
	// Space Complexity: O(n) (for recursion stack)
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	int x = fibo_recursive(n-1);
	return x + fibo_recursive(n-2);
}

int main() {
	int ch, method;
	while (true) {
		cout << "Enter n to find the Fibonacci number (-1 for exit): ";
		cin >> ch;
		if (ch == -1)
			break;
		
		cout << "Choose method: 1 for Iterative, 2 for Recursive: ";
		cin >> method;

		string suffixes[] = {"", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"};
		int result;
		if (method == 1)
			result = fibo_iterative(ch);
		else if (method == 2)
			result = fibo_recursive(ch);
		else {
			cout << "Invalid method choice. Try again." << endl;
			continue;
		}

		cout << "The " << ch << suffixes[ch % 10] << " Fibonacci number is: " << result << endl;
	}
	return 0;
}
