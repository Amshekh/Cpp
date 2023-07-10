class Student
{
public:
	explicit Student(float s) //Cannot be use for conversion.
	{
		id = 0;
		score = s;
	}

	float GetScore() const
	{
		return score;
	}

	void SetScore(float value)
	{
		score = value;
	}

	long GetId() const
	{
		static long count;

		if(id == 0)
			id = ++count;

		return id;
	}

	static const Student* BestStudent()
	{
		static Student best(100);

		return &best;
	}

private:
	mutable long id;
	float score;
};




















