/*
SS4225
1942-12-05
SS6359
1963-05-19
SS3596
1935-09-06
SS1742
1917-04-02
SR2638
1926-03-28
SS1913
1919-01-03
SR9512
1995-11-22
SM1828
1918-12-18
SM2170
1921-07-10
SS2786
1927-08-26
SS9343
1993-04-03
SS5292
1952-09-22
SS3958
1939-05-18
SR9208
1992-10-28
SS1200
1912-10-20
SR4121
1941-12-21
SM9111
1991-11-11
SM5957
1959-05-27
SS5101
1951-10-11
SS5804
1958-10-04
SS2825
1928-12-25
SR4697
1946-09-17
SS7255
1972-05-25
SR7588
1975-08-18
SM8170
1981-07-10
SM8220
1982-12-20
SS3478
1934-07-28
SS9372
1993-07-12
SR9651
1996-05-01
SS4808
1948-10-28
SR2972
1929-07-12
SM8126
1981-12-16
SM7251
1972-05-21
SS1357
1913-05-17
SR2228
1922-12-08
SS1424
1914-12-04
SR9660
1996-06-20
SM6613
1966-01-03
SM8414
1984-11-04
SS1023
1910-12-13
RS8625
1986-12-25
RR6646
1966-04-26
RM3932
1939-03-02
RM6957
1969-05-07
RS2549
1925-04-19
SR6574
1965-07-24
SM8531
1985-03-01
SM1129
1911-12-09
SS9788
1997-08-18
RM5564
1955-06-14
RM5496
1954-09-06
RS9600
1909-06-20
MM2945
1929-04-15
MS4600
1904-06-20
MS2824
1928-02-04

*/

/*
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ()
*/

#include <bits/stdc++.h>
#define INSERTINTO << "\nINSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)\nVALUES (" <<
#define CM << ", " <<
#define ST << '-' <<
#define END << ");"


struct employee
{
	std::string code;
	std::string birth_date;

	std::string position_code;

	int vf_year;
	int vf_month;
	int vf_date;

	int vt_year;
	int vt_month;
	int vt_date;
};
std::vector<employee> v;

std::string code[100];
std::string date[100];

std::string position_code[] = {"POS1", "POS2", "POS3", "POS4", "POS5", "POS6", "POS7", "POS8", "POS9", "POS10"};

