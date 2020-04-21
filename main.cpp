#include <iostream>
#include <locale>
//#include <io.h>
//#include <fcntl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>

bool isBeginOfDialog(const std::wstring& wstrLine);

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
	std::wstreampos posDialogBegin = 0;

	while (std::getline(infile, wstrLine))
	{	
		// stores the position of the begin of dialog
		if (isBeginOfDialog(wstrLine))
		{
			posDialogBegin = infile.tellg();
		}

		// find the specified message
		if (wstrLine.find(wstrMessage) != std::wstring::npos)
		{
			// message is found
			std::wcout << wstrLine << std::endl;

			// get back to the position of begin if dialog to retrieve the whole 
			// dialog message section
			infile.seekg(posDialogBegin);

			// print out again
		}
	}

	/*std::wcin >> wstrMessage;
	std::wcout << wstrMessage << std::endl;*/

	return 0;
}

bool isBeginOfDialog(const std::wstring& wstrLine)
{
	// begin of dialog like:
	// [2020/04/20 xxx)>]
	// ...
	return true;
}