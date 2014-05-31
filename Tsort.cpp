#include <iostream>
#include <conio.h>
#include <string.h>

template <class T>
void sort(T* m, int size, void (*swap)(T& a)) {
	for (int i=n-1; i>=1; i--)
		for (int j=0; j<i; j++)
			swap(m[j],m[j+1]);
}

class DW {
private:
	char incarnation[2]; // For War Doctor - 9, for 9th - 10, for 10th - 11 è 12,
	// for 11th - 13, for 12th - 14
	char* companion[2];
public:
	DW() {
		this->incarnation[0]=1;
		this->incarnation[1]=2;
		this->companion[0]="Susan Forman";
		this->companion[1]="Jamie Maccrimon";
	}
	DW(int inc[2], char* sat[2]) {
		this->incarnation[0]=inc[0];
		this->incarnation[1]=inc[1];
		this->companion[0]=sat[0];
		this->companion[1]=sat[1];
	}
	void swap(DW& a) {
		if(a.incarnation[1]>a.incarnation[0]) {
			int foo=a.incarnation[0];
			a.incarnation[0]=a.incarnation[1];
			a.incarnation[1]=foo;
			char* str; strcpy(str,a.companion[0]);
			strcpy(a.companion[0],a.companion[1]);
			a.companion[0][strlen(a.companion[1])]='\0';
			strcpy(a.companion[1],str);
			a.companion[1][strlen(str)]='\0';
		}
	}
	void show() {
		printf("%d: %s",this->incarnation[0],this->companion[0]);
		printf("%d: %s",this->incarnation[1],this->companion[1]);
	}
};

class Country {
private:
	unsigned int population[2];
	char* name[2];
public:
	Country() {
		this->population[0]=143666931;
		this->name[0]="Russia";
		this->population[1]=320194478;
		this->name[1]="USA";
	}
	Country(char* n[2], unsigned int p[2]) {
		this->population[0]=p[0];
		this->name[0]=n[0];
		this->population[1]=p[1];
		this->name[1]=n[1];
	}
	void swap(Country& a) {
		if(a.population[1]>a.population[0]) {
			int foo=a.population[0];
			a.population[1]=foo;
			char* str; strcpy(str,a.name[0]);
			strcpy(a.name[0],a.name[1]);
			a.name[0][strlen(a.name[1])]='\0';
			strcpy(a.name[1],str);
			a.name[1][strlen(str)]='\0';
		}
	}
	void show() {
		printf("%s: %d",this->name[0],this->population[0]);
		printf("%s: %d",this->name[1],this->population[1]);
	}
};

int main() {
	int Carn[2]={9, 11};
	char sats[2][15]={"Rose Tyler", "Amy Pond"};
	char state[2][15]={"Belarus", "Canada"};
	unsigned int people[2]={9467000, 34568211};
	DW b(Carn,sats); Country d(state, people);
	sort(b,2,(&DW::swap)); sort(d,2,(&Country::swap));
	b.show(); d.show();

	getch();
}