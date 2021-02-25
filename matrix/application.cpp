#include "application.h"

template<typename T>
void Application::print_interface(Matrix<T>& matrix)
{
	int user;
	do
	{
		print_menu(matrix);
		cin >> user;

		system("cls");

		user_action(user, matrix);
	} while (user != 0);
}

template<typename T>
void Application::print_menu(Matrix<T>& matrix)
{
	system("cls");

	cout << matrix << endl;

	cout << "[1] �����������;" << endl
		<< "[2] ����� ������������� ��������;" << endl
		<< "[3] ����� ������������ ��������;" << endl
		<< "[0] �����" << endl
		<< "-> ";
}

template<typename T>
void Application::user_action(int user, Matrix<T>& matrix)
{
	switch (user)
	{
		case 1:
			open_calculator(matrix);
			break;

		case 2:
			print_max_element(matrix);
			break;

		case 3:
			print_min_element(matrix);
			break;
	}
}

template<typename T>
void Application::print_min_element(Matrix<T>& matrix)
{
	cout << matrix << endl;

	cout << "����������� �������: " << matrix.find_min_element() << endl;
	system("pause");
}

template<typename T>
void Application::print_max_element(Matrix<T>& matrix)
{
	cout << matrix << endl;

	cout << "������������ �������: " << matrix.find_max_element() << endl;
	system("pause");
}

template<typename T>
void Application::open_calculator(Matrix<T>& A)
{
	int user;
	list_arithmetic(A);
	cin >> user;
	do_arithmetic(user, A);
}

template<typename T>
void Application::list_arithmetic(Matrix<T>& A)
{
	cout << A << endl;

	cout << "[1] ��������;" << endl
		<< "[2] ���������;" << endl
		<< "[3] ���������;" << endl
		<< "[4] �������;" << endl
		<< "-> ";
}

template<typename T>
void Application::do_arithmetic(int user, Matrix<T>& A)
{
	switch (user)
	{
		case 1:
			A = addition(A);
			break;
			
		case 2:
			A = subtraction(A);
			break;

		case 3:
			A = multiplication(A);
			break;

		case 4:
			A = division(A);
			break;
	}
}

template<typename T>
Matrix<T> Application::addition(Matrix<T>& A)
{
	Matrix<T> B(A.get_rows(), A.get_cols());
	cin >> B;
	return A + B;
}

template<typename T>
Matrix<T> Application::subtraction(Matrix<T>& A)
{
	cout << "������� B:" << endl;
	Matrix<T> B(A.get_rows(), A.get_cols());
	cin >> B;
	return A - B;
}

template<typename T>
Matrix<T> Application::multiplication(Matrix<T>& A)
{
	cout << "������� B:" << endl;
	Matrix<T> B(A.get_rows(), enter_cols());
	cin >> B;
	return A * B;
}

template<typename T>
Matrix<T> Application::division(Matrix<T>& A)
{
	Matrix<T> B(A.get_rows(), enter_cols());
	cin >> B;
	return A / B;
}

int Application::enter_cols()
{
	int col;
	cout << "������� ���������� �������:" << endl
		<< "-> ";
	cin >> col;

	return col;
}

void Application::start()
{	
	cout << "������� A:" << endl;
	Matrix<double> A;
	A.set_parameters();
	cin >> A;
	print_interface(A);
}