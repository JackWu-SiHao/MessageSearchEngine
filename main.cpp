#include <iostream>
#include <locale>
//#include <io.h>
//#include <fcntl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>

int main(int argc, char const* argv[])
{
	//_setmode(_fileno(stdout), _O_U16TEXT);
	//std::locale locTaiwan("zh-TW");

	//std::wcin.imbue(locTaiwan);
	//std::wcout.imbue(locTaiwan);

	// read message
	std::wstring wstrMessage;
	std::getline(std::wcin, wstrMessage);
	std::wcout << L"Start to seach message: " << wstrMessage << std::endl;
	
	// ring buffer for message
	//std::queue<std::wstring> qwstrMsgContext;

	std::wifstream infile("inputdata1.txt");
	std::wstring wstrLine;
	while (std::getline(infile, wstrLine))
	{
		//std::wistringstream wiss(wstrLine);
		// find the specified message
		if (wstrLine.find(wstrMessage) != std::wstring::npos)
		{
			std::wcout << wstrLine << std::endl;
			// I think we should also show the file opened
		}
	}

	/*std::wcin >> wstrMessage;
	std::wcout << wstrMessage << std::endl;*/

#if 0

	// std::wcout << L"§d±ã¯E" << std::endl;
	// std::wcout << "Test Englishg" << std::endl;

	std::wstring wstrChinese(L"§d±ã¯E");
	std::wcout << wstrChinese << ", size = " << wstrChinese.size() << std::endl;

	int i = 0;
	std::wcout << wstrChinese[i++] << ' ' << wstrChinese[i++] << ' ' << wstrChinese[i++] << ' ' << std::endl;

	std::wstring wstrEng(L"Jack");
	std::wcout << wstrEng << ", size = " << wstrEng.size() << std::endl;

	//int i = 0;
	//std::wcout << wstrEng[i++] << ' ' << wstrEng[i++] << ' ' << wstrEng[i++] << ' ' << std::endl;

	std::string strEng("Jack");
	std::wcout << strEng[0] << std::endl;
	std::wcout << L"haha" << std::endl;
	//std::wcout << std::wstring(strEng.begin(), strEng.end()) << std::endl;
	
	//std::u32string u32strAA(U"Jack");
	//std::cout << u32strAA << std::endl;

#endif

	return 0;
}
