// Created on 2017-06-03
// Author: Binbin Zhang

#include "vad.h"
#include "stdio.h"
#include "stdlib.h"

Vad::Vad(int mode): mode_(mode) {
    if (WebRtcVad_Create(&handle_) < 0) {
        printf("Create webrtc vad handle error\n");
        exit(-1);
    }
    WebRtcVad_Init(handle_);
    WebRtcVad_set_mode(handle_, mode_);
}

Vad::~Vad() {
    WebRtcVad_Free(handle_);
}

void Vad::SetMode(int mode) {
    mode_ = mode;
    WebRtcVad_set_mode(handle_, mode_);
}

bool Vad::IsSpeech(const int16_t *data, int num_samples, int fs) {
    int ret = WebRtcVad_Process(handle_, fs, data, num_samples);
    switch (ret) {
        case 0:
            return false;
        case 1:
            return true;
        default:
            printf("WebRtcVad_Process error, check sample rate or frame length\n");
            exit(-1);
            return false;
    }
}






