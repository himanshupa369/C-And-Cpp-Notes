
```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	auto calcLam = [](int choice) ->  int(*)  (int,int )
	{
		switch (choice)
		{
		case 1:
			return [] (int a, int b) { return a + b; };
			break;
		case 2:
			return [](int a, int b) { return a - b; };
			break;
		case 3:
			return [](int a, int b) { return a * b; };
			break;
		}
		return [](int , int ) { return 0; };
	};

 
	auto operation = calcLam(2); // Get the operation lambda (function pointer)
	int result = operation(10, 20); // Use it
	cout<<result;
	return 0;
}
```
