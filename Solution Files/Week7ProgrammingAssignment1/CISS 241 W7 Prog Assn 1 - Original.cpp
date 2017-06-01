//This program asks the user for rainfall information for each month, then calculates
//the highest, lowest, average, and total rainfall for the year.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void getRainfall(string[], double[], int);
double getTotal(double[], int);
double getAverage(double[], int);
double getLowest(double[], int, int&);
double getHighest(double[], int, int&);

int main()
{
	//Create a constant variable for array sizes in this program.
	const int ARRAY_SIZE = 12;

	//Create the arrays to store the names of the months and the rainfall amounts.
	string months[ARRAY_SIZE] = { "January", "February", "March",
									"April", "May", "June", "July",
									"August", "September", "October",
									"November", "December" };
	double rainfall[ARRAY_SIZE];

	//Create variables to store the lowest, highest, average, and total rainfall.
	double totalRainfall;
	double averageRainfall;
	double highestRainfall;
	double lowestRainfall;
	int indexOfLowest = 0;
	int indexOfHighest = 0;

	//Display a welcome message to the user.
	cout << "Welcome to the Rainfall program.\n"
		<< "This program will ask you to input the amount of rainfall\n"
		<< "for each month, and then will calculate the total rainfall\n"
		<< "for the year, the average rainfall, and the months in which\n"
		<< "the greatest and least amounts of rainfall occurred.\n\n";

	//Have the user input the rainfall for each month.
	getRainfall(months, rainfall, ARRAY_SIZE);
	cout << endl;

	//Calculate the total rainfall for the year.
	totalRainfall = getTotal(rainfall, ARRAY_SIZE);

	//Calculate the average rainfall for the year.
	averageRainfall = getAverage(rainfall, ARRAY_SIZE);

	//Find the lowest value in the rainfall array.
	lowestRainfall = getLowest(rainfall, ARRAY_SIZE, indexOfLowest);

	//Find the highest value in the rainfall array
	highestRainfall = getHighest(rainfall, ARRAY_SIZE, indexOfHighest);

	//Display all the information for the user (could be made into a separate function)
	//Set output formatting
	cout << fixed << showpoint << setprecision(2);

	//Show the rainfall data that the user entered
	cout << "You have entered the following information:\n\n";
	cout << setw(16) << left << "Month" << "Rainfall\n"
		<< "***************************************\n";
	for (int index = 0; index < ARRAY_SIZE; index++)
		cout << setw(16) << left << months[index] << setw(8) << right << rainfall[index] << endl;
	
	cout << endl;

	//Show the total rainfall for the year
	cout << "The total rainfall for this year was " << totalRainfall << " inches.\n\n";

	//Show the average rainfall for the year
	cout << "The average rainfall for the year was " << averageRainfall << " inches per month.\n\n";

	//Show the month in which the lowest rainfall occurred.
	cout << "The month with the least amount of rain was ";
	cout << months[indexOfLowest];
	cout << ",\nwith ";
	cout << rainfall[indexOfLowest];
	cout << " inches of rain.\n\n";

	//Show the month in which the highest rainfall occurred.
	cout << "The month with the greatest amount of rain was ";
	cout << months[indexOfHighest];
	cout << ",\nwith ";
	cout << rainfall[indexOfHighest];
	cout << " inches of rain.\n\n";

	return 0;
}

void getRainfall(string displayMonth[], double getRainfall[], int SIZE)
{
	cout << "Please input the amount of rainfall for each month.\n\n";
	for (int index = 0; index < SIZE; index++)
	{
		cout << displayMonth[index] << ": ";
		cin >> getRainfall[index];

		//Validate the input
		while (getRainfall[index] < 0)
		{
			cout << "Error: You must input a number greater than 0. Please try again.\n\n";
			cout << displayMonth[index] << ": ";
			cin >> getRainfall[index];
		}
	}
}

double getTotal(double totalRainfall[], int SIZE)
{
	//Set an accumulator for the total and initialize it to 0.
	double total = 0;

	for (int index = 0; index < SIZE; index++)
		total += totalRainfall[index];

	//Send the final total back to the main() function.
	return total;
}

double getAverage(double averageRainfall[], int SIZE)
{
	//Set an accumulator for the total and initialize it to 0.
	double total = 0;

	//Define a variable for the average.
	double average;

	//Calculate the total of the array elements.
	for (int index = 0; index < SIZE; index++)
	{
		total += averageRainfall[index];
	}

	//Calculate the average and store it in the appropriate variable.
	average = total / SIZE;

	//Return the average to the main() function.
	return average;
}

double getLowest(double lowestRainfall[], int SIZE, int &lowestIndex)
{
	int lowest = lowestRainfall[0];

	for (int index = 0; index < SIZE; index++)
	{
		if (lowestRainfall[index] < lowest)
		{
			lowest = lowestRainfall[index];
			lowestIndex = index;
		}
	}
	
	return lowest;
}

double getHighest(double highestRainfall[], int SIZE, int &highestIndex)
{
	int highest = highestRainfall[0];

	for (int index = 0; index < SIZE; index++)
	{
		if (highestRainfall[index] > highest)
		{
			highest = highestRainfall[index];
			highestIndex = index;
		}
	}

	return highest;
}