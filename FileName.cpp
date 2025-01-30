#include <iostream>
#include <Windows.h>
#include <future>
#include <time.h>
#include <mmsystem.h>

#pragma comment(lib,"Winmm.lib")


int standard_living{ 100 }, total_income{ 5 }, danger_level{ 1 }, total_money{ 1000 }, per_income;

class Structure
{
protected:
	int price;
	int income;
	char sign;
public:
	Structure(int price, int income, char sign)
	{
		this->price = price;
		this->income = income;
		this->sign = sign;
	}
	int get_price()
	{
		return price;
	}
	int get_income()
	{
		return income;
	}
	char get_sign()
	{
		return sign;
	}
	bool prov_sign(char sign)
	{
		return (this->sign == sign);
	}
};

class Structure_of_living : public Structure
{
protected:
	int per_life;
public:
	Structure_of_living(int price, int income, int per_life, char sign) : Structure(price, income, sign)
	{
		this->per_life = per_life;
	}
	int get_per_life()
	{
		return per_life;
	}
};

class Structure_of_danger : public Structure
{
protected:
	int per_danger;
public:

	Structure_of_danger(int price, int income, int per_danger, char sign) : Structure(price, income, sign)
	{
		this->per_danger = per_danger;
	}
	int get_per_danger()
	{
		return per_danger;
	}
};
class Total_Structure : public Structure
{
protected:
	int per_life;
	int per_danger;
public:
	Total_Structure(int price, int income, int per_danger, int per_life, char sign) : Structure(price, income, sign)
	{
		this->per_life = per_life;
		this->per_danger = per_danger;
	}
	int get_per_danger()
	{
		return per_danger;
	}
	int get_per_life()
	{
		return per_life;
	}

};

Total_Structure operator+(Structure& a, Structure_of_danger& b)
{
	int a_price = a.get_price();
	int b_price = a.get_price();
	int total_price = a_price + b_price;
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), b.get_per_danger(), 0, 'a');
	return c;
}
Total_Structure operator+(Structure_of_danger& b, Structure& a)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), b.get_per_danger(), 0, 'a');
	return c;
}

Total_Structure operator+(Structure& b, Structure& a)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), 0, 0, 'a');
	return c;
}
Total_Structure operator+(Structure_of_danger& b, Structure_of_danger& a)
{

	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), (b.get_per_danger() + a.get_per_danger()), 0, 'a');
	return c;
}
Total_Structure operator+(Structure_of_living& b, Structure& a)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), 0, b.get_per_life(), 'a');
	return c;
}
Total_Structure operator+(Structure& b, Structure_of_living& a)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), 0, a.get_per_life(), 'a');
	return c;
}
Total_Structure operator+(Structure_of_living& a, Structure_of_living& b)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), 0, (a.get_per_life() + b.get_per_life()), 'a');
	return c;
}
Total_Structure operator+(Structure_of_danger& b, Structure_of_living& a)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), b.get_per_danger(), a.get_per_life(), 'a');
	return c;
}
Total_Structure operator+(Structure_of_living& a, Structure_of_danger& b)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), b.get_per_danger(), a.get_per_life(), 'a');
	return c;
}
Total_Structure operator+(Total_Structure& a, Structure_of_living& b)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), a.get_per_danger(), (a.get_per_life() + b.get_per_life()), 'a');
	return c;
}
Total_Structure operator+(Structure_of_living& b, Total_Structure& a)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), a.get_per_danger(), (a.get_per_life() + b.get_per_life()), 'a');
	return c;
}
Total_Structure operator+(Total_Structure& a, Structure_of_danger& b)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), (a.get_per_danger() + b.get_per_danger()), (a.get_per_life()), 'a');
	return c;
}
Total_Structure operator+(Structure_of_danger& b, Total_Structure& a)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), (a.get_per_danger() + b.get_per_danger()), (a.get_per_life()), 'a');
	return c;
}

