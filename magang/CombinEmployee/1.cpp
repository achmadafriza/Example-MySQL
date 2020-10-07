#include <bits/stdc++.h>
/*
Suprapto Sutejo
Suprapto Sumarni
Suprapto Suparman
Suprapto Stip
Suprapto Rojers
Suprapto Sapidarman
Suprapto Ricardo
Suprapto Milos
Suprapto Mutejo
Suprapto Solihin
Sutejo Sumarni
Sutejo Suparman
Sutejo Stip
Sutejo Rojers
Sutejo Sapidarman
Sutejo Ricardo
Sutejo Milos
Sutejo Mutejo
Sutejo Solihin
Sumarni Suparman
Sumarni Stip
Sumarni Rojers
Sumarni Sapidarman
Sumarni Ricardo
Sumarni Milos
Sumarni Mutejo
Sumarni Solihin
Suparman Stip
Suparman Rojers
Suparman Sapidarman
Suparman Ricardo
Suparman Milos
Suparman Mutejo
Suparman Solihin
Stip Rojers
Stip Sapidarman
Stip Ricardo
Stip Milos
Stip Mutejo
Stip Solihin
Rojers Sapidarman
Rojers Ricardo
Rojers Milos
Rojers Mutejo
Rojers Solihin
Sapidarman Ricardo
Sapidarman Milos
Sapidarman Mutejo
Sapidarman Solihin
Ricardo Milos
Ricardo Mutejo
Ricardo Solihin
Milos Mutejo
Milos Solihin
Mutejo Solihin
*/

/*
11
Suprapto
Sutejo
Sumarni
Suparman
Stip
Rojers
Sapidarman
Ricardo
Milos
Mutejo
Solihin
*/
int deep[110], pos[110];
int r = 2;
int n;
std::string s[110];
//int count = 0;

struct employee
{
	std::string nama1;
	std::string nama2;
	int code;
	int year;
	int month;
	int day;
	std::string address;
} a[110];
int iterator = 1;
int doCombin(int pos)
{
	if(pos > r)
	{
		for(int i = 1; i < pos; i++)
		{
			if(i == 1)
				a[iterator].nama1 = s[deep[i]];
			else if(i == 2)
				a[iterator].nama2 = s[deep[i]];
			// std::cout << deep[i];

/*			if(i == pos-1)
				std::cout << std::endl;
			else
				std::cout << " ";*/
		}
		//count++;
		iterator++;
	}
	else
	{
		for(int i = deep[pos-1] + 1; i <= n; i++)
		{
			deep[pos] = i;
			doCombin(pos+1);
		}
	}
}

std::string countries[] = {
	"Avengers",
	"Incredible Hulk",
	"Captain America",
	"Black Panther",
	"Age of Ultron",
	"Endgame",
	"Infinity War",
	"Thor: The Dark World",
	"Civil War",
	"Disney"
};

/*
	INSERT INTO `position` (position_code, position_name, valid_from, valid_to)
	VALUES ("POS[1-10]", "Random", "1970-01-01", "9999-01-01")
*/

/*
	employee
	- id: int, primary key, auto increment
	- employee_code: int, primary key
	- employee_name: string
	- birth_date: date
	- address: string
*/

