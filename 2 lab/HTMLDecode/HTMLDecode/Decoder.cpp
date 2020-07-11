#include "Decoder.h"
using namespace std;

map<string, string> htmlEntities{
	{"&quot;", "\""},
	{ "&apos;", "\'" },
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&amp;", "&" } };

string ReplaceSubString(const string& line, const string& searchString, const string& replaceString)
{
	string lineWithReplace;
	size_t lastPos = 0;

	if (searchString != "")
	{
		lastPos = 0;
		lineWithReplace = "";
		size_t foundPos = line.find(searchString);
		while (foundPos != string::npos)
		{
			lineWithReplace.append(line, lastPos, foundPos - lastPos);
			lineWithReplace.append(replaceString);
			lastPos = foundPos + searchString.length();
			foundPos = line.find(searchString, foundPos + searchString.length());
		}
	}
	lineWithReplace.append(line, lastPos, line.length() - lastPos);

	return lineWithReplace;
}

string DecodeHtml(const string& html)
{

	string decodeHtml = html;

	for (pair<string, string> htmlEntity : htmlEntities)
	{
		decodeHtml = ReplaceSubString(decodeHtml, htmlEntity.first, htmlEntity.second);
	}

	return decodeHtml;
}