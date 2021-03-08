// Exercise #2 Katuuk Christian Everhard
// OBJECT ORIENTED PROGRAMMING


#include <iostream>

using namespace std;

class time{
	private:
		int hours,minutes,seconds;
	public:
		time(){
			this->hours = 0;
			this->minutes = 0;
			this->seconds = 0;
		}
		time(int hours, int minutes, int seconds){
			this->hours = hours;
			this->minutes = minutes;
			this->seconds = seconds;
		}
		int gethours(){
			return this->hours;
		}
		int getminutes(){
			return this->minutes;
		}
		int getseconds(){
			return this->seconds;
		}
		
void display(){
	cout << hours << ":" << minutes << ":" << seconds << endl;
}
time add(time time1, time time2) {
int hoursAdd = time1.gethours() + time2.gethours();
	if (hoursAdd > 23) {
		hoursAdd -= 24;
}
int minutesAdd = time1.getminutes() + time2.getminutes();
	if (minutesAdd > 59) {
		minutesAdd -= 60;
			hoursAdd += 1;
}
int secondsAdd = time1.getseconds() + time2.getseconds();
if (secondsAdd > 59) {
secondsAdd -= 60;
minutesAdd += 1;
}

time time3(hoursAdd, minutesAdd, secondsAdd);
return time3;
}

};

int main() {
time time1(12, 40, 30);
time time2(21, 23, 43);
time time3;
time3 = time3.add(time1, time2);
time1.display();
time2.display();
time3.display();
return 0;
} 
