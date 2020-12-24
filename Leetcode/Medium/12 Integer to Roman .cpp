string inline resolve(int &n) // it would be faster to take the idea of binary search in the ifs
{
	/*
	"I" 1
	"IV" 4
	"V" 5
	"IX" 9
	"X" 10//
	"XL" 40
	"L" 50
	"XC" 90//
	"C" 100
	"CD" 400
	"D" 500//
	"CM" 900
	"M" 1000
	*/

	if (n >= 1000)
	{
		n -= 1000;
		return "M";
	}
	if (n >= 900)
	{
		n -= 900;
		return "CM";
	}
	if (n >= 500)
	{
		n -= 500;
		return "D";
	}
	if (n >= 400)
	{
		n -= 400;
		return "CD";
	}
	if (n >= 100)
	{
		n -= 100;
		return "C";
	}
	if (n >= 90)
	{
		n -= 90;
		return "XC";
	}
	if (n >= 50)
	{
		n -= 50;
		return "L";
	}
	if (n >= 40)
	{
		n -= 40;
		return "XL";
	}
	if (n >= 10)
	{
		n -= 10;
		return "X";
	}
	if (n >= 9)
	{
		n -= 9;
		return "IX";
	}
	if (n >= 5)
	{
		n -= 5;
		return "V";
	}
	if (n >= 4)
	{
		n -= 4;
		return "IV";
	}
	if (n >= 1)
	{
		n--;
		return "I";
	}
	return "";
}
string intToRoman(int num)
{
	string roman = "";
	while (num)
	{
		roman += resolve(num);
	}
	return roman;
}