#include <iostream>
#include<string>

struct personData {
	struct dateData {// Это в типе данных создается по правилам  Лауэр Кэмел Кейс название dateData
		int day = 1;// Если unsigned int day = 1; То это будет значение по умолчанию 
		int month = 1;
		int year = 1970;
		// Всегда указываем данные по умолчанию т.к если не задали то сразу видно что нет данных и мусора не выводится
	};
	std::string name = "noname";// в string не пишем !!!!  = 1; Значения по умолчанию
	dateData birthday;//Объект структуры в качестве поля для другой структуры
	std::string job = "emty";
	int salary = 0;
};
personData pd{// Указание для другой структуры в рамках этой структуры
"Mike Legend",
{29, 7, 1998},
"ticher",
	80000
};

// Создадим фгтлцию
void show_person(const personData& PD) {//Это константная ссылка
	std::cout << "Name:   " << pd.name << std::endl;
	std::cout << "Birthday:   " << pd.name <<
		PD.birthday.day << '.' <<
		PD.birthday.month << '.' <<
		PD.birthday.year << std::endl;
	std::cout << "job:  " << PD.job << std::endl;
	std::cout << "Salery:  " << PD.salary << std::endl;
}

//Функция возврыщает нам результат Она запрашивает поля объекта и возвращает объект
personData input_person() {
	personData tmp;
	std::cout << "Enter name -> ";
	std::cin.ignore();
	std::getline(std::cin, tmp.name);
	std::cout << "Enter birthday day -> ";
	std::cin >> tmp.birthday.day;
	std::cout << "Enter birthday month -> ";
	std::cin >> tmp.birthday.month;
	std::cout << "Enter birthday year -> ";
	std::cin >> tmp.birthday.year;
	std::cin.ignore();
	std::cout << "Enter job -> ";
	std::getline(std::cin, tmp.job);
	std::cout << "Enter Salery -> ";
	std::cin >> tmp.salary;

	return tmp;
}



// Задача 1
struct coinKeeper {
	std::string name = "emty";
	int age = 0;
	int coins_number = 0;
	int* coins = nullptr;
};

void show_coinKeeper(const coinKeeper& CK) {
	std::cout << "Имя: " << CK.name << std::endl;
	std::cout << "Возраст: " << CK.age << std::endl;
	std::cout << "Монеты: " ;
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ", ";
	std::cout << "\b\b \n";
}

inline int yer_of_birth(const coinKeeper& CK, int year) {
	return (year - CK.age);
}

