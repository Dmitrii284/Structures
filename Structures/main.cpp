#include <iostream>
#include<string>

struct personData {
	struct dateData {// ��� � ���� ������ ��������� �� ��������  ����� ����� ���� �������� dateData
		int day = 1;// ���� unsigned int day = 1; �� ��� ����� �������� �� ��������� 
		int month = 1;
		int year = 1970;
		// ������ ��������� ������ �� ��������� �.� ���� �� ������ �� ����� ����� ��� ��� ������ � ������ �� ���������
	};
	std::string name = "noname";// � string �� ����� !!!!  = 1; �������� �� ���������
	dateData birthday;//������ ��������� � �������� ���� ��� ������ ���������
	std::string job = "emty";
	int salary = 0;
};
personData pd{// �������� ��� ������ ��������� � ������ ���� ���������
"Mike Legend",
{29, 7, 1998},
"ticher",
	80000
};

// �������� �������
void show_person(const personData& PD) {//��� ����������� ������
	std::cout << "Name:   " << pd.name << std::endl;
	std::cout << "Birthday:   " << pd.name <<
		PD.birthday.day << '.' <<
		PD.birthday.month << '.' <<
		PD.birthday.year << std::endl;
	std::cout << "job:  " << PD.job << std::endl;
	std::cout << "Salery:  " << PD.salary << std::endl;
}

//������� ���������� ��� ��������� ��� ����������� ���� ������� � ���������� ������
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



// ������ 1
struct coinKeeper {
	std::string name = "emty";
	int age = 0;
	int coins_number = 0;
	int* coins = nullptr;
};

void show_coinKeeper(const coinKeeper& CK) {
	std::cout << "���: " << CK.name << std::endl;
	std::cout << "�������: " << CK.age << std::endl;
	std::cout << "������: " ;
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
	// ���������
	// struct ��� ����� ���� ��������(��� ������) �� �������� ������� ������
	/*struct person {// ��������� ���������� ���� ��������� ��������(��� ������)
		std::string name;//��� ���� ��������� ����������
		int age;//��� ���� ��������� ���������� ���� ���������� �����������.
		std::string gender;//��� ���� 
		std::string job;
		int salary;
	} p1, p2{"Elisa Thompson", 22, "female", "actriss", 50000}; //p2{....} ��� ��� ���������� ������������� ������� ������
	// p2{"Elisa Thompson", 22, "female", "actriss", 50000}; ��� ������ ���������, ����� ���� ������ �����, ��������� ����������������
	
	// ��� �� ������� ������ p1 ��������� person
	//p2 ��� ��� ������� �������. �� ��� �� ������ ���������������� 
	// � ���������� ��������� ��������.

	// ��� �� ������� �������������
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
		// ��� ���������� �������������
		std::cout << "Name:" << p2.name << std::endl;
		std::cout << "Age :" << p2.age << std::endl;
		std::cout << "Gender :" << p2.gender << std::endl;
		std::cout << "Job :" << p2.job << std::endl;
		std::cout << "Salary :" << p2.salary << std::endl;

		// ������ ��� ������������. �������������� ������� �������� �������.
		person p3{
			"Alex Romanov",
			46,
			"male",
			"director",
			100000
		};// ��� ����� ������� ������ ������ ������� }p4 {  .....};

		person p4;//����������� ���� ������ ������� � ���� ������� ������� � ���������� ����������
		p4 = p3; //������ ������������ ����� ������ p4 ���� ������� p3
		std::cout << "---------------------------\n";
		// ��� ���������� �������������
		std::cout << "Name:" << p4.name << std::endl;
		std::cout << "Age :" << p4.age << std::endl;
		std::cout << "Gender :" << p4.gender << std::endl;
		std::cout << "Job :" << p4.job << std::endl;
		std::cout << "Salary :" << p4.salary << std::endl;
		*/

	//��������� date
	/*struct date {
		unsigned int day = 1;// ���� unsigned int day = 1; �� ��� ����� �������� �� ��������� 
		unsigned int month = 1 ;
		unsigned int year = 1970;
		std::string note = "empty";// �� ��������� � ���� note � ��� �������� "empty" ��� �� ���������. 
	};
	date bd{ 1, 5, 2010}; // ���� �������� { 1, 5, 2010, "Halloy world!!"} �� ������ "Halloy world!!"
	std::cout << bd.day << '.' <<
	 bd.month << '.' <<
		bd.year << " - " <<
	bd.note << std::endl;
	// �� ������ 1.5.2010 - empty
	*/

	//struct dateData {// ��� � ���� ������ ��������� �� ��������  ����� ����� ���� �������� dateData
	//		int day = 1;// ���� unsigned int day = 1; �� ��� ����� �������� �� ��������� 
	//		int month = 1;
	//		int year = 1970;
	//		// ������ ��������� ������ �� ��������� �.� ���� �� ������ �� ����� ����� ��� ��� ������ � ������ �� ���������
	//};
	//struct personData{
	//	std::string name = "noname";// � string �� ����� !!!!  = 1; �������� �� ���������
	//dateData birthday;//������ ��������� � �������� ���� ��� ������ ���������
	//std::string job = "emty";
	//int salary = 0;
	//};
	//personData pd{// �������� ��� ������ ��������� � ������ ���� ���������
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
	std::cout << pointer->name << std::endl;//-> ��� ���������� 2 ������� ����� -> ������ ���� ���
	std::cout<< pointer->birthday.day << std::endl;

	personData pd2 = input_person();
	show_person(pd2);
	*/

// ������ 1 ������ � ��������
std::cout << "������1.\n ������ � ��������";
coinKeeper keeper{
	"Peter",
	10,
	7,
	new int[7] {1, 10, 5, 2, 1, 1, 10}
};
show_coinKeeper(keeper);
std::cout << "��� ��������: " << yer_of_birth(keeper, 2023) << std::endl;
std::cout << "����� ����������: " << cash(keeper) << std::endl;





delete[] keeper.coins;




	return 0;
}