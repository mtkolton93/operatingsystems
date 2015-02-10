#ifndef SEASHELLs_H
#define SEASHELL_H

#include <string>

class Seashell
{
public:
	void help();
	void list();
	void down(std::string s);
	void up();
	void wai();
};

#endif