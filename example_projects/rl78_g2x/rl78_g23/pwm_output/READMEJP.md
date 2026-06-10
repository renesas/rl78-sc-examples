# RL78/G23 タイマ・アレイ・ユニット (PWM出力)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23のタイマ・アレイ・ユニット（TAU）によるPWM出力機能の使用方法を説明しています。チャネル0とチャネル1を連動動作させてPWM信号を生成し、LEDの輝度制御を行います。タイマ割り込みの周期を利用してデューティ比を段階的に変更します。また、500msごとにLED出力を反転させることで動作タイミングを示します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.05.00 |
| e2 studio | V2021-04 (21.4.0) |
| CC-RL | V1.10.00 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V1.0.1 |
| BSP | V1.00 |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LED1
- LED2

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 タイマ・アレイ・ユニット (PWM出力)](https://www.renesas.com/ja/document/apn/rl78g23-timer-array-unit-pwm-output)
