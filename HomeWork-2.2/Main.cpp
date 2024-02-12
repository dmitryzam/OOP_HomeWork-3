#include<iostream>
#include<string>
#include<vector>
// Класс человек:
class Human {
public:
	std::string name_;
	int age_;	
	Human() { };
	~Human() { };
};
// Класс квартира:
class Apartmen {
private:
	std::vector<Human*>objHuman;
public:
	int numOfApart_;		// номер квартиры
	int numOfRoom_;		// кол-во комнат

	Apartmen() { };
	
	void AddHuman(std::string name, int age) {
		Human* newHuman = new Human;
		newHuman->name_ = name;
		newHuman->age_ = age;
		objHuman.push_back(newHuman);
	}

	void showApart()const {
		std::cout << "Квартира № " << numOfApart_ << ", комнат - " << numOfRoom_ << '\n';
	}

	void showResidents()const {
		std::cout << "Проживают:\n";
		for (int i = 0; i < objHuman.size(); i++)
			std::cout << "Имя: " << objHuman[i]->name_ << "\nВозраст: " << objHuman[i]->age_ << '\n';
		std::cout << '\n';
	}

	~Apartmen() { };
};
// Класс Дом:
class House {
private:
	std::vector<Apartmen*>objApartment;
public:
	int numOfHouse_;		// номер дома
	int numOfAparts_;	// кол-во квартир

	House(int num) { numOfHouse_ = num; }

	void AddApart(int num, int numOfRoom) {
		Apartmen* newApart = new Apartmen;
		newApart->numOfApart_ = num;
		newApart->numOfRoom_ = numOfRoom;
		objApartment.push_back(newApart);
		numOfAparts_ += 1;
	}

	void showNumHouse() {std::cout << "Номер дома: " << numOfHouse_ << 
			"\nКоличество квартир в доме: " << numOfAparts_ << '\n';
	}

	void showHouse() {
		std::cout << "Квартиры в доме:\n";
		for (int i = 0; i < objApartment.size(); i++) {
			std::cout << "Квартиры № " << objApartment[i]->numOfApart_ <<
				", комнат - " << objApartment[i]->numOfRoom_ << '\n';
		}
		std::cout << '\n';
	}

	~House() { };
};
int main() {
	setlocale(LC_ALL, "RU");
	// Создадим объект obj1 типа House:
	House obj1(11);
	// Создадим объект apart1 и apart2 типа Apartmen:
	Apartmen apart1;
	apart1.numOfApart_ = 10;
	apart1.numOfRoom_ = 3;
	Apartmen apart2;
	apart2.numOfApart_ = 11;
	apart2.numOfRoom_ = 2;

	obj1.AddApart(10, 3);
	obj1.AddApart(11, 2);

	obj1.showNumHouse();
	obj1.showHouse();

	std::cout << "Предпросмотр квартиры:\n";
	apart1.showApart();
	// Заселим в эту квартиру жильцов:
	apart1.AddHuman("Сан Саныч", 56);
	apart1.AddHuman("Ольга Павловна", 53);
	apart1.showResidents();
	
	std::cout << "Предпросмотр квартиры:\n";
	apart2.showApart();
	// Заселим в эту квартиру жильцов:
	apart2.AddHuman("Пал Палыч", 45);
	apart2.AddHuman("Светлана Святославовна", 44);
	apart2.showResidents();

	return 0;
}