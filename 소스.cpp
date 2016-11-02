#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class VectorND
{
public:
	int x_[5];
	int i = 0;
	int num = 0;
	VectorND()
	{
		for (int i = 0;i < 5;i++)
		{
			x_[i] = 0;
		}
	}
	VectorND(int num2)
	{
		num = num2;
		////x_ = new int[num];
		//for (int i = 0;i < 5;i++)
		//{
		//	x_[i] = 1;
		//}
	}
	int operator*(const VectorND& input)//dot product
	{
		int ans;

		ans = this->x_[0] * input.x_[0];
		for (int i = 0;i < 5 ;i++)
		{
			ans += this->x_[i] * input.x_[i];
		}
		return ans;

	}
	friend ostream& operator<<(ostream& os, const VectorND& dt);

	VectorND operator+(const VectorND& input)//dot product
	{
		VectorND vec;

		for (int i = 0;i < 5;i++)
		{
			vec.x_[i] = this->x_[i] + input.x_[i];
		}
		return vec;

	}

};
class Matrix3x3
{
public:
	int row0,col0;
	VectorND mat[5];
	Matrix3x3(const int _r0, const int _C0)
	{
		row0 = _r0;
		col0 = _C0;
		//mat = new VectorND[col0];
		for (int i=0;i < _r0;i++)
		{
			for (int j = 0;j <  _r0;j++)
			{
				mat[i].x_[j] = rand() % (j+1)+1;
			}
		}

	}
	
	VectorND operator*(const VectorND& rhs)//multiplication of matrix 3x3 and vector3D
	{
		VectorND ans[5] = { 0, };
		//ans = new VectorND[col0];
		for (int i = 0;i<4;i++)
		{
			for (int j = 0;j < 5;j++)
			{
				ans[i].x_[j] = mat[i].x_[j] * rhs.x_[j];

			}
		}

		return *ans;

	}
};
ostream& operator<<(ostream& os, const Matrix3x3& vec)
{
	
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			os << vec.mat[i].x_[i] << " ";
		}
		cout << endl;
	}
	return os;
}

int main()
{
	srand((unsigned)time(NULL));
	Matrix3x3 m(5, 4);

	VectorND v(5);

	VectorND y = m * y;
	cout << m<< endl;
	//cout << y << endl;
}