Total_Structure operator+(Total_Structure& a, Structure& b)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), a.get_per_danger(), (a.get_per_life()), 'a');
	return c;
}
Total_Structure operator+(Structure& b, Total_Structure& a)
{
	Total_Structure c((a.get_price() + b.get_price()), (a.get_income() + b.get_income()), a.get_per_danger(), (a.get_per_life()), 'a');
	return c;
}

class City
{
	Structure factory{ 1000, 100, '@' };
	Structure oil_derrick{ 4100, 200, '^' };
	Structure bank{ 15000, 0, '$' };
	Structure_of_living school{ 2500, 100, 1, '#' };
	Structure_of_danger dam{ 3000, 0, 1, '[' };
	Structure structure_final{ 250, 0, 'X' };
	
	const int size{ 9 };
	char pole[9][9];
public:
	City()
	{
		for (int i = 0; i < size; i++)
		{
			for (int g = 0; g < size; g++)
			{
				pole[i][g] = '*';
			}
		}
	}
	void prov_char(int i, int g)
	{
		if (pole[i][g] == bank.get_sign())
		{
			total_income += bank.get_income();
			per_income += 3;
		}
		else if (pole[i][g] == factory.get_sign())
		{
			total_income += factory.get_income();
		}
		else if (pole[i][g] == dam.get_sign())
		{
			total_income += dam.get_income();
			danger_level -= dam.get_per_danger();
		}
		else if (pole[i][g] == school.get_sign())
		{
			total_income += school.get_income();
			standard_living += school.get_per_life();
		}
		else if (pole[i][g] == oil_derrick.get_sign())
		{
			total_income += oil_derrick.get_income();
		}
	}

	bool prov_final()
	{
		bool prov{ true };
		for (int i = 0; i < size && prov == true; i++)
		{
			for (int g = 0; g < size && prov == true; g++)
			{
				if (pole[i][g] == 'X')
				{
					std::cout << "Вы выйграли\n";
					prov = false;
				}
			}
		}
		if (prov != false && total_income == 0)
		{
			prov = false;
			std::cout << "Вы проиграли\n";
		}
		return prov;
	}

	void directory()
	{
		setlocale(LC_ALL, "RU");
		system("cls");
		std::cout << "\t\t\t\t\t\t\tschool\n\n" << "Цена\t" << school.get_price() << "\nДоход\t" << school.get_income()
			<< "\nПовышение уровня жизни\t" << school.get_per_life() << "\nПонижение уровня опасности\t" << 0 << "\nЗнак\t" << school.get_sign() << "\n\n";

		std::cout << "\t\t\t\t\t\t\tfactory\n\n" << "Цена\t" << factory.get_price() << "\nДоход\t" << factory.get_income()
			<< "\nПовышение уровня жизни\t" << 0 << "\nПонижение уровня опасности\t" << 0 << "\nЗнак\t" << factory.get_sign() << "\n\n";

		std::cout << "\t\t\t\t\t\t\toil_derrick\n\n" << "Цена\t" << oil_derrick.get_price() << "\nДоход\t" << oil_derrick.get_income()
			<< "\nПовышение уровня жизни\t" << 0 << "\nПонижение уровня опасности\t" << 0 << "\nЗнак\t" << oil_derrick.get_sign() << "\n\n";

		std::cout << "\t\t\t\t\t\t\tdam\n\n" << "Цена\t" << dam.get_price() << "\nДоход\t" << dam.get_income()
			<< "\nПовышение уровня жизни\t" << 0 << "\nПонижение уровня опасности\t" << 0 << "\nЗнак\t" << dam.get_sign() << "\n\n";

		std::cout << "\t\t\t\t\t\t\tbank\n\n" << "Цена\t" << bank.get_price() << "\nДоход\t" << bank.get_income()
			<< "\nПовышение уровня жизни\t" << 0 << "\nПонижение уровня опасности\t" << 0 << "\nПриносит 3% от бщего дохода\n" << "\nЗнак\t" << dam.get_sign() << "\n\n";

		std::cout << "Уроыень жизни - чем он меньше, тем меньше доход\n";
		std::cout << "Уровень опасности - чем он выше, тем выше шанс катастрофы\n";
		int i;
		std::cout << "\n\nЕсли вы все прочитала введите любое число\n";
		std::cin >> i;
	}

