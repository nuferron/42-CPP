#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

void  write_rep_text(std::string replace, std::string subs, std::string buff, std::ofstream &writeFile)
{
  size_t  found = 0;
  size_t  i = 0;
  size_t  len = buff.length();
  size_t  subs_len = subs.length();

  (void)replace;
  while (i < len)
  {
    found = buff.find(subs, i);
    //std::cout << "\033[1;31m Busca linia a partir de i: " << i << "\t la troba a "<< found << std::endl;
    //std::cout << "\033[1;32m Escriura " << buff.substr(i, found - i) << "\n\ti: " << i << " found: " << found << std::endl;
    writeFile << buff.substr(i, found - i);
    //writeFile << replace;
    i += found + subs_len;
    std::cout << "next: |" << buff[i] << "|" << std::endl;
    //std::cout << &buff[i] << " len " << subs.length() << std::endl;
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
  //std::cout << readFile.rdbuf() << std::endl;
  content.assign( (std::istreambuf_iterator<char>(readFile) ), (std::istreambuf_iterator<char>()    ) );
  readFile.close();
  write_rep_text("AAAAAH", "linia", content, writeFile);
}