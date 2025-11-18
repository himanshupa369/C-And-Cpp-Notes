In C++, an **array function parameter** means **passing an array to a function**.
But an important point:

### 👉 In C++, **arrays cannot be passed by value**.

When you pass an array to a function, it **decays into a pointer to its first element**.

So an “array parameter” is really a **pointer parameter**.

---

# ✅ How Arrays Work as Function Parameters

### When you write:

```cpp
void func(int arr[]);
```

It is **exactly the same as**:

```cpp
void func(int* arr);
```

Both mean:

* `arr` is a pointer to the first element of the array
* The size information is **lost**
* You can modify the actual array elements from inside the function

---

# 📌 Example 1: Array as a Function Parameter

```cpp
#include <iostream>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int nums[5] = {1, 2, 3, 4, 5};
    printArray(nums, 5);   // array decays to pointer
}
```

---

# 📌 Example 2: Modifying the Array Inside the Function

```cpp
void update(int arr[], int size) {
    arr[0] = 100;   // modifies the original array
}

int main() {
    int a[3] = {1, 2, 3};
    update(a, 3);
    // a[0] is now 100
}
```

Since the array decays into a pointer, modification reflects on the original array.

---

# 🔍 Key Concepts

### 1️⃣ Arrays *decay* to pointers

So writing any of these is the same:

```cpp
void fun(int arr[]);
void fun(int arr[10]);  // still pointer
void fun(int* arr);
```

All mean “`arr` is a pointer to int”.

---

### 2️⃣ Size is not automatically passed

You must pass the **size separately**:

```cpp
void fun(int arr[], int size);
```

---

### 3️⃣ Arrays cannot be passed by value

Because copying arrays is expensive and not built into the language.

If you want pass-by-value behavior for arrays, use:

* `std::array`
* `std::vector`

---

### 4️⃣ You can also pass multi-dimensional arrays

But the inner dimension must be known:

```cpp
void matrixPrint(int arr[][3], int rows);
```

---

# 🧠 Simple Definition (Easy to Remember)

> **An array function parameter is really a pointer parameter.
> The array decays to a pointer when passed to a function.**

---

```cpp

//example:-
#include <iostream>
#include <array>


//double sum( double scores[], size_t count){
double sum (double* scores , size_t count){

    double score_sum{};

   // std::cout << "sizeof(scores)  : " << sizeof(scores) << std::endl;
   // std::cout << "sizeof(int*) : " << sizeof (int *) << std::endl;
   //size_t arr_size = std::size(scores);

   for(size_t i{0} ; i < count ; ++i){
       score_sum += scores[i];
   }
    return score_sum;
}



int main(){
    double my_scores[]{10.5,34.3,4.8,6.5};
    //std::cout << "sizeof(my_scores) : " << sizeof(my_scores) << std::endl;
   

   double result = sum(my_scores,std::size(my_scores));
   std::cout << "result : " << result << std::endl;
 
    return 0;
}
```