	int building_structure()
	{
		setlocale(LC_ALL, "RU");
		int  i;
		char pg;
		int g;
		char sign;
		std::cout << "\nВведите номер поля(сначало число, потом букву) или два ноля чтобы выйти. \n";
		do
		{
			std::cin >> i;
			std::cin >> pg;
			i--;
			g = pg - 65;
		} while ((i < 0 || i > 9 || g < 0 || g > 9) && (i != -1 && g != -65 && i != 9 && g != -55) );
		if (i == -1 || g == -65)
		{
			return -1;
		}
		
		else
		{

			do
			{
				std::cin >> i;
				std::cin >> pg;
				i--;
				g = pg - 65;
			} while ((i < 0 || i > 9 || g < 0 || g > 9) && (i != -1 && g != -65));
			if (i == -1 || g == -65)
			{
				return -1;
			}

			std::cout << "Введите иконку здания которое хотите купить\n";
			std::cin >> sign;
			if (
				factory.prov_sign(sign) && oil_derrick.prov_sign(sign) && dam.prov_sign(sign) &&
				school.prov_sign(sign) && bank.prov_sign(sign) && structure_final.prov_sign(sign)
				)
			{
				std::cout << "Такого здания нет\n";

			}
			else
			{
				if (factory.prov_sign(sign))
				{
					if (factory.get_price() > total_money)
					{
						std::cout << "У вас недостаточно денег\n";
					}
					else
					{
						pole[i][g] = sign;
						total_money -= factory.get_price();
					}
				}
				else if (oil_derrick.prov_sign(sign))
				{
					if (oil_derrick.get_price() > total_money)
					{
						std::cout << "У вас недостаточно денег\n";
					}
					else
					{
						pole[i][g] = sign;
						total_money -= oil_derrick.get_price();
					}
				}
				else if (dam.prov_sign(sign))
				{
					if (dam.get_price() > total_money)
					{
						std::cout << "У вас недостаточно денег\n";
					}
					else
					{
						pole[i][g] = sign;
						total_money -= dam.get_price();
					}
				}
				else if (school.prov_sign(sign))
				{
					if (school.get_price() > total_money)
					{
						std::cout << "У вас недостаточно денег\n";
					}
					else
					{
						pole[i][g] = sign;
						total_money -= school.get_price();
					}
				}
				else if (bank.prov_sign(sign))
				{
					if (bank.get_price() > total_money)
					{
						std::cout << "У вас недостаточно денег\n";
					}
					else
					{
						pole[i][g] = sign;
						total_money -= bank.get_price();
					}
				}
				else if (structure_final.prov_sign(sign))
				{
					if (structure_final.get_price() > total_money)
					{
						std::cout << "У вас недостаточно денег\n";
					}
					else
					{
						pole[i][g] = sign;
						total_money -= structure_final.get_price();
					}

				}
				
			}
		}
		return 0;
	}
	void print()
	{
		system("cls");
		std::cout << '\t';

		for (char i = 65; i < 74; i++)
		{
			std::cout << i << '\t';
		}
		std::cout << '\n';
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << '\t';
			for (int g = 0; g < size; g++)
			{
				std::cout << pole[i][g] << '\t';
			}
			std::cout << "\n\n\n";
		}
	}
	void rand_disaster()
	{
		setlocale(LC_ALL, "RU");
		srand(time(NULL));
		int disaster;
		disaster = 1 + rand() % 4;
		if (disaster == 1)
		{
			PlaySoundA("okean-shumnyii-blizkii.wav", NULL, SND_ASYNC);

			// Генерируем случайное число для выбора стороны
			int border = std::rand() % 4; // 0 - верх, 1 - нижний, 2 - левый, 3 - правый

			if (border == 0) {
				// Заменяем верхнюю строку на пробелы
				for (int col = 0; col < size; ++col)
				{
					pole[0][col] = '*';
				}

			}
			else if (border == 1) {
				// Заменяем нижнюю строку на пробелы
				for (int col = 0; col < size; ++col)
				{
					pole[size - 1][col] = '*';
				}

			}
			else if (border == 2) {

				for (int row = 0; row < size; ++row)
				{
					pole[row][0] = '*';
				}

			}
			else {

				for (int row = 0; row < size; ++row) {
					pole[row][size - 1] = '*';
				}

			}
			print();
			std::cout << "\n\nВ вашем городе случилось наводнение. Проверьте, все ли здания целы\n";
			Sleep(2000);
		}
		else if (disaster == 2)
		{
			PlaySoundA("18917.wav", NULL, SND_ASYNC);
			int randomRow = rand() % (size - 2); 
			int randomCol = rand() % (size - 2); 

			for (int i = 0; i < 3; ++i) 
			{
				for (int j = 0; j < 3; ++j) 
				{
					pole[randomRow + i][randomCol + j] = '*';
				}
			}
			print();
			std::cout << "\n\nВ вашем городе упал метеорит. Проверьте, все ли здания целы\n";
			Sleep(2000);
		}
	}
	
};

