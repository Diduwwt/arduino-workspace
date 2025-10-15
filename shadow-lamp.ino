// 腳位設定
const int buttonPin = 2;   // 按鈕
const int RledPin = 9;     // 紅
const int GledPin = 10;     // 綠
const int BledPin = 11;     // 藍

// 狀態變數
int buttonState = 0;
int lastButtonState = 0;
int colorMode = 0;  // 用來記錄現在是第幾種顏色

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // 使用內建上拉電阻
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);

  // 一開始全關
  setColor(0, 0, 0);
}

void loop() {
  // 讀取按鈕狀態
  buttonState = digitalRead(buttonPin);

  // 檢查按鈕是否從未按 → 被按下
  if (buttonState == LOW && lastButtonState == HIGH) {
    colorMode++;
    if (colorMode > 7) colorMode = 0; // 循環回到暗的狀態
    changeColor(colorMode);
    delay(200);  // 去抖動
  }

  lastButtonState = buttonState;
}

// 設定顏色（共陰極：HIGH=亮, LOW=暗）
void setColor(int r, int g, int b) {
  digitalWrite(RledPin, r ? HIGH : LOW);
  digitalWrite(GledPin, g ? HIGH : LOW);
  digitalWrite(BledPin, b ? HIGH : LOW);
}

// 根據 colorMode 改變顏色
void changeColor(int mode) {
  switch (mode) {
    case 0: setColor(0, 0, 0); break; // 暗
    case 1: setColor(1, 0, 0); break; // 紅
    case 2: setColor(0, 1, 0); break; // 綠
    case 3: setColor(0, 0, 1); break; // 藍
    case 4: setColor(1, 1, 0); break; // 黃
    case 5: setColor(1, 0, 1); break; // 紫
    case 6: setColor(0, 1, 1); break; // 青
    case 7: setColor(1, 1, 1); break; // 白
  }
}
