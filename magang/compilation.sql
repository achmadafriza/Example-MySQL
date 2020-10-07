ALTER TABLE employee ADD company_code VARCHAR(255) AFTER employee_code;
UPDATE employee
SET company_code = (
SELECT company_code
FROM company
);


SELECT employee.company_code, company.company_name, employee.employee_code, employee.employee_name,
(
	SELECT position.position_name
	FROM position
	WHERE employee_position.position_code = position.position_code
) AS position_name, employee_position.valid_from, employee_position.valid_to
FROM employee
INNER JOIN company ON employee.company_code = company.company_code
INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
WHERE employee_position.position_code IN (
	SELECT position_code
	FROM position
	WHERE position_name IN ("IT Auditor", "IT Staff")
)
ORDER BY employee_position.position_code

v

SELECT employee.company_code, company.company_name, employee.employee_code, employee.employee_name,
position.position_name, employee_position.valid_from, employee_position.valid_to
FROM employee
INNER JOIN company ON employee.company_code = company.company_code
INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
INNER JOIN position ON position.position_code = employee_position.position_code
WHERE position.position_name IN ("IT Auditor", "IT Staff") AND employee_position.valid_to >= '2019-05-13'
ORDER BY position.position_code

-----------------------------------------------------------------------------------------------------------

UPDATE employee_position
INNER JOIN position ON employee_position.position_code = position.position_code
SET employee_position.position_code = (
SELECT position_code
FROM position
WHERE position_name = "Software Developer"
)
WHERE position.position_name IN ("IT Auditor", "IT Staff") AND employee_position.valid_to >= '2019-05-13'

SELECT employee.company_code, company.company_name, employee.employee_code, employee.employee_name,
position.position_name, employee_position.valid_from, employee_position.valid_to
FROM employee
INNER JOIN company ON employee.company_code = company.company_code
INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
INNER JOIN position ON position.position_code = employee_position.position_code
WHERE position.position_name IN ("Software Developer") AND employee_position.valid_to >= '2019-05-13'
ORDER BY position.position_code

-----------------------------------------------------------------------------------------------------------

INSERT INTO employee_position(employee_code, position_code, valid_from, valid_to)
SELECT employee_code, position_code, valid_from, valid_to
FROM employee_position

-----------------------------------------------------------------------------------------------------------

/*
kalo dia "Active" (tanggal sekarang ada diantara valid from & valid to), di kolomnya muncul "Active"
vice versa.
*/

SELECT employee.company_code, company.company_name, employee.employee_code, employee.employee_name,
position.position_name, (
CASE
	WHEN CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
		THEN "ACTIVE"
	ELSE "NOT ACTIVE" END
) AS 'Validity'
FROM employee
INNER JOIN company ON employee.company_code = company.company_code
INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
INNER JOIN position ON position.position_code = employee_position.position_code
WHERE position.position_name IN ("Software Developer") AND employee_position.valid_to >= '2019-05-13'
ORDER BY Validity

SELECT employee.company_code, company.company_name, employee.employee_code, employee.employee_name,
position.position_name, IF(CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to, "Active", "Not Active") AS 'validity'
FROM employee
INNER JOIN company ON employee.company_code = company.company_code
INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
INNER JOIN position ON position.position_code = employee_position.position_code
WHERE position.position_name IN ("Software Developer") AND employee_position.valid_to >= '2019-05-13'
ORDER BY validity

-----------------------------------------------------------------------------------------------------------
SELECT distinct if(employee_position.position_code = "POS1", employee.employee_name, NULL) AS position_1,
					 if(employee_position.position_code = "POS2", employee.employee_name, NULL) AS position_2,
					 if(employee_position.position_code = "POS3", employee.employee_name, NULL) AS position_3,
					 if(employee_position.position_code = "POS4", employee.employee_name, NULL) AS position_4,
					 if(employee_position.position_code = "POS5", employee.employee_name, NULL) AS position_5,
					 if(employee_position.position_code = "POS6", employee.employee_name, NULL) AS position_6,
					 if(employee_position.position_code = "POS7", employee.employee_name, NULL) AS position_7,
					 if(employee_position.position_code = "POS8", employee.employee_name, NULL) AS position_8,
					 if(employee_position.position_code = "POS9", employee.employee_name, NULL) AS position_9,
					 if(employee_position.position_code = "POS10", employee.employee_name, NULL) AS position_10
FROM employee
INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
INNER JOIN position ON position.position_code = employee_position.position_code;

SELECT DISTINCT (if employee_position.position_code = "POS1" then employee.employee_name) AS position_1,
					 (if employee_position.position_code = "POS2" then employee.employee_name) AS position_2,
					 (if employee_position.position_code = "POS3" then employee.employee_name) AS position_3,
					 (if employee_position.position_code = "POS4" then employee.employee_name) AS position_4,
					 (if employee_position.position_code = "POS5" then employee.employee_name) AS position_5,
					 (if employee_position.position_code = "POS6" then employee.employee_name) AS position_6,
					 (if employee_position.position_code = "POS7" then employee.employee_name) AS position_7,
					 (if employee_position.position_code = "POS8" then employee.employee_name) AS position_8,
					 (if employee_position.position_code = "POS9" then employee.employee_name) AS position_9,
					 (if employee_position.position_code = "POS10" then employee.employee_name) AS position_10,
