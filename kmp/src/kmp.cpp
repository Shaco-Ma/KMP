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
	//总长度
	int base_len = this->base_s.size();
	//需要查询的字串长度
	int find_len = this->find_s.size();
	while(i < base_len && j < find_len)
	{
		//j = -1,只有在j=0的时候,就是对比find_s的第0个都不一样,就直接往后移动,此时base_s就移动下一位,二find_s则从0开始
		//对比是否相同,或者如果是j=-1,证明对比不对,往后移动
		if(j == -1 || this->base_s.at(i) == this->find_s.at(j))
		{
			i++;
			j++;
		}
		else
		{
			// 当前字符匹配失败，进行跳转
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
/*
   012345
   size = 6
   ABCABC
   next[0] = -1;
   i=0,j=-1,,执行1,此时i=1,j=0,next[1] = 0;
   i=1,j=0,find_s[1](B) != find_s[0](A),执行2,此时i=1,j=0,j=next[0]=-1
   i=1,j=-1,执行1,此时,i=2,j=0,next[2]=j=0;
   i=2,j=0,fins_s[2](C) != find_s[0](A),执行2,此时i=2,j=next[0]=-1;
   i=2,j=-1,执行1,此时i=3,j=0,next[3]=j=0
   i=3,j=0,fins_s[3](A) == find_s[0](A),执行1,此时开始处理偏移量了,i=4,j=1,next[i=4] = j = 1
   i=4,j=1,fins_s[4](B) == find_s[1](B),执行1,同样处理偏移,i=5,j=2,这是最后一个了,next[i=5] = j = 2
   -1
   0
   0
   0
   1
   2
   结束
*/

void KMP::GetNext()
{
	int find_s_len = this->find_s.size();
	int i = 0;   // find_s 的下标
	int j = -1;
	this->next[0] = -1;

	while(i < find_s_len - 1)
	{
		//1
		if (j == -1 || this->find_s[i] == this->find_s[j])
		{
			i++;
			j++;
			this->next[i] = j;
		}
		//2
		else
		{
			j = this->next[j];
		}
	}
};





