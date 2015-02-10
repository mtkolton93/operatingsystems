#include "seashell.h"
#include <string>
#include <iostream>

int main(int argc, char * argv[])
{
	Seashell sh;
	bool ex(false);
	std::string in;

	std::cout << "Welcome to Seashell" << std::endl;
	sh.help();

	while(!ex)
	{
		std::cout << "Seashell>";
		getline(std::cin, in);

		if(in == "l" || in == "list")
			sh.list();
		else if(in == std::string("u") || in == std::string("up"))
			sh.up();
		else if(in.substr(0, 2) == std::string("d "))
			sh.down(in.substr(2, std::string::npos));
		else if(in.substr(0, 5) == std::string("down "))
			sh.down(in.substr(5, std::string::npos));
		else if(in == std::string("w") || in == std::string("wai"))
			sh.wai();
		else if(in == std::string("e") || in == std::string("exit"))
			ex = true;
		else
			sh.help();
	}
}