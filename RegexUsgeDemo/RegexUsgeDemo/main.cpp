#include <iostream>
#include <regex>


void match()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_match
	//std::regex_match: 正则表达式需要匹配整个字符串序列, 也就是说正则表达式要与
	//字符串完全匹配, 因此, 它是单次匹配, 否则匹配失败. 
	//此外, 它还可以获取子匹配的组

	std::string text = "Date:2017-10-10";

	//构造正则表达式
	//这里 "()" 用于捕获组, 捕获组的编号是按照 "(" 出现的顺序, 从左到右, 从1开始进行编号的 
	std::string pattern = "Date.(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	//匹配
	std::cout.setf(std::ios_base::boolalpha);
	/*模板函数1-1*/
	//第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果
	//这里使用的是 std::string::iterator 迭代器, 与 begin()/ end() 返回的迭代器类型(std::string::iterator)要一致
	std::match_results<std::string::iterator> results1;
	if(std::regex_match(text.begin(), text.end(), results1, express))
	{
		std::match_results<std::string::iterator>::const_iterator iter;
		for (iter = results1.begin(); iter != results1.end(); iter++)
		{
			std::cout << iter->length() << ": " << iter->str() << std::endl;
		}
	}
	/*输出
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*模板函数1-2*/
	//第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果
	//std::smatch == std::match_results<std::string::const_iterator>
	std::smatch s_results1;
	if(std::regex_match(text.cbegin(), text.cend(), s_results1, express))
	{
		std::match_results<std::string::const_iterator>::const_iterator iter;
		for (iter = s_results1.begin(); iter != s_results1.end(); iter++)
		{
			std::cout << iter->length() << ": " << iter->str() << std::endl;
		}
	}
	/*输出
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*模板函数2*/
	//显示字符串是否符合正则表达式, 用于检测字符串规则
	std::cout << std::regex_match(text.begin(), text.end(), express) << std::endl;

	/*模板函数3*/
	//第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果
	//std::cmatch == std::match_results<const char*>
	std::cmatch c_results3;
	if(std::regex_match(text.c_str(), c_results3, express))
	{
		for (auto iter = c_results3.begin(); iter != c_results3.end(); iter++)
		{
			std::cout << iter->length() << ": " << iter->str() << std::endl;
		}
	}
	/*输出
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*模板函数4*/
	//显示字符串是否符合正则表达式, 用于检测字符串规则
	std::cout << std::regex_match(text.c_str(), express) << std::endl;

	/*模板函数5*/
	//第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果
	std::match_results<std::string::const_iterator> s_results5;
	if(std::regex_match(text, s_results5, express))
	{
		for (size_t index = 0; index < s_results5.size(); index++)
		{
			//sub_match: 子匹配, match_results里面都存放的是sub_match
			//sub_match 可以理解为 std::pair 的扩展, 它继承了 std::pair,
			//其中 first 实际上存放的是获取的字符串头指针地址, second 为尾指针地址
			std::ssub_match sub = s_results5[index];
			std::cout << sub.length() << ": " << sub.str() << std::endl;
		}
	}
	/*输出
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*模板函数6*/
	//显示字符串是否符合正则表达式, 用于检测字符串规则
	std::cout << std::regex_match(text, express) << std::endl;
	/////////////////////////////////////////////////////////////////////////
}


void search()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_search
	//std::regex_search: 搜素正则表达式参数, 但它不要求整个字符序列完全匹配. 
	//而且它只进行单次搜索, 搜索到即停止继续搜索, 不进行重复多次搜索.

	std::string text = "Date:2017-10-10 ~ 2017-10-15";

	//构造正则表达式
	//这里 "()" 用于捕获组, 捕获组的编号是按照 "(" 出现的顺序, 从左到右, 从1开始进行编号的
	std::string pattern = "(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	//匹配
	std::cout.setf(std::ios_base::boolalpha);

	/*模板函数1*/
	//第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果, 它不进行重复多次搜索
	std::match_results<std::string::iterator> results1;
	if(std::regex_search(text.begin(), text.end(), results1, express))
	{
		//使用迭代器遍历, 这里的迭代器实际上是指向 std::sub_match 的指针
		std::match_results<std::string::iterator>::const_iterator iter;
		for (iter = results1.begin(); iter != results1.end(); iter++)
		{
			std::cout << iter->length() << ": " << iter->str() << std::endl;
		}
	}
	/*输出
	10: 2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/
	
	/*模板函数2*/
	//显示是否有搜索到符合正则表达式的结果
	std::cout << std::regex_search(text.begin(), text.end(), express) << std::endl;

	/*模板函数3*/
	//第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果, 它不进行重复多次搜索
	std::cmatch c_results3;
	if(std::regex_search(text.c_str(), c_results3, express))
	{
		for (size_t index = 0; index < c_results3.size(); index++)
		{
			//获取组里面的数据, 注意: 这里使用的是 std::csub_match, 
			//实际上存放在 std::match_results 里面的数据就是一组 std::sub_match
			std::csub_match sub = c_results3[index];

			//先获取长度, 再获取内容
			std::cout << sub.length() << ": " << sub.str() << std::endl; 
		}
	}
	/*输出
	10: 2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*模板函数4*/
	//显示是否有搜索到符合正则表达式的结果
	std::cout << std::regex_search(text.c_str(), express) << std::endl;

	/*模板函数5*/
	//第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果, 它不进行重复多次搜索
	std::smatch s_results5;
	if (std::regex_search(text, s_results5, express))
	{
		for (auto iter = s_results5.begin(); iter != s_results5.end(); iter++)
		{
			std::cout << iter->length() << ": " << iter->str() << std::endl;
		}
	}
	/*输出
	10: 2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*模板函数6*/
	//显示是否有搜索到符合正则表达式的结果
	std::cout << std::regex_search(text, express) << std::endl;
}


