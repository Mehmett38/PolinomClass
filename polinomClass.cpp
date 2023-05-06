#include <iostream>

using namespace std;

class Polinom {
private:
	int index1;			//(index1)x^2 + (index2)x + index3 
	int index2;			//çarpma durumunda 2. dereceden bir denklem 4. dereceden bir denklem oluyor
	int index3;			// o yüzden (index5)x^4 ve (index4)x^3 için kullanýlacak
	int index4 = 0;
	int index5 = 0;
	double x;				//bilinmeyen
	double deger;
public:
	Polinom(int index1, int index2, int index3)
	{
		this->index1 = index1;
		this->index2 = index2;
		this->index3 = index3;
		this->x = 0;
		deger = (index1 * x * x) + (index2 * x) + (index3);
	}
	Polinom()
	{
		this->index1 = 0;
		this->index2 = 0;
		this->index3 = 0;
		this->x = 0;
		deger = 0;
	}
	void setX(double x)
	{
		this->x = x;
	}
	double getX()
	{
		return this->x;
	}
	double getDeger()
	{
		return ( (index5 * x*x*x*x) + (index4 *x*x*x) +(index1 * x*x) + (index2 * x) + (index3));
	}

	Polinom operator+(Polinom const& obj)
	{
		Polinom res;
		res.index1 = index1 + obj.index1;
		res.index2 = index2 + obj.index2;
		res.index3 = index3 + obj.index3;
		return res;
	}

	Polinom operator-(Polinom const& obj)
	{
		Polinom res;
		res.index1 = index1 - obj.index1;
		res.index2 = index2 - obj.index2;
		res.index3 = index3 - obj.index3;
		return res;
	}

	Polinom operator*(Polinom const& obj)
	{
		Polinom res;
		res.index5 = index1 * obj.index1;		//x^4 lü terim katsayýlarý
		res.index4 = index1 * obj.index2 + index2 * obj.index1;	//x^3 terim katsayýlarý
		res.index1 = index1 * obj.index3 + index2 * obj.index2 + index3 * obj.index1;	//x^2 terimler
		res.index2 = index2 * obj.index3 + index3 * obj.index2; // x terimler
		res.index3 = index3 * obj.index3;
		return res;
	}

	Polinom operator=(Polinom const& obj)
	{
		Polinom res;
		res.index1 = obj.index1;
		res.index2 = obj.index2;
		res.index3 = obj.index3;
		res.x = obj.x;
		res.deger = obj.deger;
	}

	Polinom operator+=(Polinom const& obj)
	{
		Polinom res;
		res.index1 = index1 + obj.index1;
		res.index2 = index2 + obj.index2;
		res.index3 = index3 + obj.index3;
		return res;
	}

	Polinom operator-=(Polinom const& obj)
	{
		Polinom res;
		res.index1 = index1 - obj.index1;
		res.index2 = index2 - obj.index2;
		res.index3 = index3 - obj.index3;
		return res;
	}

	Polinom operator*=(Polinom const& obj)
	{
		Polinom res;
		res.index5 = index1 * obj.index1;		//x^4 lü terim katsayýlarý
		res.index4 = index1 * obj.index2 + index2 * obj.index1;	//x^3 terim katsayýlarý
		res.index1 = index1 * obj.index3 + index2 * obj.index2 + index3 * obj.index1;	//x^2 terimler
		res.index2 = index2 * obj.index3 + index3 * obj.index2; // x terimler
		res.index3 = index3 * obj.index3;
		return res;
	}
};

int main()
{
	Polinom pol1(2, 4, 20);	// 2x^2 + 4x + 20
	Polinom pol2(1,1,10);	// x^2 + x + 10

	Polinom pol3 = pol1 + pol2;		// 3x^2 + 5x + 30
	Polinom pol4 = pol1 - pol2;		// x^2 + 3x + 10
	Polinom pol5 = pol1;				
	Polinom pol6 = pol1 * pol2;		// ...
	Polinom pol7 = pol1;
	pol7 -= pol2;					//// x^2 + 3x + 10
	Polinom pol8 = pol1;
	pol8 += pol1;
	Polinom pol9 = pol1;
	pol9 *= pol2;

	pol3.setX(2);	//4 + 4 + 1
	pol4.setX(3);
	pol5.setX(4);			// 13 * 9 
	pol6.setX(5);	//4 + 4 + 1
	pol7.setX(6);
	pol8.setX(7);			// 13 * 9 
	pol9.setX(8);	//4 + 4 + 1

	cout << "Pol 3 : " << pol3.getDeger() << endl;
	cout << "Pol 4 : " << pol4.getDeger() << endl;
	cout << "Pol 5 : " << pol5.getDeger() << endl;
	cout << "Pol 6 : " << pol6.getDeger() << endl;
	cout << "Pol 7 : " << pol7.getDeger() << endl;
	cout << "Pol 8 : " << pol8.getDeger() << endl;
	cout << "Pol 9 : " << pol9.getDeger() << endl;
}


