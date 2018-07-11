#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <map>

class Language : public std::map<std::string, std::string>
{
public:
	static Language& Get();
	static void SetLanguages(const std::string& language);
private:
	Language() {};
	Language(const Language &) {};
};

#endif // !LANGUAGE_H