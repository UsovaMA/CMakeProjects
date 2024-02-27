#include <iostream>

enum Status { SUCCESS, ERROR, WARNING };

struct Time {
	int hours;
	int minutes;
	int seconds;
};

Status input(Time* time) {
	Status state = SUCCESS;
	char colon;
	std::cin >> time->hours >> colon
	>> time->minutes >> colon
	>> time->seconds;
	/*
	state = check(&time);
	if (state == ERROR) {
	   time = nullptr;
	}
	*/
	return state;
}

Status set_values(Time* time, int hours, int minutes, int seconds) {
	Status state = SUCCESS;
	time->hours = hours;
	time->minutes = minutes;
	time->seconds = seconds;
	return state;
}

Status check(const Time* time);
Status convert(Time* time);
// 12:32:78 -> 12:33:18 SUCCESS
// 23:60:78 -> 00:01:18 WARNING
// 78:11:19 -> ERROR

// + sub
Status add_hours(Time* time, int hours);
Status add_minutes(Time* time, int minutes);
Status add_seconds(Time* time, int seconds);

// 12:33:18 +4 hours -> 16:33:18 SUCCESS
// 20:33:18 +4 hours -> 24:33:18 = 00:33:18 WARNING
// 78:11:19 +4 hours -> ERROR

// 1 - time1 > time2, 0 - time1 == time2, -1 time1 < time2
int compare(const Time* time1, const Time* time2);

// time1 = time2
Status assign(Time *time1, const Time *time2) {
	Status state = SUCCESS;
	if (time2 == nullptr) {
		state = ERROR;
	} else {
		time1->hours = time2->hours;
		time1->minutes = time2->minutes;
		time1->seconds = time2->seconds;
	}
	return state;
}

Status output(const Time* time) {
	Status state = SUCCESS;
	if (time == nullptr) {
		state = ERROR;
	} else {
		std::cout << time->hours << ":"
			<< time->minutes << ":"
			<< time->seconds;
	}
	return state;
}

int main() {
	Time time1 = {11, 12, 57}, time2;
	output(&time1);
	assign(&time2, &time1);
	output(&time2);
	input(&time1);
	output(&time1);
	set_values(&time2, 6, 12, 32);
	output(&time2);
	return 0;
}