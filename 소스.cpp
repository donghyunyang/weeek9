#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int numm1 = 0, numm2 = 0, row1 = 0, col1 = 0;
class VectorND
{
public:
	int *x_;
	VectorND()
	{
		if (numm1>0)
			x_ = new int[numm1];
	}
	VectorND(const int& num2)
	{
		numm1 = num2;
		x_ = new int[numm1];
		for (int i = 0;i < numm1;i++)
		{
			x_[i] = rand() % 10 + 1;

		}
	}
	int operator*(const VectorND& input)//dot product
	{
		int ans;
		ans = this->x_[0] * input.x_[0];
		for (int i = 1;i < col1;i++)
		{
			ans += this->x_[i] * input.x_[i];
		}
		return ans;

	}
	friend ostream& operator<<(ostream& os, const VectorND& dt);

	VectorND operator+(const VectorND& input)//dot product
	{
		VectorND vec;

		for (int i = 0;i < numm1;i++)
		{
			vec.x_[i] = this->x_[i] + input.x_[i];
		}
		return vec;

	}

};
class Matrix3x3
{
public:
	int row0, col0;
	VectorND *mat;

	Matrix3x3(const int _r0, const int _C0)
	{
		row1 = row0 = _r0;
		col1 = col0 = _C0;
		mat = new VectorND[row0];

		for (int i = 0;i < row0;i++)
		{
			VectorND q(col0);

			mat[i] = q;

		}
	}

	VectorND operator*(const VectorND& rhs)//multiplication of matrix 3x3 and vector3D
	{
		VectorND ans(row1);

		for (int j = 0;j < row1;j++)
		{
			ans.x_[j] = mat[j] * rhs;
		}
		for (int i = 0; i< row1; i++)
			return ans;
	}
};
ostream& operator<<(ostream& os, const VectorND& vec)
{
	for (int i = 0;i < numm1;i++)
	{
		os << "\t\t" << vec.x_[i] << " " << endl;
	}
	return os;
}

int main()
{
	Matrix3x3 m(5, 4);

	VectorND v(4);
	printf("\t"); printf("%d x %d Matrix", row1, col1);printf("\t");
	printf("Vector");
	puts("");puts("");
	for (int i = 0;i<m.row0;i++)
	{
		printf("\t");
		for (int j = 0;j < m.col0;j++)
		{
			printf("%2d ", m.mat[i].x_[j]);
		}
		if (i<m.row0 - 1)
			printf("\t  %d", v.x_[i]);
		puts("");
	}
	VectorND y = m * v;
	puts("");
	printf("\t      answer");
	puts("");
	cout << y << endl;

}
