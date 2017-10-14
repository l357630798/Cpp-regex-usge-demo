#include <iostream>
#include <regex>


void match()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_match
	//std::regex_match: ������ʽ��Ҫƥ�������ַ�������, Ҳ����˵������ʽҪ��
	//�ַ�����ȫƥ��, ���, ���ǵ���ƥ��, ����ƥ��ʧ��. 
	//����, �������Ի�ȡ��ƥ�����

	std::string text = "Date:2017-10-10";

	//����������ʽ
	//���� "()" ���ڲ�����, ������ı���ǰ��� "(" ���ֵ�˳��, ������, ��1��ʼ���б�ŵ� 
	std::string pattern = "Date.(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	//ƥ��
	std::cout.setf(std::ios_base::boolalpha);
	/*ģ�庯��1-1*/
	//��0��һ��������������ʽƥ����, ���������ǲ�����Ľ��
	//����ʹ�õ��� std::string::iterator ������, �� begin()/ end() ���صĵ���������(std::string::iterator)Ҫһ��
	std::match_results<std::string::iterator> results1;
	if(std::regex_match(text.begin(), text.end(), results1, express))
	{
		std::match_results<std::string::iterator>::const_iterator iter;
		for (iter = results1.begin(); iter != results1.end(); iter++)
		{
			std::cout << iter->length() << ": " << iter->str() << std::endl;
		}
	}
	/*���
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*ģ�庯��1-2*/
	//��0��һ��������������ʽƥ����, ���������ǲ�����Ľ��
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
	/*���
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*ģ�庯��2*/
	//��ʾ�ַ����Ƿ����������ʽ, ���ڼ���ַ�������
	std::cout << std::regex_match(text.begin(), text.end(), express) << std::endl;

	/*ģ�庯��3*/
	//��0��һ��������������ʽƥ����, ���������ǲ�����Ľ��
	//std::cmatch == std::match_results<const char*>
	std::cmatch c_results3;
	if(std::regex_match(text.c_str(), c_results3, express))
	{
		for (auto iter = c_results3.begin(); iter != c_results3.end(); iter++)
		{
			std::cout << iter->length() << ": " << iter->str() << std::endl;
		}
	}
	/*���
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*ģ�庯��4*/
	//��ʾ�ַ����Ƿ����������ʽ, ���ڼ���ַ�������
	std::cout << std::regex_match(text.c_str(), express) << std::endl;

	/*ģ�庯��5*/
	//��0��һ��������������ʽƥ����, ���������ǲ�����Ľ��
	std::match_results<std::string::const_iterator> s_results5;
	if(std::regex_match(text, s_results5, express))
	{
		for (size_t index = 0; index < s_results5.size(); index++)
		{
			//sub_match: ��ƥ��, match_results���涼��ŵ���sub_match
			//sub_match �������Ϊ std::pair ����չ, ���̳��� std::pair,
			//���� first ʵ���ϴ�ŵ��ǻ�ȡ���ַ���ͷָ���ַ, second Ϊβָ���ַ
			std::ssub_match sub = s_results5[index];
			std::cout << sub.length() << ": " << sub.str() << std::endl;
		}
	}
	/*���
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*ģ�庯��6*/
	//��ʾ�ַ����Ƿ����������ʽ, ���ڼ���ַ�������
	std::cout << std::regex_match(text, express) << std::endl;
	/////////////////////////////////////////////////////////////////////////
}


