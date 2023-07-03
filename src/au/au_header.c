#include "defs.h"
#include "au_header.h"

struct AudioHeader au_header_init(UWord16 bandwidth, UWord16 bitRate, UWord32 totalAudioFrames, UWord32 wordsCount) {
    struct AudioHeader header;
    header.AU[0] = 'A';
    header.AU[1] = 'U';

    header.sampleRate = bandwidth == 7000 ? 16000 : 32000;
    header.bitRate = bitRate / 10;
    header.channels = 1;

    header.totalAudioFrames = totalAudioFrames;
    header.sizeOfAudioBinary = wordsCount;

    header.markFlag = 0;
    header.silenceFlag = 0;

    header._unknown1 = 0;
    header._unknown2 = 0;  //  it is supposed to by always 0xffff, but cloudpets writes 0x0000
    header._unknown3 = 0;

    header.headerSize = AUDIOHEADER_DEFAULTSIZE;

    header.headerEnd = 0xffffffff;

    return header;
}

#if 0
struct MarkTable au_marktable_read(FILE *inputStream) {
    struct MarkTable markTable;

    Word32 readLength = fread(&markTable.tableLength, 2, 1, inputStream);

    // Ignore the table. Just skip it

}
#endif
