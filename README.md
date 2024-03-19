# C++ Matrix Library:
### Comprehensive C++ header for matrix calculations. This header provides a robust set of tools for matrix manipulation and analysis, making it a valuable resource for C++ programmers working with matrices.

## Features:
#### System of Equations: Calculate the solution of a system of equations using the matrix inversion method.  
#### Matrix Inversion: Compute the inverse of a square matrix of order n-by-n.  
#### Determinant Calculation: Determine the determinant of a square matrix of order n-by-n.  
#### Scalar Multiplication: Perform element wise multiplication with a non-zero scalar using the '*' and '*=' operators.  
#### Scalar Division: Perform element wise division with a non-zero scalar using the '/' and '/=' operators.  
#### Print Matrices: Print non-empty matrices.
#### Print Order: Print Order Of Any Matrix. 
#### Get Order: Get Order Of Matrix In Pair.
#### Element Replacement: Replace elements using row and column positions of the existing element you want to replace.  
#### Transpose Calculation: Compute the transpose of a matrix.  
#### Validation: Check if a matrix is valid.  
#### Comparison: Perform element-by-element comparison using the == operator.  
#### Matrix Addition and Subtraction: Perform addition and subtraction of matrices using the '+' , '+=' , '-' , '-=' operators.  
#### Matrix Multiplication: Perform matrix multiplication by using the '*' and '*=' operators.  
#### Augmentation: Augment matrices with others of the same rows.  
#### User Input: Fill matrices with user input.  
#### Null Matrix Check: Determine if a matrix is null.  
#### Dimension Check: Check if a matrix is dimensionless (empty).  
#### Identity Matrix Check: Determine if a matrix is an identity matrix.  
#### Square Matrix Check: Determine if a matrix is square.  
#### Symmetry Check: Determine if a matrix is symmetric.  
#### Skew-Symmetry Check: Determine if a matrix is skew-symmetric.  

## Note: 
#### 1) The '==' Operator Is Overloaded For Element-Wise Comparison Of Two Matrices.
#### 2) The '+' and  '+=' Operators Are Overloaded For Addition Of Two Matrices Of Same Order.
#### 3) The '-' and '-=' Operators Are Overloaded For Subtraction Of Two Matrices Of Same Order.
#### 4) The '*' and '*=' Operators Are Overload For Multiplication Of Two Matrices Of Any Order If Confirmable.
#### 5) The '*' and '*=' Operators Are Overloaded For Element-Wise Multiplication With A Non-Zero Scalar.
#### 6) The '/' and '/=' Is Overloaded For Element Wise Division By A Non-Zero Scalar.
#### 7) The '<<' and '>>' Operators Are Overloaded For Direct I/O On Matrices.

## Usage

#### Include the matrix.h header in your C++ program.
#### Utilize the provided functions and overloaded operators for various matrix operations.

# Example Snippets:

## 1) Main Usage Example.
```cpp
#include <iostream>
#include "matrix.h"

// using namespace linear_algebra;

int main() {
    
    linear_algebra::matrix matrix1(3, 3); // Create a 3x3 double matrix
    cin >> matrix1; // fill each place of element by user
    cout << matrix1; // print matrix
    // Perform other operations as needed
    return 0;
}
```

## 2) Get Order Example.
```cpp
#include <iostream>
#include "matrix.h"    

// using namespace linear_algebra;

int main() {
    
    linear_algebra::matrix matrix1(3, 3); // Create a 3x3 double matrix
    std::pair<int , int> order = matrix1.get_order(); // Return Order Of The Matrix.
    // Do Whatever You Want With Matrix.
    return 0;
}
```
## 3) Usage Of Overloaded Operators.
```cpp
#include <iostream>
#include "matrix.h"    

// using namespace linear_algebra;

int main() {
    
    linear_algebra::matrix matrix1 = {{1,2,3},{4,5,6},{7,8,9}};    // list initialization of matrix1
    linear_algebra::matrix matrix2 = {{5,1,2},{9,0,-5},{-1,0,0}};  // list initialization of matrix2
    matrix1 *= matrix2; // multiply matrix1 and matrix2.
    matrix1 *= -2 // multiply each element of matrix1 with -2.
    matrix1 += matrix2 // addition of matrix1 and matrix2.
    matrix1 /= 3 // divide each element of matrix1 with 3.
    // also this one
    if(matrix1 == matrix2)   // Element Wise Comparison Of matrix1 with matrix2.
    {
        std::cout << "Both Matrices Are Equal.\n";
    }
    else 
    {
         std::cout << "Both Matrices Are Not Equal.\n";
    }
    return 0;
}
```
# Contributions:
#### If Someone Want To Contribute This Library To Work And Add More Features To This Header File Are Welcome.  
  
### For Contributions:  
#### Email Me Through khankkhan123apsacs@gmail.com.  
#### FAQ: Why Not Pull Requests ?
#### Answer:
##### Because I Am New To Github And Git Will Understand Everything About Github Gradually.

# License
#### This project is licensed under the GNU General Public License v 3.0- see the LICENSE file for details.
