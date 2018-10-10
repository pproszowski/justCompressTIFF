#include <iostream>
#include <tiffio.h>
#include <cstdlib>

main(int argc, char* argv[]){

  TIFF* tif = TIFFOpen(argv[1], "r");

  if (tif) {

    uint32 width;
    uint32 height;
    uint32 depth = 0;

    TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);
    TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &height);

    do {
      depth++;
    } while (TIFFReadDirectory(tif));

    std::cout<<"height: "<<height<<std::endl;
    std::cout<<"weight: "<<width<<std::endl;
    std::cout<<"depth: "<<depth<<std::endl;
	}

	TIFFClose(tif);

}

