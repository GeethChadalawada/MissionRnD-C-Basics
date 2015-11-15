/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isValid(int d1, int m1, int y1, int d2, int m2, int y2)
{
	if (d1 <= 0 || d1 > 31 || d2 <= 0 || d2 > 31 || m1 <= 0 || m1 > 12 || m2 <= 0 || m2 > 12 || y1 == 0 || y2 == 0)
		return -1;

	switch (m1)
	{
	case 2:
		if (d1 == 29 && y1 % 4 != 0)
			return -1;
		else if (d1 > 28)
			return -1;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		if (d1 == 31)
			return -1;
		break;
	}

	switch (m2)
	{
	case 2:
		if (d2 == 29 && y2 % 4 != 0)
			return -1;
		else if (d2 > 28)
			return -1;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		if (d2 == 31)
			return -1;
		break;
	}

	return 1;
}

int isOlder(char *dob1, char *dob2)
{
	int date1 = 0, month1 = 0, year1 = 0, date2 = 0, month2 = 0, year2 = 0, age = -1, i = 0;

	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-')
		return -1;

	while (*(dob1 + i) != '-')
	{
		if (dob1[i] <= '0' || dob1[i] >= '9')
			return -1;

		date1 = (date1 * 10) + (*(dob1 + i) - '0');
		i++;
	}

	i++;

	while (*(dob1 + i) != '-')
	{
		if (dob1[i] <= '0' || dob1[i] >= '9')
			return -1;

		month1 = (month1 * 10) + (*(dob1 + i) - '0');
		i++;
	}

	i++;

	while (*(dob1 + i) != '\0')
	{
		if (dob1[i] <= '0' || dob1[i] >= '9')
			return -1;

		year1 = (year1 * 10) + (*(dob1 + i) - '0');
		i++;
	}



	i = 0;

	while (*(dob2 + i) != '-')
	{
		if (dob2[i] <= '0' || dob2[i] >= '9')
			return -1;

		date2 = (date2 * 10) + (*(dob2 + i) - '0');
		i++;
	}

	i++;

	while (*(dob2 + i) != '-')
	{
		if (dob2[i] <= '0' || dob2[i] >= '9')
			return -1;

		month2 = (month2 * 10) + (*(dob2 + i) - '0');
		i++;
	}

	i++;

	while (*(dob2 + i) != '\0')
	{
		if (dob2[i] <= '0' || dob2[i] >= '9')
			return -1;

		year2 = (year2 * 10) + (*(dob2 + i) - '0');
		i++;
	}

	i = isValid(date1, month1, year1, date2, month2, year2);

	if (i == -1)
		return -1;

	if (year1 > year2)
		return 2;
	else if (year1 < year2)
		return 1;
	else
	{
		if (month1 > month2)
			return 2;
		else if (month1 < month2)
			return 1;
		else
		{
			if (date1 > date2)
				return 2;
			else if (date1 < date2)
				return 1;
			else
				return 0;
		}
	}

	return age;
}
