#include <iostream>

using namespace std;

enum ELoggerLevel
{
	Message,
	Warning,
	Error
};

class Logger
{
public:
	int loggerLevel = 0;

	template<typename T>
	static const void Log(const T const t)
	{
		cout << t << endl;
	}

	template<typename T>
	static const void LogGame(const T const t)
	{
		cout << "[Game]: " << t << endl;
	}
};

