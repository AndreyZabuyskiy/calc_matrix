#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Matrix
{
private:
	int rows;
	int cols;
	T** field;

	void initialization()
	{
		field = new T * [rows];
		for (int i = 0; i < rows; ++i)
		{
			field[i] = new T[cols];
		}
	}
	void remove()
	{
		if (field != nullptr)
		{
			for (int i = 0; i < rows; ++i)
			{
				delete[] field[i];
			}
			delete[] field;
		}
	}
	void fill_zero()
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				field[i][j] = 0;
			}
		}
	}

public:
	Matrix() : rows(0), cols(0), field(nullptr) {}
	Matrix(int rows, int cols) : rows(rows), cols(cols){ initialization(); }
	
	/*Matrix& operator = (Matrix& other)
	{
		remove();

		rows = other.get_rows();
		cols = other.get_cols();

		initialization();

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				field[i][j] = other.get_field()[i][j];
			}
		}

		return *this;
	}*/
	Matrix operator + (Matrix& other)
	{
		Matrix tmp(rows, cols);

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				tmp.get_field()[i][j] = field[i][j] + other.get_field()[i][j];
			}
		}

		return tmp;
	}
	Matrix operator - (Matrix& other)
	{
		Matrix tmp(rows, cols);

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				tmp.get_field()[i][j] = field[i][j] - other.get_field()[i][j];
			}
		}

		return tmp;
	}
	Matrix operator * (Matrix& other)
	{
		Matrix tmp(other.get_rows(), other.get_cols());

		int tmp_element = 0;

		for (int i = 0; i < other.get_rows(); ++i)
		{
			for (int j = 0; j < other.get_cols(); ++j)
			{
				for (int k = 0; k < other.get_rows(); ++k)
				{
					tmp_element += field[i][k] * other.get_field()[k][j];
				}

				tmp.get_field()[i][j] = tmp_element;
				tmp_element = 0;
			}
		}

		return tmp;
	}
	Matrix operator / (Matrix& other)
	{
		Matrix tmp(other.get_rows(), other.get_cols());

		int tmp_element = 0;

		for (int i = 0; i < other.get_rows(); ++i)
		{
			for (int j = 0; j < other.get_cols(); ++j)
			{
				for (int k = 0; k < other.get_rows(); ++k)
				{
					tmp_element += field[i][k] / other.get_field()[k][j];
				}

				tmp.get_field()[i][j] = tmp_element;
				tmp_element = 0;
			}
		}

		return tmp;
	}

	T** get_field(){ return field; }
	int get_rows() { return rows; }
	int get_cols() { return cols; }

	void set_parameters()
	{
		cout << "Введите количество строк" << endl
			<< "-> ";
		cin >> rows;

		cout << "Введите количество колонок" << endl
			<< "-> ";
		cin >> cols;
	}
	void fill_rand()
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				field[i][j] = 10 + (rand() % 90);
			}
		}
	}
	T find_min_element()
	{
		T min = field[0][0];

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (min > field[i][j])
				{
					min = field[i][j];
				}
			}
		}

		return min;
	}
	T find_max_element()
	{
		T max = field[0][0];

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (max < field[i][j])
				{
					max = field[i][j];
				}
			}
		}

		return max;
	}

	template<typename T2>
	friend ostream& operator<< (ostream& os, Matrix<T2>& obj);

	template<typename T2>
	friend istream& operator>> (istream& is, Matrix<T2>& obj);
};

template<typename T>
ostream& operator<<(ostream& os, Matrix<T>& obj)
{
	for (int i = 0; i < obj.rows; ++i)
	{
		for (int j = 0; j < obj.cols; ++j)
		{
			cout << "[" << obj.field[i][j] << "] ";
		}
		cout << endl;
	}

	return os;
}

template<typename T>
istream& operator>>(istream& is, Matrix<T>& obj)
{
	obj.remove();
	obj.initialization();

	obj.fill_zero();

	for (int i = 0; i < obj.rows; ++i)
	{
		for (int j = 0; j < obj.cols; ++j)
		{
			system("cls");
			cout << obj << endl;

			cout << "[" << i + 1 << "][" << j + 1 << "] -> ";
			is >> obj.field[i][j];
		}
	}

	return is;
}