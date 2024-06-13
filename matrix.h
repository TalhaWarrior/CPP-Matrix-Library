#ifndef MATRIX_H
#define MATRIX_H

#include <iostream> // for std::cout , std::cin , std::endl
#include <vector> // for std::vector
#include <utility> // std::pair and std::make_pair().


namespace linear_algebra
{
	class matrix
	{
		std::vector<std::vector<double>> matrices;

		int get_rows() const
		{
			return matrices.size();
		}

		std::pair<int, int> get_resultant_matrix_order(int rows_matrix_1, int columns_matrix_1, int rows_matrix_2,
		                                               int columns_matrix_2)
		{
			if (columns_matrix_1 == rows_matrix_2)
			{
				return std::make_pair(rows_matrix_1, columns_matrix_2);
			}
			if (rows_matrix_1 == columns_matrix_2)
			{
				return std::make_pair(columns_matrix_1, rows_matrix_2);
			}
			return std::make_pair(-1, -1);
		}

		bool is_confirmable_for_addition_or_subtraction(const int rows_matrix_1, const int coulumns_matrix_1,
		                                                const int rows_matrix_2, const int columns_matrix_2) const
		{
			if (rows_matrix_1 == rows_matrix_2 && coulumns_matrix_1 == columns_matrix_2)
			{
				return true;
			}
			return false;
		}

		bool is_confirmable_for_multiplication(const int rows_matrix_1, const int columns_matrix_1,
		                                       const int rows_matrix_2, const int columns_matrix_2) const
		{
			if ((columns_matrix_1 == rows_matrix_2) || (rows_matrix_1 == columns_matrix_2))
			{
				return true;
			}
			return false;
		}

		matrix fill_identity(int order)
		{
			for (int i = 0; i < order; i++)
			{
				for (int j = 0; j < order; j++)
				{
					if (i == j)
					{
						matrices[i][j] = 1;
					}
					else
					{
						matrices[i][j] = 0;
					}
				}
			}
			return *this;
		}

		matrix cofactor_matrix(int row, int col) const
		{
			int n = matrices.size();
			matrix cofactor(n - 1, n - 1);

			for (int i = 0, k = 0; i < n; ++i)
			{
				if (i == row) continue;
				for (int j = 0, l = 0; j < n; ++j)
				{
					if (j == col) continue;
					cofactor.matrices[k][l] = matrices[i][j];
					++l;
				}
				++k;
			}

			return cofactor;
		}

		matrix adjoint() const
		{
			int n = matrices.size();
			matrix adj(n, n);

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					matrix cofactor = cofactor_matrix(i, j);

					int sign = ((i + j) % 2 == 0) ? 1 : -1;

					double det = cofactor.determinant();
					adj.matrices[j][i] = sign * det;
				}
			}