void replace()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_replace
	//std::regex_replace: 

	std::string text = "Date:2017-10-10 ~ 2017-10-15";

	//构造正则表达式
	//这里 "()" 用于捕获组, 捕获组的编号是按照 "(" 出现的顺序, 从左到右, 从1开始进行编号的 
	std::string pattern = "(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	//定义存储结果变量已经替换字符
	std::string result(256, '0');
	std::string substitutes = "2017-10-12";

	/*模板函数1*/
	//多次搜索整个正则表达式(不考虑捕获组), 然后替换正则表达式匹配到的结果 
	//std::regex_replace 模板函数返回值实际上是新的字符串存入变量后尾部的指针位置, 置 0 是为了防止变量数据出错或乱码
	*std::regex_replace(result.begin(), text.begin(), text.end(), express, substitutes) = '\0';
	std::cout << result.c_str() << std::endl;
	/*输出:
	Date:2017-10-12 ~ 2017-10-12
	*/
	
	result.clear();
	result.resize(256, '0');

	/*模板函数2*/
	//多次搜索整个正则表达式(不考虑捕获组), 然后替换正则表达式匹配到的结果 
	//std::regex_replace 模板函数返回值实际上是新的字符串存入变量后尾部的指针位置, 置 0 是为了防止变量数据出错或乱码
	result = std::regex_replace(text, express, substitutes);
	std::cout << result.c_str() << std::endl;
	/*输出:
	Date:2017-10-12 ~ 2017-10-12
	*/
}


void iterator()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_iterator
	//std::regex_iterator: 用于多次重复匹配, 不分组, 只进行多次匹配整个正则表达式,
	//可获取整个正则表达式的结果

	std::string text = "Date:2017-10-10 ~ 2017-10-15";

	//构造正则表达式
	//这里 "()" 用于捕获组, 捕获组的编号是按照 "(" 出现的顺序, 从左到右, 从1开始进行编号的
	std::string pattern = "(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	std::regex_iterator<std::string::const_iterator> begin(text.cbegin(), text.cend(), express);
	//std::sregex_iterator == std::regex_iterator<std::string::const_iterator>
	for (auto iter = begin; iter != std::sregex_iterator(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*输出
	10: 2017-10-10
	10: 2017-10-15
	*/
}


void token_iterator()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_token_iterator
	//std::regex_token_iterator: 用于多次匹配正则表达式, 它可以获取整个正则表达式
	//的结果, 也可以获取正则表达式的前缀, 还可以获取正则表达式的分组子匹配

	std::string text = "Date:2017-10-10 ~ 2017-10-15";

	//构造正则表达式
	//这里 "()" 用于捕获组, 捕获组的编号是按照 "(" 出现的顺序, 从左到右, 从1开始进行编号的
	std::string pattern = "(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	/*构造函数2-1*/
	//(多次匹配)显示正则表达式匹配, 即参数 4 等于 0
	std::regex_token_iterator<std::string::const_iterator> begin2_1(text.cbegin(), text.cend(), express);
	//std::sregex_token_iterator == std::regex_token_iterator<std::string::const_iterator>
	for (auto iter = begin2_1; iter != std::sregex_token_iterator(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*输出
	10: 2017-10-10
	10: 2017-10-15
	*/

	/*构造函数2-2*/
	//(多次匹配)显示正则表达式匹配到的前缀, -1 则表示只显示前缀
	std::regex_token_iterator<std::string::const_iterator> begin2_2(text.cbegin(), text.cend(), express, -1);
	for (auto iter = begin2_2; iter != std::sregex_token_iterator(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*输出
	5: Date:
	3:  ~
	*/

	/*构造函数2-3*/
	//(多次匹配)显示正则表达式子匹配, 3 表示第三组子匹配
	std::regex_token_iterator<std::string::const_iterator> begin2_3(text.cbegin(), text.cend(), express, 3);
	for (auto iter = begin2_3; iter != std::sregex_token_iterator(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*输出
	2: 10
	2: 15
	*/

	/*构造函数3*/
	//(多次匹配)显示正则表达式匹配到的前缀和子匹配, -1 表示前缀, 2 表示第二个子匹配
	std::vector<int> vec;
	vec.push_back(-1);
	vec.push_back(2);
	std::regex_token_iterator<std::string::iterator> begin3(text.begin(), text.end(), express, vec);
	for (auto iter = begin3; iter != std::regex_token_iterator<std::string::iterator>(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*输出
	5: Date:
	5: 10-10
	3:  ~
	5: 10-15
	*/

	/*构造函数4*/
	//(多次匹配)显示正则表达式匹配到的前缀和整个正则表达式匹配, -1 表示前缀, 0 表示匹配整个正则表达式.
	int arr[] = {-1, 0};
	std::regex_token_iterator<std::string::iterator> begin4(text.begin(), text.end(), express, arr);
	for (auto iter = begin4; iter != std::regex_token_iterator<std::string::iterator>(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*输出
	5: Date:
	10: 2017-10-10
	3:  ~
	10: 2017-10-15
	*/
}


int main()
{
	search();

	system("pause");
	return 0;
}