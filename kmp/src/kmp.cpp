#include "kmp.h"

KMP::KMP(string base_s_in, string find_s_in)
{
	if(base_s_in.size() <= 0 || find_s_in.size() <= 0)
	{
		cout << "Wrong In " << __func__ << ": " << __LINE__ << endl;
	}
	base_s = base_s_in;
	find_s = find_s_in;
	cout << "base_s: " << base_s << " find_s: " << find_s << endl;

	if(find_s.size() > 0)
	{
		next = new int[find_s.size()];
		GetNext();
		GetAllKMP();
	}
}

void KMP::GetAllKMP()
{
	int i = 0, j = 0;
	int base_len = this->base_s.size();
	int find_len = this->find_s.size();
	while(i < base_len && j < find_len)
	{
		if(j == -1 || this->base_s.at(i) == this->find_s.at(j))
		{
			i++;
			j++;
		}
		else
		{
			j = this->next[j];
		}
		if(j == find_len)
		{
			cout << "Find : " << i-j << endl;
			this->all_get_num.push_back(i-j);
			++i;
			j = 0;
		}
	}
}

void KMP::GetNext()
{
	int find_s_len = this->find_s.size();
	int i = 0;   // find_s 的下标
	int j = -1;
	this->next[0] = -1;

	while(i < find_s_len - 1)
	{
		if (j == -1 || this->find_s[i] == this->find_s[j])
		{
			i++;
			j++;
			this->next[i] = j;
		}
		else
		{
			j = this->next[j];
		}
	}
};





