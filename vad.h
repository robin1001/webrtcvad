// Created on 2017-06-03
// Author: Binbin Zhang

#ifndef WEBRTC_VAD_H_
#define WEBRTC_VAD_H_

#include "webrtc/common_audio/vad/include/webrtc_vad.h"
#include "webrtc/typedefs.h"

// vad wrapper for webrtc vad

class Vad {
public:
    // @param mode, set its aggressiveness mode, which is an integer 
    //              between 0 and 3. 0 is the least aggressive about 
    //              filtering out non-speech, 3 is the most aggressive
    Vad(int mode = 0); 
    virtual ~Vad();
    void SetMode(int mode);
    bool IsSpeech(const int16_t *data, int num_samples, int fs); 
private:
    int mode_;
    VadInst* handle_;
};


#endif
