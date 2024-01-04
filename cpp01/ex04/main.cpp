#include <iostream>
#include <fstream>
#include <string>

int	main()
{
	std::ifstream	readFile("test.txt");
	std::ofstream	writeFile("result.replace");
	std::string		search;
	std::string		readout;

	getline(std::cin, search);
	std::cout << search;
    while (getline(readFile, readout)){
        if(readout == search){
            /*
                id remains the same
                But the First name and Last name are replaced with
                the user `firstname` and `lastname` input
            */
            	std::cout << "aixo es el readout: " << readout << std::endl;
				writeFile << "HOLA";

			}
            std::cout << "readout: " << readout << std::endl;
    }
}
