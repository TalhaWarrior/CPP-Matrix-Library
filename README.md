# C++ Matrix Library
Comprehensive C++ header for matrix calculations. This header provides a robust set of tools for matrix manipulation and analysis, making it a valuable resource for C++ programmers working with matrices.

## Features
#### System of Equations: Calculate the solution of a system of equations using the matrix inversion method.  
#### Matrix Inversion: Compute the inverse of a square matrix of order n-by-n.  
#### Determinant Calculation: Determine the determinant of a square matrix of order n-by-n.  
#### Scalar Multiplication: Perform matrix multiplication with a non-zero scalar.  
#### Dynamic Resizing: Resize a matrix even after declaration.  
#### Print Matrices: Print non-empty matrices.
#### Print Order: Print Order Of Any Matrix. 
#### Get Order: Get Order Of Matrix In Pair.
#### Element Replacement: Replace elements using row and column positions of the existing element you want to replace.  
#### Transpose Calculation: Compute the transpose of a matrix.  
#### Validation: Check if a matrix is valid.  
#### Comparison: Perform element-by-element comparison using the == operator.  
#### Matrix Addition and Subtraction: Perform addition and subtraction of matrices using the '+' and '-' operators.  
#### Matrix Multiplication: Perform matrix multiplication by using the '*' operator.  
#### Augmentation: Augment matrices with others of the same rows.  
#### User Input: Fill matrices with user input.  
#### Null Matrix Check: Determine if a matrix is null.  
#### Dimension Check: Check if a matrix is dimensionless (empty).  
#### Identity Matrix Check: Determine if a matrix is an identity matrix.  
#### Square Matrix Check: Determine if a matrix is square.  
#### Symmetry Check: Determine if a matrix is symmetric.  
#### Skew-Symmetry Check: Determine if a matrix is skew-symmetric.  

## Note: 
#### The '==' , '+' , '-' and '*' operators are overloaded so that they can be used directly on matrices.

## Usage

#### Include the matrix.h header in your C++ program.
#### Utilize the provided functions and overloaded operators for various matrix operations.

# Example: Main Usage Example
```cpp
#include <iostream>
#include "matrix.h"

// using namespace linear_algebra;

int main() {
    
    linear_algebra::matrix matrix1(3, 3); // Create a 3x3 double matrix
    matrix1.fill_by_user(); // Fill matrix with user input
    matrix1.print_matrix(); // Print the matrix

    // Perform other operations as needed

    return 0;
}
```

## Example: Get Order Example.
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

# Contribution
#### Contributions to enhance the functionality or documentation of this library are welcome. Please feel free to submit pull requests or open issues for any bugs or feature requests.

# License
#### This project is licensed under the GNU General Public License v 3.0- see the LICENSE file for details.
