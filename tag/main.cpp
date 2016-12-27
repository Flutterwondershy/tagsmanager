#include <iostream>

#include <fileref.h>

#include "tags.h"


using namespace std;
using namespace TagLib;

int main(int argc, char* argv[])
{
	FileRef* music = 0;
	bool readMode = true;
	int arg = 1; //On commence à partir de 1
	char* tag = "";
	char* fileName = "";
	char* value = "";


	//Options optionnelle (mode lecture par défaut)
	if(argc > arg)
	{
	    if(argv[arg][0] == '-')
	    {
		switch(argv[arg][1])
		{
		    case 'r':
			readMode = true;
			break;
		    case 'w':
			readMode = false;
			break;
			
		    default:
			cerr << "Attention: Option inatendu." << endl;
			readMode = true;
		}
		if(argv[arg][2] != '\0')
		{
		    cerr << "Attention: Une seule option est attendu." << endl;
		    readMode = true;
		}

		arg++; //On passe au paramètre suivant
	    }
	    else readMode = true;
	}
	
	//On détermine le nom du fichier
	if(argc > arg)
	{
	    fileName = argv[arg];
	    arg++; //Parametre suivant
	}
	else
	{
	    cerr << "Paramètre manquant: fileName." << endl;
	    return 1;
	}
	
	//On détermine le tag à traiter
	if(argc > arg)
	{
	    tag = argv[arg];
	    arg++;
	}
	//Pas d'else car optionnel

	if(!readMode)
	{
	    if(argc > arg)
	    {
		value = argv[arg];
		arg++;
	    }
	    else
	    {
		cerr << "Valeur attendu à l'option 'w'" << endl;
		return 1;
	    }
	}


	music = new FileRef(fileName, readMode);
	if(music->isNull())
	{
	    cerr << "Impossible d'exploiter le fichier \"" << string(fileName) << "\"." << endl;
	    delete music;
	    return 1;
	}
	
	if(!tagsManager(music, readMode, tag, value)) 
		cerr << "tagsManager a renvoyé une erreur" << endl;
	
	delete music;
	return 0;
}
