#ifndef TAGS_H_INCLUDED
#define TAGS_H_INCLUDED
    #include <string>
    #include <iostream>
    #include <cstdlib>

    #include <fileref.h>

    bool tagsManager(TagLib::FileRef* music, 
		     bool readMode, 
		     std::string tag,
		     std::string value);

#endif //TAGS_H_INCLUDED
