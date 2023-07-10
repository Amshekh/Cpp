#include "student.h"
#include <iostream>

using namespace std;

int main(void)
{
	const Student* bs = Student::BestStudent();

	Student* bs1 = const_cast<Student*>(bs);
	bs1->SetScore(85);

	struct _Student
	{
		long id;
		float score;
	};
	_Student* bs2 = reinterpret_cast<_Student*>(bs1);
	bs2->id = 10;
	
	cout << "Best student's ID is "
		 << bs->GetId()
		 << " and Score is "
		 << bs->GetScore()
		 << endl;
}








