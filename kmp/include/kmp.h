#ifndef _KMP_H_
#define _KMP_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
https://segmentfault.com/a/1190000008575379
A  B C D A B C D E F A B C D A B C D A G
-1 0 0 0 0 1 2 3 4 0 0 1 2 3 4 5 6 7 8 5
计算next的是,当前字串的之前的字符串,计算出来所有的真前缀和真后缀,找出相同的字串,计算当前字串的长度,就是改next[n]的值
默认第零个为-1,从第一个字符开始,第一个字符为B,所有B前面的为字串为A,真前缀为0,真后缀为0,所以为0
第二个,AB的真前缀为A,真后缀为B,为0
到第五个,当前字符的前面的字符串为ABCDA,真前缀为A, AB, ABC, ABCD,真后缀为BCDA, CDA, DA, A,最长的为A,为1
以此类推
最后一个是前面字符串是ABCDACBCDEFABCDABCDA, 真前缀 A, AB, ABCD, ABCDA, ABCDAB, ABCDABC, ABCDABCDE, ABCDABCDEF, ABCDABCDEFA, ABCDABCDEFAB, ABCDABCDEFABC, ABCDABCDEFABCD, 
ABCDABCDEFABCDA, ABCDABCDEFABCDAB, ABCDABCDEFABCDABC, ABCDABCDEFABCDABCD, 真后缀为 BCDABCDEFABCDABCDA, CDABCDEFABCDABCDA, DABCDEFABCDABCDA, ABCDEFABCDABCDA, BCDEFABCDABCDA, 
CDEFABCDABCDA, DEFABCDABCDA, EFABCDABCDA, FABCDABCDA, ABCDABCDA, BCDABCDA, CDABCDA, DABCDA, ABCDA, BCDA, CDA, DA, D, 相同为ABCDA,长度为5

 0 1 2 3 4 5 6 7 8
 A B C D A B C A B
-1 0 0 0 0 1 2 3 1

next数组的值表示的是被查找字符串的这一位不同的时候,需要从被查找字符串[next数组的值]处开始查找
比如上面的那个,如果查找到find_s[5]不一样了,next[5], 证明至少是前面的A是相同的,而find_s的第一个A是开头处的,那么移动到 find_s[next[5]]继续对比
*/

class KMP
{
	public:
		KMP(string, string);
		~KMP(){
			if(this->next != nullptr)
			{
				delete [] this->next;
			}
		};
		size_t return_find_s_size()
		{
			return this->find_s.size();
		}
		string &return_find_s()
		{
			return this->find_s;
		}
		void print_all_get_item()
		{
			if(this->next == nullptr)
			{
				cout << "this->next == nullptr !" << endl;
				return;
			}
			if(this->find_s.size() == 0 || this->base_s.size() == 0)
			{
				cout << "this->find_s.size() == 0 || this->base_s.size() == 0!" << endl;
				return;
			}
			for(auto item : all_get_num)
			{
				cout << "postation: " << item << endl;
			}
		}
		void print_all_next_item()
		{
			if(this->next == nullptr)
			{
				cout << "this->next == nullptr !" << endl;
				return;
			}
			if(this->find_s.size() == 0)
			{
				cout << "this->find_s.size() == 0!" << endl;
				return;
			}
			for(auto i=0;i!=this->find_s.size();i++)
			{
				cout << "next[" << i << "]: " << this->next[i] << endl;
			}
		}

	private:
		//保留计算到的next数组
		int *next = nullptr;
		//保存所有相同字串的个数
		vector<int> all_get_num;
		string base_s;
		string find_s;
		void GetNext();
		void GetAllKMP();
};

#endif

