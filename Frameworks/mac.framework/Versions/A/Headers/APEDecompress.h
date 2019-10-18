#pragma once

#include "UnBitArrayBase.h"
#include "MACLib.h"
#include "Prepare.h"
#include "CircleBuffer.h"

namespace APE
{

class CUnBitArray;
class CPrepare;
class CAPEInfo;
class IPredictorDecompress;

class CAPEDecompress : public IAPEDecompress
{
public:
    CAPEDecompress(int * pErrorCode, CAPEInfo * pAPEInfo, int64 nStartBlock = -1, int64 nFinishBlock = -1);
    ~CAPEDecompress();

    int GetData(char * pBuffer, intn nBlocks, intn * pBlocksRetrieved);
    int Seek(intn nBlockOffset);

    intn GetInfo(APE_DECOMPRESS_FIELDS Field, intn nParam1 = 0, intn nParam2 = 0);

protected:
    // file info
    intn m_nBlockAlign;
    intn m_nCurrentFrame;
    
    // start / finish information
    int64 m_nStartBlock;
    int64 m_nFinishBlock;
    int64 m_nCurrentBlock;
    bool m_bIsRanged;
    bool m_bDecompressorInitialized;

    // decoding tools    
    CPrepare m_Prepare;
    WAVEFORMATEX m_wfeInput;
    unsigned int m_nCRC;
    unsigned int m_nStoredCRC;
    int m_nSpecialCodes;
	int * m_paryChannelData;
    
    int SeekToFrame(intn nFrameIndex);
    void DecodeBlocksToFrameBuffer(intn nBlocks);
    int FillFrameBuffer();
    void StartFrame();
    void EndFrame();
    int InitializeDecompressor();

    // more decoding components
    CSmartPtr<CAPEInfo> m_spAPEInfo;
    CSmartPtr<CUnBitArrayBase> m_spUnBitArray;
    UNBIT_ARRAY_STATE m_aryBitArrayStates[8];
	IPredictorDecompress * m_aryPredictor[8];
    int m_nLastX;
    
    // decoding buffer
    bool m_bErrorDecodingCurrentFrame;
    intn m_nErrorDecodingCurrentFrameOutputSilenceBlocks;
    intn m_nCurrentFrameBufferBlock;
    intn m_nFrameBufferFinishedBlocks;
    CCircleBuffer m_cbFrameBuffer;
};

}
