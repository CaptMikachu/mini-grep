#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>



// PROTOTYPES ***************************************************************************

void finderFunc();

void finderFuncBasicArgs(std::string, std::string);

void finderFuncExtendedArgs(std::string, std::string, std::string);

std::string upCaser(std::string);


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


	else if (argc == 4)
	{
		if ((argv[1])[0] != '-' || (argv[1])[1] != 'o')
		{
			std::cout << "You didn't start your 2nd argument with '-o', 2nd argument ignored" << std::endl << std::endl;
			finderFuncBasicArgs(argv[2], argv[3]); // sending the searchTerm and the fileName to the finder function
		}

		else
		{
			finderFuncExtendedArgs(argv[1], argv[2], argv[3]); // sending the searchTerm and the fileName to the finder function
		}

	}


	else
	{
		std::cout << std::endl << std::endl << "If you ended up here, check your args, cuz something ain't right" << std::endl << std::endl;
	}




	return 0;
}








// FUNCTIONS ***************************************************************************












// FINDER ***************************************************************************

void finderFunc() {
	std::string dataset_f = "", input_f = "";

	while (dataset_f.length() == 0)
	{
		std::cout << "Give a string from which to search for: ";
		getline(std::cin, dataset_f);
	}

	while (input_f.length() == 0 || input_f.length() > dataset_f.length()) // only accept strings with the length of more than zero, and less or equal to the dataset length
	{
		std::cout << "Give search string: ";
		getline(std::cin, input_f);
	}

	size_t found = dataset_f.find(input_f);



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
		std::cout << "Error opening the file, check file name and location" << std::endl << std::endl;
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












// FINDER WITH EXTENDED ARGS ***************************************************************************

void finderFuncExtendedArgs(std::string extArgs_f, std::string searchTerm_f, std::string fileName_f) {


	//std::cout << extArgs_f << std::endl;

	extArgs_f.erase(0, 2); // omit the first 2 characters from the extArgs-string, them being '-o'


	//std::cout << extArgs_f << std::endl;


	size_t
		found,
		foundOccurrence = extArgs_f.find('o'), // option for occurrences
		foundLineNum = extArgs_f.find('l'), // option for line numbers
		foundReverse = extArgs_f.find('r'), // option for reverse search
		foundCaseIgnore = extArgs_f.find('i'); // option for case ignoring

	std::string textLine = ""; // variable to store a line of text file at a time

	std::ifstream reader; // object used toi read the file

	unsigned int
		lineNum = 0,
		occurrences = 0;




	if (foundOccurrence != std::string::npos)
	{

	}




	// Open the file for reading using passed
	reader.open(fileName_f);


	if (!reader) // check if reader.open failed
	{
		std::cout << "Error opening the file, check file name and location" << std::endl << std::endl;
		exit(0);

	}



	while (std::getline(reader, textLine))
	{
		lineNum++;

		if (foundReverse != std::string::npos) // if args contained 'r' for searching lines NOT containing searchTerm
		{

			if (foundCaseIgnore != std::string::npos) // if args contained 'i' for ignoring case-sensitivity
			{
				found = upCaser(textLine).find(upCaser(searchTerm_f)); // actual searching of the substring as NOT case-sensitive
			}

			else
			{
				found = textLine.find(searchTerm_f); // actual searching of the substring as case-sensitive

			}

			if (found == std::string::npos) // if searchTerm is found from the textLine (found is NOT npos, means the search returned positive), print that line of text in whole
			{
				if (foundLineNum != std::string::npos) // if the argument 'l' is found, print the line number too
				{
					std::cout << lineNum << ":" << textLine << "" << std::endl;
				}

				else
				{
					std::cout << textLine << std::endl;
				}

				occurrences++;

			}
		}





		else // normal search for lines containing searchTerm
		{

			if (foundCaseIgnore != std::string::npos) // if args contained 'i'
			{
				found = upCaser(textLine).find(upCaser(searchTerm_f)); // actual searching of the substring as NOT case-sensitive
			}

			else
			{
				found = textLine.find(searchTerm_f); // actual searching of the substring as case-sensitive

			}

			if (found != std::string::npos) // if searchTerm is found from the textLine (found is NOT npos, means the search returned positive), print that line of text in whole
			{
				if (foundLineNum != std::string::npos) // if the argument 'l' is found, print the line number too
				{
					std::cout << lineNum << ":" << textLine << "" << std::endl;
				}

				else
				{
					std::cout << textLine << std::endl;
				}

				occurrences++;

			}
		}
	}


	reader.close();



	if (foundOccurrence != std::string::npos) // if the argument 'o' is found, print the occurrences too
	{
		if (foundReverse != std::string::npos)
		{

			std::cout << std::endl << std::endl << "Occurrences of lines NOT containing '" << searchTerm_f << "': " << occurrences << std::endl;
		}

		else
		{
			std::cout << std::endl << std::endl << "Occurrences of lines containing '" << searchTerm_f << "': " << occurrences << std::endl;
		}


	}


}


// END OF FINDER WITH EXTENDED ARGS ---------------------------------------------------------------------------












// UPCASER ***************************************************************************


std::string upCaser(std::string original) { // make both dataset and input UPPER CASE to make the search NOT CASE-SENSITIVE

	for (int i = 0; i < original.length(); i++)
	{
		original[i] = (std::toupper(original[i]));
	}

	return original;
}


// END OF UPCASER ---------------------------------------------------------------------------












// END OF FUNCTIONS ---------------------------------------------------------------------------