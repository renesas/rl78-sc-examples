# RL78/G23 リアルタイム・クロック

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23のリアルタイム・クロック（RTC）の定周期割り込み機能とアラーム割り込み機能の使用例を説明します。定周期割り込みにより出力ポートの反転とLCDへの時刻表示を行い、アラーム割り込みにより設定時刻から5秒後に割り込みを発生させます。さらに、リセット中でもRTCが継続動作していることをLCD表示で確認できます。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.11.00 |
| e2 studio | V2024-04 (24.4.0) |
| CC-RL | V1.13.00 |
| IAR Embedded Workbench | V5.10.3 |
| IAR Compiler | V5.10.3.2716 |
| Smart Configurator | V1.6.0 |
| BSP | V1.60 |

## ハードウェア構成
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LCDモジュール (ACM1602NI-FLW-FBW-M01)
- LED

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 リアルタイム・クロック](https://www.renesas.com/ja/document/apn/rl78g23-realtime-clock)
