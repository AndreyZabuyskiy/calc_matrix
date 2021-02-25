#pragma once
#include "matrix.h"

class Application
{
	template<typename T>
	void print_interface(Matrix<T>& matrix);

	template<typename T>
	void print_menu(Matrix<T>& matrix);

	template<typename T>
	void user_action(int user, Matrix<T>& matrix);

	template<typename T>
	void print_min_element(Matrix<T>& matrix);

	template<typename T>
	void print_max_element(Matrix<T>& matrix);

	template<typename T>
	void open_calculator(Matrix<T>& A);

	template<typename T>
	void list_arithmetic(Matrix<T>& A);

	template<typename T>
	void do_arithmetic(int user, Matrix<T>& A);

	template<typename T>
	Matrix<T> addition(Matrix<T>& A);

	template<typename T>
	Matrix<T> subtraction(Matrix<T>& A);

	template<typename T>
	Matrix<T> multiplication(Matrix<T>& A);

	template<typename T>
	Matrix<T> division(Matrix<T>& A);

	int enter_cols();

public:
	void start();
};