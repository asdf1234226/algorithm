#include <stdio.h>
#include <string.h>
#include<string>
#include <pcre.h>

#define OVECCOUNT 30    /* should be a multiple of 3 */

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
    pcre *re;
    const char *error;
    int erroffset;
    int ovector[OVECCOUNT];
    int rc, i;
    std::string pattern = "(^" + RegQuote("*\?0*") + "$)";
    //const char *pattern = "(^.*.0.*$)";
    //const char *pattern = "(^.*\\.0.*$)";
    const char *subject = "?0";  /* the subject string */

    /* compile the pattern */
    int option = 0;
    option |= PCRE_CASELESS;
    re = pcre_compile(pattern.c_str(), 0, &error, &erroffset, NULL);
    if (re == NULL) {
        printf("pcre_compile failed (offset: %d), %s\n", erroffset, error);
        return 1;
    }

    /* match the pattern */
    rc = pcre_exec(re, NULL, subject, strlen(subject), 0, 0, ovector, 3);

    /* check the result */
    if (rc < 0) {
        printf("Match failed: %d\n", rc);
    } else {
        printf("Match succeeded\n");
    }

    /* clean up */
    pcre_free(re);

    return 0;
}
