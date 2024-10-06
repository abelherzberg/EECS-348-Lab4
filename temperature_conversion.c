#include <stdio.h>

float temp_value;
int current_scale;
int conversion_scale;
float fahrenheit_conversion;
float fahrenheit_conversion;
float celsius_conversion;
float kelvin_conversion;
float celsius;

float celsius_to_fahrenheit(float temp_value){
    fahrenheit_conversion = (9.0/5.0)*(temp_value) + 32;
    printf("Fahrenheit Conversion: %.1f°F", fahrenheit_conversion);
}

float celsius_to_kelvin(float temp_value){
    kelvin_conversion = (temp_value) + 273.15;
    printf("Kelvin Conversion: %.2fK", kelvin_conversion);
}

float fahrenheit_to_celsius(float temp_value){
    celsius_conversion = (5.0/9.0)*(temp_value - 32);
    printf("Celsius Conversion: %.1f°C", celsius_conversion);
}

float fahrenheit_to_kelvin(float temp_value){
    kelvin_conversion = (temp_value + 459.67)*(5.0/9.0);
    printf("Kelvin Conversion: %.2fK", kelvin_conversion);
}

float kelvin_to_celsius(float temp_value){
    celsius_conversion = (temp_value) - 273.15;
    printf("Celsius Conversion: %.1f°C", celsius_conversion);
}

float kelvin_to_fahrenheit(float temp_value){
    fahrenheit_conversion = (temp_value)*(9.0/5.0) - 459.67;
    printf("Fahrenheit Conversion: %.1f°F", fahrenheit_conversion);
}

void categorize_temperature(float temp_value){
    if(current_scale == 1){
        celsius = temp_value;
    }
    else if(current_scale == 2){
        celsius = (5/9)*(temp_value - 32);
    }
    else if(current_scale == 3){
        celsius = (temp_value) - 273.15;
    }
    
    if (celsius < 0){
        printf("\nFreezing\n");
        printf("Stay inside");
    }
    else if(celsius >= 0 && celsius < 10){
        printf("\nCold\n");
        printf("Wear a jacket");
    }
    else if(celsius >=10 && celsius < 25){
        printf("\nComfortable\n");
        printf("You should feel comfortable");
    }
    else if(celsius >= 25 && celsius < 35){
        printf("\nHot\n");
        printf("Might be a bit toasty");
    }
    else if(celsius >= 35){
        printf("\nExtreme Heat\n");
        printf("Stay indoors with A/C");
    }
}

int main(){
    printf("Enter the temperature value: ");
    scanf("%f", &temp_value);

    printf("Choose the current scale (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
    scanf("%d", &current_scale);
    if (current_scale > 3 || current_scale < 1){
        printf("ERROR: Invalid scale selection. Please choose a scale 1-3 \n");
        while (current_scale > 3 || current_scale < 1){
            printf("Choose the current scale (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
            scanf("%d", &current_scale);
        }
    }

    printf("Convert to (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
    scanf("%d", &conversion_scale);
    if (conversion_scale > 3 || conversion_scale < 0){
        printf("ERROR: Invalid scale selection. Please choose a scale 1-3 \n");
        while(conversion_scale > 3 || conversion_scale < 0){
            printf("Convert to (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
            scanf("%d", &conversion_scale);
        }
    }

    if(current_scale == conversion_scale){
        printf("ERROR: The conversion scale entered matches the original scale inputted. Please choose another scale for conversion: \n");
        while(conversion_scale == current_scale){
            printf("Convert temperature to (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
            scanf("%d", &conversion_scale);
        }
    }

    if(current_scale == 1){
        if(conversion_scale == 2){
            celsius_to_fahrenheit(temp_value);
        }
        else if(conversion_scale == 3){
            while(temp_value < -273.15){
                printf("ERROR: the original temp value entered results in a negative Kelvin reading. Enter a different temperature value before converting to Kelvin: \n ");
                printf("Enter the temperature value: ");
                scanf("%f", &temp_value);
            }
            celsius_to_kelvin(temp_value);
        }
    }
    else if(current_scale == 2){
        if(conversion_scale == 1){
            fahrenheit_to_celsius(temp_value);
        }
        else if(conversion_scale == 3){
            while(temp_value < -459.67){
                printf("ERROR: the original temp value entered results in a negative Kelvin reading. Enter a different temperature value before converting to Kelvin: \n ");
                printf("Enter the temperature value: ");
                scanf("%f", &temp_value);
            }
            fahrenheit_to_kelvin(temp_value);
        }
    }
    else if(current_scale == 3){
        while(temp_value < 0){
            printf("ERROR: the original temp value entered results in a negative Kelvin reading. Enter a different temperature value before converting to Kelvin: \n ");
            printf("Enter the temperature value: ");
            scanf("%f", &temp_value);
        }
        if(conversion_scale == 1){
            kelvin_to_celsius(temp_value);
        }
        else if(conversion_scale == 2){
            kelvin_to_fahrenheit(temp_value);
        }
    }
    categorize_temperature(temp_value);
}