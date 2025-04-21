#include <iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;

public:

	Time(int h_val = 0, int m_val = 0) : hours(h_val), minutes(m_val) {}

	Time(const Time& rhs) {
		this->hours = rhs.hours;
		this->minutes = rhs.minutes;
	}

	~Time() {}

	void print() {
		cout << hours << ":" << minutes << endl;
	}

	friend Time operator+(const Time& t1, const Time& t2) {
		Time t;

		t.minutes = t1.minutes + t2.minutes;
		t.hours =  t1.hours + t2.hours + (t.minutes / 60);

		if (t.hours >= 24) t.hours = t.hours % 24;

		t.minutes = t.minutes % 60;
		

		return t;
	}

	friend ostream& operator<<(ostream& out, const Time& rhs) {
		if (rhs.hours < 10 && rhs.minutes < 10) {
			out << "0" << rhs.hours << ":0" << rhs.minutes << "";
		}
		else if (rhs.hours < 10 && rhs.minutes >= 10) {
			out << "0" << rhs.hours << ":" << rhs.minutes << "";
		}
		else if (rhs.hours >= 10 && rhs.minutes < 10) {
			out << rhs.hours << ":0" << rhs.minutes << "";
		}
		else if (rhs.hours >= 10 && rhs.minutes >= 10) {
			out << rhs.hours << ":" << rhs.minutes << "";
		}
		return out;
	}

	friend bool operator==(const Time& t1, const Time& t2) {
		return t1.hours == t2.hours && t1.minutes == t2.minutes;
	}
};

int main(void)
{
	Time t1(21, 10);
	Time t2(7, 5);

	Time t3 = t1 + t2;

	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;

	if (t3 == Time(4, 15))
		cout << "동일한 시간 입니다." << endl;
	else
		cout << "다른 시간 입니다." << endl;


	return 0;
}