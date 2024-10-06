#include <stdio.h>

float temp_value; //float variable defined as temp_value that is used to store the temperature value the user of the program inputs at the beginning
int current_scale; //int variable defined as current_scale that is used to store an integer value(1-3) based on what scale the user wants to use for the temp_value they enter
int conversion_scale; //int variable defined as conversion_scale that is used to store an integer value(1-3) based on what scale the user wants to use for the conversion of their temp_value
float fahrenheit_conversion; //float variable used in the conversion functions when the conversion scale requested is Fahrenheit 
float celsius_conversion; //float variable used in the conversion functions when the conversion scale requested is Celsius
float kelvin_conversion; //float variable used in the conversion functions when the conversion scale requested is Kelvin
float celsius; //float variable used in the categorize_temperature function to determine which print statement to run as output for the categorize_temperature function

float celsius_to_fahrenheit(float temp_value){ //function that converts the temp_value entered by the user from celsius to Fahrenheit
    fahrenheit_conversion = (9.0/5.0)*(temp_value) + 32; //defines fahrenheit_conversion variable to the numerical result of the formula that converts to celsius to fahreneheit 
    printf("Fahrenheit Conversion: %.1f°F", fahrenheit_conversion); //prints the fahrenheit_conversion variable to one decimal place
}

float celsius_to_kelvin(float temp_value){ //function that converts the temp_value entered by the user from celsius to kelvin
    kelvin_conversion = (temp_value) + 273.15; //defines kelvin_conversion variable to the numerical result of the formula that converts to celsius to kelvin
    printf("Kelvin Conversion: %.2fK", kelvin_conversion); //prints the kelvin_conversion variable to two decimal places
}

float fahrenheit_to_celsius(float temp_value){ //function that converts the temp_value entered by the user from Fahrenheit to Celsius
    celsius_conversion = (5.0/9.0)*(temp_value - 32); //defines celsius variable to the numerical result of the formula that converts to fahrenheit to celsius
    printf("Celsius Conversion: %.1f°C", celsius_conversion); //prints the celsius_conversion variable to one decimal place
}

float fahrenheit_to_kelvin(float temp_value){ //function that converts the temp_value entered by the user from Fahrenheit to Kelvin
    kelvin_conversion = (temp_value + 459.67)*(5.0/9.0); //defines kelvin_conversion variable to the numerical result of the formula that converts to fahrenheit to kelvin
    printf("Kelvin Conversion: %.2fK", kelvin_conversion); //prints the kelvin_conversion variable to two decimal places
}

float kelvin_to_celsius(float temp_value){ //function that converts the temp_value entered by the user from Kelvin to Celsius
    celsius_conversion = (temp_value) - 273.15; //defines celsius_conversion variable to the numerical result of the formula that converts to kelvin to celsius
    printf("Celsius Conversion: %.1f°C", celsius_conversion); //prints the celsius_conversion variable to one decimal place
}

float kelvin_to_fahrenheit(float temp_value){ //function that converts the temp_value entered by the user from Kelvin to Fahrenheit
    fahrenheit_conversion = (temp_value)*(9.0/5.0) - 459.67; //defines fahrenheit_conversion variable to the numerical result of the formula that converts to kelvin to fahreneheit
    printf("Fahrenheit Conversion: %.1f°F", fahrenheit_conversion); //prints the fahrenheit_conversion variable to one decimal place
}

