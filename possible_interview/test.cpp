#include <iostream>
#include<string>
#include <regex>

const char  *szRegSpecialChars = "\\^$.-[]|()+{}*?";

std::string RegQuote(const std::string& text)
{
	std::string strRet;

	const char* p = text.c_str();
	const char *start_position = text.c_str();
	while(*p != 0)
	{
		if (*p == '*')
		{
			if ((p != start_position) && (*(p-1) == '\\'))
			{
				strRet.push_back('*');
				p++;
				continue;
			}

			strRet += ".*";

			p++;
			continue;
		}

		if (*p == '?')
		{
			strRet.push_back('.');

			p++;
			continue;
		}

		if (strchr(szRegSpecialChars, *p) != NULL)
		{
			if(*p == '\\' && *(p+1) != 0 && *(p+1)=='*')
			{
				strRet.push_back(*p);
				p++;
				continue;
			}

			strRet.push_back('\\');
			strRet.push_back(*p);

			p++;
			continue;
		}

		strRet.push_back(*p);
		p++;
	}

	return strRet;
}
int main() {
    std::string re = "(^" + RegQuote("*\?0*") + "$)";
    std::cout << re << std::endl;
    //re = "^.*\\?0.*$";
    std::string s = "\?0";
    std::regex e(re);  // 注意这里的转义字符

    // 使用 regex_match() 来检查字符串是否完全匹配正则表达式
    if (std::regex_match(s, e))
        std::cout << "String is a match.\n";
    else
        std::cout << "No match.\n";

    return 0;
}
