#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <ctime>
#include <math.h>

void f(int& H, int&M, int&S, int s);
int f1(int ch);
int Len(int ch);
bool Pal(int N);
bool Sch(int ch);

using namespace std;
unsigned short int nz;


void main()
{
	setlocale(LC_ALL, "Rus");

start:
	cout << "Введите номер задания \n";
	cin >> nz;

	switch (nz)
	{
	case 1:
	{
		/*1.	Напишите функцию f(int& h, int& m, int& s, int sec), которая принимает 
		количество секунд, прошедших с начала дня, и возвращает три целых переменных
		(часы, минуты и секунды)*/
		int s, H, M, S;
		cout << "Введите количество секунд \n";
		cin >> s;
		
		f(H, M, S, s);
	
		cout << "C начала дня прошло " << H << " часов," << M << " минут," << S << " секунд \n";
	}
	break;
	case 2:
	{
		/*2.	Напишите функцию int f(int x), которая принимает целое значение
			(не больше пяти знаков) и возвращает число с обратным порядком цифр.
			Например, принимается число 7631, возвращается число 1367*/
		int ch1, ch2, raz;
		CH:
		cout << "Введите число от 2 до 5 разрядов \n";
		cin >> ch1;
		raz = Len(ch1);
		if((raz > 1) && (raz < 6))
		{
			ch2 = f1(ch1);
			cout << "Число с обратынм порчдком цифр: " << ch2 << endl;
			goto start;
		}
		else
		{
			cout << "Число должно быть от 2 до 5 разрядов \n";
			goto CH;		
		}	
	}
	break;
	case 3:
	{
		/*3.	Палиндром – число или текст, который одинаково читается слева направо и справа 
			налево.Например, каждое из следующих пятизначных целых чисел является палиндромом 
			: 12321, 55555, 45554 и 11611. Текст–палиндром : Ешь немытого ты меньше.
			Напишите функцию bool f(int N), которая определяет, является ли пятизначное целое 
			число N палиндромом*/
		int N,raz;
		bool Rez;
		NN:
		cout << "Введите пяти разрядное число \n";
		cin >> N;
		raz = Len(N);
		if (raz == 5)
		{
			Rez = Pal(N);
			if (Rez == true)
			{
				cout << "Число " << N << " является палиндромом \n";
				goto start;
			}
			else
			{
				cout << "Число " << N << " не является палиндромом \n";
				goto start;
			}
		}
		else
		{
			cout<<"Число не является пяти разрядным \n";
			goto NN;
		}

	}
	break;
	case 4:
	{
		/*4.	Говорят, что целое число является совершенным числом, если его сомножители, 
			включая 1 (но не само число) в сумме дают это число.Например, 6 – совершенное число, 
			так как 6 = 1 + 2 + 3. Напишите функцию bool f(int n), которая определяет, 
			является ли ее параметр n совершенным числом.Используйте эту функцию в программе, 
			которая определяет и печатает все совершенные числа в диапазоне от 1 до 1000.*/
		
		bool rez;
		int i;
		for (i = 1; i <= 1000; ++i)
		{
			rez = Sch(i);
			if (rez == true) cout << i << endl;
		}
		goto start;
	}
	break;
	case 5:
	{
	/*	5.	Напишите программу, которая с помощью функции rand() ставит оценки в пределах 
			от 2 до 5. В файл протокола направляйте слово “Неуд” при появлении 2, 
			«Удовл» при появлении 3, и т.д.Используйте оператор switch.*/

		unsigned short int oc,i;
		unsigned short int fp[10];
		srand(time(0));

		for (i = 0; i < 10; ++i)
		{			
			oc = 2 + rand() % 4;
			fp[i] = oc;
		}

		for (i = 0; i < 10; ++i)
		{
			//cout << fp[i] << endl;
			switch (fp[i])
			{
			case 2:
			{
			cout << "Неуд \n";
			}
			break;
			case 3:
			{
			cout << "Удовл \n";
			}
			break;
			case 4:
			{
			cout << "Хор \n";
			}
			break;
			case 5:
			{
			cout << "Отл \n";
			}
			break;
			}
		}
		goto start;		
	}
	break;
	case 6:
	{
		/*6.	 Билет на одну поездку в метро стоит 15 тенге, билет на 10 поездок стоит 125 тенге, 
			билет на 60 поездок стоит 440 тенге.Пассажир планирует совершить n поездок.Определите, 
			сколько билетов каждого вида он должен приобрести, чтобы суммарное количество оплаченных 
			поездок было не меньше n, а общая стоимость приобретенных билетов – минимальна.
			Входные данные : количество поездок n.Выходные данные – три целых числа, равные 
			необходимому количеству билетов на 1, на 10, на 60 поездок.Например, при вводе 129 
			программа должна вывести 0 1 2 (2 билета на 60 поездок и 1 билет на 10 поездок).*/
		unsigned short int k1, k10, k60, n,ost,pi;
		cout << "Введите колличество поездок \n";
		cin >> n;
		if (n >= 60)
		{
			k60 = n / 60;
			ost = n % 60;
			//cout <<k60 <<", "<< ost << endl;
			if (ost >= 10)
			{
				k10 = ost / 10;
				ost = ost % 10;
				//cout << k10 << ", " << ost << endl;
				if (ost >= 1)
				{
					k1 = ost / 1;
					//cout << k1 << ", " << ost << endl;
				}
			}
			else
			{
				k10 = 0;
				k1 = ost;
			}
			pi = (k10 * 125) + (k1 * 15);// pi промежуточный итог суммы билетов на 10 и на 1 поездку
			if (pi >= 440) // если pi больше 440 лучше купить еще один билет на 60 поездок 
			{
				k60++;
				cout << "0 0 " << k60<<endl;
				goto start;
			}
			else
			{
				if (k1 * 15 >= 125)
				{
					k10++;
					cout << "0 " << k10 << " " << k60 << endl;
					goto start;
				}
				else
				{
					cout << k1 << " " << k10 << " " << k60 << endl;
					goto start;
				}
			}

		}
		else if (n < 60)
		{
			k60 = 0;
			k10 = n / 10;
			k1 = n % 10;
			pi = (k10 * 125) + (k1 * 15);
			if (pi >= 440)
			{
				k60++;
				cout << "0 0 " << k60 << endl;
				goto start;
			}
			else
			{
				if (k1 * 15 >= 125)
				{
					k10++;
					cout << "0 " << k10 << " " << k60 << endl;
					goto start;
				}
				else
				{
					cout << k1 << " " << k10 << " " << k60 << endl;
					goto start;
				}
			}
		}
		else if (n < 10)
		{
			k60 = 0;
			k10 = 0;
			k1 = n;
			if (k1 * 15 >= 125)
			{
				k10++;
				k1 = 0;
				cout << k1 << " " << k10 << " " << k60 << endl;
				goto start;
			}
		}
	}
	break;
	case 7:
	{
		/*7.	Решите предыдущую задачу при наличии следующих билетов : 1 поездка - 15 тенге, 
			5 поездок - 70 тенге, 10 поездок - 125 тенге, 20 поездок - 230 тенге, 
			60 поездок - 440 тенге.Если для какого - то данного n существует несколько 
			способов приобретения билетов одинаковой стоимости, необходимо вывести ту комбинацию 
			билетов, которая дает большее число поездок.*/
		unsigned short int k1, k5, k10, k20, k60, n, ost, pi;
		cout << "Введите колличество поездок \n";
		cin >> n;
		if (n >= 60)
		{
			k60 = n / 60;
			ost = n % 60;					
		}
		else
		{
			k60 = 0;
		}
		if (ost >= 20)
		{
			k20 = ost / 20;
			ost = ost % 20;			
		}
		else
		{
			k20 = 0;			
		}
		if (ost >= 10)
		{
			k10 = ost / 10;
			ost = ost % 10;			
		}
		else
		{
			k10 = 0;			
		}
		if (ost >= 5)
		{
			k5 = ost / 5;
			ost = ost % 5;			
		}
		else
		{
			k5 = 0;			
		}
		if (ost >= 1)
		{
			k1 = ost / 1;			
		}
		else
		{
			k1 = 0;			
		}
		pi = (k20 * 230) + (k10 * 125) + (k5 * 70) + (k1 * 15);
		if (pi >= 440)
		{
			k60++;
			k20 = 0;
			k10 = 0;
			k5 = 0;
			k1 = 0;
			cout << k1<<" "<<k5<<" "<<k10<<" "<<k20<<" "<< k60 << endl;
			goto start;
		}
		else
		{
			pi= (k10 * 125) + (k5 * 70) + (k1 * 15);
			if (pi >= 230)
			{
				k20++;
				k10 = 0;
				k5 = 0;
				k1 = 0;
				cout << k1 << " " << k5 << " " << k10 << " " << k20 << " " << k60 << endl;
				goto start;
			}
			else
			{
				pi= (k5 * 70) + (k1 * 15);
				if (pi >= 125)
				{
					k10++;
					k5 = 0;
					k1 = 0;
					cout << k1 << " " << k5 << " " << k10 << " " << k20 << " " << k60 << endl;
					goto start;
				}
				else
				{
					if (k1 * 15 >= 70)
					{
						k5++;
						k1 = 0;
						cout << k1 << " " << k5 << " " << k10 << " " << k20 << " " << k60 << endl;
						goto start;
					}
					else
					{
						cout << k1 << " " << k5 << " " << k10 << " " << k20 << " " << k60 << endl;
						goto start;
					}
				}
			}
		}
	}
	break;
	default:
	{
		cout << "Такого задания не существует \n";
		goto start;
	}
	break;
	}
}
void f(int& H,int& M,int& S, int s)
{
	H = s / 3600;
	M = (s % 3600) / 60;
	S = s - (H * 3600) - (M * 60);	
}
int f1(int ch)
{
	// количество разрядов числа raz
	int raz,nch,ch1;
	int c1, c2, c3, c4, c5, ost;
	raz = Len(ch);
	if (raz == 5)
	{
		c1 = ch / 10000;
		ost = ch - (c1 * 10000);
		c2 = ost / 1000;
		ost = ost - (c2 * 1000);
		c3 = ost / 100;
		ost = ost - (c3 * 100);
		c4 = ost / 10;
		ost = ost - (c4 * 10);
		c5 = ost;
		nch = c5 * 10000 + c4 * 1000 + c3 * 100 + c2 * 10 + c1;
		return nch;
	}
	else if (raz == 4)
	{
		c1 = ch / 1000;
		ost = ch - (c1 * 1000);
		c2 = ost / 100;
		ost = ost - (c2 * 100);
		c3 = ost / 10;
		ost = ost - (c3 * 10);
		c4 = ost;
		nch = c4 * 1000 + c3 * 100 + c2 * 10 + c1;
		return nch;
	}
	else if (raz == 3)
	{
		c1 = ch / 100;
		ost = ch - (c1 * 100);
		c2 = ost / 10;
		ost = ost - (c2 * 10);
		c3 = ost;
		nch = c3 * 100 + c2 * 10 + c1;
		return nch;
	}
	else if (raz == 2)
	{
		c1 = ch / 10;
		ost = ch - (c1 * 10);
		c2 = ost;
		nch = c2 * 10 + c1;
		return nch;
	}	

}
int Len(int ch)
{
	// Функция считающая количестов разрядов
	int raz = 0;
	while (ch > 0)
	{
		ch = ch / 10;
		++raz;
	}
	return raz;
}
bool Pal(int N)
{
	int c1, c2, c3, c4, c5, ost;
	c1 = N / 10000;
	ost = N - (c1 * 10000);
	c2 = ost / 1000;
	ost = ost - (c2 * 1000);
	c3 = ost / 100;
	ost = ost - (c3 * 100);
	c4 = ost / 10;
	ost = ost - (c4 * 10);
	c5 = ost;
	if ((c1 == c5) && (c2 == c4)) return true;
	else return false;
}
bool Sch(int ch)
{
	int s = 0;
	for (int i = 1; i < ch; ++i)
	{
		if (ch%i == 0)
		{
			s += i;
			//cout << i << endl;
		}
	}
	if (s == ch) return true;
	else return false;
}