FROM employee
INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
INNER JOIN position ON position.position_code = employee_position.position_code

----------------------------

SELECT IFNULL(TABLE1.position_1, " ") POS1, IFNULL(TABLE2.position_2, " ") POS2, IFNULL(TABLE3.position_3, " ") POS3, IFNULL(TABLE4.position_4, " ") POS4, IFNULL(TABLE5.position_5, " ") POS5,
		 IFNULL(TABLE6.position_6, " ") POS6, IFNULL(TABLE7.position_7, " ") POS7, IFNULL(TABLE8.position_8, " ") POS8, IFNULL(TABLE9.position_9, " ") POS9, IFNULL(TABLE10.position_10, " ") POS10
FROM (
	SELECT (
		case
			when if(employee_position.position_code = "POS1", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t1 := @t1 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS1", employee.employee_name, NULL) AS position_1
	FROM (SELECT @t1 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS1", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE1
RIGHT JOIN (
	SELECT (
		case
			when if(employee_position.position_code = "POS2", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t2 := @t2 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS2", employee.employee_name, NULL) AS position_2
	FROM (SELECT @t2 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS2", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE2 ON TABLE1.row_num = TABLE2.row_num
RIGHT JOIN (
	SELECT (
		case
			when if(employee_position.position_code = "POS3", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t3 := @t3 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS3", employee.employee_name, NULL) AS position_3
	FROM (SELECT @t3 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS3", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE3 ON TABLE2.row_num = TABLE3.row_num
LEFT JOIN (
	SELECT (
		case
			when if(employee_position.position_code = "POS4", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t4 := @t4 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS4", employee.employee_name, NULL) AS position_4
	FROM (SELECT @t4 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS4", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE4 ON TABLE3.row_num = TABLE4.row_num
LEFT JOIN (
	SELECT (
		case
			when if(employee_position.position_code = "POS5", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t5 := @t5 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS5", employee.employee_name, NULL) AS position_5
	FROM (SELECT @t5 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS5", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE5 ON TABLE3.row_num = TABLE5.row_num
LEFT JOIN (
	SELECT (
		case
			when if(employee_position.position_code = "POS6", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t6 := @t6 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS6", employee.employee_name, NULL) AS position_6
	FROM (SELECT @t6 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS6", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE6 ON TABLE3.row_num = TABLE6.row_num
LEFT JOIN (
	SELECT (
		case
			when if(employee_position.position_code = "POS7", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t7 := @t7 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS7", employee.employee_name, NULL) AS position_7
	FROM (SELECT @t7 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS7", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE7 ON TABLE3.row_num = TABLE7.row_num
LEFT JOIN (
	SELECT (
		case
			when if(employee_position.position_code = "POS8", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t8 := @t8 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS8", employee.employee_name, NULL) AS position_8
	FROM (SELECT @t8 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS8", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE8 ON TABLE3.row_num = TABLE8.row_num
LEFT JOIN (
	SELECT (
		case
			when if(employee_position.position_code = "POS9", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t9 := @t9 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS9", employee.employee_name, NULL) AS position_9
	FROM (SELECT @t9 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS9", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE9 ON TABLE3.row_num = TABLE9.row_num
LEFT JOIN (
	SELECT (
		case
			when if(employee_position.position_code = "POS10", employee.employee_name, NULL) IS NOT NULL
				  AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to then @t10 := @t10 + 1
			ELSE NULL END
	) AS row_num, if(employee_position.position_code = "POS10", employee.employee_name, NULL) AS position_10
	FROM (SELECT @t10 := 0) AS m, employee
	INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
	INNER JOIN position ON position.position_code = employee_position.position_code
	WHERE if(employee_position.position_code = "POS10", employee.employee_name, NULL) IS NOT NULL
			AND CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to
	ORDER BY row_num
) AS TABLE10 ON TABLE3.row_num = TABLE10.row_num;

------------------

-- JAVA TESTING QUERIES

jdbc:mysql://localhost:3306/mydb?allowPublicKeyRetrieval=true&useSSL=false&serverTimezone=UTC

SELECT employee.company_code, company.company_name, employee.employee_code, employee.employee_name,
position.position_name, IF(CURDATE() BETWEEN employee_position.valid_from AND employee_position.valid_to, "Active", "Not Active") AS 'validity'
FROM employee
INNER JOIN company ON employee.company_code = company.company_code
INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
INNER JOIN position ON position.position_code = employee_position.position_code
WHERE employee_position.valid_to >= '2019-05-13'
ORDER BY validity;

SELECT employee.company_code, company.company_name, employee.employee_code, employee.employee_name,
position.position_name, employee_position.valid_from, employee_position.valid_to
FROM employee
INNER JOIN company ON employee.company_code = company.company_code
INNER JOIN employee_position ON employee.employee_code = employee_position.employee_code
INNER JOIN position ON position.position_code = employee_position.position_code
WHERE employee_position.valid_to >= '2019-05-13'
ORDER BY position.position_code