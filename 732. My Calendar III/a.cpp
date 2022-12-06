/* 732. My Calendar III */

/*
A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

You are given some events [startTime, endTime), after each given event, return an integer k representing the maximum k-booking between all the previous events.

Implement the MyCalendarThree class:

MyCalendarThree() Initializes the object.
int book(int startTime, int endTime) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.

Example 1:

Input
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, 1, 1, 2, 3, 3, 3]

Explanation
MyCalendarThree myCalendarThree = new MyCalendarThree();
myCalendarThree.book(10, 20); // return 1
myCalendarThree.book(50, 60); // return 1
myCalendarThree.book(10, 40); // return 2
myCalendarThree.book(5, 15); // return 3
myCalendarThree.book(5, 10); // return 3
myCalendarThree.book(25, 55); // return 3

Constraints:

0 <= startTime < endTime <= 10^9
At most 400 calls will be made to book.

*/

#include <iostream>
#include <map>

using namespace std;

class MyCalendarThree {
public:
	MyCalendarThree() {

	}
	
	int book(int startTime, int endTime) {
		int ans = 0, maxBook = 0;
		cnt[startTime]++;
		cnt[endTime]--;
		for (auto &[_,freq] : cnt)
		{
			maxBook += freq;
			ans = max(ans, maxBook);
		}
		return ans;
	}
private:
	map<int,int> cnt;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */

int main()
{
	cout << "Hello! leetcode 732\n";

	MyCalendarThree *myCalendarThree = new MyCalendarThree();
	int param_1 = myCalendarThree->book(10, 20); // return True, The event can be booked. 
	int param_2 = myCalendarThree->book(50, 60); // return True, The event can be booked. 
	int param_3 = myCalendarThree->book(10, 40); // return True, The event can be double booked. 
	int param_4 = myCalendarThree->book(5 , 15); // return False, The event cannot be booked, because it would result in a triple booking.
	int param_5 = myCalendarThree->book(5 , 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
	int param_6 = myCalendarThree->book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.

	cout << param_1 << ' ';
	cout << param_2 << ' ';
	cout << param_3 << ' ';
	cout << param_4 << ' ';
	cout << param_5 << ' ';
	cout << param_6 << ' ';
	cout << endl;
}