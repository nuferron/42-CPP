#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

int put_error_msg(char *error, char *str)
{
  std::cout << error << str << std::endl;
  return (1);
}

int put_error_msg(char *error)
{
  std::cout << error << std::endl;
  return (1);
}

void  write_rep_text(std::string replace, std::string subs, std::string buff, std::ofstream &writeFile)
{
  size_t  found = 0;
  size_t  i = 0;
  size_t  len = buff.length();

  if (subs == "")
  {
    std::cout << "There's nothing to find!" << std::endl;
    return ;
  }
  while (i < len)
  {
    found = buff.find(subs, i);
    if (found > len)
      return ;
    writeFile << buff.substr(i, found - i);
    writeFile << replace;
    std::cout << "found: " << found << std::endl;
    i = found + subs.length();
  }
}

int	main(int argc, char **argv)
{
  std::string file;
  std::string content;
	std::ifstream	readFile;
	std::ofstream	writeFile;

  (void)argv;
  if (argc != 2)
    return (printf("ARGUMENTS!\n"));
  file = argv[1];
  readFile.open(file.c_str());
  file.resize(file.rfind("."));
  file.append(".replace");
  writeFile.open (file.c_str(), std::ofstream::trunc);
  std::cout << file << std::endl;
  if (!readFile)
  {
    std::cout << "There are problems to read \"" << argv[1] << "\""<< std::endl;
    return (1);
  }
  if (!writeFile)
  {
    std::cout << "Sorry, there are problems to create \"" << file << "\""<< std::endl;
    return (1);
  }
  content.assign( (std::istreambuf_iterator<char>(readFile) ), (std::istreambuf_iterator<char>()    ) );
  readFile.close();
  write_rep_text("AAAAAH", "", content, writeFile);
}