int main()
{
	std::cin >> n;
	for(int i = 1; i <= n; i++)
		std::cin >> s[i];

	doCombin(1);
	for(int i = 1; i <= iterator; i++)
	{
		a[i].year = std::rand() % 99 + 1901;
		a[i].month = std::rand() % 12 + 1;
		a[i].day = std::rand() % 30 + 1;

		a[i].code = a[i].day%10 + a[i].month%10 *10 + a[i].year%100 * 100;

		a[i].address = countries[std::rand() % 10];
	}

	std::cout << iterator << std::endl;
	for(int i = 1; i <= iterator; i++)
	{
		char c1 = a[i].nama1[0];
		char c2 = a[i].nama2[0];
		std::cout << "INSERT INTO `employee` (employee_code, employee_name, birth_date, address)" << std::endl;
		std::cout << "VALUES (" << '"' << c1 << c2 << a[i].code << '"'
						<< ", " << '"' << a[i].nama1 << " " << a[i].nama2 << '"'
						<< ", " << '"' << a[i].year << '-' << a[i].month << '-' << a[i].day << '"'
						<< ", " << '"' << a[i].address << '"' << ");" << std::endl;
	}

	//std::cout << count << std::endl;
/*
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS4225", "Suprapto Sutejo", "1942-12-5", "Avengers");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS6359", "Suprapto Sumarni", "1963-5-19", "Civil War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS3596", "Suprapto Suparman", "1935-9-6", "Endgame");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS1742", "Suprapto Stip", "1917-4-2", "Incredible Hulk");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR2638", "Suprapto Rojers", "1926-3-28", "Infinity War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS1913", "Suprapto Sapidarman", "1919-1-3", "Black Panther");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR9512", "Suprapto Ricardo", "1995-11-22", "Infinity War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM1828", "Suprapto Milos", "1918-12-18", "Infinity War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM2170", "Suprapto Mutejo", "1921-7-10", "Captain America");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS2786", "Suprapto Solihin", "1927-8-26", "Age of Ultron");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS9343", "Sutejo Sumarni", "1993-4-3", "Black Panther");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS5292", "Sutejo Suparman", "1952-9-22", "Incredible Hulk");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS3958", "Sutejo Stip", "1939-5-18", "Age of Ultron");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR9208", "Sutejo Rojers", "1992-10-28", "Disney");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS1200", "Sutejo Sapidarman", "1912-10-20", "Civil War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR4121", "Sutejo Ricardo", "1941-12-21", "Captain America");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM9111", "Sutejo Milos", "1991-11-11", "Captain America");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM5957", "Sutejo Mutejo", "1959-5-27", "Endgame");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS5101", "Sutejo Solihin", "1951-10-11", "Avengers");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS5804", "Sumarni Suparman", "1958-10-4", "Civil War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS2825", "Sumarni Stip", "1928-12-25", "Age of Ultron");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR4697", "Sumarni Rojers", "1946-9-17", "Infinity War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS7255", "Sumarni Sapidarman", "1972-5-25", "Disney");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR7588", "Sumarni Ricardo", "1975-8-18", "Civil War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM8170", "Sumarni Milos", "1981-7-10", "Incredible Hulk");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM8220", "Sumarni Mutejo", "1982-12-20", "Civil War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS3478", "Sumarni Solihin", "1934-7-28", "Infinity War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS9372", "Suparman Stip", "1993-7-12", "Endgame");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR9651", "Suparman Rojers", "1996-5-1", "Disney");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS4808", "Suparman Sapidarman", "1948-10-28", "Captain America");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR2972", "Suparman Ricardo", "1929-7-12", "Infinity War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM8126", "Suparman Milos", "1981-12-16", "Age of Ultron");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM7251", "Suparman Mutejo", "1972-5-21", "Avengers");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS1357", "Suparman Solihin", "1913-5-17", "Avengers");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR2228", "Stip Rojers", "1922-12-8", "Thor: The Dark World");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS1424", "Stip Sapidarman", "1914-12-4", "Black Panther");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR9660", "Stip Ricardo", "1996-6-20", "Civil War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM6613", "Stip Milos", "1966-1-3", "Infinity War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM8414", "Stip Mutejo", "1984-11-4", "Civil War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS1023", "Stip Solihin", "1910-12-13", "Endgame");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("RS8625", "Rojers Sapidarman", "1986-12-25", "Thor: The Dark World");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("RR6646", "Rojers Ricardo", "1966-4-26", "Incredible Hulk");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("RM3932", "Rojers Milos", "1939-3-2", "Infinity War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("RM6957", "Rojers Mutejo", "1969-5-7", "Incredible Hulk");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("RS2549", "Rojers Solihin", "1925-4-19", "Age of Ultron");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SR6574", "Sapidarman Ricardo", "1965-7-24", "Disney");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM8531", "Sapidarman Milos", "1985-3-1", "Civil War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SM1129", "Sapidarman Mutejo", "1911-12-9", "Black Panther");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("SS9788", "Sapidarman Solihin", "1997-8-18", "Incredible Hulk");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("RM5564", "Ricardo Milos", "1955-6-14", "Age of Ultron");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("RM5496", "Ricardo Mutejo", "1954-9-6", "Incredible Hulk");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("RS960", "Ricardo Solihin", "1909-6-20", "Infinity War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("MM2945", "Milos Mutejo", "1929-4-15", "Civil War");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("MS460", "Milos Solihin", "1904-6-20", "Captain America");
INSERT INTO `employee` (employee_code, employee_name, birth_date, address)
VALUES ("MS2824", "Mutejo Solihin", "1928-2-4", "Black Panther");
*/
}