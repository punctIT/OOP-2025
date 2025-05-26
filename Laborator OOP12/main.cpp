#include <iostream>
#include "Student.h"
#include "Catalog.h"
#include "CatalogRO.h"
#include "Materie.h"
#include "Math.h"
#include "Informatica.h"
using namespace std;


int main() {
	Student i("ion", "2005");
	i.adauga_materie(new Math{ 1.5, 2.4, 10, 5.5 });
	Student i1("ion1", "2005");
	i1.adauga_materie(new Math{ 1.5, 2.4, 10, 5.5 });
	i1.adauga_materie(new Informatica{ 1.5, 2.4, 10, 123 });
	Student i2("ion2", "2005");
	Student i3("ion3", "2005");
	Catalog *c = new CatalogRO();
	c->AddStudent(&i);
	c->AddStudent(&i1);
	c->AddStudent(&i2);
	c->AddStudent(&i3);
	c->ListStudent();
	cout << endl;
	c->GetGradesStudent("ion1");
}