void search()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_search
	//std::regex_search: ����������ʽ����, ������Ҫ�������ַ�������ȫƥ��. 
	//������ֻ���е�������, ��������ֹͣ��������, �������ظ��������.

	std::string text = "Date:2017-10-10 ~ 2017-10-15";

	//����������ʽ
	//���� "()" ���ڲ�����, ������ı���ǰ��� "(" ���ֵ�˳��, ������, ��1��ʼ���б�ŵ�
	std::string pattern = "(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	//ƥ��
	std::cout.setf(std::ios_base::boolalpha);

	/*ģ�庯��1*/
	//��0��һ��������������ʽƥ����, ���������ǲ�����Ľ��, ���������ظ��������
	std::match_results<std::string::iterator> results1;
	if(std::regex_search(text.begin(), text.end(), results1, express))
	{
		//ʹ�õ���������, ����ĵ�����ʵ������ָ�� std::sub_match ��ָ��
		std::match_results<std::string::iterator>::const_iterator iter;
		for (iter = results1.begin(); iter != results1.end(); iter++)
		{
			std::cout << iter->length() << ": " << iter->str() << std::endl;
		}
	}
	/*���
	10: 2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/
	
	/*ģ�庯��2*/
	//��ʾ�Ƿ�������������������ʽ�Ľ��
	std::cout << std::regex_search(text.begin(), text.end(), express) << std::endl;

	/*ģ�庯��3*/
	//��0��һ��������������ʽƥ����, ���������ǲ�����Ľ��, ���������ظ��������
	std::cmatch c_results3;
	if(std::regex_search(text.c_str(), c_results3, express))
	{
		for (size_t index = 0; index < c_results3.size(); index++)
		{
			//��ȡ�����������, ע��: ����ʹ�õ��� std::csub_match, 
			//ʵ���ϴ���� std::match_results ��������ݾ���һ�� std::sub_match
			std::csub_match sub = c_results3[index];

			//�Ȼ�ȡ����, �ٻ�ȡ����
			std::cout << sub.length() << ": " << sub.str() << std::endl; 
		}
	}
	/*���
	10: 2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*ģ�庯��4*/
	//��ʾ�Ƿ�������������������ʽ�Ľ��
	std::cout << std::regex_search(text.c_str(), express) << std::endl;

	/*ģ�庯��5*/
	//��0��һ��������������ʽƥ����, ���������ǲ�����Ľ��, ���������ظ��������
	std::smatch s_results5;
	if (std::regex_search(text, s_results5, express))
	{
		for (auto iter = s_results5.begin(); iter != s_results5.end(); iter++)
		{
			std::cout << iter->length() << ": " << iter->str() << std::endl;
		}
	}
	/*���
	10: 2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

	/*ģ�庯��6*/
	//��ʾ�Ƿ�������������������ʽ�Ľ��
	std::cout << std::regex_search(text, express) << std::endl;
}


void replace()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_replace
	//std::regex_replace: 

	std::string text = "Date:2017-10-10 ~ 2017-10-15";

	//����������ʽ
	//���� "()" ���ڲ�����, ������ı���ǰ��� "(" ���ֵ�˳��, ������, ��1��ʼ���б�ŵ� 
	std::string pattern = "(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	//����洢��������Ѿ��滻�ַ�
	std::string result(256, '0');
	std::string substitutes = "2017-10-12";

	/*ģ�庯��1*/
	//�����������������ʽ(�����ǲ�����), Ȼ���滻������ʽƥ�䵽�Ľ�� 
	//std::regex_replace ģ�庯������ֵʵ�������µ��ַ������������β����ָ��λ��, �� 0 ��Ϊ�˷�ֹ�������ݳ��������
	*std::regex_replace(result.begin(), text.begin(), text.end(), express, substitutes) = '\0';
	std::cout << result.c_str() << std::endl;
	/*���:
	Date:2017-10-12 ~ 2017-10-12
	*/
	
	result.clear();
	result.resize(256, '0');

	/*ģ�庯��2*/
	//�����������������ʽ(�����ǲ�����), Ȼ���滻������ʽƥ�䵽�Ľ�� 
	//std::regex_replace ģ�庯������ֵʵ�������µ��ַ������������β����ָ��λ��, �� 0 ��Ϊ�˷�ֹ�������ݳ��������
	result = std::regex_replace(text, express, substitutes);
	std::cout << result.c_str() << std::endl;
	/*���:
	Date:2017-10-12 ~ 2017-10-12
	*/
}


