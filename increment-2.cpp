#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>



// PROTOTYPES ***************************************************************************
void finderFunc();

void finderFuncBasicArgs(std::string, std::string);

// END OF PROTOTYPES ---------------------------------------------------------------------------









int main(int argc, char* argv[]) {



	if (argc == 1)
	{
		std::cout << "No arguments passed other than the program name!" << std::endl << std::endl;

		finderFunc();
	}



	else if (argc == 3)
	{

		finderFuncBasicArgs(argv[1], argv[2]); // sending the searchTerm and the fileName to the finder function
	}


	else
	{
		std::cout << std::endl << std::endl << "If you ended up here, check your args" << std::endl << std::endl;
	}




	return 0;
}








// FUNCTIONS ***************************************************************************



// FINDER ***************************************************************************

void finderFunc() {
	std::string dataset_f = "", input_f = "";

	while (dataset_f .length() == 0)
	{
		std::cout << "Give a string from which to search for: ";
		getline(std::cin, dataset_f);
	}

	while (input_f.length() == 0 || input_f.length() > dataset_f .length())
	{
		std::cout << "Give search string: ";
		getline(std::cin, input_f);
	}

	size_t found = dataset_f .find(input_f);



	if (found != std::string::npos)
	{
		std::cout << "'" << input_f << "' found in '" << dataset_f << "' in position " << found << std::endl;
	}

	else
	{
		std::cout << "'" << input_f << "' NOT found in '" << dataset_f << "'" << std::endl;
	}

}


// END OF FINDER ---------------------------------------------------------------------------




// FINDER WITH BASIC ARGS ***************************************************************************

void finderFuncBasicArgs(std::string searchTerm_f, std::string fileName_f) {

	size_t found;

	std::string textLine = ""; // variable to store a line of text file at a time

	std::ifstream reader; // object used toi read the file


	// Open the file for reading using passed
	reader.open(fileName_f);


	if (!reader) // check if reader.open failed
	{
		std::cout << "Error opening the file, check file name and location";
		exit(0);

	}

	

	while (std::getline(reader, textLine))
	{
		found = textLine.find(searchTerm_f); // actual searching of the substring

		if (found != std::string::npos) // if searchTerm is found from the textLine (found is NOT npos, means the search returned positive), print that line of text in whole
		{
			std::cout << textLine << std::endl;

		}

	}
	

	reader.close();


}


// END OF FINDER WITH BASIC ARGS ---------------------------------------------------------------------------


// END OF FUNCTIONS ---------------------------------------------------------------------------