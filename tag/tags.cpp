#include "tags.h"


bool tagsManager(TagLib::FileRef* music, 
	         bool readMode, 
    	         std::string tag,
	         std::string value)
{
    if(readMode)
    {
		if(!tag.compare("artist"))
			std::cout << music->tag()->artist() << std::endl;
		else if(!tag.compare("album"))
			std::cout << music->tag()->album() << std::endl;
		else if(!tag.compare("comment"))
			std::cout << music->tag()->comment() << std::endl;
		else if(!tag.compare("genre"))
			std::cout << music->tag()->genre() << std::endl;
		else if(!tag.compare("year"))
			std::cout << music->tag()->year() << std::endl;
		else if(!tag.compare("track"))
			std::cout << music->tag()->track() << std::endl;
		else //Par défaut: title
			std::cout << music->tag()->title() << std::endl;

		return true;
    }
    else
    {
	
		if(!tag.compare("artist"))
			music->tag()->setArtist(value);
		else if(!tag.compare("album"))
			music->tag()->setAlbum(value);
		else if(!tag.compare("comment"))
			music->tag()->setComment(value);
		else if(!tag.compare("genre"))
			music->tag()->setGenre(value);
		else if(!tag.compare("year"))
			music->tag()->setYear(atoi(value.c_str()));
		else if(!tag.compare("track"))
			music->tag()->setTrack(atoi(value.c_str()));
		else //Par défaut: title
			music->tag()->setTitle(value);

		return music->save();
    }
}
