#include <iostream>
#include <tiffio.h>
#include <cstdlib>

main(int argc, char* argv[]){

  TIFF* tif = TIFFOpen(argv[1], "r");

  if (tif) {

    uint32 width;
    uint32 height;
    uint32 depth = 0;
    uint32 compression;

    TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);
    TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &height);
    TIFFGetField(tif, TIFFTAG_COMPRESSION, &compression);


    do {
      depth++;
    } while (TIFFReadDirectory(tif));

    std::cout<<"height: "<<height<<std::endl;
    std::cout<<"weight: "<<width<<std::endl;
    std::cout<<"depth: "<<depth<<std::endl;
    std::cout<<"compression: "<<compression<<std::endl;
	}

	TIFFClose(tif);

}