			return adj;
		}

		int get_columns() const
		{
			int rows = get_rows();
			int columns = (rows > 0) ? matrices[0].size() : 0;
			return columns;
		}

	public:

		matrix(std::vector<std::vector<double>> mat) : matrices(mat)
		{
		}

		matrix()
		{
			matrices.clear();
		}

		matrix(int rows, int columns)
		{
			matrices.resize(rows);
			for (size_t i = 0; i < matrices.size(); i++)
			{
				matrices[i].resize(columns);
			}
		}

		matrix(std::initializer_list<std::initializer_list<double>> values)
		{
			matrices.resize(values.size());

			auto row_it = values.begin();
			for (size_t i = 0; i < matrices.size(); ++i, ++row_it)
			{
				matrices[i].resize(row_it->size());

				auto col_it = row_it->begin();
				for (size_t j = 0; j < matrices[i].size(); ++j, ++col_it)
				{
					matrices[i][j] = *col_it;
				}
			}
		}

		std::pair<int, int> get_order()
		{
			int rows = matrices.size();
			int columns = matrices[0].size();
			return std::make_pair(rows, columns);
		}

		matrix& operator =(const matrix& mat)
		{
			matrices = mat.matrices;
			return *this;
		}

		void replace_element(double element, int row_position, int coulumn_position)
		{
			matrices[row_position - 1][coulumn_position - 1] = element;
		}

		matrix transpose() const
		{
			matrix trn(matrices[0].size(), matrices.size());
			for (size_t i = 0; i < matrices.size(); ++i)
			{
				for (size_t j = 0; j < matrices[i].size(); ++j)
				{
					trn.matrices[j][i] = matrices[i][j];
				}
			}
			return trn;
		}

		bool is_valid() const
		{
			int rows = get_rows(), cols = get_columns();
			if (rows == 0 || cols == 0)
			{
				return false;
			}
			return true;
		}

		bool operator ==(const matrix& rightMatrix)
		{
			int myRows = get_rows();
			int myCols = get_columns();
			int hisRows = rightMatrix.get_rows();
			int hisCols = rightMatrix.get_columns();

			if (myRows == hisRows && myCols == hisCols)
			{
				for (size_t i = 0; i < myRows; i++)
				{
					for (size_t j = 0; j < myCols; j++)
					{
						if (matrices[i][j] != rightMatrix.matrices[i][j])
						{
							return false;
						}
					}
				}
				return true;
			}
			return false;
		}

		double determinant() const
		{
			int n = matrices.size();

			if (n == 1)
			{
				return matrices[0][0];
			}

			double det = 0;
			for (int i = 0; i < n; ++i)
			{
				std::vector<std::vector<double>> submatrix;
				for (int j = 1; j < n; ++j)
				{
					std::vector<double> row;
					for (int k = 0; k < n; ++k)
					{
						if (k != i)
						{
							row.push_back(matrices[j][k]);
						}
					}
					submatrix.push_back(row);
				}

				double sub_det = matrix(submatrix).determinant();

				if (i % 2 == 0)
				{
					det += matrices[0][i] * sub_det;
				}
				else
				{
					det -= matrices[0][i] * sub_det;
				}
			}
			return det;
		}

		
		matrix inverse() const
		{
			if (!is_square() || determinant() == 0)
			{
				std::cerr << "Matrix is not invertible." << std::endl;
				return matrix();
			}

			int n = matrices.size();
			matrix inv(n, n);

			double det = determinant();

			matrix adj = adjoint();

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					inv.matrices[i][j] = adj.matrices[i][j] / det;
				}
			}

			return inv;
		}

		matrix solve_system(matrix matrix_of_RHS_values)
		{
			matrix inv = inverse();
			matrix result = inv * matrix_of_RHS_values;
			return result;
		}

		matrix operator +(const matrix& mat)
		{
			if (!is_confirmable_for_addition_or_subtraction(get_rows(), get_columns(), mat.get_rows(),
			                                                mat.get_columns()))
			{
				return matrix();
			}
			matrix result(get_rows(), get_columns());
			for (size_t i = 0; i < matrices.size(); i++)
			{
				for (size_t j = 0; j < matrices[i].size(); j++)
				{
					result.matrices[i][j] = matrices[i][j] + mat.matrices[i][j];
				}
			}
			return result;
		}

		matrix operator -(const matrix& mat)
		{
			if (!is_confirmable_for_addition_or_subtraction(get_rows(), get_columns(), mat.get_rows(),
			                                                mat.get_columns()))
			{
				return matrix();
			}
			matrix result(get_rows(), get_columns());
			for (size_t i = 0; i < matrices.size(); i++)
			{
				for (size_t j = 0; j < matrices[i].size(); j++)
				{
					result.matrices[i][j] = matrices[i][j] - mat.matrices[i][j];
				}
			}
			return result;
		}

		matrix operator *(const matrix& mat)
		{
			if (!is_confirmable_for_multiplication(get_rows(), get_columns(), mat.get_rows(), mat.get_columns()))
			{
				return matrix();
			}
			std::pair<int, int> res_order = get_resultant_matrix_order(get_rows(), get_columns(), mat.get_rows(),
			                                                           mat.get_columns());
			matrix resultantMatrix(res_order.first, res_order.second);
			for (int i = 0; i < get_rows(); ++i)
			{
				for (int j = 0; j < mat.get_columns(); ++j)
				{
					for (int k = 0; k < get_columns(); ++k)
					{
						resultantMatrix.matrices[i][j] += matrices[i][k] * mat.matrices[k][j];
					}
				}
			}
			return resultantMatrix;
		}
		matrix operator * (double scalar)
		{
			if (scalar > 0 || scalar < 0) {
				for (int i = 0; i < matrices.size(); i++)
				{
					for (int j = 0; j < matrices[i].size(); j++)
					{
						matrices[i][j] *= scalar;
					}
				}
				return *this;
			}
			return matrix();
		}
		matrix operator += (const matrix& mat)
		{
			*this = *this + mat;
			return *this;
		}

		matrix operator -= (const matrix& mat)
		{
			*this = *this - mat;
			return  *this;
		}
		matrix operator *= (const matrix& mat)
		{
			*this = *this * mat;
			return  *this;
		}
		matrix operator *= (double scalar)
		{
			*this = *this * scalar;
			return *this;
		}
		
		matrix operator / (double scalar)
		{
			if (scalar > 0 || scalar < 0) {
				for (int i = 0; i < matrices.size(); i++)
				{
					for (int j = 0; j < matrices[i].size(); j++)
					{
						matrices[i][j] /= scalar;
					}
				}
				return *this;
			}
			return matrix();
		}
		
		matrix operator /= (double scalar)
		{
			*this = *this / scalar;
			return *this;
		}
		
		matrix augment_with(const matrix& mat)
		{
			int r1 = get_rows();
			int r2 = mat.get_rows();
			int c1 = get_columns();
			int c2 = mat.get_columns();

			if (r1 == r2)
			{
				matrix augmented(r1, c1 + c2);


				for (int i = 0; i < r1; ++i)
				{
					for (int j = 0; j < c1; ++j)
					{
						augmented.matrices[i][j] = matrices[i][j];
					}
				}

				for (int i = 0; i < r2; ++i)
				{
					for (int j = 0; j < c2; ++j)
					{
						augmented.matrices[i][j + c1] = mat.matrices[i][j];
					}
				}

				return augmented;
			}
			return matrix();
		}


		void print_order()
		{
			std::pair<int, int> order = get_order();

			if (is_valid() == true)
			{
				std::cout << "Order Of Matrix Is " << order.first << " - by - " << order.second << std::endl;
			}
			else
			{
				std::cerr << "Invalid Matrix !" << std::endl;
			}
		}

		bool is_null() const
		{
			for (const auto& e : matrices)
			{
				for (const auto& val : e)
				{
					if (val != 0)
					{
						return false;
					}
				}
			}
			return true;
		}

		bool is_empty() const
		{
			return matrices.empty();
		}

		bool is_square() const
		{
			const int rows = matrices.size();
			const int columns = (rows > 0) ? matrices[0].size() : 0;
			if (rows == columns)
			{
				return true;
			}
			return false;
		}

		bool is_identity() const
		{
			if (is_square() == false)
			{
				return false;
			}
			for (size_t i = 0; i < matrices.size(); i++)
			{
				for (size_t j = 0; j < matrices[i].size(); j++)
				{
					if ((i == j) && (matrices[i][j] != 1))
					{
						return false;
					}
					if ((i != j) && (matrices[i][j] != 0))
					{
						return false;
					}
				}
			}
			return true;
		}

		bool is_symmetric()
		{
			if (*this == transpose())
			{
				return true;
			}
			return false;
		}

		bool is_skew_symmetric()
		{
			matrix res = transpose();
			res *= -1;
			if (*this == res)
			{
				return true;
			}
			return false;
		}
		friend  std::istream& operator >> (std::istream& CIN, matrix& m);
		friend  std::ostream& operator << (std::ostream& COUT, matrix& m);
		~matrix() = default;
		
	};

	std::ostream& operator << (std::ostream& COUT, matrix& m)
	{
		for (size_t i = 0; i < m.matrices.size(); i++)
		{
			for (size_t j = 0; j < m.matrices[i].size(); j++)
			{
				COUT << m.matrices[i][j] << "\t";
			}
			COUT << std::endl;
		}
		return COUT;
	}
	std::istream& operator >> (std::istream& CIN, matrix& m)
	{
		std::cout << "Assign Values To Your Matrix: \n\n";
		for (size_t i = 0; i < m.matrices.size(); i++)
		{
			for (size_t j = 0; j < m.matrices[i].size(); j++)
			{
				std::cout << "Element At [" << i + 1 << "][" << j + 1 << "] = ";
				CIN >> m.matrices[i][j];
				std::cout << std::endl;
			}
		}
		return CIN;
	}

}
#endif

/*
 * Copyright (c) by Muhammad Talha. All rights reserved.
 * GNU Public License v3.0
 * V1.0(stable) */
