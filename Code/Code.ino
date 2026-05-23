#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>
#include <SpotifyEsp32.h>

#define TFT_CS 15
#define TFT_RST 4
#define TFT_DC 2
#define TFT_SCLK 18
#define TFT_MOSI 23
#define TFT_MISO 19
#define TFT_TOUCH_CS 21

#define SPOTIFY_GREEN 0x1EDB
#define BAR_GREY 0x4A49

const char* WIFI_SSID = "Your WiFi SSID";
const char* WIFI_PASS = "Your WiFi Password";
const char* SPOTIFY_CID = "Your Client ID";
const char* SPOTIFY_SEC = "Your Client Secret";

String activeArtist = "";
String activeTrack = "";
bool isPlaying = true;
unsigned long lastTouchTime = 0;

unsigned long trackDuration = 0;
unsigned long trackProgress = 0;
unsigned long lastSyncTime = 0;
int lastFilledWidth = 0;

Adafruit_ILI9341 screen = Adafruit_ILI9341(
  TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST, TFT_MISO
);

XPT2046_Touchscreen touch(TFT_TOUCH_CS);
Spotify sp(SPOTIFY_CID, SPOTIFY_SEC);

void drawThickArc(int x, int y, int r, int startAngle, int endAngle, uint16_t color, int thickness) {
  for (int i = 0; i < thickness; i++) {
    for (int a = startAngle; a <= endAngle; a++) {
      float rad = a * PI / 180.0;
    int px = x + (r-i) * cos(rad);
    int py = y+(r-i)*sin(rad);
    screen.drawPixel(px, py, color);
    } 
  }
}

void playBootAnimation() {
  int centerX = 160;
  int centerY = 100;

  for(int r = 0; r<=60; r+=4){
    screen.fillCircle(centerX, centerY, r, SPOTIFY_GREEN);
    delay(15);
  }

  drawThickArc(centerX, centerY + 40, 60, 220,  320, ILI9341_BLACK, 4);
  delay(100);

  drawThickArc(centerX, centerY + 36, 42, 225, 315, ILI9341_BLACK, 3);
  delay(100);

  drawThickArc(centerX, centerY + 32, 24, 230, 310, ILI9341_BLACK, 3);
  delay(100);

  screen.setTextColor(ILI9341_WHITE);
  screen.setTextSize(2);

  screen.setCursor(60, 180);
  screen.print("BOOTING SYSTEM...");
  delay(400);
}

void updateProgressBar(){
  if (!isPlaying || trackDuration == 0) return;

  unsigned long currentProgress = trackProgress + (millis() - lastSyncTime);
  if (currentProgress > trackDuration) currentProgress = trackDuration;

  int filledWidth = map(currentProgress, 0, trackDuration, 0, 280);

  if (filledWidth > lastFilledWidth) {
    screen.fillRect(20+lastFilledWidth, 180, filledWidth - lastFilledWidth, 10, SPOTIFY_GREEN);
    lastFilledWidth = filledWidth;
  }
}

void connectNetwork() {
  Serial.print("Initializing Link (WiFi)...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while(WiFi.status() != WL_CONNECTED) {
    delay(750);
    Serial.print(".");
  }
  Serial.printf("\n[SUCCESS] Connected! IP: %s\n", WiFi.localIP().toString().c_str()); 
}

void processTouchInput() {
  if (touch.touched() && (millis() - lastTouchTime > 500)) {
    TS_Point p = touch.getPoint();

    if (p.x < 1333) {
      Serial.println("Action: Previous Song");
      sp.previous_song();
      lastFilledWidth = 0;
    }

    else if (p.x > 2666) {
      Serial.println("Action: Next Song");
      sp.next_song();
      lastFilledWidth = 0;
    }

    else {
      if (isPlaying) {
        Serial.println("Action: Pause Song");
        sp.pause();
        trackProgress = trackProgress + (millis() - lastSyncTime);
      }
      else {
        Serial.println("Action: Play Song");
        sp.play();
        lastSyncTime = millis();
      }
      isPlaying =!isPlaying;
    }
    lastTouchTime = millis();
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);

  screen.begin();
  screen.setRotation(1);
  screen.fillScreen(ILI9341_BLACK);
  Serial.println("[SYSTEM] TFT Online!");

  playBootAnimation();

  touch.begin();
  touch.setRotation(1);
  Serial.println("[SYSTEM] Touch Controller Online!");

  connectNetwork();

  screen.fillScreen(ILI9341_BLACK);
  screen.setCursor(30, 110);
  screen.setTextColor(ILI9341_WHITE);
  screen.setTextSize(2);
  screen.print("Authenticating Spotify...");

  sp.begin();
  while(!sp.is_auth()) {
    sp.handle_client();
  }

  screen.fillScreen(ILI9341_BLACK);
  Serial.println("[SYSTEM] Spotify Auth Complete!");
}

void loop() {
  processTouchInput();

  String fetchedArtist = sp.current_artist_names();
  String fetchedTrack = sp.current_track_name();

  bool isValidData = (fetchedArtist != "Something went wrong!" && !fetchedArtist.isEmpty() && fetchedTrack != "null");

  if (isValidData && (fetchedTrack != activeTrack || fetchedArtist != activeArtist)) {
    activeArtist = fetchedArtist;
    activeTrack = fetchedTrack;

    trackDuration = sp.duration_ms();
    trackProgress = sp.progress_ms();
    lastSyncTime = millis();
    lastFilledWidth = 0;

    screen.fillScreen(ILI9341_BLACK);

    Serial.println(">>> Now Playing <<<");
    Serial.println("Track: " +activeTrack);
    Serial.println("Artist: " +activeArtist);

    screen.setCursor(20, 60);
    screen.setTextColor(SPOTIFY_GREEN);
    screen.setTextSize(2);
    screen.print(activeArtist);

    screen.setCursor(20, 110);
    screen.setTextColor(ILI9341_WHITE);
    screen.setTextSize(2);
    screen.print(activeTrack);

    screen.fillRect(20, 180, 280, 10, BAR_GREY);
  }

  updateProgressBar();

  delay(100);
}