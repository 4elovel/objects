#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

const short SIZE = 50;
class Object
{
public:
	static int indetificator;
	Object(int weight, int price) : weight(weight), price(price)
	{
		id = indetificator;
		indetificator++;
	}
	int id;
	int weight, price;
	int value = price / weight;


	void print() {
		cout << "Object number-> " << id
			<< "\tWeight-> " << weight
			<< "\tPrice-> " << price << "\n";
	}
};

int Object::indetificator = 1;

void packing(vector <Object> objects) {
	int total_price = 0;
	int rem = SIZE;
	vector <Object> by_val(objects);
	vector <Object> result;
	sort(by_val.begin(), by_val.end(), [](const Object& a, const Object& b) { return a.value > b.value; });
	for (size_t i = 0; i < by_val.size(); i++)
	{
		if (rem >= by_val[i].weight) {
			result.push_back(by_val[i]);
			rem -= by_val[i].weight;
			total_price += by_val[i].price;
		}
	}
	cout << "In Backpack you can have:\n";
	for (auto i : result)
	{
		i.print();
	}
	cout << "\nTotal price-> " << total_price;
}


int main()
{
	srand(time(NULL));
	vector <Object> objects{};

	for (size_t i = 0; i < 70; i++)
	{
		Object a( 1 + rand() % 49, 1 + rand() % 49);
		objects.push_back(a);
		objects[i].print();

	}

	cout << "\n\n";
	packing(objects);
}
