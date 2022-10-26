#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class S
{
public:
	S()
	{
		_a1 = 0;
	}
	S& operator++()
	{
		++_a1;
		return *this;
	}
	S operator++(int)
	{
		S tmp(*this);
		++_a1;
		return tmp;
	}
	friend ostream& operator<<(ostream& out, const S& s);
private:
	int _a1;
};

ostream& operator<<(ostream& out, const S& s)
{
	out << s._a1;
	return out;
}

class Solution
{

public:
	bool pop_sequence(vector<int> push, vector <int> pop)
	{
		stack<int> tmp;
		int i = 0;
		int j = 0;
		while (j < push.size() && i < pop.size())
		{
			while (j < push.size() && (tmp.empty() || tmp.top() != pop[i]))
			{
				tmp.push(push[j]);
				++j;
			}
			while(!tmp.empty() && i < pop.size() && tmp.top() == pop[i])
			{
				tmp.pop();
				++i;
			}
		}
		return tmp.empty();
	}
};



int main()
{
	int arr[] = { 5,2,45,235,325 };
	sort(arr, arr + 5, greater<int>());
	for (auto e : arr)
	{
		cout << e << " ";
	}
	vector<int>::iterator i;
	std::vector<int>::const_iterator ci = i;
	//Test<vector<int>> a1;
	//S s1;
	//cout << s1++ << endl;
	return 0;
}