void categorize_temperature(float temp_value){ //function that uses the temp_value from the user, and converts it to celsius if the current_scale from the user is not equal to 1, then uses the celsius value to decide which print statements to output. telling the user about the temperature
    if(current_scale == 1){ //checks if the current_scale provided by the user is 1, meaning celsius
        celsius = temp_value; //celsius is set to temp_value since temp_value is already in celsius
    }
    else if(current_scale == 2){ //checks if the current_scale provided by the user is 2, meaning Fahrenheit
        celsius = (5.0/9.0)*(temp_value - 32); //celsius is set to conversion of temp_value from Fahrenheit to Celsius
    }
    else if(current_scale == 3){ //checks if the current_scale provided by the user is 3, meaning kelvin
        celsius = (temp_value) - 273.15; //celsius is set to conversion of temp_value from kelvin to Celsius
    }
    
    if (celsius < 0){ //if the value of the Celsius float is less than 0
        printf("\nFreezing\n"); //print statement describing how the temperature the user inputted feels
        printf("Stay inside"); //print statement that recommends how the user should handle the temperature
    }
    else if(celsius >= 0 && celsius < 10){ //if the value of the Celsius float is less than 10, but greater than or equal to 0
        printf("\nCold\n"); //print statement describing how the temperature the user inputted feels
        printf("Wear a jacket"); //print statement that recommends how the user should handle the temperature
    }
    else if(celsius >=10 && celsius < 25){ //if the value of the Celsius float is less than 25, but greater than or equal to 10
        printf("\nComfortable\n"); //print statement describing how the temperature the user inputted feels
        printf("You should feel comfortable"); //print statement that recommends how the user should handle the temperature
    }
    else if(celsius >= 25 && celsius < 35){ //if the value of the Celsius float is less than 35, but greater than or equal to 25
        printf("\nHot\n"); //print statement describing how the temperature the user inputted feels
        printf("Might be a bit toasty"); //print statement that recommends how the user should handle the temperature
    }
    else if(celsius >= 35){ //if the value of the Celsius float is greater than 35
        printf("\nExtreme Heat\n"); //print statement describing how the temperature the user inputted feels
        printf("Stay indoors with A/C"); //print statement that recommends how the user should handle the temperature
    }
}