void iterator()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_iterator
	//std::regex_iterator: ���ڶ���ظ�ƥ��, ������, ֻ���ж��ƥ������������ʽ,
	//�ɻ�ȡ����������ʽ�Ľ��

	std::string text = "Date:2017-10-10 ~ 2017-10-15";

	//����������ʽ
	//���� "()" ���ڲ�����, ������ı���ǰ��� "(" ���ֵ�˳��, ������, ��1��ʼ���б�ŵ�
	std::string pattern = "(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	std::regex_iterator<std::string::const_iterator> begin(text.cbegin(), text.cend(), express);
	//std::sregex_iterator == std::regex_iterator<std::string::const_iterator>
	for (auto iter = begin; iter != std::sregex_iterator(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*���
	10: 2017-10-10
	10: 2017-10-15
	*/
}


void token_iterator()
{
	/////////////////////////////////////////////////////////////////////////
	//std::regex_token_iterator
	//std::regex_token_iterator: ���ڶ��ƥ��������ʽ, �����Ի�ȡ����������ʽ
	//�Ľ��, Ҳ���Ի�ȡ������ʽ��ǰ׺, �����Ի�ȡ������ʽ�ķ�����ƥ��

	std::string text = "Date:2017-10-10 ~ 2017-10-15";

	//����������ʽ
	//���� "()" ���ڲ�����, ������ı���ǰ��� "(" ���ֵ�˳��, ������, ��1��ʼ���б�ŵ�
	std::string pattern = "(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	/*���캯��2-1*/
	//(���ƥ��)��ʾ������ʽƥ��, ������ 4 ���� 0
	std::regex_token_iterator<std::string::const_iterator> begin2_1(text.cbegin(), text.cend(), express);
	//std::sregex_token_iterator == std::regex_token_iterator<std::string::const_iterator>
	for (auto iter = begin2_1; iter != std::sregex_token_iterator(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*���
	10: 2017-10-10
	10: 2017-10-15
	*/

	/*���캯��2-2*/
	//(���ƥ��)��ʾ������ʽƥ�䵽��ǰ׺, -1 ���ʾֻ��ʾǰ׺
	std::regex_token_iterator<std::string::const_iterator> begin2_2(text.cbegin(), text.cend(), express, -1);
	for (auto iter = begin2_2; iter != std::sregex_token_iterator(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*���
	5: Date:
	3:  ~
	*/

	/*���캯��2-3*/
	//(���ƥ��)��ʾ������ʽ��ƥ��, 3 ��ʾ��������ƥ��
	std::regex_token_iterator<std::string::const_iterator> begin2_3(text.cbegin(), text.cend(), express, 3);
	for (auto iter = begin2_3; iter != std::sregex_token_iterator(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*���
	2: 10
	2: 15
	*/

	/*���캯��3*/
	//(���ƥ��)��ʾ������ʽƥ�䵽��ǰ׺����ƥ��, -1 ��ʾǰ׺, 2 ��ʾ�ڶ�����ƥ��
	std::vector<int> vec;
	vec.push_back(-1);
	vec.push_back(2);
	std::regex_token_iterator<std::string::iterator> begin3(text.begin(), text.end(), express, vec);
	for (auto iter = begin3; iter != std::regex_token_iterator<std::string::iterator>(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*���
	5: Date:
	5: 10-10
	3:  ~
	5: 10-15
	*/

	/*���캯��4*/
	//(���ƥ��)��ʾ������ʽƥ�䵽��ǰ׺������������ʽƥ��, -1 ��ʾǰ׺, 0 ��ʾƥ������������ʽ.
	int arr[] = {-1, 0};
	std::regex_token_iterator<std::string::iterator> begin4(text.begin(), text.end(), express, arr);
	for (auto iter = begin4; iter != std::regex_token_iterator<std::string::iterator>(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str() << std::endl;
	}
	/*���
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