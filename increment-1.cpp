#include<iostream>
#include<string>
#include<algorithm>



// PROTOTYPES ***************************************************************************
void finderFunc();

// END OF PROTOTYPES ---------------------------------------------------------------------------









int main() {

	finderFunc();



	return 0;
}








// FUNCTIONS ***************************************************************************



// FINDER ***************************************************************************

void finderFunc() {
	std::string dataset = "", input = "";

	while (dataset.length() == 0)
	{
		std::cout << "Give a string from which to search for: ";
		getline(std::cin, dataset);
	}

	while (input.length() == 0 || input.length() > dataset.length())
	{
		std::cout << "Give search string: ";
		getline(std::cin, input);
	}

	size_t found = dataset.find(input);



	if (found != std::string::npos)
	{
		std::cout << "'" << input << "' found in '" << dataset << "' in position " << found << std::endl;
	}

	else
	{
		std::cout << "'" << input << "' NOT found in '" << dataset << "'" << std::endl;
	}

}


// END OF FINDER ---------------------------------------------------------------------------


// END OF FUNCTIONS ---------------------------------------------------------------------------


