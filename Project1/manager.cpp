/*
This class is used to manage the interactions between external entities and the
manager class will in take all lines from the "txt' file and analyze the first
character of the line and send the command to the appropriate container.

*/
#include "manager.h"

	
void Manager::intakeDataFromFile(ifstream & intakeFile){
	char movieCode;
	intakeFile >> movieCode;
	emptyObject =  objFactory.createIt(movieCode); //new Obj
	emptyObject->setData(intakeFile);
	containerArray.insertIt(movieCode, emptyObject);
	emptyObject = NULL;
	if (!intakeFile.eof()){
		intakeDataFromFile(intakeFile);
	}
}

Manager::~Manager(){
	delete emptyObject;
	emptyObject = NULL;
	//other two attributes delete on their own
}


void Manager::printContainer(ostream & output, ObjectController & toPrint){
	toPrint.print(output);
}

void Manager::print(ostream & output){
	printContainer(output, containerArray);
}

	//peek and get line are from ifstream class itself