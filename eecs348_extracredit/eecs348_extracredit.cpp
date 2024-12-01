#include <iostream>
#include <iomanip> // For formatting a double-precision number.
#include <string>
// Add this line to avoid repeating std::
using namespace std;
// Prototype for the extractNumeric function
double extractNumeric(const string& str);
int operatorCount(string expression);
int main(){
    string input;
    while(true)
    {
        //Ask the user for input
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;
        //Exit condition 
        if (input == "END"){
            break;
        }
        //Function call to get number from string 
        double number = extractNumeric(input);

        if (number != -999999.99){
        //If the function returns a number 
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }

        else{
            //The function returns an error code 
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}

int operatorCount(string expression){
    //This function counts the number of + or - operators in the expression
    int count = 0;
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == '+'|| expression[i] == '-'){
            //Add to the count 
            count++;
        }
    }
    return count;
}
double extractNumeric(const string& str){
    //Track if the number is negitive 
    bool negitive = false;
    //Set exp as a short hand for the input string 
    string exp = str;
    //Storage for the number 
    string number;
    int count = operatorCount(exp);
    //Check if the expression is invaild 
    if(count > 1){return -999999.99;}

    for (int i = 0; i < exp.length(); i++) {
        //Ignore spaces 
        if(isspace(exp[i])){
            continue;
        }
        else if (isalpha(exp[i])){
            //If a letter is in the string the input is invaild 
            return -999999.99;
        }
        else if (isdigit(exp[i]) || exp[i] == '.') {
            //If expected input keep adding to the number
            number += exp[i];
        }
        //Check if the current char is a negitive sign
        else if (exp[i] == '-' && i == 0 ){
            negitive = true;
        }
        else if(exp[i] == '+' && i == 0){
            //Check if the number has a plus sign 
            //Skip that char if so
            continue;
        }
        else{
            //Any other case return an error
            return -999999.99;
        }
    }
    bool decimal_found = false;
    double result = 0.0;
    double times = 1.0;
    //Loop for converting a string to a double number 
    for(int i = 0; i < number.size(); i++){
        if(number[i] == '.'){
            //If we find 2 decimal places return an error 
            if(decimal_found){
                return -999999.99;
            }
            //We found a decimal place 
            decimal_found = true;
            continue;
        }
        if(!decimal_found){
            //Increment the number up 
            result = result * 10 + number[i] - '0';
        }
        else{
            //Add the decimal part 
            times *= .1;
            result += (number[i] - '0') * times;
        }
    }
    if(negitive){
        //If the number in the string was negitive, make the double negitive as well 
        result = -1 * result;
    }
    //Return the final expression
	return result;
}
