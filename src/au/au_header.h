#pragma once
// based on: https://www.exploitee.rs/index.php/Teddy_Ruxpin

#define AUDIOHEADER_DEFAULTSIZE 16          // words

struct AudioHeader {
    char AU[2]; // always "AU"
    UWord16 sampleRate; // always 16,000Hz
    /**
     * (compressed) bit rate = bitRate * 10
     */
    UWord16 bitRate; // always 3200 (32 kbps)
    UWord16 channels; // always 1 (mono)
    UWord32 totalAudioFrames;
    /**
     * size (in bytes) = sizeOfAudioBinary * 2
     *
     * Also at 32 kbps, each block is 80 bytes,
     * so this is also equal to totalAudioFrames * 80
     *
     * Note: Some 0xFFs will normally pad audio binary data afterwards.
     */
    UWord32 sizeOfAudioBinary;          // in words
    UWord16 markFlag; // always 1 (enabled)
    UWord16 silenceFlag; // always 0 (disabled)

    UWord16 _unknown1; // always 0x0
    UWord16 _unknown2; // always 0xFFFF
    UWord16 _unknown3; // always 0x0

    /**
     * Audio binary data proceeds this header struct.
     * Use the header size to figure its starting address.
     */
    UWord16 headerSize;                 // in words

    UWord32 headerEnd;
};

/**
 * A table which coordinates eye animations and mouth movement, with audio.
 */
typedef struct MarkTable {
    /**
     * size (in bytes) = tableLength * 2
     */
    UWord16 tableLength;

    /**
     * Entries in the table are sequential.
     * Each entry has a duration (milliseconds) and an identifier.
     * The duration represents a period of time that elapses before the next action.
     *
     * If the duration is equal or below 32,767 ms, then the entry is as follows:
     * uint16_t duration;
     * uint16_t identifier;
     *
     * If the duration exceeds 32,767 ms, then the entry is 6 bytes is as follows:
     * uint16_t durationUpper;
     * uint16_t durationLower;
     * uint16_t identifier;
     *
     * Where:
     * - durationUpper must have MSB set (i.e. durationUpper & 0x8000 === durationUpper is true)
     * - duration = (durationUpper & 0x7FFF) << 16 + durationLower;
     *
     * Identifiers:
     * - 0x00 mouth closed
     * - 0x01 mouth half open
     * - 0x02 mouth fully open
     * - >= 0x03 matches an animationId
     * - >= 0x60 (To be confirmed)
     */
    UWord16 tableWords[];

} MarkTable;

/**
 * Prototypes
 **/

struct AudioHeader au_header_init(UWord16 sampleRate, UWord16 bitRate, UWord32 totalAudioFrames, UWord32 wordsCount);
