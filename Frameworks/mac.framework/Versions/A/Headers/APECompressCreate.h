#pragma once

#include "APECompress.h"

namespace APE
{
class CAPECompressCore;

class CAPECompressCreate
{
public:
    CAPECompressCreate();
    ~CAPECompressCreate();
    
    int InitializeFile(CIO * pIO, const WAVEFORMATEX * pwfeInput, intn nMaxFrames, intn nCompressionLevel, const void * pHeaderData, int64 nHeaderBytes);
    int FinalizeFile(CIO * pIO, int nNumberOfFrames, int nFinalFrameBlocks, const void * pTerminatingData, int64 nTerminatingBytes, int64 nWAVTerminatingBytes);
    
    int SetSeekByte(int nFrame, int nByteOffset);

    int Start(CIO * pioOutput, const WAVEFORMATEX * pwfeInput, int64 nMaxAudioBytes, intn nCompressionLevel = COMPRESSION_LEVEL_NORMAL, const void * pHeaderData = NULL, int64 nHeaderBytes = CREATE_WAV_HEADER_ON_DECOMPRESSION);
        
    intn GetFullFrameBytes();
    int EncodeFrame(const void * pInputData, intn nInputBytes);

    int Finish(const void * pTerminatingData, int64 nTerminatingBytes, int64 nWAVTerminatingBytes);
    
private:    
    CSmartPtr<uint32> m_spSeekTable;
    intn m_nMaxFrames;

    CSmartPtr<CIO> m_spIO;
    CSmartPtr<CAPECompressCore> m_spAPECompressCore;
    
    WAVEFORMATEX m_wfeInput;
    intn m_nCompressionLevel;
    intn m_nSamplesPerFrame;
    intn m_nFrameIndex;
    intn m_nLastFrameBlocks;
};

}
