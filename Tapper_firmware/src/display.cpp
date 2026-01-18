#include "display.h"

#ifdef HAS_TFT

#include <TFT_eSPI.h>

static TFT_eSPI tft = TFT_eSPI();

void Display::display_init() {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLUE);
    tft.setTextDatum(MC_DATUM);  // center text
}

void Display::display_show_bpm(float bpm) {
    int bpmInt = (int)(bpm + 0.5f);

    char buf[8];
    snprintf(buf, sizeof(buf), "%d", bpmInt);

    tft.fillScreen(TFT_BLUE);
    tft.setTextColor(TFT_WHITE, TFT_BLUE);

    tft.setTextFont(7);            // <-- 7-segment compressed font
    tft.setTextDatum(MC_DATUM);
    tft.setTextPadding(tft.width());

    tft.drawString(buf, tft.width() / 2, tft.height() / 2);
}

#endif