int main(){ //main function
    printf("Enter the temperature value: "); //print statement that asks the user to enter a temperature value
    scanf("%f", &temp_value); //stores the user's temperature input to the temp_value float

    printf("Choose the current scale (1)Celsius, (2)Fahrenheit, (3)Kelvin: "); //print statement that asks the user to enter an integer corresponding to one of the 3 temperature scale options, for the temperature value they typed in
    scanf("%d", &current_scale); //stores the scale chosen to the current_scale variable defined at the beginning of the code
    if (current_scale > 3 || current_scale < 1){ //checks to see if the current_scale typed in by the user is outside the bounds (1-3)
        printf("ERROR: Invalid scale selection. Please choose a scale 1-3 \n"); //prints an error message if the selection for scale is invalid
        while (current_scale > 3 || current_scale < 1){ //while loop that continues until the current_scale value is valid (between 1 and 3)
            printf("Choose the current scale (1)Celsius, (2)Fahrenheit, (3)Kelvin: "); //print statement that asks the user to enter an integer corresponding to one of the 3 temperature scale options, for the temperature value they typed in
            scanf("%d", &current_scale); //stores the scale chosen to the current_scale variable defined at the beginning of the code
        }
    }

    printf("Convert to (1)Celsius, (2)Fahrenheit, (3)Kelvin: "); //print statement that asks the user to enter an integer corresponding to one of the 3 temperature scale options. This is the conversion scale that their temperature will be converted to, so it should not match the initial scale they typed above(current_scale)
    scanf("%d", &conversion_scale); //stores the integer entered to the conversion_scale variable declared at the beginning of the code 
    if (conversion_scale > 3 || conversion_scale < 0){ //if statement that ensures the conversion_scale variable is an integer in the bounds (1-3)
        printf("ERROR: Invalid scale selection. Please choose a scale 1-3 \n"); //print statement if the conversion_scale variable is outside the bounds
        while(conversion_scale > 3 || conversion_scale < 0){ //while loop that runs until the conversion_scale variable is a valid integer inside the bounds
            printf("Convert to (1)Celsius, (2)Fahrenheit, (3)Kelvin: "); //print statement that asks the user to enter an integer corresponding to one of the 3 temperature scale options. This is the conversion scale that their temperature will be converted to, so it should not match the initial scale they typed above(current_scale)
            scanf("%d", &conversion_scale); //stores the integer entered to the conversion_scale variable declared at the beginning of the code 
        }
    }

    if(current_scale == conversion_scale){ //if statement that checks if the current_scale value and the conversion_scale value are the same. They should not be, because then there would be no conversion to do, so the user will have to input a new converesion scale
        printf("ERROR: The conversion scale entered matches the original scale inputted. Please choose another scale for conversion: \n"); //print statement that tells the user what the error is
        while(conversion_scale == current_scale){ //while loop that continues until the conversion scale and the current_scale are different values
            printf("Convert temperature to (1)Celsius, (2)Fahrenheit, (3)Kelvin: "); //print statement that asks the user to enter an integer corresponding to one of the 3 temperature scale options. This is the conversion scale that their temperature will be converted to, so it should not match the initial scale they typed above(current_scale)
            scanf("%d", &conversion_scale); //stores the integer entered to the conversion_scale variable declared at the beginning of the code 
        }
    }

    if(current_scale == 1){ //if statement that checks to see if the current_scale is equal to 1
        if(conversion_scale == 2){ //if statement that checks if the conversion_scale value is equal to 2
            celsius_to_fahrenheit(temp_value); //calls the celsius_to_fahrenheit function with the user's temp_value as a parameter
        }
        else if(conversion_scale == 3){ //else-if statement that checks if the conversion_scale value is equal to 3, if it's not 2
            while(temp_value < -273.15){ //while loop that continues until the temp_value float is greater than 273.15, since kelvin can't be negative
                printf("ERROR: the original temp value entered results in a negative Kelvin reading. Enter a different temperature value before converting to Kelvin: \n "); //print statement that tells the user what error has occured
                printf("Enter the temperature value: "); //print statement that asks the user to re-enter their temperature value to a valid one
                scanf("%f", &temp_value); //stores the value entered to the temp_value float
            }
            celsius_to_kelvin(temp_value); //calls the celsius_to_kelvin function with the user's temp_value as a parameter
        }
    }
    else if(current_scale == 2){ //if statement that checks to see if the current_scale is equal to 2
        if(conversion_scale == 1){ //if statement that checks to see if the conversion_scale is equal to 1
            fahrenheit_to_celsius(temp_value); //calls the fahrenheit_to_celsius function with the user's temp_value as a parameter
        }
        else if(conversion_scale == 3){ //else-if statement that checks if the conversion_scale value is equal to 3, if it's not 1
            while(temp_value < -459.67){ //while loop that continues until the temp_value float is greater than 459.67, since kelvin can't be negative
                printf("ERROR: the original temp value entered results in a negative Kelvin reading. Enter a different temperature value before converting to Kelvin: \n "); //print statement that tells the user what error has occured
                printf("Enter the temperature value: "); //print statement that asks the user to re-enter their temperature value to a valid one
                scanf("%f", &temp_value); //stores the value entered to the temp_value float
            }
            fahrenheit_to_kelvin(temp_value); //calls the fahrenheit_to_kelvin function with the user's temp_value as a parameter
        }
    }
    else if(current_scale == 3){ //if statement that checks to see if the current_scale is equal to 3
        while(temp_value < 0){ //while loop that continues until the temp_value float is greater than 0, since kelvin can't be negative
            printf("ERROR: the original temp value entered results in a negative Kelvin reading. Enter a different temperature value before converting to Kelvin: \n "); //print statement that tells the user what error has occured
            printf("Enter the temperature value: "); //print statement that asks the user to re-enter their temperature value to a valid one
            scanf("%f", &temp_value); //stores the value entered to the temp_value float
        }
        if(conversion_scale == 1){ //if statement that checks if the conversion_scale value is equal to 1
            kelvin_to_celsius(temp_value); //calls the kelvin_to_celsius function with the user's temp_value as a parameter
        }
        else if(conversion_scale == 2){ //if statement that checks if the conversion_scale value is equal to 2
            kelvin_to_fahrenheit(temp_value); //calls the kelvin_to_fahrenheit function with the user's temp_value as a parameter
        }
    }
    categorize_temperature(temp_value); //calls the categorize_temperature function with temp_value as a parameter
}
