/*Name: Ethan Johnson
Date: October 15, 2023
Project Name: MyFitnessFriend (Midterm Porject)
Project Description: MyFitnessPal is a calorie tracker that asks the user to enter information about themselves to calculate their maintenance calorie level.
The user is given multiple meal and beverage options to choose from, and their choices will determine the total calorie count for that meal.*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include<string>

using namespace std;

int main() {

	string softwareName = "MyFitnessFriend", userName, meal1 = "6 eggs , 2 english muffins, & 1 banana", meal2 = "Shredded chicken thighs (12 ounces) & mashed potatoes (2 cups)", 
		meal3 = "Ground beef (12 ounces) & white rice (1 cup)", meal4 = "Greek yogurt (2 cups) with frozen berries and granola", 
		shake = "Protein shake (8 ounces of milk, 1 scoop of protein powder, 1 banana)", beverage1 = "Water", beverage2 = "Cranberry juice (12 ounces)", 
		beverage3 = "Orange juice (12 ounces)", beverage4 = "Lemonade (12 ounces)", bodyWeightGoal1 = "Lose weight", bodyWeightGoal2 = "Maintain weight", bodyWeightGoal3 = "Lose weight";
	const int MEAL_1_CALORIES = 780, MEAL_2_CALORIES = 600, MEAL_3_CALORIES = 770, MEAL_4_CALORIES = 580, SHAKE_CALORIES = 360, BEVERAGE_1_CALORIES = 0, BEVERAGE_2_CALORIES = 170,
		BEVERAGE_3_CALORIES = 150, BEVERAGE_4_CALORIES = 105;
	int mealNumber, beverageNumber, totalCalories, refillCount, beverageCalories, bodyWeightGoal, userActivityLevel;
	double userBodyWeight, userHeight, userAge, maintenanceCalories;
	char refillResponse, laterRefillResponse, userSex;

	cout << "Welcome to " << softwareName << "!";
	cout << "\n\nStart your log by entering your biological sex (M for male and F for female): ";
	cin >> userSex;
	cout << "\nEnter your bodyweight in kilograms, to the nearest decimal: ";
	cin >> userBodyWeight;
	cout << "\nEnter your height in centimeters to the nearest whole number: ";
	cin >> userHeight;
	cout << "\nEnter your age in years, rounded to the nearest whole number: ";
	cin >> userAge;
	cout << "\nEnter your weekly activity level on a scale of 1-3 (1 being little to no activity and 3 being high activity): ";
	cin >> userActivityLevel;
	
	switch (userActivityLevel) {
	case 1:
		if (userActivityLevel == 1 && (userSex == 'm' || userSex == 'M')) {
			maintenanceCalories = ceil(((10 * userBodyWeight) + (6.25 * userHeight) - (5 * userAge) + 5) * 1.2);
		}
		else if (userActivityLevel == 1 && (userSex == 'f' || userSex == 'F')) {
			maintenanceCalories = ceil(((10 * userBodyWeight) + (6.25 * userHeight) - (5 * userAge) - 161) * 1.2);
		}
		break;
	case 2:
		if (userActivityLevel == 2 && (userSex == 'm' || userSex == 'M')) {
			maintenanceCalories = ceil(((10 * userBodyWeight) + (6.25 * userHeight) - (5 * userAge) + 5) * 1.55);
		}
		else if (userActivityLevel == 2 && (userSex == 'f' || userSex == 'F')) {
			maintenanceCalories = ceil(((10 * userBodyWeight) + (6.25 * userHeight) - (5 * userAge) - 161) * 1.55);
		}
		break;
	case 3:
		if (userActivityLevel == 3 && (userSex == 'm' || userSex == 'M')) {
			maintenanceCalories = ceil(((10 * userBodyWeight) + (6.25 * userHeight) - (5 * userAge) + 5) * 1.9);
		}
		else if (userActivityLevel == 3 && (userSex == 'f' || userSex == 'F')) {
			maintenanceCalories = ceil(((10 * userBodyWeight) + (6.25 * userHeight) - (5 * userAge) - 161) * 1.9);
		}
		break;
	default:
		maintenanceCalories = 2000;
	}
	cout << "\nYour maintenance calorie level is approximately " << maintenanceCalories << " calories.";

	cout << "\n\nFinally, enter your first and last name: ";
	cin.ignore();
	getline(cin, userName);
	cout << "\nWelcome " << userName << ". The meal options are listed below: ";
	cout << "\n1. " << meal1 << setw(55) <<  "Calories: " << MEAL_1_CALORIES;
	cout << "\n2. " << meal2 << setw(31) << "Calories: " << MEAL_2_CALORIES;
	cout << "\n3. " << meal3 << setw(49) << "Calories: " << MEAL_3_CALORIES;
	cout << "\n4. " << meal4 << setw(40) << "Calories: " << MEAL_4_CALORIES;
	cout << "\n5. " << shake << setw(24) << "Calories: " << SHAKE_CALORIES;
	cout << "\n\nEnter the corresponding number for the meal you ate: ";
	cin >> mealNumber;

	if (mealNumber == 1) {
		totalCalories = MEAL_1_CALORIES;
	}
	else if (mealNumber == 2) {
		totalCalories = MEAL_2_CALORIES;
	}
	else if (mealNumber == 3) {
		totalCalories = MEAL_3_CALORIES;
	}
	else if (mealNumber == 4) {
		totalCalories = MEAL_4_CALORIES;
	}
	else if (mealNumber == 5) {
		totalCalories = SHAKE_CALORIES;
	}
	else {
		cout << "\nPlease enter a valid meal option number.";
	}
	cout << "\nThank you! Your total calorie consumption is: " << totalCalories;

	cout << "\n\nThe beverage options are listed below:";
	cout << "\n1. " << beverage1 << setw(88) << "Calories: " << BEVERAGE_1_CALORIES;
	cout << "\n2. " << beverage2 << setw(66) << "Calories: " << BEVERAGE_2_CALORIES;
	cout << "\n3. " << beverage3 << setw(69) << "Calories: " << BEVERAGE_3_CALORIES;
	cout << "\n4. " << beverage4 << setw(73) << "Calories: " << BEVERAGE_4_CALORIES;
	cout << "\n\nEnter the corresponding number for the beverage option you would like to choose: ";
	cin >> beverageNumber;

	if (beverageNumber == 1) {
		beverageCalories = BEVERAGE_1_CALORIES;
		totalCalories += BEVERAGE_1_CALORIES;
	}
	else if (beverageNumber == 2) {
		beverageCalories = BEVERAGE_2_CALORIES;
		totalCalories += BEVERAGE_2_CALORIES;
	}
	else if (beverageNumber == 3) {
		beverageCalories = BEVERAGE_3_CALORIES;
		totalCalories += BEVERAGE_3_CALORIES;
	}
	else if (beverageNumber == 4) {
		beverageCalories = BEVERAGE_4_CALORIES;
		totalCalories += BEVERAGE_4_CALORIES;
	}
	else {
		cout << "\nPlease enter a valid beverage option number.";
	}
	cout << "\nThank you! Your total calorie consumption is: " << totalCalories;

	cout << "\n\nDid you have any beverage refills? Enter Y for yes and N for no: ";
	cin >> refillResponse;

	if (refillResponse == 'Y' || refillResponse == 'y') {
		cout << "\nEnter the number of refills you had: ";
		cin >> refillCount;
		totalCalories += (beverageCalories * refillCount);
		cout << "\nThank you! Your total calorie consumption is: " << totalCalories;
	}
	else if (refillResponse == 'N' || refillResponse == 'n') {
		cout << "\nDo you plan to have any refills later? Enter Y for yes and N for no: ";
		cin >> laterRefillResponse;
		if (laterRefillResponse == 'Y' || laterRefillResponse == 'y') {
			cout << "\nEnter the number of refills you plan to have: ";
			cin >> refillCount;
			totalCalories = totalCalories + (beverageCalories * refillCount);
			cout << "\nThank you! Your total calorie consumption will be: " << totalCalories << ". I hope you enjoyed your meal!";
		}
		else if (laterRefillResponse == 'N' || laterRefillResponse == 'n') {
			cout << "\nThank you! I hope you enjoyed your meal!";
		}
		else {
			cout << "\nPlease enter a valid response.";
		}
	}
	else {
		cout << "\nPlease enter a valid response.";
	}

	cout << endl << endl;
	system("pause");
	return 0;
}