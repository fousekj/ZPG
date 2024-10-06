#include "App.h"

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

/**
 * @file main.cpp
 *
 * @brief Main function
 *
 * @author Jiří Fousek
  **/



int main(void)
{
	
	App* app = new App();
	app->initialization();
	app->run();


}