City city;


void game()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	while (city.prov_final())
	{
		
		total_income = 1;
		per_income = 0;

		for (int i = 0; i < 9; i++)
		{
			for (int g = 0; g < 9; g++)
			{
				city.prov_char(i, g);
			}
		}
		total_income -= ((100 - standard_living) * (total_income / 100));
		total_money += total_income;
		total_income += (total_income / 100) * per_income;

		if ((1 + rand() % 100) <= danger_level)
		{
			city.rand_disaster();
			danger_level = 1;

		}
		danger_level += rand() % (3 - (-1) + 1) + (-1);
		if (danger_level < 0)
		{
			danger_level = 0;
		}
		else if (danger_level > 100)
		{
			danger_level = 100;
		}
		if (standard_living <= 0)
		{
			standard_living = 1;
		}
		if (standard_living > 3)
		{
			standard_living -= rand() % (3 - (-2) + 1) + (-2);
			if (standard_living > 100)
			{
				standard_living = 100;
			}
		}
		//убрать

		Sleep(1000);
	}
}

void control()
{
	setlocale(LC_ALL, "RU");
	while (city.prov_final())
	{
		if (GetKeyState('D') & 0x8000)
		{
			system("cls");
			std::cout << "Управление: D\nПосмотреть доход, уровень жизни и опасности: правая кнопка мыши\n"
				<< "Вывод поля: S\nПоставить здание: A\nПосмотреть справочник: W\n";

			Sleep(500);
		}
		else if (GetKeyState('W') & 0x8000)
		{
			city.directory();
			Sleep(500);
		}
		else if (GetKeyState(VK_RBUTTON) & 0x8000)
		{
			system("cls");
			std::cout << "Доход: " << total_income << "\nОбщее количество денег: " << total_money
				<< "\nУровень жизни: " << standard_living << "\nУровень опасности: " << danger_level << '\n';
			Sleep(500);
		}
		else if (GetKeyState('S') & 0x8000)
		{
			system("cls");
			city.print();
			Sleep(500);
		}
		else if (GetKeyState('A') & 0x8000)
		{
			system("cls");

			city.print();

			city.building_structure();
			Sleep(500);
		}
	}

}




int main()
{
	setlocale(LC_ALL, "RU");
	

	std::cout << "Управление можно посмотреть на D";

	std::future<void> f_1(std::async(control));
	std::future<void> f_2(std::async(game));

	Structure a(10, 10, 'a');
	Structure_of_danger b(5, 5, 5, 'b');
	Structure_of_living g(3, 3, 3, 'g');
	Total_Structure c = b + a;

}