int cash(const coinKeeper& CK) {
	int sum = 0;
	for (int i = 0; i < CK.coins_number; i++)
		sum += CK.coins[i];
	return sum;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	// СТРУКТУРА
	// struct Это всего лишь описание(Как чертеж) по которому создают объект
	/*struct person {// Структура являющаяся лишь ОПИСАНИЕМ объектов(Как чертеж)
		std::string name;//Это поля строковых переменных
		int age;//Это поля структуры являющиеся цело численными переменными.
		std::string gender;//Это поля 
		std::string job;
		int salary;
	} p1, p2{"Elisa Thompson", 22, "female", "actriss", 50000}; //p2{....} Это для мгновенной Инициализации Создали ОБЪЕКТ
	// p2{"Elisa Thompson", 22, "female", "actriss", 50000}; Это объект структуры, может быть создан позже, Мгновенно инициализируется
	
	// Это мы создали объект p1 структуры person
	//p2 Это имя второго объекта. Но так не удобно Инициализировать 
	// И существует синтаксис объектов.

	// Это не удобная Инициализация
	p1.name = "Tom Smith";
	p1.age = 26;
	p1.gender = "male";
	p1.job = "programer";
	p1.salary = 8000;

		std::cout << "Name:" << p1.name << std::endl;
		std::cout << "Age :" << p1.age << std::endl;
		std::cout << "Gender :" << p1.gender << std::endl;
		std::cout << "Job :" << p1.job << std::endl;
		std::cout << "Salary :" << p1.salary << std::endl;

		std::cout << "---------------------------\n";
		// Это Мгновенная инициализация
		std::cout << "Name:" << p2.name << std::endl;
		std::cout << "Age :" << p2.age << std::endl;
		std::cout << "Gender :" << p2.gender << std::endl;
		std::cout << "Job :" << p2.job << std::endl;
		std::cout << "Salary :" << p2.salary << std::endl;

		// Третий вид иницализации. Альтернативный вариант создания объекта.
		person p3{
			"Alex Romanov",
			46,
			"male",
			"director",
			100000
		};// Тут можно создать другие данные дописав }p4 {  .....};

		person p4;//Скопировали поля одного объекта в поля другого объекта с одтнаковой структурой
		p4 = p3; //Прямое присваивание полям бъекта p4 поля объекта p3
		std::cout << "---------------------------\n";
		// Это Мгновенная инициализация
		std::cout << "Name:" << p4.name << std::endl;
		std::cout << "Age :" << p4.age << std::endl;
		std::cout << "Gender :" << p4.gender << std::endl;
		std::cout << "Job :" << p4.job << std::endl;
		std::cout << "Salary :" << p4.salary << std::endl;
		*/

	//Структура date
	/*struct date {
		unsigned int day = 1;// Если unsigned int day = 1; То это будет значение по умолчанию 
		unsigned int month = 1 ;
		unsigned int year = 1970;
		std::string note = "empty";// По умолчанию в поле note у нас значение "empty" это по умолчанию. 
	};
	date bd{ 1, 5, 2010}; // если добавить { 1, 5, 2010, "Halloy world!!"} На экране "Halloy world!!"
	std::cout << bd.day << '.' <<
	 bd.month << '.' <<
		bd.year << " - " <<
	bd.note << std::endl;
	// На экране 1.5.2010 - empty
	*/

	//struct dateData {// Это в типе данных создается по правилам  Лауэр Кэмел Кейс название dateData
	//		int day = 1;// Если unsigned int day = 1; То это будет значение по умолчанию 
	//		int month = 1;
	//		int year = 1970;
	//		// Всегда указываем данные по умолчанию т.к если не задали то сразу видно что нет данных и мусора не выводится
	//};
	//struct personData{
	//	std::string name = "noname";// в string не пишем !!!!  = 1; Значения по умолчанию
	//dateData birthday;//Объект структуры в качестве поля для другой структуры
	//std::string job = "emty";
	//int salary = 0;
	//};
	//personData pd{// Указание для другой структуры в рамках этой структуры
	//"Mike Legend",
	//{29, 7, 1998},
	//"ticher",
	//	80000
	//};
	/*std::cout << "Name:   " << pd.name << std::endl;
	std::cout << "Birthday:   " << pd.name <<
		pd.birthday.day << '.' <<
		pd.birthday.month << '.' <<
		pd.birthday.year << std::endl;
	std::cout << "job:  " << pd.job << std::endl;
	std::cout << "Salery:  " << pd.salary << std::endl;

	show_person(pd);

	personData* pointer = &pd;
	std::cout << pointer->name << std::endl;//-> Она объединяет 2 объекта Пишем -> только один раз
	std::cout<< pointer->birthday.day << std::endl;

	personData pd2 = input_person();
	show_person(pd2);
	*/

// Задача 1 Объект с монетами
std::cout << "Задача1.\n Объект с монетами";
coinKeeper keeper{
	"Peter",
	10,
	7,
	new int[7] {1, 10, 5, 2, 1, 1, 10}
};
show_coinKeeper(keeper);
std::cout << "Год рождения: " << yer_of_birth(keeper, 2023) << std::endl;
std::cout << "Общие сбережения: " << cash(keeper) << std::endl;





delete[] keeper.coins;




	return 0;
}