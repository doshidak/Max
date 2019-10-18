#pragma once

#include "APECompress.h"
#include "BitArray.h"

namespace APE
{

class CPrepare;
class IPredictorCompress;

/*************************************************************************************************
CAPECompressCore - manages the core of compression and bitstream output
*************************************************************************************************/
class  CAPECompressCore
{
public:
    CAPECompressCore(CIO * pIO, const WAVEFORMATEX * pwfeInput, intn nMaxFrameBlocks, intn nCompressionLevel);
    ~CAPECompressCore();

    int EncodeFrame(const void * pInputData, intn nInputBytes);

    CBitArray * GetBitArray() { return m_spBitArray.GetPtr(); }
    intn GetPeakLevel() { return m_nPeakLevel; }

private:
    int Prepare(const void * pInputData, int nInputBytes, int * pSpecialCodes);

    CSmartPtr<CBitArray> m_spBitArray;
	IPredictorCompress * m_aryPredictors[8];
    BIT_ARRAY_STATE m_aryBitArrayStates[8];
	CSmartPtr<int> m_spData;
    CSmartPtr<int> m_spTempData;
    CSmartPtr<CPrepare> m_spPrepare;
    WAVEFORMATEX m_wfeInput;
	intn m_nPeakLevel;
	intn m_nMaxFrameBlocks;
};

}
