//
// Created by Nicholas Newdigate on 13/04/2020.
//

#ifndef ARDUINO_MIDI_WRITER_XYSCOPEVIEW_H
#define ARDUINO_MIDI_WRITER_XYSCOPEVIEW_H

#include "Arduino.h"
#include <ST7735_t3.h> // Hardware-specific library
#include "Audio.h"

#undef swap
#include <functional>
using namespace std;
#undef swap
#define swap(a, b) { typeof(a) t = a; a = b; b = t; }

class XYScopeView {
public:
    inline XYScopeView(
            ST7735_t3 &tft,
            AudioRecordQueue &recordQueue,
            AudioRecordQueue &recordQueue2,
            int16_t color,
            int16_t backgroundColor,
            int8_t xOffset,
            int8_t yOffset) :
            _tft(&tft),
            _recordQueue(&recordQueue),
            _recordQueue2(&recordQueue2),
            _backgroundColor(backgroundColor),
            _color(color),
            _xOffset(xOffset),
            _yOffset(yOffset){
    };

    void undrawScope();
    void drawScope();
    void checkForUpdateBuffer();

    uint16_t oscilliscope_x = 0;
    uint16_t oscilliscope_x2 = 0;
private:
    ST7735_t3 *_tft;
    AudioRecordQueue *_recordQueue;
    AudioRecordQueue *_recordQueue2;

    int16_t buffer[128];
    int16_t buffer_y[128];
    int16_t lastbuffer[128];
    int16_t lastbuffer_y[128];
    int16_t _backgroundColor;
    int16_t _color;
    int8_t _xOffset;
    int8_t _yOffset;
};

#endif //ARDUINO_MIDI_WRITER_XYSCOPEVIEW_H

