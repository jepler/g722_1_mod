#include "defs.h"
#include "wav_header.h"

struct WaveHeader wave_header_init(UWord16 bandwidth, UWord16 bitsPerSample, UWord32 dataSize) {
    struct  WaveHeader header;

    // Write the RIFF header
    header.riff_header[0] = 'R';
    header.riff_header[1] = 'I';
    header.riff_header[2] = 'F';
    header.riff_header[3] = 'F';

    header.wav_size = dataSize + 36; // Data size + 36 bytes for the header

    header.wave_header[0] = 'W';
    header.wave_header[1] = 'A';
    header.wave_header[2] = 'V';
    header.wave_header[3] = 'E';

    // Write the fmt subchunk
    header.fmt_header[0] = 'f';
    header.fmt_header[1] = 'm';
    header.fmt_header[2] = 't';
    header.fmt_header[3] = ' ';

    header.fmt_chunk_size = 16;     // Subchunk1Size
    header.audio_format = 1;        // AudioFormat (PCM = 1)

    UWord16 numChannels = 1;
    header.num_channels = numChannels;

    UWord32 sampleRate = bandwidth == 7000 ? 16000 : 32000;
    header.sample_rate = sampleRate;

    header.byte_rate = sampleRate * numChannels * bitsPerSample / 8;

    header.sample_alignment = numChannels * bitsPerSample / 8;
    header.bit_depth = bitsPerSample;

    // Write the data subchunk
    header.data_header[0] = 'd';
    header.data_header[1] = 'a';
    header.data_header[2] = 't';
    header.data_header[3] = 'a';

    header.data_bytes = dataSize;

    return header;
}

