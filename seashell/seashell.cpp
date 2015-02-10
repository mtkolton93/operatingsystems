#include "seashell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <string>

const int MAXSIZE = 255;

void Seashell::help()
{
	std::cout << "\t(l)ist: lists the contents of the current directory" << std::endl;
	std::cout << "\t(d)own [dir]: moves to the specified child directory" << std::endl;
	std::cout << "\t(u)p: moves to the parent directory" << std::endl;
	std::cout << "\t(w)ai: prints the current directory" << std::endl;
	std::cout << "\t(e)xit: exits Seashell" << std::endl;
	std::cout << "\t(h)elp: prints a list of the supported commands" << std::endl;
}

void Seashell::list()
{
	DIR *dp;
	struct dirent *dirp;
	struct stat fileStat;
	dp = opendir(".");
	if(dp == NULL)
	{
		std::cout << "error opening current directory";
	}
	else
	{
		dirp = readdir(dp);
		while (dirp != NULL)
		{
			if(std::string(dirp->d_name) != "." && std::string(dirp->d_name) != "..")
			{
				stat(dirp->d_name, &fileStat);
				bool isDir = S_ISDIR(fileStat.st_mode);
				if(isDir)
					std::cout << "\t(d) " << dirp->d_name << std::endl;
				else
					std::cout << "\t(f) " << dirp->d_name << std::endl;
			}
			dirp = readdir(dp);			
		}
	}
	closedir(dp);
}

void Seashell::down(std::string s)
{
	DIR *dp = opendir(s.c_str());
	if(dp == NULL)
		std::cout << "directory does not exist" << std::endl;
	else
	{
		chdir(s.c_str());
		wai();
	}
	
}

void Seashell::up()
{
	chdir("..");
	wai();
}

void Seashell::wai()
{
	char buff[MAXSIZE];
	getcwd(buff, MAXSIZE);
	std::cout << buff << std::endl;
}