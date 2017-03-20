class Date{
private:
	short day;
	short month;
	short year;

public:
	Date();
	Date(short, short, short);
	short getDay();
	short getMonth();
	short getYear();
	void setDay(short);
	void setMonth(short);
	void setYear(short);
	bool isLeapYear();
	short GetDaysInMonth();
	bool IsValidDate();
	void printDate();

	bool isEqual(Date d);
	void addDays(short);
	void subDays(short);
};
