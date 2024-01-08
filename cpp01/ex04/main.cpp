#include <iostream>
#include <fstream>
#include <string>
#include "replace.h"

void  put_error_msg(const char *error, const char *str)
{
  std::cout << error << " \"" << str << "\"" << std::endl;
}

void  put_error_msg(const char *error)
{
  std::cout << error << std::endl;
}

size_t  ft_strlen(char *str)
{
  size_t  i = 0;

  if (!str)
    return (0);
  while (str[i])
    i++;
  return (i);
}

void  write_rep_text(char *replace, char *subs, std::string buff, std::ofstream &writeFile)
{
  size_t  found = 0;
  size_t  i = 0;
  size_t  len = buff.length();
  size_t  subs_len = ft_strlen(subs);

  if (!subs_len)
  {
    put_error_msg(FIND);
    return ;
  }
  while (i < len)
  {
    found = buff.find(subs, i);
    if (found > len)
      return ;
    writeFile << buff.substr(i, found - i);
    writeFile << replace;
    i = found + subs_len;
  }
}

int	main(int argc, char **argv)
{
  std::string file;
  std::string content;
	std::ifstream	readFile;
	std::ofstream	writeFile;

  if (argc != 4)
    return (put_error_msg(ARGUMENTS), 1);
  file = argv[1];
  readFile.open(file.c_str());
  if (!readFile)
    return (put_error_msg(READ, file.c_str()), 1);
  file.resize(file.rfind("."));
  file.append(".replace");
  writeFile.open (file.c_str(), std::ofstream::trunc);
  if (!writeFile)
    return (put_error_msg(WRITE, file.c_str()), 1);
  content.assign((std::istreambuf_iterator<char>(readFile)), (std::istreambuf_iterator<char>()));
  readFile.close();
  write_rep_text(argv[3], argv[2], content, writeFile);
  writeFile.close();
}