int main()
{
	int co;
	std::cin >> co;

	for(int i = 1; i <= co; i++)
		std::cin >> code[i] >> date[i];

	for(int i = 1; i <= co; i++)
	{
		employee temp;
		temp.code = code[i];
		temp.birth_date = date[i];
		// std::cout << i << " = code, birth_date" << std::endl;
		// std::cout << temp.code << " " << temp.birth_date << std::endl;

		// std::cout << "ganti berapa kali?" << std::endl;
		int n;
		// std::cin >> n;
		n = std::rand() %5 +1;

		int temp_year = std::stoi(temp.birth_date.substr(0, 4)) + 25;
		int temp_month = std::rand() %12 + 1;
		int temp_date = std::rand() %30 + 1;
		for(int i = 1; i <= n; i++)
		{
			temp.position_code = position_code[std::rand()%10];
			// std::cout << "position_code = " << temp.position_code << std::endl;;

			temp.vf_year = temp_year;
			temp.vf_month = temp_month;
			temp.vf_date = temp_date;

			temp.vt_year = temp_year + std::rand() %10 + 1;
			temp.vt_month = std::rand() %12 + 1;
			temp.vt_date = std::rand() %30 + 1;

			temp_year = temp.vt_year;
			temp_month = temp.vt_month;
			temp_date = temp.vt_date;

			if(i == n)
			{
				temp.vt_year = 9999;
				temp.vt_month = 1;
				temp.vt_date = 1;
			}
			v.push_back(temp);

			// std::cout << temp.vf_year << "-" << temp.vf_month << "-" << temp.vf_date << " until "
					  // << temp.vt_year << "-" << temp.vt_month << "-" << temp.vt_date << std::endl;
		}
	}

/*
#define INSERTINTO << "INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)\nVALUES (" <<
#define CM << ", " <<
#define ST << '-' <<
#define END << ");"

struct employee
{
	std::string code;
	std::string birth_date;

	std::string position_code;

	int vf_year;
	int vf_month;
	int vf_date;

	int vt_year;
	int vt_month;
	int vt_date;
};
*/

	for(int i = 0; i < v.size(); i++)
	{
		std::cout INSERTINTO '"' << v[i].code << '"'
						  CM '"' << v[i].position_code << '"'
						  CM '"' << v[i].vf_year ST v[i].vf_month ST v[i].vf_date << '"'
						  CM '"' << v[i].vt_year ST v[i].vt_month ST v[i].vt_date << '"'
						  END;
	}

	return 0;

/*
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS4225", "POS1", "1967-12-5", "1977-5-19");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS4225", "POS9", "1977-5-19", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS6359", "POS2", "1988-2-28", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3596", "POS5", "1960-1-22", "1963-10-23");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3596", "POS3", "1963-10-23", "1965-9-9");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3596", "POS6", "1965-9-9", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1742", "POS8", "1942-10-23", "1952-8-25");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1742", "POS4", "1952-8-25", "1954-3-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1742", "POS4", "1954-3-4", "1959-10-2");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1742", "POS4", "1959-10-2", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR2638", "POS10", "1951-10-28", "1955-10-20");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR2638", "POS9", "1955-10-20", "1962-12-21");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR2638", "POS3", "1962-12-21", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1913", "POS7", "1944-5-29", "1950-3-10");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1913", "POS1", "1950-3-10", "1951-7-22");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1913", "POS4", "1951-7-22", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9512", "POS1", "2020-11-7", "2027-9-12");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9512", "POS9", "2027-9-12", "2032-4-27");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9512", "POS4", "2032-4-27", "2040-11-9");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9512", "POS3", "2040-11-9", "2050-6-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9512", "POS6", "2050-6-4", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM1828", "POS4", "1943-10-27", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM2170", "POS10", "1946-5-1", "1954-10-28");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM2170", "POS3", "1954-10-28", "1961-7-12");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM2170", "POS7", "1961-7-12", "1967-12-16");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM2170", "POS5", "1967-12-16", "1969-5-21");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM2170", "POS1", "1969-5-21", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS2786", "POS8", "1952-4-12", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9343", "POS10", "2018-4-6", "2028-3-12");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9343", "POS9", "2028-3-12", "2031-11-27");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9343", "POS1", "2031-11-27", "2035-9-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9343", "POS2", "2035-9-1", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5292", "POS9", "1977-1-18", "1981-8-22");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5292", "POS3", "1981-8-22", "1982-8-27");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5292", "POS5", "1982-8-27", "1983-1-22");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5292", "POS9", "1983-1-22", "1993-1-5");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5292", "POS2", "1993-1-5", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3958", "POS9", "1964-3-1", "1972-12-9");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3958", "POS4", "1972-12-9", "1981-8-18");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3958", "POS2", "1981-8-18", "1982-6-14");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3958", "POS5", "1982-6-14", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9208", "POS10", "2017-9-30", "2024-11-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9208", "POS5", "2024-11-4", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1200", "POS6", "1937-3-16", "1941-4-14");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1200", "POS8", "1941-4-14", "1946-12-9");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1200", "POS1", "1946-12-9", "1955-7-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1200", "POS7", "1955-7-1", "1964-6-30");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1200", "POS9", "1964-6-30", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR4121", "POS9", "1966-11-23", "1976-11-18");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR4121", "POS9", "1976-11-18", "1978-4-29");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR4121", "POS7", "1978-4-29", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM9111", "POS7", "2016-4-19", "2019-3-6");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM9111", "POS4", "2019-3-6", "2029-7-25");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM9111", "POS7", "2029-7-25", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM5957", "POS8", "1984-2-30", "1991-5-30");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM5957", "POS6", "1991-5-30", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5101", "POS9", "1976-2-12", "1978-10-16");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5101", "POS4", "1978-10-16", "1981-2-3");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5101", "POS6", "1981-2-3", "1990-11-28");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5101", "POS8", "1990-11-28", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5804", "POS7", "1983-6-30", "1993-5-13");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5804", "POS6", "1993-5-13", "1999-3-20");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5804", "POS2", "1999-3-20", "2002-2-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5804", "POS9", "2002-2-1", "2006-12-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS5804", "POS10", "2006-12-4", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS2825", "POS10", "1953-2-7", "1957-12-28");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS2825", "POS7", "1957-12-28", "1964-2-9");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS2825", "POS3", "1964-2-9", "1970-7-25");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS2825", "POS2", "1970-7-25", "1977-8-27");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS2825", "POS4", "1977-8-27", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR4697", "POS3", "1971-1-9", "1977-6-7");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR4697", "POS2", "1977-6-7", "1986-7-23");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR4697", "POS2", "1986-7-23", "1991-1-3");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR4697", "POS10", "1991-1-3", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS7255", "POS10", "1997-3-15", "2000-4-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS7255", "POS5", "2000-4-4", "2005-3-6");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS7255", "POS10", "2005-3-6", "2012-10-5");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS7255", "POS3", "2012-10-5", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR7588", "POS3", "2000-7-12", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8170", "POS5", "2006-1-25", "2009-12-14");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8170", "POS1", "2009-12-14", "2017-2-19");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8170", "POS8", "2017-2-19", "2021-3-24");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8170", "POS9", "2021-3-24", "2024-6-13");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8170", "POS1", "2024-6-13", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8220", "POS4", "2007-12-16", "2012-8-3");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8220", "POS2", "2012-8-3", "2014-8-13");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8220", "POS6", "2014-8-13", "2018-10-12");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8220", "POS3", "2018-10-12", "2021-3-27");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8220", "POS5", "2021-3-27", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3478", "POS1", "1959-3-21", "1965-6-2");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3478", "POS1", "1965-6-2", "1972-12-26");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3478", "POS1", "1972-12-26", "1973-3-26");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS3478", "POS5", "1973-3-26", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9372", "POS2", "2018-3-23", "2025-11-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9372", "POS2", "2025-11-4", "2030-11-25");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9372", "POS10", "2030-11-25", "2033-5-28");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9372", "POS1", "2033-5-28", "2040-11-18");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9372", "POS1", "2040-11-18", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9651", "POS10", "2021-7-25", "2024-11-16");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9651", "POS8", "2024-11-16", "2032-3-16");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9651", "POS8", "2032-3-16", "2042-9-14");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9651", "POS1", "2042-9-14", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS4808", "POS6", "1973-6-2", "1979-5-11");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS4808", "POS3", "1979-5-11", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR2972", "POS8", "1954-4-22", "1958-5-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR2972", "POS5", "1958-5-1", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8126", "POS1", "2006-3-30", "2010-11-29");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8126", "POS6", "2010-11-29", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM7251", "POS1", "1997-8-24", "2005-9-28");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM7251", "POS9", "2005-9-28", "2009-8-2");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM7251", "POS1", "2009-8-2", "2010-1-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM7251", "POS5", "2010-1-4", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1357", "POS3", "1938-8-17", "1939-8-26");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1357", "POS7", "1939-8-26", "1946-7-28");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1357", "POS7", "1946-7-28", "1954-10-22");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1357", "POS10", "1954-10-22", "1956-9-3");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1357", "POS8", "1956-9-3", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR2228", "POS10", "1947-6-4", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1424", "POS4", "1939-1-6", "1942-9-5");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1424", "POS5", "1942-9-5", "1945-2-30");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1424", "POS3", "1945-2-30", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9660", "POS9", "2021-8-18", "2027-3-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR9660", "POS3", "2027-3-4", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM6613", "POS2", "1991-4-6", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8414", "POS9", "2009-8-1", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1023", "POS7", "1935-6-15", "1939-1-26");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1023", "POS3", "1939-1-26", "1948-6-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1023", "POS4", "1948-6-1", "1950-8-16");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1023", "POS3", "1950-8-16", "1953-12-8");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS1023", "POS5", "1953-12-8", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RS8625", "POS4", "2011-2-21", "2017-9-9");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RS8625", "POS1", "2017-9-9", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RR6646", "POS1", "1991-6-12", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM3932", "POS6", "1964-10-11", "1968-7-22");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM3932", "POS1", "1968-7-22", "1973-3-6");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM3932", "POS10", "1973-3-6", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM6957", "POS6", "1994-4-20", "2003-1-28");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM6957", "POS10", "2003-1-28", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RS2549", "POS1", "1950-10-30", "1954-3-22");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RS2549", "POS8", "1954-3-22", "1960-8-24");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RS2549", "POS3", "1960-8-24", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR6574", "POS8", "1990-7-29", "1995-8-7");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR6574", "POS9", "1995-8-7", "1996-12-28");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR6574", "POS5", "1996-12-28", "2000-6-14");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR6574", "POS7", "2000-6-14", "2004-11-2");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SR6574", "POS10", "2004-11-2", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8531", "POS5", "2010-10-2", "2019-5-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8531", "POS6", "2019-5-1", "2025-4-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8531", "POS3", "2025-4-4", "2034-4-25");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8531", "POS9", "2034-4-25", "2036-9-24");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM8531", "POS6", "2036-9-24", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM1129", "POS10", "1936-6-23", "1942-6-15");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM1129", "POS6", "1942-6-15", "1943-2-9");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM1129", "POS9", "1943-2-9", "1944-2-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SM1129", "POS3", "1944-2-4", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("SS9788", "POS4", "2022-4-22", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5564", "POS9", "1980-12-16", "1984-4-19");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5564", "POS4", "1984-4-19", "1992-6-4");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5564", "POS10", "1992-6-4", "1994-5-3");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5564", "POS9", "1994-5-3", "1995-6-19");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5564", "POS5", "1995-6-19", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5496", "POS1", "1979-4-11", "1988-8-7");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5496", "POS4", "1988-8-7", "1994-7-6");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5496", "POS9", "1994-7-6", "1998-10-5");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5496", "POS9", "1998-10-5", "2002-12-8");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RM5496", "POS7", "2002-12-8", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RS9600", "POS6", "1934-8-26", "1936-2-17");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("RS9600", "POS5", "1936-2-17", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("MM2945", "POS7", "1954-10-3", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("MS4600", "POS5", "1929-2-10", "1935-11-23");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("MS4600", "POS6", "1935-11-23", "9999-1-1");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("MS2824", "POS5", "1953-6-5", "1960-5-27");
INSERT INTO `employee_position` (employee_code, position_code, valid_from, valid_to)
VALUES ("MS2824", "POS9", "1960-5-27", "9999-1-1");
*/
}